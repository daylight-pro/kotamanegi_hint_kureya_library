#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"

#include "test/template.hpp"
#include "src/graph/max_flow.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n, m;
   cin >> n >> m;

   mf_graph<int> g(n);
   rep(i, 0, m) {
      int u, v, c;
      cin >> u >> v >> c;
      g.add_edge(u, v, c);
   }
   cout << g.flow(0, n - 1) << "\n";

   return 0;
}