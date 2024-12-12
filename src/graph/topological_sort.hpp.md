---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/topological_sort.hpp\"\nvector<int> topological_sort(vector<vector<int>>&\
    \ g) {\n   int n = g.size();\n   vector<int> indeg(n);\n   for(int i = 0; i <\
    \ n; i++)\n      for(int j : g[i]) indeg[j]++;\n   vector<int> res;\n   queue<int>\
    \ q;\n   for(int i = 0; i < n; i++)\n      if(indeg[i] == 0) q.push(i);\n   while(!q.empty())\
    \ {\n      auto v = q.front();\n      q.pop();\n      res.push_back(v);\n    \
    \  for(auto u : g[v]) {\n         indeg[u]--;\n         if(indeg[u] == 0) q.push(u);\n\
    \      }\n   }\n   return res;\n}\n"
  code: "vector<int> topological_sort(vector<vector<int>>& g) {\n   int n = g.size();\n\
    \   vector<int> indeg(n);\n   for(int i = 0; i < n; i++)\n      for(int j : g[i])\
    \ indeg[j]++;\n   vector<int> res;\n   queue<int> q;\n   for(int i = 0; i < n;\
    \ i++)\n      if(indeg[i] == 0) q.push(i);\n   while(!q.empty()) {\n      auto\
    \ v = q.front();\n      q.pop();\n      res.push_back(v);\n      for(auto u :\
    \ g[v]) {\n         indeg[u]--;\n         if(indeg[u] == 0) q.push(u);\n     \
    \ }\n   }\n   return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-12-13 01:39:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: src/graph/topological_sort.hpp
---
