---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/crt.test.cpp
    title: test/math/crt.test.cpp
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
  bundledCode: "#line 1 \"src/math/modinv.hpp\"\nll modinv(ll a, ll MOD) {\n   ll\
    \ b = MOD, u = 1, v = 0;\n   while(b) {\n      ll t = a / b;\n      a -= t * b;\n\
    \      swap(a, b);\n      u -= t * v;\n      swap(u, v);\n   }\n   u %= MOD;\n\
    \   if(u < 0) u += MOD;\n   return u;\n}\n"
  code: "ll modinv(ll a, ll MOD) {\n   ll b = MOD, u = 1, v = 0;\n   while(b) {\n\
    \      ll t = a / b;\n      a -= t * b;\n      swap(a, b);\n      u -= t * v;\n\
    \      swap(u, v);\n   }\n   u %= MOD;\n   if(u < 0) u += MOD;\n   return u;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modinv.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/crt.test.cpp
  - test/math/rho.test.cpp
  - test/math/primality.test.cpp
documentation_of: src/math/modinv.hpp
layout: document
redirect_from:
- /library/src/math/modinv.hpp
- /library/src/math/modinv.hpp.html
title: src/math/modinv.hpp
---
