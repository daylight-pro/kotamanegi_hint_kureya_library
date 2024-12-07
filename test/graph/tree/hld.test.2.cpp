#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "test/template.hpp"
#include "src/graph/tree/hld.hpp"
#include "src/data-structure/segtree.hpp"
#include "src/modint/modint.hpp"

using P = pair<mm, mm>;
P op(P a, P b) { return {a.first * b.first, a.second * b.first + b.second}; }
P op2(P a, P b) { return {a.first * b.first, a.first * b.second + a.second}; }

P e() { return {1, 0}; }

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   HLDcomposition hld(N);
   vector<int> A(N), B(N);
   rep(i, 0, N) { cin >> A[i] >> B[i]; }
   rep(i, 0, N - 1) {
      int u, v;
      cin >> u >> v;
      hld.add_edge(u, v);
   }
   hld.build();
   segtree<P, op, e> seg(N);
   segtree<P, op2, e> seg2(N);
   rep(i, 0, N) {
      seg.set(hld.index(i), {A[i], B[i]});
      seg2.set(hld.index(i), {A[i], B[i]});
   }
   while(Q--) {
      int k;
      cin >> k;
      if(k == 0) {
         int p, c, d;
         cin >> p >> c >> d;
         seg.set(hld.index(p), {c, d});
         seg2.set(hld.index(p), {c, d});
      } else {
         int u, v;
         cin >> u >> v;
         int y;
         cin >> y;
         mm x(y);
         for(auto [l, r, f] : hld.path_query(u, v)) {
            if(f) {
               auto [c, d] = seg2.prod(l, r);
               x = c * x + d;
            } else {
               auto [a, b] = seg.prod(l, r);
               x = a * x + b;
            }
         }
         cout << x.x << endl;
      }
   }
   return 0;
}
