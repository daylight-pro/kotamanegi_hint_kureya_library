/*
 AtCoder Beginner Contest 174 F - Range Set Query

 AC確認済み: https://atcoder.jp/contests/abc174/submissions/60865846


#include "test/template.hpp"
#include "src/data-structure/BIT.hpp"
#include "src/data-structure/range_tree.hpp"

struct M {
   using S = ll;
   using D = BIT;
   static S op(S a, S b) { return a + b; }
   static S e() { return 0; }
   static D init(int n) { return BIT(n); }
   static void apply(D& bit, int k, const S& v) { bit.add(k, v); }
   static S prod(D& bit, int l, int r) { return bit.sum(l, r); }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;
   vector<ll> c(N);
   for(auto& x : c) cin >> x;
   vector<ll> pre(N + 1, -1);
   range_tree<int, M> rt;
   vector<pair<int, int>> dup;
   for(int i = 0; i < N; i++) {
      if(pre[c[i]] != -1) {
         dup.emplace_back(pre[c[i]], i);
         rt.add(pre[c[i]], i);
      }
      pre[c[i]] = i;
   }
   rt.build();
   for(auto [x, y] : dup) rt.apply(x, y, 1);
   while(Q--) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << r - l - rt.prod(l, l, r, r) << '\n';
   }
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "test/data-structure/BIT.hpp"
#include "src/data-structure/range_tree.hpp"

int main() { puts("Hello World"); }
