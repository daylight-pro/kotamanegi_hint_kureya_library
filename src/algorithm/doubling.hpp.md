---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/doubling.test.cpp
    title: test/algorithm/doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/doubling.hpp\"\ntemplate<int L> struct Doubling\
    \ {\n   private:\n   vector<vector<int>> V;\n\n   public:\n   Doubling(const vector<int>&\
    \ v) {\n      int N = size(v);\n      V = vector<vector<int>>(L, vector<int>(N));\n\
    \      rep(i, 0, N) V[0][i] = v[i];\n      rep(i, 0, L - 1) rep(j, 0, N) {\n \
    \        if(V[i][j] != -1) V[i + 1][j] = V[i][V[i][j]];\n      }\n   }\n\n   int\
    \ jump(int from, ll k) {\n      for(int cnt = 0; k > 0; k >>= 1, ++cnt) {\n  \
    \       if((k & 1) && from != -1) from = V[cnt][from];\n      }\n      return\
    \ from;\n   }\n};\n"
  code: "template<int L> struct Doubling {\n   private:\n   vector<vector<int>> V;\n\
    \n   public:\n   Doubling(const vector<int>& v) {\n      int N = size(v);\n  \
    \    V = vector<vector<int>>(L, vector<int>(N));\n      rep(i, 0, N) V[0][i] =\
    \ v[i];\n      rep(i, 0, L - 1) rep(j, 0, N) {\n         if(V[i][j] != -1) V[i\
    \ + 1][j] = V[i][V[i][j]];\n      }\n   }\n\n   int jump(int from, ll k) {\n \
    \     for(int cnt = 0; k > 0; k >>= 1, ++cnt) {\n         if((k & 1) && from !=\
    \ -1) from = V[cnt][from];\n      }\n      return from;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/doubling.hpp
  requiredBy: []
  timestamp: '2024-12-09 20:05:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/doubling.test.cpp
documentation_of: src/algorithm/doubling.hpp
layout: document
redirect_from:
- /library/src/algorithm/doubling.hpp
- /library/src/algorithm/doubling.hpp.html
title: src/algorithm/doubling.hpp
---
