---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/eratos.test.cpp
    title: test/math/eratos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/eratos.hpp\"\nvoid eratos(int n, vector<bool>&\
    \ isprime) {\n   isprime = vector<bool>(n + 1, true);\n   isprime[0] = false;\n\
    \   isprime[1] = false;\n   int last = ((int)sqrt(n)) + 1;\n   for(int i = 2;\
    \ i < last; i++) {\n      if(isprime[i]) {\n         int j = i + i;\n        \
    \ while(j <= n) {\n            isprime[j] = false;\n            j += i;\n    \
    \     }\n      }\n   }\n}\n"
  code: "void eratos(int n, vector<bool>& isprime) {\n   isprime = vector<bool>(n\
    \ + 1, true);\n   isprime[0] = false;\n   isprime[1] = false;\n   int last = ((int)sqrt(n))\
    \ + 1;\n   for(int i = 2; i < last; i++) {\n      if(isprime[i]) {\n         int\
    \ j = i + i;\n         while(j <= n) {\n            isprime[j] = false;\n    \
    \        j += i;\n         }\n      }\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/eratos.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:36:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/eratos.test.cpp
documentation_of: src/math/eratos.hpp
layout: document
redirect_from:
- /library/src/math/eratos.hpp
- /library/src/math/eratos.hpp.html
title: src/math/eratos.hpp
---
