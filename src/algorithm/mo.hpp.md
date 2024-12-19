---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/mo.test.cpp
    title: test/algorithm/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/algorithm/tree_mo.test.cpp
    title: test/algorithm/tree_mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/mo.hpp\"\nstruct Mo {\n   int width;\n   vector<int>\
    \ left, right, order;\n   Mo(int N, int Q) : order(Q) {\n      width = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n      iota(all(order), 0);\n\
    \   }\n\n   void insert(int l, int r) {\n      left.emplace_back(l);\n      right.emplace_back(r);\n\
    \   }\n\n   void run(const auto& add_left,\n            const auto& add_right,\n\
    \            const auto& delete_left,\n            const auto& delete_right,\n\
    \            const auto& rem) {\n      sort(begin(order), end(order), [&](int\
    \ a, int b) {\n         int ablock = left[a] / width, bblock = left[b] / width;\n\
    \         if(ablock != bblock) return ablock < bblock;\n         return (ablock\
    \ & 1) ? right[a] > right[b] : right[a] < right[b];\n      });\n      int nl =\
    \ 0, nr = 0;\n      for(auto idx : order) {\n         while(nl > left[idx]) add_left(--nl);\n\
    \         while(nr < right[idx]) add_right(nr++);\n         while(nl < left[idx])\
    \ delete_left(nl++);\n         while(nr > right[idx]) delete_right(--nr);\n  \
    \       rem(idx);\n      }\n   }\n};\n"
  code: "struct Mo {\n   int width;\n   vector<int> left, right, order;\n   Mo(int\
    \ N, int Q) : order(Q) {\n      width = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(Q * 2.0 / 3.0)));\n      iota(all(order), 0);\n   }\n\n   void insert(int\
    \ l, int r) {\n      left.emplace_back(l);\n      right.emplace_back(r);\n   }\n\
    \n   void run(const auto& add_left,\n            const auto& add_right,\n    \
    \        const auto& delete_left,\n            const auto& delete_right,\n   \
    \         const auto& rem) {\n      sort(begin(order), end(order), [&](int a,\
    \ int b) {\n         int ablock = left[a] / width, bblock = left[b] / width;\n\
    \         if(ablock != bblock) return ablock < bblock;\n         return (ablock\
    \ & 1) ? right[a] > right[b] : right[a] < right[b];\n      });\n      int nl =\
    \ 0, nr = 0;\n      for(auto idx : order) {\n         while(nl > left[idx]) add_left(--nl);\n\
    \         while(nr < right[idx]) add_right(nr++);\n         while(nl < left[idx])\
    \ delete_left(nl++);\n         while(nr > right[idx]) delete_right(--nr);\n  \
    \       rem(idx);\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/mo.hpp
  requiredBy: []
  timestamp: '2024-12-16 16:28:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/mo.test.cpp
  - test/algorithm/tree_mo.test.cpp
documentation_of: src/algorithm/mo.hpp
layout: document
redirect_from:
- /library/src/algorithm/mo.hpp
- /library/src/algorithm/mo.hpp.html
title: src/algorithm/mo.hpp
---
