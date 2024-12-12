#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "test/template.hpp"
#include "src/data-structure/disjoint_sparse_table.hpp"

struct SG {
   using S = ll;
   static S op(S a, S b) { return a + b; }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto&& a : A) cin >> a;
   disjoint_sparse_table<SG> st(A);
   while(Q--) {
      int l, r;
      cin >> l >> r;
      cout << st.prod(l, r) << '\n';
   }
   return 0;
}