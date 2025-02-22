---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/rollback_mo.test.cpp
    title: test/algorithm/rollback_mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/rollback_mo.hpp\"\nstruct Mo_rollback {\n\
    \   int width;\n   vector<int> left, right, order;\n   Mo_rollback(int N, int\
    \ Q) : order(Q) {\n      width = sqrt(N);\n      iota(all(order), 0);\n   }\n\n\
    \   void insert(int l, int r) {\n      left.emplace_back(l);\n      right.emplace_back(r);\n\
    \   }\n\n   void run(const auto& add_left,\n            const auto& add_right,\n\
    \            const auto& rem,\n            const auto& reset,\n            const\
    \ auto& snapshot,\n            const auto& rollback) {\n      sort(begin(order),\
    \ end(order), [&](int a, int b) {\n         int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n         if(ablock != bblock) return ablock < bblock;\n\
    \         return right[a] < right[b];\n      });\n      reset();\n      snapshot();\n\
    \      for(auto idx : order) {\n         if(right[idx] - left[idx] < width) {\n\
    \            for(int i = left[idx]; i < right[idx]; i++) add_right(i);\n     \
    \       rem(idx);\n            rollback();\n         }\n      }\n      int nr\
    \ = 0, last_block = -1;\n      for(auto idx : order) {\n         if(right[idx]\
    \ - left[idx] < width) continue;\n         int block = left[idx] / width;\n  \
    \       if(block != last_block) {\n            reset();\n            nr = (block\
    \ + 1) * width;\n            last_block = block;\n         }\n         while(nr\
    \ < right[idx]) add_right(nr++);\n         snapshot();\n         for(int j = (block\
    \ + 1) * width - 1; j >= left[idx]; j--) add_left(j);\n         rem(idx);\n  \
    \       rollback();\n      }\n   }\n};\n"
  code: "struct Mo_rollback {\n   int width;\n   vector<int> left, right, order;\n\
    \   Mo_rollback(int N, int Q) : order(Q) {\n      width = sqrt(N);\n      iota(all(order),\
    \ 0);\n   }\n\n   void insert(int l, int r) {\n      left.emplace_back(l);\n \
    \     right.emplace_back(r);\n   }\n\n   void run(const auto& add_left,\n    \
    \        const auto& add_right,\n            const auto& rem,\n            const\
    \ auto& reset,\n            const auto& snapshot,\n            const auto& rollback)\
    \ {\n      sort(begin(order), end(order), [&](int a, int b) {\n         int ablock\
    \ = left[a] / width, bblock = left[b] / width;\n         if(ablock != bblock)\
    \ return ablock < bblock;\n         return right[a] < right[b];\n      });\n \
    \     reset();\n      snapshot();\n      for(auto idx : order) {\n         if(right[idx]\
    \ - left[idx] < width) {\n            for(int i = left[idx]; i < right[idx]; i++)\
    \ add_right(i);\n            rem(idx);\n            rollback();\n         }\n\
    \      }\n      int nr = 0, last_block = -1;\n      for(auto idx : order) {\n\
    \         if(right[idx] - left[idx] < width) continue;\n         int block = left[idx]\
    \ / width;\n         if(block != last_block) {\n            reset();\n       \
    \     nr = (block + 1) * width;\n            last_block = block;\n         }\n\
    \         while(nr < right[idx]) add_right(nr++);\n         snapshot();\n    \
    \     for(int j = (block + 1) * width - 1; j >= left[idx]; j--) add_left(j);\n\
    \         rem(idx);\n         rollback();\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/rollback_mo.hpp
  requiredBy: []
  timestamp: '2024-12-16 16:28:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/rollback_mo.test.cpp
documentation_of: src/algorithm/rollback_mo.hpp
layout: document
redirect_from:
- /library/src/algorithm/rollback_mo.hpp
- /library/src/algorithm/rollback_mo.hpp.html
title: src/algorithm/rollback_mo.hpp
---
