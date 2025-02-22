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
  bundledCode: "#line 1 \"src/math/lagrange_polynomial.hpp\"\ntemplate<typename T>\
    \ T lagrange_polynomial(const vector<T>& y, ll t, ll mod = 1000000007) {\n   int\
    \ n = y.size() - 1;\n   if(t <= n) return y[t];\n   T ret(0);\n   Combination\
    \ comb(n + 1, mod);\n   vector<T> dp(n + 1, 1), pd(n + 1, 1);\n   for(int i =\
    \ 0; i < n; i++) dp[i + 1] = dp[i] * (t - i);\n   for(int i = n; i > 0; i--) pd[i\
    \ - 1] = pd[i] * (t - i);\n   for(int i = 0; i <= n; i++) {\n      T tmp = y[i]\
    \ * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];\n      ret -= ((n - i) &\
    \ 1 ? tmp : T(0) - tmp);\n   }\n   return ret;\n}\n"
  code: "template<typename T> T lagrange_polynomial(const vector<T>& y, ll t, ll mod\
    \ = 1000000007) {\n   int n = y.size() - 1;\n   if(t <= n) return y[t];\n   T\
    \ ret(0);\n   Combination comb(n + 1, mod);\n   vector<T> dp(n + 1, 1), pd(n +\
    \ 1, 1);\n   for(int i = 0; i < n; i++) dp[i + 1] = dp[i] * (t - i);\n   for(int\
    \ i = n; i > 0; i--) pd[i - 1] = pd[i] * (t - i);\n   for(int i = 0; i <= n; i++)\
    \ {\n      T tmp = y[i] * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];\n \
    \     ret -= ((n - i) & 1 ? tmp : T(0) - tmp);\n   }\n   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/lagrange_polynomial.hpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/lagrange_polynomial.test.cpp
documentation_of: src/math/lagrange_polynomial.hpp
layout: document
redirect_from:
- /library/src/math/lagrange_polynomial.hpp
- /library/src/math/lagrange_polynomial.hpp.html
title: src/math/lagrange_polynomial.hpp
---
