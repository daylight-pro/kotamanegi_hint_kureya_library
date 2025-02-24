---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/tree_mo.test.cpp
    title: test/algorithm/tree_mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/eulerian_trail.test.directed.cpp
    title: test/graph/eulerian_trail.test.directed.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/eulerian_trail.test.undirected.cpp
    title: test/graph/eulerian_trail.test.undirected.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/data-structure/dsu.hpp\"\n// base: d569f4\nstruct dsu\
    \ {\n   private:\n   int _n;\n   vector<int> p;\n\n   public:\n   dsu() : _n(0)\
    \ {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\n   int merge(int a, int b)\
    \ {\n      // assert(0 <= a && a < _n);\n      // assert(0 <= b && b < _n);\n\
    \      int x = leader(a), y = leader(b);\n      if(x == y) return x;\n      if(-p[x]\
    \ < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y] = x;\n      return x;\n\
    \   }\n\n   bool same(int a, int b) {\n      // assert(0 <= a && a < _n);\n  \
    \    // assert(0 <= b && b < _n);\n      return leader(a) == leader(b);\n   }\n\
    \n   int leader(int a) {\n      // assert(0 <= a && a < _n);\n      if(p[a] <\
    \ 0) return a;\n      int x = a;\n      while(p[x] >= 0) x = p[x];\n      while(p[a]\
    \ >= 0) {\n         int t = p[a];\n         p[a] = x;\n         a = t;\n     \
    \ }\n      return x;\n   }\n\n   int size(int a) {\n      // assert(0 <= a &&\
    \ a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\n   vector<vector<int>>\
    \ groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n      for(int\
    \ i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(_n);\n      for(int i = 0; i < _n;\
    \ i++) result[i].reserve(group_size[i]);\n      for(int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n\
    \      result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>&\
    \ v) { return v.empty(); }),\n                   result.end());\n      return\
    \ result;\n   }  // bf3a1e\n};\n"
  code: "// base: d569f4\nstruct dsu {\n   private:\n   int _n;\n   vector<int> p;\n\
    \n   public:\n   dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\
    \n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      int x = leader(a), y = leader(b);\n      if(x == y)\
    \ return x;\n      if(-p[x] < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y]\
    \ = x;\n      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0\
    \ <= a && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a)\
    \ == leader(b);\n   }\n\n   int leader(int a) {\n      // assert(0 <= a && a <\
    \ _n);\n      if(p[a] < 0) return a;\n      int x = a;\n      while(p[x] >= 0)\
    \ x = p[x];\n      while(p[a] >= 0) {\n         int t = p[a];\n         p[a] =\
    \ x;\n         a = t;\n      }\n      return x;\n   }\n\n   int size(int a) {\n\
    \      // assert(0 <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n\
    \      for(int i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n  \
    \       group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(_n);\n\
    \      for(int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // bf3a1e\n};"
  dependsOn: []
  isVerificationFile: false
  path: test/data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2025-01-07 15:52:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/tree_mo.test.cpp
  - test/graph/eulerian_trail.test.undirected.cpp
  - test/graph/eulerian_trail.test.directed.cpp
documentation_of: test/data-structure/dsu.hpp
layout: document
redirect_from:
- /library/test/data-structure/dsu.hpp
- /library/test/data-structure/dsu.hpp.html
title: test/data-structure/dsu.hpp
---
