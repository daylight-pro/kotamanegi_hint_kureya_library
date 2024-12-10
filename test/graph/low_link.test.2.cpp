#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B"

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
   auto bridge = lowlink.getBridges();
   for(auto&& [u, v] : bridge) {
      if(u > v) swap(u, v);
   }
   sort(all(bridge));
   for(auto& [u, v] : bridge) cout << u << ' ' << v << '\n';
   return 0;
}