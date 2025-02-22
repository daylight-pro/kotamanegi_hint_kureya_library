---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bi_connected_components.test.2.cpp
    title: test/graph/bi_connected_components.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bi_connected_components.test.cpp
    title: test/graph/bi_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bi_connected_components.hpp\"\nstruct BiConnectedComponents\
    \ : LowLink {\n   public:\n   using LowLink::bridge;\n   using LowLink::g;\n \
    \  using LowLink::low;\n   using LowLink::ord;\n\n   vector<int> comp;\n   vector<vector<int>>\
    \ tree;\n   vector<vector<int>> group;\n\n   void build(const vector<vector<int>>&\
    \ g) {\n      comp.assign(size(g), -1);\n      int k = 0;\n      for(int i = 0;\
    \ i < size(comp); i++) {\n         if(comp[i] == -1) { dfs(i, -1, k); }\n    \
    \  }\n      group.resize(k);\n      for(int i = 0; i < size(g); i++) { group[comp[i]].push_back(i);\
    \ }\n      tree.resize(k);\n      for(auto& e : bridge) {\n         tree[comp[e.first]].push_back(comp[e.second]);\n\
    \         tree[comp[e.second]].push_back(comp[e.first]);\n      }\n   }\n\n  \
    \ explicit BiConnectedComponents(const vector<vector<int>>& g) : LowLink(g) {\
    \ build(g); }\n\n   private:\n   vector<int> used;\n   vector<pair<int, int>>\
    \ tmp;\n\n   void dfs(int cur, int pre, int& k) {\n      if(pre != -1 && ord[pre]\
    \ >= low[cur]) comp[cur] = comp[pre];\n      else comp[cur] = k++;\n      for(auto\
    \ to : g[cur]) {\n         if(comp[to] == -1) dfs(to, cur, k);\n      }\n   }\n\
    };\n"
  code: "struct BiConnectedComponents : LowLink {\n   public:\n   using LowLink::bridge;\n\
    \   using LowLink::g;\n   using LowLink::low;\n   using LowLink::ord;\n\n   vector<int>\
    \ comp;\n   vector<vector<int>> tree;\n   vector<vector<int>> group;\n\n   void\
    \ build(const vector<vector<int>>& g) {\n      comp.assign(size(g), -1);\n   \
    \   int k = 0;\n      for(int i = 0; i < size(comp); i++) {\n         if(comp[i]\
    \ == -1) { dfs(i, -1, k); }\n      }\n      group.resize(k);\n      for(int i\
    \ = 0; i < size(g); i++) { group[comp[i]].push_back(i); }\n      tree.resize(k);\n\
    \      for(auto& e : bridge) {\n         tree[comp[e.first]].push_back(comp[e.second]);\n\
    \         tree[comp[e.second]].push_back(comp[e.first]);\n      }\n   }\n\n  \
    \ explicit BiConnectedComponents(const vector<vector<int>>& g) : LowLink(g) {\
    \ build(g); }\n\n   private:\n   vector<int> used;\n   vector<pair<int, int>>\
    \ tmp;\n\n   void dfs(int cur, int pre, int& k) {\n      if(pre != -1 && ord[pre]\
    \ >= low[cur]) comp[cur] = comp[pre];\n      else comp[cur] = k++;\n      for(auto\
    \ to : g[cur]) {\n         if(comp[to] == -1) dfs(to, cur, k);\n      }\n   }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bi_connected_components.hpp
  requiredBy: []
  timestamp: '2024-12-15 21:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bi_connected_components.test.2.cpp
  - test/graph/bi_connected_components.test.cpp
documentation_of: src/graph/bi_connected_components.hpp
layout: document
redirect_from:
- /library/src/graph/bi_connected_components.hpp
- /library/src/graph/bi_connected_components.hpp.html
title: src/graph/bi_connected_components.hpp
---
