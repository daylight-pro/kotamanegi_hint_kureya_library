---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: src/algorithm/mo.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/tree_mo.hpp
    title: src/algorithm/tree_mo.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary_trie.hpp
    title: src/data-structure/binary_trie.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline_lca.hpp
    title: src/graph/tree/offline_lca.hpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu.hpp
    title: test/data-structure/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0489
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0489
  bundledCode: "#line 1 \"test/algorithm/tree_mo.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0489\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/mo.hpp\"\
    \nstruct Mo {\n   int width;\n   vector<int> left, right, order;\n   Mo(int N,\
    \ int Q) : order(Q) {\n      width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q\
    \ * 2.0 / 3.0)));\n      iota(all(order), 0);\n   }\n\n   void insert(int l, int\
    \ r) {\n      left.emplace_back(l);\n      right.emplace_back(r);\n   }\n\n  \
    \ void run(const auto& add_left,\n            const auto& add_right,\n       \
    \     const auto& delete_left,\n            const auto& delete_right,\n      \
    \      const auto& rem) {\n      sort(begin(order), end(order), [&](int a, int\
    \ b) {\n         int ablock = left[a] / width, bblock = left[b] / width;\n   \
    \      if(ablock != bblock) return ablock < bblock;\n         return (ablock &\
    \ 1) ? right[a] > right[b] : right[a] < right[b];\n      });\n      int nl = 0,\
    \ nr = 0;\n      for(auto idx : order) {\n         while(nl > left[idx]) add_left(--nl);\n\
    \         while(nr < right[idx]) add_right(nr++);\n         while(nl < left[idx])\
    \ delete_left(nl++);\n         while(nr > right[idx]) delete_right(--nr);\n  \
    \       rem(idx);\n      }\n   }\n};\n#line 1 \"src/algorithm/tree_mo.hpp\"\n\
    template<class T> struct MoTree_edge {\n   int n;\n   vector<vector<pair<int,\
    \ T>>> es;\n   vector<int> in;\n   vector<pair<int, T>> vals;\n   Mo mo;\n   MoTree_edge(int\
    \ _n) : n(_n), es(_n), mo(0, 0) {}\n\n   void add_edge(int u, int v, T w) {\n\
    \      es[u].emplace_back(v, w);\n      es[v].emplace_back(u, w);\n   }\n\n  \
    \ void build(int q) {\n      int tnow = 0;\n      auto dfs = [&](auto dfs, int\
    \ v, int f) -> void {\n         in[v] = tnow++;\n         for(auto [u, w] : es[v])\
    \ {\n            if(u == f) continue;\n            vals.emplace_back(u, w);\n\
    \            dfs(dfs, u, v);\n            vals.emplace_back(u, w);\n         \
    \   tnow++;\n         }\n      };\n      in.resize(n);\n      dfs(dfs, 0, -1);\n\
    \      mo = Mo(2 * n - 2, q);\n   }\n\n   void insert(int u, int v) {\n      u\
    \ = in[u];\n      v = in[v];\n      if(u > v) swap(u, v);\n      mo.insert(u,\
    \ v);\n   }\n\n   void run(const auto& add, const auto& del, const auto& rem)\
    \ {\n      vector<bool> contain(n, false);\n      auto change = [&](int i) {\n\
    \         int id = vals[i].first;\n         if(contain[id]) {\n            del(vals[i].second);\n\
    \            contain[id] = false;\n         } else {\n            add(vals[i].second);\n\
    \            contain[id] = true;\n         }\n      };\n      mo.run(change, change,\
    \ change, change, rem);\n   }\n};  // b505c7\n\ntemplate<class T> struct MoTree_vertex\
    \ {\n   int n;\n   vector<vector<int>> es;\n   vector<T> b;\n   vector<int> in,\
    \ lcas;\n   vector<pair<int, T>> vals;\n   Mo mo;\n   MoTree_vertex(int _n, vector<T>\
    \ _b) : n(_n), b(_b), mo(0, 0) { es.resize(n); }\n\n   void add_edge(int u, int\
    \ v) {\n      es[u].push_back(v);\n      es[v].push_back(u);\n   }\n\n   void\
    \ build(int q) {\n      vals.reserve(2 * n - 2);\n      lcas.reserve(q);\n   \
    \   int tnow = 0;\n      auto dfs = [&](auto dfs, int v, int f) -> void {\n  \
    \       in[v] = tnow++;\n         for(auto u : es[v]) {\n            if(u == f)\
    \ continue;\n            vals.emplace_back(u, b[u]);\n            dfs(dfs, u,\
    \ v);\n            vals.emplace_back(u, b[u]);\n            tnow++;\n        \
    \ }\n      };\n      in.resize(n);\n      dfs(dfs, 0, -1);\n      mo = Mo(2 *\
    \ n - 2, q);\n   }\n\n   void insert(int u, int v, int lca) {\n      u = in[u],\
    \ v = in[v];\n      if(u > v) swap(u, v);\n      mo.insert(u, v);\n      lcas.push_back(lca);\n\
    \   }\n\n   void run(const auto& add, const auto& del, const auto& rem) {\n  \
    \    vector<bool> contain(n, false);\n      auto change = [&](int i) {\n     \
    \    int id = vals[i].first;\n         if(contain[id]) {\n            del(vals[i].second);\n\
    \            contain[id] = false;\n         } else {\n            add(vals[i].second);\n\
    \            contain[id] = true;\n         }\n      };\n      auto rem_add_lca\
    \ = [&](int i) {\n         add(b[lcas[i]]);\n         rem(i);\n         del(b[lcas[i]]);\n\
    \      };\n      mo.run(change, change, change, change, rem_add_lca);\n   }\n\
    };  // da9ab0\n#line 1 \"test/data-structure/dsu.hpp\"\n// base: d569f4\nstruct\
    \ dsu {\n   private:\n   int _n;\n   vector<int> p;\n\n   public:\n   dsu() :\
    \ _n(0) {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\n   int merge(int a,\
    \ int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0 <= b && b <\
    \ _n);\n      int x = leader(a), y = leader(b);\n      if(x == y) return x;\n\
    \      if(-p[x] < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y] = x;\n \
    \     return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0 <= a\
    \ && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a) == leader(b);\n\
    \   }\n\n   int leader(int a) {\n      // assert(0 <= a && a < _n);\n      if(p[a]\
    \ < 0) return a;\n      int x = a;\n      while(p[x] >= 0) x = p[x];\n      while(p[a]\
    \ >= 0) {\n         int t = p[a];\n         p[a] = x;\n         a = t;\n     \
    \ }\n      return x;\n   }\n\n   int size(int a) {\n      // assert(0 <= a &&\
    \ a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\n   vector<vector<int>>\
    \ groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n      for(int\
    \ i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(_n);\n      for(int i = 0; i < _n;\
    \ i++) result[i].reserve(group_size[i]);\n      for(int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n\
    \      result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>&\
    \ v) { return v.empty(); }),\n                   result.end());\n      return\
    \ result;\n   }  // bf3a1e\n};\n#line 1 \"src/graph/tree/offline_lca.hpp\"\nvector<int>\
    \ offline_lca(const vector<vector<int>>& g, const vector<pair<int, int>>& qs,\
    \ int root = 0) {\n   int N = size(g);\n   int Q = size(qs);\n   dsu d(N);\n \
    \  vector<int> mark(N), ptr(N), ans(Q, -1);\n   stack<int> st;\n   st.push(root);\n\
    \   for(auto& [l, r] : qs) {\n      mark[l]++;\n      mark[r]++;\n   }\n\n   vector<vector<pair<int,\
    \ int>>> q(N);\n   for(int i = 0; i < N; i++) {\n      q[i].reserve(mark[i]);\n\
    \      mark[i] = -1;\n      ptr[i] = size(g[i]);\n   }\n   for(int i = 0; i <\
    \ Q; i++) {\n      q[qs[i].first].emplace_back(qs[i].second, i);\n      q[qs[i].second].emplace_back(qs[i].first,\
    \ i);\n   }\n   auto run = [&](int u) -> bool {\n      while(ptr[u]) {\n     \
    \    int v = g[u][--ptr[u]];\n         if(mark[v] == -1) {\n            st.push(v);\n\
    \            return true;\n         }\n      }\n      return false;\n   };\n\n\
    \   while(!st.empty()) {\n      int u = st.top();\n      if(mark[u] == -1) mark[u]\
    \ = u;\n      else {\n         d.merge(u, g[u][ptr[u]]);\n         mark[d.leader(u)]\
    \ = u;\n      }\n      if(!run(u)) {\n         for(auto& [v, i] : q[u]) {\n  \
    \          if(~mark[v] && ans[i] == -1) { ans[i] = mark[d.leader(v)]; }\n    \
    \     }\n         st.pop();\n      }\n   }\n   return ans;\n};\n#line 1 \"src/data-structure/binary_trie.hpp\"\
    \n// base: b75bb1\ntemplate<typename T, int MAX_LOG = 32> struct BinaryTrie {\n\
    \   struct Node {\n      array<int, 2> next;\n      int common;\n      T lazy;\n\
    \      Node() : next{-1, -1}, common(), lazy() {}\n   };\n   vector<Node> nodes;\n\
    \   BinaryTrie() { nodes.push_back(Node()); }\n   void apply_xor(T val) { nodes[0].lazy\
    \ ^= val; }\n   void push(int cur, int b) {\n      if((nodes[cur].lazy >> b) &\
    \ 1) swap(nodes[cur].next[0], nodes[cur].next[1]);\n      for(int i = 0; i < 2;\
    \ i++) {\n         if(nodes[cur].next[i] == -1) nodes[nodes[cur].next[i]].lazy\
    \ ^= nodes[cur].lazy;\n      }\n      nodes[cur].lazy = 0;\n   }\n   void add(T\
    \ val, int cur = 0, int b = MAX_LOG - 1) {\n      nodes[cur].common++;\n     \
    \ if(b == -1) return;\n      push(cur, b);\n      int nxt = (val >> (T)b) & (T)1;\n\
    \      if(nodes[cur].next[nxt] == -1) {\n         nodes[cur].next[nxt] = size(nodes);\n\
    \         nodes.push_back(Node());\n      }\n      add(val, nodes[cur].next[nxt],\
    \ b - 1);\n   }\n\n   void erase(T val, int cur = 0, int b = MAX_LOG - 1) {\n\
    \      nodes[cur].common--;\n      if(b == -1) return;\n      push(cur, b);\n\
    \      erase(val, nodes[cur].next[(val >> b) & 1], b - 1);\n   }\n\n   T min_element(T\
    \ val = 0, int cur = 0, int b = MAX_LOG - 1) {\n      if(b == -1) return 0;\n\
    \      push(cur, b);\n      T nxt = (val >> b) & 1;\n      int ind = nodes[cur].next[nxt];\n\
    \      if(ind == -1 || nodes[ind].common == 0) nxt ^= 1;\n      return min_element(val,\
    \ nodes[cur].next[nxt], b - 1) | (nxt << b);\n   }  // ddf699\n\n   T max_element(T\
    \ val = 0, int cur = 0, int b = MAX_LOG - 1) { return min_element(~val); }  //\
    \ 5e1a86\n\n   int lower_bound_rank(T val, int cur = 0, int b = MAX_LOG - 1) {\n\
    \      if(cur == -1 || b == -1) return 0;\n      push(cur, b);\n      T nxt =\
    \ (val >> b) & 1;\n      int ret = lower_bound_rank(val, nodes[cur].next[nxt],\
    \ b - 1);\n      if(nxt == 1 && nodes[cur].next[0] != -1) { ret += nodes[nodes[cur].next[0]].common;\
    \ }\n      return ret;\n   }  // 05b14c\n\n   int upper_bound_rank(T val) { return\
    \ lower_bound_rank(val + 1); }  // 70e301\n\n   T kth_smallest(int k, int cur\
    \ = 0, int b = MAX_LOG - 1) {\n      if(b == -1) return 0;\n      int lower_ind\
    \ = nodes[cur].next[0];\n      int lower_cnt = 0;\n      if(lower_ind != -1) lower_cnt\
    \ = nodes[lower_ind].common;\n      if(k < lower_cnt) return kth_smallest(k, nodes[cur].next[0],\
    \ b - 1);\n      return kth_smallest(k - lower_cnt, nodes[cur].next[1], b - 1)\
    \ | (T(1) << b);\n   }  // b85845\n\n   T kth_largest(int k) { return kth_smallest(nodes[0].common\
    \ - k); }  // 1df41b\n\n   int count(T val) {\n      int cur = 0;\n      for(int\
    \ b = MAX_LOG - 1; b >= 0; b--) {\n         push(cur, b);\n         cur = nodes[cur].next[(val\
    \ >> b) & 1];\n         if(cur == -1) return 0;\n      }\n      return nodes[cur].common;\n\
    \   }  // 2a3342\n\n   int count() { return nodes[0].common; }  // 210f0e\n};\n\
    #line 9 \"test/algorithm/tree_mo.test.cpp\"\n\nint main() {\n   int N, M;\n  \
    \ cin >> N >> M;\n   vector<ll> B(N);\n   for(auto& b : B) cin >> b;\n   ll base\
    \ = *min_element(all(B));\n   vector<vector<int>> G(N);\n   for(int i = 0; i <\
    \ N - 1; i++) {\n      int a, b;\n      cin >> a >> b;\n      a--;\n      b--;\n\
    \      G[a].emplace_back(b);\n      G[b].emplace_back(a);\n   }\n   vector<tuple<int,\
    \ int, int>> queries;\n   vector<pair<int, int>> lca_query;\n   for(int i = 0;\
    \ i < M; i++) {\n      int t;\n      cin >> t;\n      if(t == 1) {\n         int\
    \ u, w;\n         cin >> u >> w;\n         u--;\n         B.push_back(w);\n  \
    \       chmin(base, w);\n         G.push_back({});\n         G[u].emplace_back(N);\n\
    \         G[N].emplace_back(u);\n         N++;\n      } else {\n         int u,\
    \ v, k;\n         cin >> u >> v >> k;\n         u--;\n         v--;\n        \
    \ queries.emplace_back(u, v, k);\n         lca_query.emplace_back(u, v);\n   \
    \   }\n   }\n   for(auto& b : B) b -= base;\n   MoTree_vertex<ll> mo(N, B);\n\
    \   for(int i = 0; i < N; i++) {\n      for(auto& v : G[i])\n         if(v > i)\
    \ mo.add_edge(i, v);\n   }\n   mo.build(size(queries));\n   auto lcas = offline_lca(G,\
    \ lca_query);\n   vector<int> ans(size(queries));\n   for(int i = 0; i < size(queries);\
    \ i++) {\n      auto [u, v, k] = queries[i];\n      mo.insert(u, v, lcas[i]);\n\
    \   }\n   BinaryTrie<int> trie;\n   auto add = [&](int w) { trie.add(w); };\n\
    \   auto del = [&](int w) { trie.erase(w); };\n   auto rem = [&](int idx) {\n\
    \      int k = get<2>(queries[idx]);\n      ans[idx] = trie.kth_smallest(k - 1)\
    \ + base;\n   };\n   mo.run(add, del, rem);\n   for(auto x : ans) cout << x <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0489\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/algorithm/mo.hpp\"\n#include \"src/algorithm/tree_mo.hpp\"\
    \n#include \"test/data-structure/dsu.hpp\"\n#include \"src/graph/tree/offline_lca.hpp\"\
    \n#include \"src/data-structure/binary_trie.hpp\"\n\nint main() {\n   int N, M;\n\
    \   cin >> N >> M;\n   vector<ll> B(N);\n   for(auto& b : B) cin >> b;\n   ll\
    \ base = *min_element(all(B));\n   vector<vector<int>> G(N);\n   for(int i = 0;\
    \ i < N - 1; i++) {\n      int a, b;\n      cin >> a >> b;\n      a--;\n     \
    \ b--;\n      G[a].emplace_back(b);\n      G[b].emplace_back(a);\n   }\n   vector<tuple<int,\
    \ int, int>> queries;\n   vector<pair<int, int>> lca_query;\n   for(int i = 0;\
    \ i < M; i++) {\n      int t;\n      cin >> t;\n      if(t == 1) {\n         int\
    \ u, w;\n         cin >> u >> w;\n         u--;\n         B.push_back(w);\n  \
    \       chmin(base, w);\n         G.push_back({});\n         G[u].emplace_back(N);\n\
    \         G[N].emplace_back(u);\n         N++;\n      } else {\n         int u,\
    \ v, k;\n         cin >> u >> v >> k;\n         u--;\n         v--;\n        \
    \ queries.emplace_back(u, v, k);\n         lca_query.emplace_back(u, v);\n   \
    \   }\n   }\n   for(auto& b : B) b -= base;\n   MoTree_vertex<ll> mo(N, B);\n\
    \   for(int i = 0; i < N; i++) {\n      for(auto& v : G[i])\n         if(v > i)\
    \ mo.add_edge(i, v);\n   }\n   mo.build(size(queries));\n   auto lcas = offline_lca(G,\
    \ lca_query);\n   vector<int> ans(size(queries));\n   for(int i = 0; i < size(queries);\
    \ i++) {\n      auto [u, v, k] = queries[i];\n      mo.insert(u, v, lcas[i]);\n\
    \   }\n   BinaryTrie<int> trie;\n   auto add = [&](int w) { trie.add(w); };\n\
    \   auto del = [&](int w) { trie.erase(w); };\n   auto rem = [&](int idx) {\n\
    \      int k = get<2>(queries[idx]);\n      ans[idx] = trie.kth_smallest(k - 1)\
    \ + base;\n   };\n   mo.run(add, del, rem);\n   for(auto x : ans) cout << x <<\
    \ \"\\n\";\n}"
  dependsOn:
  - test/template.hpp
  - src/algorithm/mo.hpp
  - src/algorithm/tree_mo.hpp
  - test/data-structure/dsu.hpp
  - src/graph/tree/offline_lca.hpp
  - src/data-structure/binary_trie.hpp
  isVerificationFile: true
  path: test/algorithm/tree_mo.test.cpp
  requiredBy: []
  timestamp: '2025-01-07 15:52:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/tree_mo.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/tree_mo.test.cpp
- /verify/test/algorithm/tree_mo.test.cpp.html
title: test/algorithm/tree_mo.test.cpp
---
