---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/min_plus_concave.test.cpp
    title: test/algorithm/min_plus_concave.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/min_plus_concave.hpp\"\n// b is concave\n\
    template<typename T> vector<T> minplus_conv_concave(vector<T> &a, vector<T> &b)\
    \ {\n   int n = a.size(), m = b.size();\n   if(min(n, m) == 0) return vector<T>\
    \ ();\n   int h = n + m - 1, w = n;\n   vector<int> ymin(h, 0), ymax(h, w - 1),\
    \ xmin(w), xmax(w);\n   for(int x = m; x < h; x ++) ymin[x] = x - m + 1;\n   for(int\
    \ x = 0; x <= h - m; x ++) ymax[x] = x;\n   iota(all(xmin), 0); iota(all(xmax),\
    \ m - 1);\n   vector<T> c(h, INF); // if long long\n   auto rec = [&](auto&& rec,\
    \ int x1, int x2, int y1, int y2) {\n      if(ymax[x1] >= y2 and y1 >= ymin[x2])\
    \ {\n         auto A = [&](int i, int j) { return a[y2 - j] + b[x1 + i - y2 +\
    \ j]; };\n         auto jmin = monotone_minima<T>(x2 - x1 + 1, y2 - y1 + 1, A);\n\
    \         for(int i = x1; i <= x2; i ++) chmin(c[i], A(i - x1, jmin[i - x1]));\n\
    \         return;\n      }\n      if((ll)(x2 - x1) * (y2 - y1) < 1000) {\n   \
    \      for(int x = x1; x <= x2; x ++) for(int y = max(ymin[x], y1); y <= min(ymax[x],\
    \ y2); y ++) chmin(c[x], a[y] + b[x - y]);\n         return;\n      }\n      if(x2\
    \ - x1 > y2 - y1) {\n         int xm = (x1 + x2) / 2;\n         int ny2 = min(ymax[xm],\
    \ y2), ny1 = max(ymin[xm], y1);\n         if(y1 <= ny2) rec(rec, x1, xm, y1, ny2);\n\
    \         if(ny1 <= y2) rec(rec, xm + 1, x2, ny1, y2);\n\t\t} else {\n       \
    \  int ym = (y1 + y2) / 2;\n         int nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym],\
    \ x1);\n         if(x1 <= nx2) rec(rec, x1, nx2, y1, ym);\n         if(nx1 <=\
    \ x2) rec(rec, nx1, x2, ym + 1, y2);\n      }\n\t};\n   rec(rec, 0, h - 1, 0,\
    \ w - 1);\n   return c;\n}\n"
  code: "// b is concave\ntemplate<typename T> vector<T> minplus_conv_concave(vector<T>\
    \ &a, vector<T> &b) {\n   int n = a.size(), m = b.size();\n   if(min(n, m) ==\
    \ 0) return vector<T> ();\n   int h = n + m - 1, w = n;\n   vector<int> ymin(h,\
    \ 0), ymax(h, w - 1), xmin(w), xmax(w);\n   for(int x = m; x < h; x ++) ymin[x]\
    \ = x - m + 1;\n   for(int x = 0; x <= h - m; x ++) ymax[x] = x;\n   iota(all(xmin),\
    \ 0); iota(all(xmax), m - 1);\n   vector<T> c(h, INF); // if long long\n   auto\
    \ rec = [&](auto&& rec, int x1, int x2, int y1, int y2) {\n      if(ymax[x1] >=\
    \ y2 and y1 >= ymin[x2]) {\n         auto A = [&](int i, int j) { return a[y2\
    \ - j] + b[x1 + i - y2 + j]; };\n         auto jmin = monotone_minima<T>(x2 -\
    \ x1 + 1, y2 - y1 + 1, A);\n         for(int i = x1; i <= x2; i ++) chmin(c[i],\
    \ A(i - x1, jmin[i - x1]));\n         return;\n      }\n      if((ll)(x2 - x1)\
    \ * (y2 - y1) < 1000) {\n         for(int x = x1; x <= x2; x ++) for(int y = max(ymin[x],\
    \ y1); y <= min(ymax[x], y2); y ++) chmin(c[x], a[y] + b[x - y]);\n         return;\n\
    \      }\n      if(x2 - x1 > y2 - y1) {\n         int xm = (x1 + x2) / 2;\n  \
    \       int ny2 = min(ymax[xm], y2), ny1 = max(ymin[xm], y1);\n         if(y1\
    \ <= ny2) rec(rec, x1, xm, y1, ny2);\n         if(ny1 <= y2) rec(rec, xm + 1,\
    \ x2, ny1, y2);\n\t\t} else {\n         int ym = (y1 + y2) / 2;\n         int\
    \ nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym], x1);\n         if(x1 <= nx2) rec(rec,\
    \ x1, nx2, y1, ym);\n         if(nx1 <= x2) rec(rec, nx1, x2, ym + 1, y2);\n \
    \     }\n\t};\n   rec(rec, 0, h - 1, 0, w - 1);\n   return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/min_plus_concave.hpp
  requiredBy: []
  timestamp: '2025-02-25 02:39:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/min_plus_concave.test.cpp
documentation_of: src/algorithm/min_plus_concave.hpp
layout: document
redirect_from:
- /library/src/algorithm/min_plus_concave.hpp
- /library/src/algorithm/min_plus_concave.hpp.html
title: src/algorithm/min_plus_concave.hpp
---
