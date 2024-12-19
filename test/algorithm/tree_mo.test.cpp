#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0489"

#include "test/template.hpp"
#include "src/algorithm/mo.hpp"
#include "src/algorithm/tree_mo.hpp"
#include "src/data-structure/dsu.hpp"
#include "src/graph/tree/offline_lca.hpp"
#include "src/data-structure/binary_trie.hpp"

int main() {
   int N, M;
   cin >> N >> M;
   vector<ll> B(N);
   for(auto& b : B) cin >> b;
   ll base = *min_element(all(B));
   vector<vector<int>> G(N);
   for(int i = 0; i < N - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      G[a].emplace_back(b);
      G[b].emplace_back(a);
   }
   vector<tuple<int, int, int>> queries;
   vector<pair<int, int>> lca_query;
   for(int i = 0; i < M; i++) {
      int t;
      cin >> t;
      if(t == 1) {
         int u, w;
         cin >> u >> w;
         u--;
         B.push_back(w);
         chmin(base, w);
         G.push_back({});
         G[u].emplace_back(N);
         G[N].emplace_back(u);
         N++;
      } else {
         int u, v, k;
         cin >> u >> v >> k;
         u--;
         v--;
         queries.emplace_back(u, v, k);
         lca_query.emplace_back(u, v);
      }
   }
   for(auto& b : B) b -= base;
   MoTree_vertex<ll> mo(N, B);
   for(int i = 0; i < N; i++) {
      for(auto& v : G[i])
         if(v > i) mo.add_edge(i, v);
   }
   mo.build(size(queries));
   auto lcas = offline_lca(G, lca_query);
   vector<int> ans(size(queries));
   for(int i = 0; i < size(queries); i++) {
      auto [u, v, k] = queries[i];
      mo.insert(u, v, lcas[i]);
   }
   BinaryTrie<int> trie;
   auto add = [&](int w) { trie.add(w); };
   auto del = [&](int w) { trie.erase(w); };
   auto rem = [&](int idx) {
      int k = get<2>(queries[idx]);
      ans[idx] = trie.kth_smallest(k - 1) + base;
   };
   mo.run(add, del, rem);
   for(auto x : ans) cout << x << "\n";
}