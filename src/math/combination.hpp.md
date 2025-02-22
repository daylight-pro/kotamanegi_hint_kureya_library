---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/lagrange_polynomial.test.cpp
    title: test/math/lagrange_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/combination.hpp\"\nstruct Combination {\n   ll\
    \ C_MOD;\n   vector<ll> fac, finv, inv;\n   Combination(ll n, ll mod) : C_MOD(mod)\
    \ {\n      n = max(n, 2LL);\n      fac.resize(n, 0);\n      finv.resize(n, 0);\n\
    \      inv.resize(n, 0);\n      fac[0] = fac[1] = finv[0] = finv[1] = inv[1] =\
    \ 1;\n      for(int i = 2; i < n; i ++) {\n         fac[i] = fac[i - 1] * i %\
    \ mod;\n         inv[i] = mod - inv[mod % i] * (mod / i) % mod;\n         finv[i]\
    \ = finv[i - 1] * inv[i] % mod;\n      }\n   }\n   ll com(ll n, ll k) {\n    \
    \  if(n < k || n < 0 || k < 0) return 0;\n      return fac[n] * (finv[k] * finv[n\
    \ - k] % C_MOD) % C_MOD;\n   }\n};\n"
  code: "struct Combination {\n   ll C_MOD;\n   vector<ll> fac, finv, inv;\n   Combination(ll\
    \ n, ll mod) : C_MOD(mod) {\n      n = max(n, 2LL);\n      fac.resize(n, 0);\n\
    \      finv.resize(n, 0);\n      inv.resize(n, 0);\n      fac[0] = fac[1] = finv[0]\
    \ = finv[1] = inv[1] = 1;\n      for(int i = 2; i < n; i ++) {\n         fac[i]\
    \ = fac[i - 1] * i % mod;\n         inv[i] = mod - inv[mod % i] * (mod / i) %\
    \ mod;\n         finv[i] = finv[i - 1] * inv[i] % mod;\n      }\n   }\n   ll com(ll\
    \ n, ll k) {\n      if(n < k || n < 0 || k < 0) return 0;\n      return fac[n]\
    \ * (finv[k] * finv[n - k] % C_MOD) % C_MOD;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy: []
  timestamp: '2025-02-21 23:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/lagrange_polynomial.test.cpp
documentation_of: src/math/combination.hpp
layout: document
redirect_from:
- /library/src/math/combination.hpp
- /library/src/math/combination.hpp.html
title: src/math/combination.hpp
---
