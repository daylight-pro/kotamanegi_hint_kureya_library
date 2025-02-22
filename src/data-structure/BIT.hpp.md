---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/mo.test.cpp
    title: test/algorithm/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/BIT.test.cpp
    title: test/data-structure/BIT.test.cpp
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
  bundledCode: "#line 1 \"src/data-structure/BIT.hpp\"\nstruct BIT {\n   vector<ll>\
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
  path: src/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2025-01-03 11:14:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range_tree.test.cpp
  - test/data-structure/BIT.test.cpp
  - test/data-structure/range_tree.test.2.cpp
  - test/algorithm/mo.test.cpp
  - test/graph/tree/hld.test.3.cpp
  - test/graph/tree/hld.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
title: BIT (Fenwick Tree)
---

- 参考実装：[AC Library](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/fenwicktree.hpp)

## 使い方

1 点加算・区間和ができるデータ構造

- `BIT(ll n)`：長さ $n$ の配列を作る
- `void add(ll i, ll x)`：`A[i] += x` を行う
- `ll sum(ll r)`：`sum(A[:r])` を求める
- `ll sum(ll l, ll r)`：`sum(A[l:r])` を求める

計算量 $O(\log n)$ / クエリ
