---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/two_sat.test.cpp
    title: test/graph/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/two_sat.hpp\"\nstruct two_sat {\n   public:\n\
    \   two_sat() : _n(0), scc(0) {}\n   two_sat(int n) : _n(n), scc(2 * n), _answer(n)\
    \ {}\n\n   void add_clause(int i, bool f, int j, bool g) {\n      // assert(0\
    \ <= i && i < _n);\n      // assert(0 <= j && j < _n);\n      scc.add_edge(2 *\
    \ i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n      scc.add_edge(2 * j + (g ? 0 :\
    \ 1), 2 * i + (f ? 1 : 0));\n   }\n\n   bool satisfiable() {\n      scc.scc();\n\
    \      auto comp = scc.get_comp();\n      for(int i = 0; i < _n; i++) {\n    \
    \     if(comp[2 * i] == comp[2 * i + 1]) return false;\n         _answer[i] =\
    \ comp[2 * i] < comp[2 * i + 1];\n      }\n      return true;\n   }\n\n   vector<bool>\
    \ answer() { return _answer; }\n\n   private:\n   int _n;\n   vector<bool> _answer;\n\
    \   scc_graph scc;\n};\n"
  code: "struct two_sat {\n   public:\n   two_sat() : _n(0), scc(0) {}\n   two_sat(int\
    \ n) : _n(n), scc(2 * n), _answer(n) {}\n\n   void add_clause(int i, bool f, int\
    \ j, bool g) {\n      // assert(0 <= i && i < _n);\n      // assert(0 <= j &&\
    \ j < _n);\n      scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n  \
    \    scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n   }\n\n   bool\
    \ satisfiable() {\n      scc.scc();\n      auto comp = scc.get_comp();\n     \
    \ for(int i = 0; i < _n; i++) {\n         if(comp[2 * i] == comp[2 * i + 1]) return\
    \ false;\n         _answer[i] = comp[2 * i] < comp[2 * i + 1];\n      }\n    \
    \  return true;\n   }\n\n   vector<bool> answer() { return _answer; }\n\n   private:\n\
    \   int _n;\n   vector<bool> _answer;\n   scc_graph scc;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/two_sat.hpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/two_sat.test.cpp
documentation_of: src/graph/two_sat.hpp
layout: document
redirect_from:
- /library/src/graph/two_sat.hpp
- /library/src/graph/two_sat.hpp.html
title: src/graph/two_sat.hpp
---
