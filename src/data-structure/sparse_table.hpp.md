---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/sparse_table.test.cpp
    title: test/data-structure/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/sparse_table.hpp\"\ntemplate<typename\
    \ T, auto op> struct sparse_table {\n   vector<vector<T>> st;\n   vector<int>\
    \ lg;\n\n   sparse_table(const vector<T>& v) {\n      int b = 0;\n      while((1\
    \ << b) <= v.size()) b++;\n      st.assign(b, vector<T>(1 << b));\n      for(int\
    \ i = 0; i < size(v); i++) { st[0][i] = v[i]; }\n      for(int i = 1; i < b; i++)\
    \ {\n         for(int j = 0; j + (1 << i) <= (1 << b); j++) st[i][j] = op(st[i\
    \ - 1][j], st[i - 1][j + (1 << (i - 1))]);\n      }\n      lg.resize(v.size()\
    \ + 1);\n      for(int i = 2; i < size(lg); i++) lg[i] = lg[i >> 1] + 1;\n   }\n\
    \n   inline T prod(int l, int r) {\n      int b = lg[r - l];\n      return op(st[b][l],\
    \ st[b][r - (1 << b)]);\n   }\n};\n"
  code: "template<typename T, auto op> struct sparse_table {\n   vector<vector<T>>\
    \ st;\n   vector<int> lg;\n\n   sparse_table(const vector<T>& v) {\n      int\
    \ b = 0;\n      while((1 << b) <= v.size()) b++;\n      st.assign(b, vector<T>(1\
    \ << b));\n      for(int i = 0; i < size(v); i++) { st[0][i] = v[i]; }\n     \
    \ for(int i = 1; i < b; i++) {\n         for(int j = 0; j + (1 << i) <= (1 <<\
    \ b); j++) st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n     \
    \ }\n      lg.resize(v.size() + 1);\n      for(int i = 2; i < size(lg); i++) lg[i]\
    \ = lg[i >> 1] + 1;\n   }\n\n   inline T prod(int l, int r) {\n      int b = lg[r\
    \ - l];\n      return op(st[b][l], st[b][r - (1 << b)]);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-12-12 19:04:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/sparse_table.test.cpp
documentation_of: src/data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/src/data-structure/sparse_table.hpp
- /library/src/data-structure/sparse_table.hpp.html
title: src/data-structure/sparse_table.hpp
---
