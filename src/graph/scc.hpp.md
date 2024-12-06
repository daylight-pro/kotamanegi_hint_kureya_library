---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.test.2.cpp
    title: test/graph/scc.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.test.cpp
    title: test/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/two_sat.test.cpp
    title: test/graph/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/scc.hpp\"\n// base: 1e9c3f\nstruct scc_graph {\n\
    \   public:\n   explicit scc_graph(int _n = 0) : n(_n), G(_n), rG(_n), comp(_n,\
    \ -1), visited(_n, 0) {}\n\n   void add_edge(int from, int to) {\n      // assert(0\
    \ <= from && from < n);\n      // assert(0 <= to && to < n);\n      G[from].push_back(to);\n\
    \      rG[to].push_back(from);\n   }\n\n   vector<vector<int>> scc() {\n     \
    \ fill(all(visited), 0);\n      fill(all(comp), -1);\n      order.clear();\n \
    \     rep(i, 0, n) if(!visited[i]) dfs(i);\n      comp_size = 0;\n      for(int\
    \ i = sz(order) - 1; i >= 0; i--) {\n         if(comp[order[i]] < 0) rdfs(order[i],\
    \ comp_size++);\n      }\n      vector<vector<int>> v(comp_size);\n      rep(i,\
    \ 0, n) v[comp[i]].push_back(i);\n      return v;\n   }\n\n   vector<int> get_comp()\
    \ { return comp; }  // bdafc0\n\n   vector<vector<int>> dag() {\n      vector<vector<int>>\
    \ res(comp_size);\n      rep(i, 0, n) for(auto j : G[i]) {\n         if(comp[i]\
    \ != comp[j]) res[comp[i]].push_back(comp[j]);\n      }\n      rep(i, 0, comp_size)\
    \ {\n         sort(all(res[i]));\n         res[i].erase(unique(all(res[i])), res[i].end());\n\
    \      }\n      return res;\n   }  // da3a19\n\n   private:\n   vector<vector<int>>\
    \ G, rG;\n   vector<int> order, comp;\n   vector<bool> visited;\n   int n, comp_size;\n\
    \n   void dfs(int v) {\n      visited[v] = true;\n      for(auto to : G[v])\n\
    \         if(!visited[to]) dfs(to);\n      order.push_back(v);\n   }\n\n   void\
    \ rdfs(int v, int k) {\n      comp[v] = k;\n      for(auto to : rG[v]) {\n   \
    \      if(comp[to] < 0) rdfs(to, k);\n      }\n   }\n};\n"
  code: "// base: 1e9c3f\nstruct scc_graph {\n   public:\n   explicit scc_graph(int\
    \ _n = 0) : n(_n), G(_n), rG(_n), comp(_n, -1), visited(_n, 0) {}\n\n   void add_edge(int\
    \ from, int to) {\n      // assert(0 <= from && from < n);\n      // assert(0\
    \ <= to && to < n);\n      G[from].push_back(to);\n      rG[to].push_back(from);\n\
    \   }\n\n   vector<vector<int>> scc() {\n      fill(all(visited), 0);\n      fill(all(comp),\
    \ -1);\n      order.clear();\n      rep(i, 0, n) if(!visited[i]) dfs(i);\n   \
    \   comp_size = 0;\n      for(int i = sz(order) - 1; i >= 0; i--) {\n        \
    \ if(comp[order[i]] < 0) rdfs(order[i], comp_size++);\n      }\n      vector<vector<int>>\
    \ v(comp_size);\n      rep(i, 0, n) v[comp[i]].push_back(i);\n      return v;\n\
    \   }\n\n   vector<int> get_comp() { return comp; }  // bdafc0\n\n   vector<vector<int>>\
    \ dag() {\n      vector<vector<int>> res(comp_size);\n      rep(i, 0, n) for(auto\
    \ j : G[i]) {\n         if(comp[i] != comp[j]) res[comp[i]].push_back(comp[j]);\n\
    \      }\n      rep(i, 0, comp_size) {\n         sort(all(res[i]));\n        \
    \ res[i].erase(unique(all(res[i])), res[i].end());\n      }\n      return res;\n\
    \   }  // da3a19\n\n   private:\n   vector<vector<int>> G, rG;\n   vector<int>\
    \ order, comp;\n   vector<bool> visited;\n   int n, comp_size;\n\n   void dfs(int\
    \ v) {\n      visited[v] = true;\n      for(auto to : G[v])\n         if(!visited[to])\
    \ dfs(to);\n      order.push_back(v);\n   }\n\n   void rdfs(int v, int k) {\n\
    \      comp[v] = k;\n      for(auto to : rG[v]) {\n         if(comp[to] < 0) rdfs(to,\
    \ k);\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/scc.hpp
  requiredBy: []
  timestamp: '2024-12-07 01:03:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/scc.test.2.cpp
  - test/graph/two_sat.test.cpp
  - test/graph/scc.test.cpp
documentation_of: src/graph/scc.hpp
layout: document
redirect_from:
- /library/src/graph/scc.hpp
- /library/src/graph/scc.hpp.html
title: src/graph/scc.hpp
---
