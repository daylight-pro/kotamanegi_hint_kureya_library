---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: src/algorithm/mo.hpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/BIT.hpp
    title: test/data-structure/BIT.hpp
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/algorithm/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"test/data-structure/BIT.hpp\"\
    \nstruct BIT {\n   vector<ll> a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i,\
    \ ll x) {  // A[i] += x\n      i++;\n      while(i < size(a)) {\n         a[i]\
    \ += x;\n         i += i & -i;\n      }\n   }\n   ll sum(ll r) {\n      ll s =\
    \ 0;\n      while(r) {\n         s += a[r];\n         r -= r & -r;\n      }\n\
    \      return s;\n   }\n   ll sum(ll l, ll r) {  // sum of A[l, r)\n      return\
    \ sum(r) - sum(l);\n   }\n};\n#line 1 \"src/algorithm/mo.hpp\"\nstruct Mo {\n\
    \   int width;\n   vector<int> left, right, order;\n   Mo(int N, int Q) : order(Q)\
    \ {\n      width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n\
    \      iota(all(order), 0);\n   }\n\n   void insert(int l, int r) {\n      left.emplace_back(l);\n\
    \      right.emplace_back(r);\n   }\n\n   void run(const auto& add_left,\n   \
    \         const auto& add_right,\n            const auto& delete_left,\n     \
    \       const auto& delete_right,\n            const auto& rem) {\n      sort(begin(order),\
    \ end(order), [&](int a, int b) {\n         int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n         if(ablock != bblock) return ablock < bblock;\n\
    \         return (ablock & 1) ? right[a] > right[b] : right[a] < right[b];\n \
    \     });\n      int nl = 0, nr = 0;\n      for(auto idx : order) {\n        \
    \ while(nl > left[idx]) add_left(--nl);\n         while(nr < right[idx]) add_right(nr++);\n\
    \         while(nl < left[idx]) delete_left(nl++);\n         while(nr > right[idx])\
    \ delete_right(--nr);\n         rem(idx);\n      }\n   }\n};\n#line 6 \"test/algorithm/mo.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   vector<int> A(N);\n   for(auto& a : A) cin >> a;\n   vector<int>\
    \ inv(N, -1);\n   map<int, int> mp1;\n   for(int e : A) mp1[e]++;\n   {\n    \
    \  int id = 0;\n      for(auto [x, y] : mp1) {\n         inv[id] = x;\n      \
    \   mp1[x] = id++;\n      }\n      for(int i = 0; i < N; i++) { A[i] = mp1[A[i]];\
    \ }\n   }\n\n   Mo mo(N, Q);\n   BIT bit(N);\n   vector<ll> ans(Q);\n   ll cur\
    \ = 0;\n   auto add_left = [&](int idx) {\n      bit.add(A[idx], 1);\n      cur\
    \ += bit.sum(0, A[idx]);\n   };\n   auto add_right = [&](int idx) {\n      bit.add(A[idx],\
    \ 1);\n      cur += bit.sum(A[idx] + 1, N);\n   };\n   auto delete_left = [&](int\
    \ idx) {\n      cur -= bit.sum(0, A[idx]);\n      bit.add(A[idx], -1);\n   };\n\
    \   auto delete_right = [&](int idx) {\n      cur -= bit.sum(A[idx] + 1, N);\n\
    \      bit.add(A[idx], -1);\n   };\n   auto rem = [&](int idx) { ans[idx] = cur;\
    \ };\n   for(int i = 0; i < Q; i++) {\n      int l, r;\n      cin >> l >> r;\n\
    \      mo.insert(l, r);\n   }\n   mo.run(add_left, add_right, delete_left, delete_right,\
    \ rem);\n   for(int i = 0; i < Q; i++) cout << ans[i] << '\\n';\n\n   return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"test/template.hpp\"\n#include \"test/data-structure/BIT.hpp\"\n\
    #include \"src/algorithm/mo.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   vector<int> A(N);\n   for(auto& a : A) cin\
    \ >> a;\n   vector<int> inv(N, -1);\n   map<int, int> mp1;\n   for(int e : A)\
    \ mp1[e]++;\n   {\n      int id = 0;\n      for(auto [x, y] : mp1) {\n       \
    \  inv[id] = x;\n         mp1[x] = id++;\n      }\n      for(int i = 0; i < N;\
    \ i++) { A[i] = mp1[A[i]]; }\n   }\n\n   Mo mo(N, Q);\n   BIT bit(N);\n   vector<ll>\
    \ ans(Q);\n   ll cur = 0;\n   auto add_left = [&](int idx) {\n      bit.add(A[idx],\
    \ 1);\n      cur += bit.sum(0, A[idx]);\n   };\n   auto add_right = [&](int idx)\
    \ {\n      bit.add(A[idx], 1);\n      cur += bit.sum(A[idx] + 1, N);\n   };\n\
    \   auto delete_left = [&](int idx) {\n      cur -= bit.sum(0, A[idx]);\n    \
    \  bit.add(A[idx], -1);\n   };\n   auto delete_right = [&](int idx) {\n      cur\
    \ -= bit.sum(A[idx] + 1, N);\n      bit.add(A[idx], -1);\n   };\n   auto rem =\
    \ [&](int idx) { ans[idx] = cur; };\n   for(int i = 0; i < Q; i++) {\n      int\
    \ l, r;\n      cin >> l >> r;\n      mo.insert(l, r);\n   }\n   mo.run(add_left,\
    \ add_right, delete_left, delete_right, rem);\n   for(int i = 0; i < Q; i++) cout\
    \ << ans[i] << '\\n';\n\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - test/data-structure/BIT.hpp
  - src/algorithm/mo.hpp
  isVerificationFile: true
  path: test/algorithm/mo.test.cpp
  requiredBy: []
  timestamp: '2025-02-23 00:18:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/mo.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/mo.test.cpp
- /verify/test/algorithm/mo.test.cpp.html
title: test/algorithm/mo.test.cpp
---
