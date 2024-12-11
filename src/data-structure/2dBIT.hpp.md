---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/2dBIT.test.cpp
    title: test/data-structure/2dBIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/2dBIT.hpp\"\ntemplate<typename T> struct\
    \ BinaryIndexedTree2D {\n   int H, W;\n   vector<vector<T>> bit;\n\n   BinaryIndexedTree2D(int\
    \ H, int W) : H(H), W(W), bit(H + 3, vector<T>(W + 3, 0)) {}\n   void add(int\
    \ x, int y, T w) {\n      if(x < 0 || x >= H || y < 0 || y >= W) return;\n   \
    \   for(int a = (++y, ++x); a <= H; a += a & -a) {\n         for(int b = y; b\
    \ <= W; b += b & -b) { bit[a][b] += w; }\n      }\n   }\n\n   void imos(int x1,\
    \ int y1, int x2, int y2, T w) {\n      add(x1, y1, w);\n      add(x2, y2, w);\n\
    \      add(x1, y2, -w);\n      add(x2, y1, -w);\n   }\n\n   T sum(int x, int y)\
    \ {\n      if(x < 0 || x >= H || y < 0 || y >= W) return 0;\n      if(x >= H)\
    \ x = H - 1;\n      if(y >= W) y = W - 1;\n      T ret = 0;\n      for(int a =\
    \ (++y, ++x); a > 0; a -= a & -a) {\n         for(int b = y; b > 0; b -= b & -b)\
    \ { ret += bit[a][b]; }\n      }\n      return ret;\n   }\n\n   T sum(int x1,\
    \ int y1, int x2, int y2) {\n      return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2,\
    \ y1 - 1) + sum(x1 - 1, y1 - 1);\n   }\n};\n"
  code: "template<typename T> struct BinaryIndexedTree2D {\n   int H, W;\n   vector<vector<T>>\
    \ bit;\n\n   BinaryIndexedTree2D(int H, int W) : H(H), W(W), bit(H + 3, vector<T>(W\
    \ + 3, 0)) {}\n   void add(int x, int y, T w) {\n      if(x < 0 || x >= H || y\
    \ < 0 || y >= W) return;\n      for(int a = (++y, ++x); a <= H; a += a & -a) {\n\
    \         for(int b = y; b <= W; b += b & -b) { bit[a][b] += w; }\n      }\n \
    \  }\n\n   void imos(int x1, int y1, int x2, int y2, T w) {\n      add(x1, y1,\
    \ w);\n      add(x2, y2, w);\n      add(x1, y2, -w);\n      add(x2, y1, -w);\n\
    \   }\n\n   T sum(int x, int y) {\n      if(x < 0 || x >= H || y < 0 || y >= W)\
    \ return 0;\n      if(x >= H) x = H - 1;\n      if(y >= W) y = W - 1;\n      T\
    \ ret = 0;\n      for(int a = (++y, ++x); a > 0; a -= a & -a) {\n         for(int\
    \ b = y; b > 0; b -= b & -b) { ret += bit[a][b]; }\n      }\n      return ret;\n\
    \   }\n\n   T sum(int x1, int y1, int x2, int y2) {\n      return sum(x2, y2)\
    \ - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/2dBIT.hpp
  requiredBy: []
  timestamp: '2024-12-10 20:28:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/2dBIT.test.cpp
documentation_of: src/data-structure/2dBIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/2dBIT.hpp
- /library/src/data-structure/2dBIT.hpp.html
title: src/data-structure/2dBIT.hpp
---
