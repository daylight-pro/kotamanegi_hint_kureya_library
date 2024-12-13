---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/potential_dsu.test.2.cpp
    title: test/data-structure/potential_dsu.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/potential_dsu.test.3.cpp
    title: test/data-structure/potential_dsu.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/potential_dsu.test.cpp
    title: test/data-structure/potential_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/potential_dsu.hpp\"\n// base: 650ffa\n\
    template<typename Abel> struct potential_dsu {\n   using T = typename Abel::T;\n\
    \   int tCount;\n   vector<int> p, rank;\n   vector<T> potential;\n   int N;\n\
    \   potential_dsu(int size) {\n      N = size;\n      p.resize(N, -1);\n     \
    \ rank.resize(N, 0);\n      potential.resize(N, Abel::e());\n      tCount = N;\n\
    \   }\n\n   bool same(int x, int y) { return leader(x) == leader(y); }\n\n   //\
    \ w[y] - w[x] = w\n   void merge(int x, int y, T w) {\n      w = Abel::op(w, get_potential(x));\n\
    \      w = Abel::op(w, Abel::inv(get_potential(y)));\n      link(leader(x), leader(y),\
    \ w);\n   }\n\n   int leader(int x) {\n      if(p[x] < 0) return x;\n      int\
    \ l = leader(p[x]);\n      potential[x] = Abel::op(potential[x], potential[p[x]]);\n\
    \      return p[x] = l;\n   }\n\n   T get_potential(int x) {\n      leader(x);\n\
    \      return potential[x];\n   }\n\n   // w[y] - w[x]\n   T diff(int x, int y)\
    \ { return Abel::op(get_potential(y), Abel::inv(get_potential(x))); }\n\n   int\
    \ count() { return tCount; }  // 154012\n\n   int size(int a) {\n      // assert(0\
    \ <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\n   vector<vector<int>>\
    \ groups() {\n      vector<int> leader_buf(N), group_size(N);\n      for(int i\
    \ = 0; i < N; i++) {\n         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(N);\n      for(int i = 0; i < N; i++)\
    \ result[i].reserve(group_size[i]);\n      for(int i = 0; i < N; i++) result[leader_buf[i]].push_back(i);\n\
    \      result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>&\
    \ v) { return v.empty(); }),\n                   result.end());\n      return\
    \ result;\n   }  // 92d7ce\n\n   private:\n   void link(int x, int y, T w) {\n\
    \      if(x == y) return;\n      tCount--;\n      if(rank[x] < rank[y]) {\n  \
    \       swap(x, y);\n         w = Abel::inv(w);\n      }\n      p[x] += p[y];\n\
    \      p[y] = x;\n      if(rank[x] == rank[y]) rank[x]++;\n      tCount--;\n \
    \     potential[y] = w;\n   }\n};\n\n/*\nstruct Abel {\n   using T = int;\n  \
    \ static T e() { return 0; }\n   static T op(T a, T b) { return a + b; }\n   static\
    \ T inv(T a) { return -a; }\n};\n\npotential_dsu<Abel> dsu(N);\n*/\n"
  code: "// base: 650ffa\ntemplate<typename Abel> struct potential_dsu {\n   using\
    \ T = typename Abel::T;\n   int tCount;\n   vector<int> p, rank;\n   vector<T>\
    \ potential;\n   int N;\n   potential_dsu(int size) {\n      N = size;\n     \
    \ p.resize(N, -1);\n      rank.resize(N, 0);\n      potential.resize(N, Abel::e());\n\
    \      tCount = N;\n   }\n\n   bool same(int x, int y) { return leader(x) == leader(y);\
    \ }\n\n   // w[y] - w[x] = w\n   void merge(int x, int y, T w) {\n      w = Abel::op(w,\
    \ get_potential(x));\n      w = Abel::op(w, Abel::inv(get_potential(y)));\n  \
    \    link(leader(x), leader(y), w);\n   }\n\n   int leader(int x) {\n      if(p[x]\
    \ < 0) return x;\n      int l = leader(p[x]);\n      potential[x] = Abel::op(potential[x],\
    \ potential[p[x]]);\n      return p[x] = l;\n   }\n\n   T get_potential(int x)\
    \ {\n      leader(x);\n      return potential[x];\n   }\n\n   // w[y] - w[x]\n\
    \   T diff(int x, int y) { return Abel::op(get_potential(y), Abel::inv(get_potential(x)));\
    \ }\n\n   int count() { return tCount; }  // 154012\n\n   int size(int a) {\n\
    \      // assert(0 <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(N), group_size(N);\n\
    \      for(int i = 0; i < N; i++) {\n         leader_buf[i] = leader(i);\n   \
    \      group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(N);\n\
    \      for(int i = 0; i < N; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < N; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // 92d7ce\n\n   private:\n\
    \   void link(int x, int y, T w) {\n      if(x == y) return;\n      tCount--;\n\
    \      if(rank[x] < rank[y]) {\n         swap(x, y);\n         w = Abel::inv(w);\n\
    \      }\n      p[x] += p[y];\n      p[y] = x;\n      if(rank[x] == rank[y]) rank[x]++;\n\
    \      tCount--;\n      potential[y] = w;\n   }\n};\n\n/*\nstruct Abel {\n   using\
    \ T = int;\n   static T e() { return 0; }\n   static T op(T a, T b) { return a\
    \ + b; }\n   static T inv(T a) { return -a; }\n};\n\npotential_dsu<Abel> dsu(N);\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/potential_dsu.hpp
  requiredBy: []
  timestamp: '2024-12-13 15:27:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/potential_dsu.test.3.cpp
  - test/data-structure/potential_dsu.test.cpp
  - test/data-structure/potential_dsu.test.2.cpp
documentation_of: src/data-structure/potential_dsu.hpp
layout: document
redirect_from:
- /library/src/data-structure/potential_dsu.hpp
- /library/src/data-structure/potential_dsu.hpp.html
title: src/data-structure/potential_dsu.hpp
---
