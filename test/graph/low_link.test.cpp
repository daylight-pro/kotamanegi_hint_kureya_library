#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A"

#include "test/template.hpp"
#include "src/graph/low_link.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> G(N);
   for(int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }
   LowLink lowlink(G);
   auto articulation = lowlink.getArticulations();
   sort(all(articulation));
   for(auto v : articulation) cout << v << '\n';
   return 0;
}