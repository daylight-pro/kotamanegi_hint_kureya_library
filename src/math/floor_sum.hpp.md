---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/floor_sum.test.cpp
    title: test/math/floor_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/min_of_mod_of_linear.test.cpp
    title: test/math/min_of_mod_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/floor_sum.hpp\"\nll floor_sum(const ll& n, const\
    \ ll& m, ll a, ll b) {\n   ll ret = 0;\n   if(a >= m) ret += (n - 1) * n * (a\
    \ / m) / 2, a %= m;\n   if(b >= m) ret += n * (b / m), b %= m;\n   ll y = (a *\
    \ n + b) / m;\n   if(y == 0) return ret;\n   ll x = y * m - b;\n   ret += (n -\
    \ (x + a - 1) / a) * y;\n   ret += floor_sum(y, a, m, (a - x % a) % a);\n   return\
    \ ret;\n}\n"
  code: "ll floor_sum(const ll& n, const ll& m, ll a, ll b) {\n   ll ret = 0;\n  \
    \ if(a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n   if(b >= m) ret += n\
    \ * (b / m), b %= m;\n   ll y = (a * n + b) / m;\n   if(y == 0) return ret;\n\
    \   ll x = y * m - b;\n   ret += (n - (x + a - 1) / a) * y;\n   ret += floor_sum(y,\
    \ a, m, (a - x % a) % a);\n   return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-12-05 15:57:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/min_of_mod_of_linear.test.cpp
  - test/math/floor_sum.test.cpp
documentation_of: src/math/floor_sum.hpp
layout: document
redirect_from:
- /library/src/math/floor_sum.hpp
- /library/src/math/floor_sum.hpp.html
title: src/math/floor_sum.hpp
---
