#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"

#include "test/template.hpp"
#include "src/graph/max_flow.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int x, y, e;
   cin >> x >> y >> e;
   mf_graph<int> g(x + y + 2);
   int s = x + y;
   int t = s + 1;
   rep(i, 0, e) {
      int a, b;
      cin >> a >> b;
      g.add_edge(a, b + x, 1);
   }
   rep(i, 0, x) g.add_edge(s, i, 1);
   rep(i, 0, y) g.add_edge(i + x, t, 1);
   cout << g.flow(s, t) << endl;
   return 0;
}