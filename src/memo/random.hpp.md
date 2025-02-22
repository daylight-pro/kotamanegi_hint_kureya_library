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
  bundledCode: "#line 1 \"src/memo/random.hpp\"\nstruct rng {\n   mt19937 mt;\n  \
    \ rng() : mt(58) {}\n   int get(int a, int b) { // [a, b]\n      uniform_int_distribution<int>\
    \ dist(a, b);\n      return dist(mt);\n   }\n};\n"
  code: "struct rng {\n   mt19937 mt;\n   rng() : mt(58) {}\n   int get(int a, int\
    \ b) { // [a, b]\n      uniform_int_distribution<int> dist(a, b);\n      return\
    \ dist(mt);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/memo/random.hpp
  requiredBy: []
  timestamp: '2025-02-21 17:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/memo/random.hpp
layout: document
redirect_from:
- /library/src/memo/random.hpp
- /library/src/memo/random.hpp.html
title: src/memo/random.hpp
---
