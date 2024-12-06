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
   rep(i, 0, M) {
      int a, b;
      cin >> a >> b;
      g.add_edge(a, b + L, 1);
      edges.emplace_back(a, b);
   }
   rep(i, 0, L) g.add_edge(s, i, 1);
   rep(i, 0, R) g.add_edge(i + L, t, 1);
   cout << g.flow(s, t) << endl;
   rep(i, 0, M) {
      auto e = g.get_edge(i);
      if(e.flow == 1) cout << edges[i].first << " " << edges[i].second << "\n";
   }
}