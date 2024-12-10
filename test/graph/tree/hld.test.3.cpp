#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "test/template.hpp"
#include "src/graph/tree/hld.hpp"
#include "src/data-structure/BIT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;

   vector<int> A(N);
   for(int i = 0; i < N; i++) cin >> A[i];

   HLDcomposition hld(N);
   for(int i = 1; i < N; i++) {
      int p;
      cin >> p;
      hld.add_edge(p, i);
   }
   hld.build();

   BIT bit(N);
   for(int i = 0; i < N; i++) { bit.add(hld.index(i), A[i]); }
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