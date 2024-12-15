#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "test/template.hpp"
#include "src/graph/low_link.hpp"
#include "src/graph/bi_connected_components.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> g(N);
   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
   }
   BiConnectedComponents bcc(g);
   cout << bcc.group.size() << "\n";
   for(auto& bg : bcc.group) {
      cout << bg.size();
      for(auto& v : bg) cout << " " << v;
      cout << "\n";
   }
   return 0;
}