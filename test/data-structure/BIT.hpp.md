---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/mo.test.cpp
    title: test/algorithm/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_tree.test.2.cpp
    title: test/data-structure/range_tree.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_tree.test.cpp
    title: test/data-structure/range_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.3.cpp
    title: test/graph/tree/hld.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.cpp
    title: test/graph/tree/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/data-structure/BIT.hpp\"\nstruct BIT {\n   vector<ll>\
    \ a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i, ll x) {  // A[i] += x\n  \
    \    i++;\n      while(i < size(a)) {\n         a[i] += x;\n         i += i &\
    \ -i;\n      }\n   }\n   ll sum(ll r) {\n      ll s = 0;\n      while(r) {\n \
    \        s += a[r];\n         r -= r & -r;\n      }\n      return s;\n   }\n \
    \  ll sum(ll l, ll r) {  // sum of A[l, r)\n      return sum(r) - sum(l);\n  \
    \ }\n};\n"
  code: "struct BIT {\n   vector<ll> a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll\
    \ i, ll x) {  // A[i] += x\n      i++;\n      while(i < size(a)) {\n         a[i]\
    \ += x;\n         i += i & -i;\n      }\n   }\n   ll sum(ll r) {\n      ll s =\
    \ 0;\n      while(r) {\n         s += a[r];\n         r -= r & -r;\n      }\n\
    \      return s;\n   }\n   ll sum(ll l, ll r) {  // sum of A[l, r)\n      return\
    \ sum(r) - sum(l);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: test/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2025-02-23 00:18:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range_tree.test.cpp
  - test/data-structure/range_tree.test.2.cpp
  - test/algorithm/mo.test.cpp
  - test/graph/tree/hld.test.3.cpp
  - test/graph/tree/hld.test.cpp
documentation_of: test/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/test/data-structure/BIT.hpp
- /library/test/data-structure/BIT.hpp.html
title: test/data-structure/BIT.hpp
---
