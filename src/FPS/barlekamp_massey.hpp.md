---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/barlekamp_massey.test.cpp
    title: test/FPS/barlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/barlekamp_massey.hpp\"\nvector<mm> BerlekampMassey(const\
    \ vector<mm>& s) {\n   const int N = (int)s.size();\n   vector<mm> b, c;\n   b.reserve(N\
    \ + 1);\n   c.reserve(N + 1);\n   b.push_back(mm(1));\n   c.push_back(mm(1));\n\
    \   mm y = mm(1);\n   for(int ed = 1; ed <= N; ed++) {\n      int l = int(c.size()),\
    \ m = int(b.size());\n      mm x = 0;\n      for(int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n      b.emplace_back(mm(0));\n      m++;\n      if(x.x ==\
    \ 0) continue;\n      mm freq = x / y;\n      if(l < m) {\n         auto tmp =\
    \ c;\n         c.insert(begin(c), m - l, mm(0));\n         for(int i = 0; i <\
    \ m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n         b = tmp;\n         y\
    \ = x;\n      } else {\n         for(int i = 0; i < m; i++) c[l - 1 - i] -= freq\
    \ * b[m - 1 - i];\n      }\n   }\n   reverse(begin(c), end(c));\n   return c;\n\
    }\n"
  code: "vector<mm> BerlekampMassey(const vector<mm>& s) {\n   const int N = (int)s.size();\n\
    \   vector<mm> b, c;\n   b.reserve(N + 1);\n   c.reserve(N + 1);\n   b.push_back(mm(1));\n\
    \   c.push_back(mm(1));\n   mm y = mm(1);\n   for(int ed = 1; ed <= N; ed++) {\n\
    \      int l = int(c.size()), m = int(b.size());\n      mm x = 0;\n      for(int\
    \ i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n      b.emplace_back(mm(0));\n\
    \      m++;\n      if(x.x == 0) continue;\n      mm freq = x / y;\n      if(l\
    \ < m) {\n         auto tmp = c;\n         c.insert(begin(c), m - l, mm(0));\n\
    \         for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n  \
    \       b = tmp;\n         y = x;\n      } else {\n         for(int i = 0; i <\
    \ m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n      }\n   }\n   reverse(begin(c),\
    \ end(c));\n   return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/barlekamp_massey.hpp
  requiredBy: []
  timestamp: '2025-02-24 10:33:49+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/barlekamp_massey.test.cpp
documentation_of: src/FPS/barlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/FPS/barlekamp_massey.hpp
- /library/src/FPS/barlekamp_massey.hpp.html
title: src/FPS/barlekamp_massey.hpp
---
