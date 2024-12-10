#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "test/template.hpp"
#include "src/graph/max_flow.hpp"

int main() {
   int L, R, M;
   cin >> L >> R >> M;
   mf_graph<int> g(L + R + 2);
   int s = L + R;
   int t = s + 1;
   vector<pair<int, int>> edges;
   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      g.add_edge(a, b + L, 1);
      edges.emplace_back(a, b);
   }
   for(int i = 0; i < L; i++) g.add_edge(s, i, 1);
   for(int i = 0; i < R; i++) g.add_edge(i + L, t, 1);
   cout << g.flow(s, t) << endl;
   for(int i = 0; i < M; i++) {
      auto e = g.get_edge(i);
      if(e.flow == 1) cout << edges[i].first << " " << edges[i].second << "\n";
   }
}