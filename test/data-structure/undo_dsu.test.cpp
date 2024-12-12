#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "test/template.hpp"
#include "src/data-structure/undo_dsu.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;

   undo_dsu d(N);
   vector<vector<int>> graph(Q + 1);
   vector<pair<int, int>> queries;
   vector<vector<int>> q(Q + 1);
   for(int i = 0; i < Q; i++) {
      int t, k, u, v;
      cin >> t >> k >> u >> v;
      if(k == -1) k = Q;
      queries.emplace_back(u, v);
      if(t == 0) {
         graph[k].emplace_back(i);
      } else {
         q[k].emplace_back(i);
      }
   }
   vector<int> ans(Q, -1);
   auto dfs = [&](auto&& f, int cur = -1) -> void {
      if(cur == -1) cur = Q;
      else d.merge(queries[cur].first, queries[cur].second);
      for(auto i : q[cur]) ans[i] = d.same(queries[i].first, queries[i].second);
      for(auto i : graph[cur]) f(f, i);
      if(cur != Q) d.undo();
   };
   dfs(dfs);
   for(auto x : ans)
      if(x != -1) cout << x << '\n';
   return 0;
}