#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/data-structure/segtree.hpp"

struct Data {
   mm c, d;
};

Data op(Data a, Data b) { return {a.c * b.c, b.c * a.d + b.d}; }

Data e() { return {1, 0}; }

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;
   vector<Data> V(N);
   rep(i, 0, N) {
      int a, b;
      cin >> a >> b;
      V[i] = {mm(a), mm(b)};
   }
   segtree<Data, op, e> seg(V);
   while(Q--) {
      int k;
      cin >> k;
      if(k == 0) {
         int p, c, d;
         cin >> p >> c >> d;
         seg.set(p, {c, d});
      } else {
         int l, r, x;
         cin >> l >> r >> x;
         auto [c, d] = seg.prod(l, r);
         cout << (c * x + d).x << endl;
      }
   }
}