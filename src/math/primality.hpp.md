---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/primality.test.cpp
    title: test/math/primality.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/rho.test.cpp
    title: test/math/rho.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/primality.hpp\"\nbool is_prime(ll N) {\n   if(N\
    \ == 2) return true;\n   if(N == 1 || N % 2 == 0) return false;\n   ll s = 0;\n\
    \   ll d = N - 1;\n   while(d % 2 == 0) {\n      s++;\n      d /= 2;\n   }\n \
    \  vector<ll> tests = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};\n   for(auto\
    \ a : tests) {\n      if(a == N) continue;\n      ll X = modpow(a, d, N);\n  \
    \    int r = 0;\n      if(X == 1) { continue; }\n      while(X != N - 1) {\n \
    \        X = modpow(X, 2, N);\n         r++;\n         if(X == 1 || r == s) return\
    \ false;\n      }\n   }\n   return true;\n}\n"
  code: "bool is_prime(ll N) {\n   if(N == 2) return true;\n   if(N == 1 || N % 2\
    \ == 0) return false;\n   ll s = 0;\n   ll d = N - 1;\n   while(d % 2 == 0) {\n\
    \      s++;\n      d /= 2;\n   }\n   vector<ll> tests = {2, 3, 5, 7, 11, 13, 17,\
    \ 19, 23, 29, 31, 37};\n   for(auto a : tests) {\n      if(a == N) continue;\n\
    \      ll X = modpow(a, d, N);\n      int r = 0;\n      if(X == 1) { continue;\
    \ }\n      while(X != N - 1) {\n         X = modpow(X, 2, N);\n         r++;\n\
    \         if(X == 1 || r == s) return false;\n      }\n   }\n   return true;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primality.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:21:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rho.test.cpp
  - test/math/primality.test.cpp
documentation_of: src/math/primality.hpp
layout: document
redirect_from:
- /library/src/math/primality.hpp
- /library/src/math/primality.hpp.html
title: src/math/primality.hpp
---
