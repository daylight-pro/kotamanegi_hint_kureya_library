---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/undo_dsu.test.cpp
    title: test/data-structure/undo_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/undo_dsu.hpp\"\n// base: edf246\nstruct\
    \ undo_dsu {\n   private:\n   int _n;\n   vector<int> p;\n   stack<pair<int, int>>\
    \ history;\n\n   public:\n   undo_dsu() : _n(0) {}\n   explicit undo_dsu(int n)\
    \ : _n(n), p(n, -1) {}\n\n   int merge(int a, int b) {\n      // assert(0 <= a\
    \ && a < _n);\n      // assert(0 <= b && b < _n);\n      int x = leader(a), y\
    \ = leader(b);\n      if(x == y) {\n         history.emplace(x, p[x]);\n     \
    \    history.emplace(y, p[y]);\n         return x;\n      }\n      if(-p[x] <\
    \ -p[y]) swap(x, y);\n      history.emplace(x, p[x]);\n      history.emplace(y,\
    \ p[y]);\n      p[x] += p[y];\n      p[y] = x;\n      return x;\n   }\n\n   bool\
    \ same(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      return leader(a) == leader(b);\n   }\n\n   int leader(int\
    \ a) {\n      // assert(0 <= a && a < _n);\n      while(p[a] >= 0) a = p[a];\n\
    \      return a;\n   }\n\n   void undo() {\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n   }\n\n   int snapshot() { return history.size(); }\n\n\
    \   void rollback(int snapshot = 0) {\n      while(history.size() > snapshot)\
    \ undo();\n   }\n\n   int size(int a) {\n      // assert(0 <= a && a < _n);\n\
    \      return -p[leader(a)];\n   }  // 818fe7\n};\n"
  code: "// base: edf246\nstruct undo_dsu {\n   private:\n   int _n;\n   vector<int>\
    \ p;\n   stack<pair<int, int>> history;\n\n   public:\n   undo_dsu() : _n(0) {}\n\
    \   explicit undo_dsu(int n) : _n(n), p(n, -1) {}\n\n   int merge(int a, int b)\
    \ {\n      // assert(0 <= a && a < _n);\n      // assert(0 <= b && b < _n);\n\
    \      int x = leader(a), y = leader(b);\n      if(x == y) {\n         history.emplace(x,\
    \ p[x]);\n         history.emplace(y, p[y]);\n         return x;\n      }\n  \
    \    if(-p[x] < -p[y]) swap(x, y);\n      history.emplace(x, p[x]);\n      history.emplace(y,\
    \ p[y]);\n      p[x] += p[y];\n      p[y] = x;\n      return x;\n   }\n\n   bool\
    \ same(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      return leader(a) == leader(b);\n   }\n\n   int leader(int\
    \ a) {\n      // assert(0 <= a && a < _n);\n      while(p[a] >= 0) a = p[a];\n\
    \      return a;\n   }\n\n   void undo() {\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n   }\n\n   int snapshot() { return history.size(); }\n\n\
    \   void rollback(int snapshot = 0) {\n      while(history.size() > snapshot)\
    \ undo();\n   }\n\n   int size(int a) {\n      // assert(0 <= a && a < _n);\n\
    \      return -p[leader(a)];\n   }  // 818fe7\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/undo_dsu.hpp
  requiredBy: []
  timestamp: '2024-12-12 18:01:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/undo_dsu.test.cpp
documentation_of: src/data-structure/undo_dsu.hpp
layout: document
redirect_from:
- /library/src/data-structure/undo_dsu.hpp
- /library/src/data-structure/undo_dsu.hpp.html
title: src/data-structure/undo_dsu.hpp
---
