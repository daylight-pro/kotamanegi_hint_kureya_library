#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja"

#include "test/template.hpp"
#include "src/graph/min_cost_flow.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n, e, f;
   cin >> n >> e >> f;
   mcf_graph<int, int> g(n);
   rep(i, 0, e) {
      int u, v, c, d;
      cin >> u >> v >> c >> d;
      g.add_edge(u, v, c, d);
   }
   auto ans = g.flow(0, n - 1, f);
   if(ans.first < f) {
      cout << -1 << endl;
   } else {
      cout << ans.second << endl;
   }
   return 0;
}