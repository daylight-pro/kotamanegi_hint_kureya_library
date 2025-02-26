---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/persistent_uf.test.cpp
    title: test/data-structure/persistent_uf.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/persistent-uf.hpp\"\nstruct PersistentUnionFind\
    \ {\n   PersistentArray<int, 3> data;\n\n   PersistentUnionFind() {}\n\n   PersistentUnionFind(int\
    \ sz) { data.build(vector<int>(sz, -1)); }\n\n   int find(int k) {\n      int\
    \ p = data.get(k);\n      return p >= 0 ? find(p) : k;\n   }\n\n   int size(int\
    \ k) { return (-data.get(find(k))); }\n\n   bool unite(int x, int y) {\n     \
    \ x = find(x);\n      y = find(y);\n      if(x == y) return false;\n      auto\
    \ u = data.get(x);\n      auto v = data.get(y);\n\n      if(u < v) {\n       \
    \  auto a = data.mutable_get(x);\n         *a += v;\n         auto b = data.mutable_get(y);\n\
    \         *b = x;\n      } else {\n         auto a = data.mutable_get(y);\n  \
    \       *a += u;\n         auto b = data.mutable_get(x);\n         *b = y;\n \
    \     }\n      return true;\n   }\n};\n"
  code: "struct PersistentUnionFind {\n   PersistentArray<int, 3> data;\n\n   PersistentUnionFind()\
    \ {}\n\n   PersistentUnionFind(int sz) { data.build(vector<int>(sz, -1)); }\n\n\
    \   int find(int k) {\n      int p = data.get(k);\n      return p >= 0 ? find(p)\
    \ : k;\n   }\n\n   int size(int k) { return (-data.get(find(k))); }\n\n   bool\
    \ unite(int x, int y) {\n      x = find(x);\n      y = find(y);\n      if(x ==\
    \ y) return false;\n      auto u = data.get(x);\n      auto v = data.get(y);\n\
    \n      if(u < v) {\n         auto a = data.mutable_get(x);\n         *a += v;\n\
    \         auto b = data.mutable_get(y);\n         *b = x;\n      } else {\n  \
    \       auto a = data.mutable_get(y);\n         *a += u;\n         auto b = data.mutable_get(x);\n\
    \         *b = y;\n      }\n      return true;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/persistent-uf.hpp
  requiredBy: []
  timestamp: '2025-02-26 00:49:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/persistent_uf.test.cpp
documentation_of: src/data-structure/persistent-uf.hpp
layout: document
redirect_from:
- /library/src/data-structure/persistent-uf.hpp
- /library/src/data-structure/persistent-uf.hpp.html
title: src/data-structure/persistent-uf.hpp
---
