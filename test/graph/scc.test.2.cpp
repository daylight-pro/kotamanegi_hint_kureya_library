#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include "test/template.hpp"
#include "src/graph/scc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int V, E;
   cin >> V >> E;
   scc_graph g(V);
   for(int i = 0; i < E; i++) {
      int s, t;
      cin >> s >> t;
      g.add_edge(s, t);
   }
   auto scc = g.scc();
   auto rev = vector<int>(V);
   for(int i = 0; i < size(scc); i++)
      for(auto v : scc[i]) rev[v] = i;
   int Q;
   cin >> Q;
   while(Q--) {
      int u, v;
      cin >> u >> v;
      cout << (rev[u] == rev[v]) << '\n';
   }
   return 0;
}