---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/3d_mo.test.cpp
    title: test/algorithm/3d_mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/3d_mo.hpp\"\nstruct Mo_3D {\n   int width;\n\
    \   vector<int> left, right, index, order;\n   vector<bool> v;\n   function<void(int)>\
    \ add, del;\n\n   Mo_3D(int N, int Q) : order(Q), v(N) { width = max<int>(1, pow(N,\
    \ 2.0 / 3.0)); }\n   void insert(int idx, int l, int r) {\n      index.push_back(idx);\n\
    \      left.emplace_back(l);\n      right.emplace_back(r);\n   }\n\n   void run(const\
    \ auto& add, const auto& del, const auto& rem, const auto& add_query, const auto&\
    \ del_query) {\n      this->add = add;\n      this->del = del;\n      order.resize(size(left));\n\
    \      iota(all(order), 0);\n      sort(all(order), [&](int a, int b) -> bool\
    \ {\n         if(left[a] / width != left[b] / width) return left[a] < left[b];\n\
    \         if(right[a] / width != right[b] / width) return ((right[a] < right[b])\
    \ ^ (left[a] / width % 2));\n         return bool((index[a] < index[b]) ^ (right[a]\
    \ / width % 2));\n      });\n      int time = 0, nl = 0, nr = 0;\n      for(auto\
    \ idx : order) {\n         while(time < index[idx]) add_query(time++, this);\n\
    \         while(time > index[idx]) del_query(--time, this);\n         while(nl\
    \ > left[idx]) distribute(--nl);\n         while(nr < right[idx]) distribute(nr++);\n\
    \         while(nl < left[idx]) distribute(nl++);\n         while(nr > right[idx])\
    \ distribute(--nr);\n         rem(index[idx]);\n      }\n   }\n\n   void distribute(int\
    \ idx) {\n      if(v[idx]) del(idx);\n      else add(idx);\n      v[idx] = !v[idx];\n\
    \   }\n};\n"
  code: "struct Mo_3D {\n   int width;\n   vector<int> left, right, index, order;\n\
    \   vector<bool> v;\n   function<void(int)> add, del;\n\n   Mo_3D(int N, int Q)\
    \ : order(Q), v(N) { width = max<int>(1, pow(N, 2.0 / 3.0)); }\n   void insert(int\
    \ idx, int l, int r) {\n      index.push_back(idx);\n      left.emplace_back(l);\n\
    \      right.emplace_back(r);\n   }\n\n   void run(const auto& add, const auto&\
    \ del, const auto& rem, const auto& add_query, const auto& del_query) {\n    \
    \  this->add = add;\n      this->del = del;\n      order.resize(size(left));\n\
    \      iota(all(order), 0);\n      sort(all(order), [&](int a, int b) -> bool\
    \ {\n         if(left[a] / width != left[b] / width) return left[a] < left[b];\n\
    \         if(right[a] / width != right[b] / width) return ((right[a] < right[b])\
    \ ^ (left[a] / width % 2));\n         return bool((index[a] < index[b]) ^ (right[a]\
    \ / width % 2));\n      });\n      int time = 0, nl = 0, nr = 0;\n      for(auto\
    \ idx : order) {\n         while(time < index[idx]) add_query(time++, this);\n\
    \         while(time > index[idx]) del_query(--time, this);\n         while(nl\
    \ > left[idx]) distribute(--nl);\n         while(nr < right[idx]) distribute(nr++);\n\
    \         while(nl < left[idx]) distribute(nl++);\n         while(nr > right[idx])\
    \ distribute(--nr);\n         rem(index[idx]);\n      }\n   }\n\n   void distribute(int\
    \ idx) {\n      if(v[idx]) del(idx);\n      else add(idx);\n      v[idx] = !v[idx];\n\
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/3d_mo.hpp
  requiredBy: []
  timestamp: '2024-12-19 19:21:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/3d_mo.test.cpp
documentation_of: src/algorithm/3d_mo.hpp
layout: document
redirect_from:
- /library/src/algorithm/3d_mo.hpp
- /library/src/algorithm/3d_mo.hpp.html
title: src/algorithm/3d_mo.hpp
---
