---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/min_of_mod_of_linear.test.cpp
    title: test/math/min_of_mod_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/min_of_mod_of_linear.hpp\"\n// depends on floor_sum\n\
    ll min_of_mod_of_linear(ll n, ll m, ll a, ll b) {\n    ll fsum = floor_sum(n,\
    \ m, a, b);\n    ll le = -1, ri = m - 1;\n    while(ri - le > 1) {\n       ll\
    \ mid = (le + ri) / 2;\n       if(floor_sum(n, m, a, b + (m - 1 - mid)) < fsum\
    \ + n) ri = mid;\n       else le = mid;\n    }\n    return ri;\n }\n"
  code: "// depends on floor_sum\nll min_of_mod_of_linear(ll n, ll m, ll a, ll b)\
    \ {\n    ll fsum = floor_sum(n, m, a, b);\n    ll le = -1, ri = m - 1;\n    while(ri\
    \ - le > 1) {\n       ll mid = (le + ri) / 2;\n       if(floor_sum(n, m, a, b\
    \ + (m - 1 - mid)) < fsum + n) ri = mid;\n       else le = mid;\n    }\n    return\
    \ ri;\n }"
  dependsOn: []
  isVerificationFile: false
  path: src/math/min_of_mod_of_linear.hpp
  requiredBy: []
  timestamp: '2025-02-23 00:00:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/min_of_mod_of_linear.test.cpp
documentation_of: src/math/min_of_mod_of_linear.hpp
layout: document
redirect_from:
- /library/src/math/min_of_mod_of_linear.hpp
- /library/src/math/min_of_mod_of_linear.hpp.html
title: src/math/min_of_mod_of_linear.hpp
---
