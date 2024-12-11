#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "test/template.hpp"
#include "src/data-structure/range_tree.hpp"
#include "src/data-structure/BIT.hpp"

struct M {
   using S = ll;
   using D = BIT;
   static ll op(ll a, ll b) { return a + b; }
   static ll e() { return 0; }
   static BIT init(int n) { return BIT(n); }
   static void apply(BIT& bit, int k, const ll& v) { bit.add(k, v); }
   static ll prod(BIT& bit, int l, int r) { return bit.sum(l, r); }
};

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int N, Q;
   cin >> N >> Q;
   range_tree<int, M> rt;
   using T = tuple<int, ll, ll, ll, ll>;
   vector<T> qs;
   for(int i = 0; i < N; i++) {
      int x, y;
      ll w;
      cin >> x >> y >> w;
      qs.emplace_back(-1, x, y, w, -1);
      rt.add(x, y);
   }
   for(int i = 0; i < Q; i++) {
      int t;
      ll l, d, r, u = -1;
      cin >> t >> l >> d >> r;
      if(t == 1) cin >> u;
      qs.emplace_back(t, l, d, r, u);
      if(t == 0) rt.add(l, d);
   }

   rt.build();

   for(auto [t, a, b, c, d] : qs) {
      if(t <= 0) rt.apply(a, b, c);
      else { cout << rt.prod(a, b, c, d) << '\n'; }
   }

   return 0;
}