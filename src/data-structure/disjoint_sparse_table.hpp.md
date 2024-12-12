---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/disjoint_sparse_table.test.2.cpp
    title: test/data-structure/disjoint_sparse_table.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/disjoint_sparse_table.test.cpp
    title: test/data-structure/disjoint_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/disjoint_sparse_table.hpp\"\ntemplate<typename\
    \ SG> struct disjoint_sparse_table {\n   using S = typename SG::S;\n   vector<vector<S>>\
    \ st;\n   vector<int> lg;\n\n   disjoint_sparse_table(const vector<S>& v) {\n\
    \      int b = 0;\n      while((1 << b) <= size(v)) b++;\n      st.assign(b, vector<S>(size(v)));\n\
    \      for(int i = 0; i < size(v); i++) st[0][i] = v[i];\n      for(int i = 1;\
    \ i < b; i++) {\n         int shift = 1 << i;\n         for(int j = 0; j < size(v);\
    \ j += shift << 1) {\n            int t = min(j + shift, (int)size(v));\n    \
    \        st[i][t - 1] = v[t - 1];\n            for(int k = t - 2; k >= j; k--)\
    \ st[i][k] = SG::op(v[k], st[i][k + 1]);\n            if(size(v) <= t) break;\n\
    \            st[i][t] = v[t];\n            for(int k = t + 1; k < min((int)size(v),\
    \ t + shift); k++) st[i][k] = SG::op(st[i][k - 1], v[k]);\n         }\n      }\n\
    \      lg.resize(1 << b);\n      for(int i = 2; i < size(lg); i++) lg[i] = lg[i\
    \ >> 1] + 1;\n   }\n   S prod(int l, int r) {\n      if(l >= --r) return st[0][l];\n\
    \      int b = lg[l ^ r];\n      return SG::op(st[b][l], st[b][r]);\n   }\n};\n"
  code: "template<typename SG> struct disjoint_sparse_table {\n   using S = typename\
    \ SG::S;\n   vector<vector<S>> st;\n   vector<int> lg;\n\n   disjoint_sparse_table(const\
    \ vector<S>& v) {\n      int b = 0;\n      while((1 << b) <= size(v)) b++;\n \
    \     st.assign(b, vector<S>(size(v)));\n      for(int i = 0; i < size(v); i++)\
    \ st[0][i] = v[i];\n      for(int i = 1; i < b; i++) {\n         int shift = 1\
    \ << i;\n         for(int j = 0; j < size(v); j += shift << 1) {\n           \
    \ int t = min(j + shift, (int)size(v));\n            st[i][t - 1] = v[t - 1];\n\
    \            for(int k = t - 2; k >= j; k--) st[i][k] = SG::op(v[k], st[i][k +\
    \ 1]);\n            if(size(v) <= t) break;\n            st[i][t] = v[t];\n  \
    \          for(int k = t + 1; k < min((int)size(v), t + shift); k++) st[i][k]\
    \ = SG::op(st[i][k - 1], v[k]);\n         }\n      }\n      lg.resize(1 << b);\n\
    \      for(int i = 2; i < size(lg); i++) lg[i] = lg[i >> 1] + 1;\n   }\n   S prod(int\
    \ l, int r) {\n      if(l >= --r) return st[0][l];\n      int b = lg[l ^ r];\n\
    \      return SG::op(st[b][l], st[b][r]);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2024-12-12 20:19:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/disjoint_sparse_table.test.2.cpp
  - test/data-structure/disjoint_sparse_table.test.cpp
documentation_of: src/data-structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/src/data-structure/disjoint_sparse_table.hpp
- /library/src/data-structure/disjoint_sparse_table.hpp.html
title: src/data-structure/disjoint_sparse_table.hpp
---
