#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "test/template.hpp"
#include "src/graph/tree/hld.hpp"
#include "src/data-structure/BIT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;

   vector<int> A(N);
   rep(i, 0, N) cin >> A[i];

   HLDcomposition hld(N);
   rep(i, 1, N) {
      int p;
      cin >> p;
      hld.add_edge(p, i);
   }
   hld.build();

   BIT bit(N);
   rep(i, 0, N) { bit.add(hld.index(i), A[i]); }
   while(Q--) {
      int t;
      cin >> t;
      if(t == 0) {
         int u, x;
         cin >> u >> x;
         bit.add(hld.index(u), x);
      } else {
         int u;
         cin >> u;
         auto [l, r] = hld.subtree_query(u);
         cout << bit.sum(l, r) << '\n';
      }
   }
   return 0;
}