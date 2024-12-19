---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/tree_mo.test.cpp
    title: test/algorithm/tree_mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/offline_lca.test.cpp
    title: test/graph/tree/offline_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/tree/offline_lca.hpp\"\nvector<int> offline_lca(const\
    \ vector<vector<int>>& g, const vector<pair<int, int>>& qs, int root = 0) {\n\
    \   int N = size(g);\n   int Q = size(qs);\n   dsu d(N);\n   vector<int> mark(N),\
    \ ptr(N), ans(Q, -1);\n   stack<int> st;\n   st.push(root);\n   for(auto& [l,\
    \ r] : qs) {\n      mark[l]++;\n      mark[r]++;\n   }\n\n   vector<vector<pair<int,\
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
    \     }\n         st.pop();\n      }\n   }\n   return ans;\n};\n"
  code: "vector<int> offline_lca(const vector<vector<int>>& g, const vector<pair<int,\
    \ int>>& qs, int root = 0) {\n   int N = size(g);\n   int Q = size(qs);\n   dsu\
    \ d(N);\n   vector<int> mark(N), ptr(N), ans(Q, -1);\n   stack<int> st;\n   st.push(root);\n\
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
    \     }\n         st.pop();\n      }\n   }\n   return ans;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/offline_lca.hpp
  requiredBy: []
  timestamp: '2024-12-18 23:28:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/tree_mo.test.cpp
  - test/graph/tree/offline_lca.test.cpp
documentation_of: src/graph/tree/offline_lca.hpp
layout: document
redirect_from:
- /library/src/graph/tree/offline_lca.hpp
- /library/src/graph/tree/offline_lca.hpp.html
title: src/graph/tree/offline_lca.hpp
---
