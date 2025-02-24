---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/barlekamp_massey.test.cpp
    title: test/FPS/barlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPS/bostan_mori.test.cpp
    title: test/FPS/bostan_mori.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/bostan_mori.hpp\"\n// find [x^N] P(x)/Q(x), O(K\
    \ log K log N)\n// deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1\nmm BostanMori(vector<mm>\
    \ P, vector<mm> Q, ll N) {\n   const int d = Q.size();\n   for (; N; N >>= 1)\
    \ {\n      auto Q_neg = Q;\n      for (size_t i = 1; i < Q.size(); i += 2) Q_neg[i]\
    \ *= -1;\n      P = conv(P, Q_neg);\n      Q = conv(Q, Q_neg);\n      for (size_t\
    \ i = N & 1; i < P.size(); i += 2) P[i >> 1] = P[i];\n      for (size_t i = 0;\
    \ i < Q.size(); i += 2) Q[i >> 1] = Q[i];\n      P.resize(d - 1);\n      Q.resize(d);\n\
    \   }\n   return P[0];\n}\n"
  code: "// find [x^N] P(x)/Q(x), O(K log K log N)\n// deg(Q(x)) = K, deg(P(x)) <\
    \ K, Q[0] = 1\nmm BostanMori(vector<mm> P, vector<mm> Q, ll N) {\n   const int\
    \ d = Q.size();\n   for (; N; N >>= 1) {\n      auto Q_neg = Q;\n      for (size_t\
    \ i = 1; i < Q.size(); i += 2) Q_neg[i] *= -1;\n      P = conv(P, Q_neg);\n  \
    \    Q = conv(Q, Q_neg);\n      for (size_t i = N & 1; i < P.size(); i += 2) P[i\
    \ >> 1] = P[i];\n      for (size_t i = 0; i < Q.size(); i += 2) Q[i >> 1] = Q[i];\n\
    \      P.resize(d - 1);\n      Q.resize(d);\n   }\n   return P[0];\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/bostan_mori.hpp
  requiredBy: []
  timestamp: '2025-02-23 17:34:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/barlekamp_massey.test.cpp
  - test/FPS/bostan_mori.test.cpp
documentation_of: src/FPS/bostan_mori.hpp
layout: document
redirect_from:
- /library/src/FPS/bostan_mori.hpp
- /library/src/FPS/bostan_mori.hpp.html
title: src/FPS/bostan_mori.hpp
---
