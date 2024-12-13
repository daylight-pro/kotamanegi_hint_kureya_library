---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull.test.cpp
    title: test/geometry/convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/geometry/convex_hull.hpp\"\nvector<Point> convex_hull(vector<Point>&\
    \ ps, bool collinear = false) {\n   int n = ps.size();\n   if(n <= 1) return ps;\n\
    \   sort(ps.begin(), ps.end(),\n        [&EPS](const Point& a, const Point& b)\
    \ { return abs(a.X - b.X) > EPS ? a.X < b.X : a.Y < b.Y; });\n   vector<Point>\
    \ hull(2 * n);\n   double th = collinear ? -EPS : EPS;\n   int k = 0;\n   for(int\
    \ i = 0; i < n; i++) {\n      if(k >= 2) {\n         while(cross(hull[k - 1] -\
    \ hull[k - 2], ps[i] - hull[k - 2]) < th) {\n            k--;\n            if(k\
    \ < 2) break;\n         }\n      }\n      if(k < 1 || abs(hull[k - 1] - ps[i])\
    \ > EPS) {\n         hull[k] = ps[i];\n         k++;\n      }\n   }\n   int t\
    \ = k + 1;\n   for(int i = n - 2; i >= 0; i--) {\n      if(k >= t) {\n       \
    \  while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k - 2]) < th) {\n     \
    \       k--;\n            if(k < t) break;\n         }\n      }\n      if(k <\
    \ 1 || abs(hull[k - 1] - ps[i]) > EPS) {\n         hull[k] = ps[i];\n        \
    \ k++;\n      }\n   }\n   hull.resize(max(1, k - 1));\n   return hull;\n}\n"
  code: "vector<Point> convex_hull(vector<Point>& ps, bool collinear = false) {\n\
    \   int n = ps.size();\n   if(n <= 1) return ps;\n   sort(ps.begin(), ps.end(),\n\
    \        [&EPS](const Point& a, const Point& b) { return abs(a.X - b.X) > EPS\
    \ ? a.X < b.X : a.Y < b.Y; });\n   vector<Point> hull(2 * n);\n   double th =\
    \ collinear ? -EPS : EPS;\n   int k = 0;\n   for(int i = 0; i < n; i++) {\n  \
    \    if(k >= 2) {\n         while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k\
    \ - 2]) < th) {\n            k--;\n            if(k < 2) break;\n         }\n\
    \      }\n      if(k < 1 || abs(hull[k - 1] - ps[i]) > EPS) {\n         hull[k]\
    \ = ps[i];\n         k++;\n      }\n   }\n   int t = k + 1;\n   for(int i = n\
    \ - 2; i >= 0; i--) {\n      if(k >= t) {\n         while(cross(hull[k - 1] -\
    \ hull[k - 2], ps[i] - hull[k - 2]) < th) {\n            k--;\n            if(k\
    \ < t) break;\n         }\n      }\n      if(k < 1 || abs(hull[k - 1] - ps[i])\
    \ > EPS) {\n         hull[k] = ps[i];\n         k++;\n      }\n   }\n   hull.resize(max(1,\
    \ k - 1));\n   return hull;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2024-12-14 05:43:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/convex_hull.test.cpp
documentation_of: src/geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/src/geometry/convex_hull.hpp
- /library/src/geometry/convex_hull.hpp.html
title: src/geometry/convex_hull.hpp
---
