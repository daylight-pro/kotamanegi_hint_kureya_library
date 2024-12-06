---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu.test.2.cpp
    title: test/data-structure/dsu.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu.test.cpp
    title: test/data-structure/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/dsu.hpp\"\n// base: c45937\nstruct dsu\
    \ {\n   private:\n   int _n;\n   vector<int> parent_or_size;\n\n   public:\n \
    \  dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\
    \n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      int x = leader(a), y = leader(b);\n      if(x == y)\
    \ return x;\n      if(-parent_or_size[x] < -parent_or_size[y]) swap(x, y);\n \
    \     parent_or_size[x] += parent_or_size[y];\n      parent_or_size[y] = x;\n\
    \      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0 <= a\
    \ && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a) == leader(b);\n\
    \   }\n\n   int leader(int a) {\n      // assert(0 <= a && a < _n);\n      if(parent_or_size[a]\
    \ < 0) return a;\n      int x = a;\n      while(parent_or_size[x] >= 0) x = parent_or_size[x];\n\
    \      while(parent_or_size[a] >= 0) {\n         int t = parent_or_size[a];\n\
    \         parent_or_size[a] = x;\n         a = t;\n      }\n      return x;\n\
    \   }\n\n   int size(int a) {\n      // assert(0 <= a && a < _n);\n      return\
    \ -parent_or_size[leader(a)];\n   }  // 1ff997\n\n   vector<vector<int>> groups()\
    \ {\n      vector<int> leader_buf(_n), group_size(_n);\n      rep(i, 0, _n) {\n\
    \         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(_n);\n      rep(i, 0, _n) result[i].reserve(group_size[i]);\n\
    \      rep(i, 0, _n) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // 45ebf9\n};\n"
  code: "// base: c45937\nstruct dsu {\n   private:\n   int _n;\n   vector<int> parent_or_size;\n\
    \n   public:\n   dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n\
    \      // assert(0 <= b && b < _n);\n      int x = leader(a), y = leader(b);\n\
    \      if(x == y) return x;\n      if(-parent_or_size[x] < -parent_or_size[y])\
    \ swap(x, y);\n      parent_or_size[x] += parent_or_size[y];\n      parent_or_size[y]\
    \ = x;\n      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0\
    \ <= a && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a)\
    \ == leader(b);\n   }\n\n   int leader(int a) {\n      // assert(0 <= a && a <\
    \ _n);\n      if(parent_or_size[a] < 0) return a;\n      int x = a;\n      while(parent_or_size[x]\
    \ >= 0) x = parent_or_size[x];\n      while(parent_or_size[a] >= 0) {\n      \
    \   int t = parent_or_size[a];\n         parent_or_size[a] = x;\n         a =\
    \ t;\n      }\n      return x;\n   }\n\n   int size(int a) {\n      // assert(0\
    \ <= a && a < _n);\n      return -parent_or_size[leader(a)];\n   }  // 1ff997\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n\
    \      rep(i, 0, _n) {\n         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(_n);\n      rep(i, 0, _n) result[i].reserve(group_size[i]);\n\
    \      rep(i, 0, _n) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // 45ebf9\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2024-12-06 16:53:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/dsu.test.2.cpp
  - test/data-structure/dsu.test.cpp
documentation_of: src/data-structure/dsu.hpp
layout: document
redirect_from:
- /library/src/data-structure/dsu.hpp
- /library/src/data-structure/dsu.hpp.html
title: src/data-structure/dsu.hpp
---
