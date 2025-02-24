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
  bundledCode: "#line 1 \"test/math/modpow.hpp\"\nll modpow(ll a, ll n, ll MOD) {\n\
    \   using T = __int128_t;\n   // using T = ll;\n   T res = 1;\n   T mul = a;\n\
    \   mul %= MOD;\n   if(n < 0) {\n      n = -n;\n      mul = modinv(mul, MOD);\n\
    \   }\n   while(n > 0) {\n      if(n & 1) res = (res * mul) % MOD;\n      mul\
    \ = (mul * mul) % MOD;\n      n >>= 1;\n   }\n   return ll(res);\n}\n"
  code: "ll modpow(ll a, ll n, ll MOD) {\n   using T = __int128_t;\n   // using T\
    \ = ll;\n   T res = 1;\n   T mul = a;\n   mul %= MOD;\n   if(n < 0) {\n      n\
    \ = -n;\n      mul = modinv(mul, MOD);\n   }\n   while(n > 0) {\n      if(n &\
    \ 1) res = (res * mul) % MOD;\n      mul = (mul * mul) % MOD;\n      n >>= 1;\n\
    \   }\n   return ll(res);\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/math/modpow.hpp
  requiredBy: []
  timestamp: '2025-02-24 20:26:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rho.test.cpp
  - test/math/primality.test.cpp
documentation_of: test/math/modpow.hpp
layout: document
redirect_from:
- /library/test/math/modpow.hpp
- /library/test/math/modpow.hpp.html
title: test/math/modpow.hpp
---
