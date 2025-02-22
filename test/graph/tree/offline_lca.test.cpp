#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "test/template.hpp"
#include "test/data-structure/dsu.hpp"
#include "src/graph/tree/offline_lca.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<vector<int>> g(N);
   for(int i = 1; i < N; i++) {
      int p;
      cin >> p;
      g[p].push_back(i);
      g[i].push_back(p);
   }
   vector<pair<int, int>> qs(Q);
   for(auto& [l, r] : qs) { cin >> l >> r; }
   auto ans = offline_lca(g, qs);
   for(auto x : ans) { cout << x << '\n'; }
   return 0;
}