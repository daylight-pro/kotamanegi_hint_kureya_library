---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/low_link.test.2.cpp
    title: test/graph/low_link.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/low_link.test.cpp
    title: test/graph/low_link.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/low_link.hpp\"\nstruct LowLink {\n   public:\n\
    \   vector<vector<int>> g;\n   vector<int> ord, low;\n   vector<int> articulation;\n\
    \   vector<bool> visited;\n   vector<pair<int, int>> bridge;\n\n   void dfs(int\
    \ cur, int pre, int& k) {\n      visited[cur] = true;\n      ord[cur] = low[cur]\
    \ = k++;\n      bool isArticulation = false;\n      int cnt = 0;\n      for(auto\
    \ to : g[cur]) {\n         if(!visited[to]) {\n            cnt++;\n          \
    \  dfs(to, cur, k);\n            chmin(low[cur], low[to]);\n            if(pre\
    \ != -1 && ord[cur] <= low[to]) isArticulation = true;\n            if(ord[cur]\
    \ < low[to]) bridge.emplace_back(min(cur, to), max(cur, to));\n         } else\
    \ if(to != pre) chmin(low[cur], ord[to]);\n      }\n      if(pre == -1 && cnt\
    \ > 1) isArticulation = true;\n      if(isArticulation) articulation.push_back(cur);\n\
    \   }\n\n   void build(const vector<vector<int>>& g) {\n      int n = g.size();\n\
    \      this->g = g;\n      ord.assign(n, -1);\n      low.assign(n, -1);\n    \
    \  visited.assign(n, false);\n      int k = 0;\n      for(int i = 0; i < n; i++)\n\
    \         if(!visited[i]) dfs(i, -1, k);\n   }\n   LowLink(const vector<vector<int>>&\
    \ g) { build(g); }\n\n   vector<int>& getArticulations() { return articulation;\
    \ }\n   vector<pair<int, int>>& getBridges() { return bridge; }\n   vector<int>&\
    \ getOrd() { return ord; }\n   vector<int>& getLowlink() { return low; }\n};\n"
  code: "struct LowLink {\n   public:\n   vector<vector<int>> g;\n   vector<int> ord,\
    \ low;\n   vector<int> articulation;\n   vector<bool> visited;\n   vector<pair<int,\
    \ int>> bridge;\n\n   void dfs(int cur, int pre, int& k) {\n      visited[cur]\
    \ = true;\n      ord[cur] = low[cur] = k++;\n      bool isArticulation = false;\n\
    \      int cnt = 0;\n      for(auto to : g[cur]) {\n         if(!visited[to])\
    \ {\n            cnt++;\n            dfs(to, cur, k);\n            chmin(low[cur],\
    \ low[to]);\n            if(pre != -1 && ord[cur] <= low[to]) isArticulation =\
    \ true;\n            if(ord[cur] < low[to]) bridge.emplace_back(min(cur, to),\
    \ max(cur, to));\n         } else if(to != pre) chmin(low[cur], ord[to]);\n  \
    \    }\n      if(pre == -1 && cnt > 1) isArticulation = true;\n      if(isArticulation)\
    \ articulation.push_back(cur);\n   }\n\n   void build(const vector<vector<int>>&\
    \ g) {\n      int n = g.size();\n      this->g = g;\n      ord.assign(n, -1);\n\
    \      low.assign(n, -1);\n      visited.assign(n, false);\n      int k = 0;\n\
    \      for(int i = 0; i < n; i++)\n         if(!visited[i]) dfs(i, -1, k);\n \
    \  }\n   LowLink(const vector<vector<int>>& g) { build(g); }\n\n   vector<int>&\
    \ getArticulations() { return articulation; }\n   vector<pair<int, int>>& getBridges()\
    \ { return bridge; }\n   vector<int>& getOrd() { return ord; }\n   vector<int>&\
    \ getLowlink() { return low; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/low_link.hpp
  requiredBy: []
  timestamp: '2024-12-09 17:00:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/low_link.test.cpp
  - test/graph/low_link.test.2.cpp
documentation_of: src/graph/low_link.hpp
layout: document
redirect_from:
- /library/src/graph/low_link.hpp
- /library/src/graph/low_link.hpp.html
title: src/graph/low_link.hpp
---
