#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "test/template.hpp"
#include "src/graph/scc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   cin >> N >> M;
   scc_graph g(N);
   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      g.add_edge(a, b);
   }
   auto scc = g.scc();
   cout << scc.size() << '\n';
   for(auto gr : scc) {
      cout << size(gr);
      for(auto v : gr) cout << ' ' << v;
      cout << '\n';
   }
   return 0;
}