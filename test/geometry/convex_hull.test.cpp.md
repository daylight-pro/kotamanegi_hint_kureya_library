---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/base.hpp
    title: src/geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: src/geometry/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
  bundledCode: "#line 1 \"test/geometry/convex_hull.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_convex_hull\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/geometry/base.hpp\"\nusing Point = complex<double>;\n\
    using Line = vector<Point>;\n\n#define X real()\n#define Y imag()\nconst double\
    \ EPS = 1e-10;\n\ninline double dot(const Point& a, const Point& b) { return a.X\
    \ * b.X + a.Y * b.Y; }\ninline double cross(const Point& a, const Point& b) {\
    \ return a.X * b.Y - a.Y * b.X; }\ninline double abs(const Point& a) { return\
    \ sqrt(dot(a, a)); }\n#line 1 \"src/geometry/convex_hull.hpp\"\nvector<Point>\
    \ convex_hull(vector<Point>& ps, bool collinear = false) {\n   int n = ps.size();\n\
    \   if(n <= 1) return ps;\n   sort(ps.begin(), ps.end(),\n        [&EPS](const\
    \ Point& a, const Point& b) { return abs(a.X - b.X) > EPS ? a.X < b.X : a.Y <\
    \ b.Y; });\n   vector<Point> hull(2 * n);\n   double th = collinear ? -EPS : EPS;\n\
    \   int k = 0;\n   for(int i = 0; i < n; i++) {\n      if(k >= 2) {\n        \
    \ while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k - 2]) < th) {\n      \
    \      k--;\n            if(k < 2) break;\n         }\n      }\n      if(k < 1\
    \ || abs(hull[k - 1] - ps[i]) > EPS) {\n         hull[k] = ps[i];\n         k++;\n\
    \      }\n   }\n   int t = k + 1;\n   for(int i = n - 2; i >= 0; i--) {\n    \
    \  if(k >= t) {\n         while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k\
    \ - 2]) < th) {\n            k--;\n            if(k < t) break;\n         }\n\
    \      }\n      if(k < 1 || abs(hull[k - 1] - ps[i]) > EPS) {\n         hull[k]\
    \ = ps[i];\n         k++;\n      }\n   }\n   hull.resize(max(1, k - 1));\n   return\
    \ hull;\n}\n#line 6 \"test/geometry/convex_hull.test.cpp\"\n\nint main() {\n \
    \  cin.tie(0)->sync_with_stdio(0);\n   cout << fixed << setprecision(10);\n  \
    \ int T;\n   cin >> T;\n   while(T--) {\n      int N;\n      cin >> N;\n     \
    \ vector<Point> ps(N);\n      for(int i = 0; i < N; i++) {\n         double x,\
    \ y;\n         cin >> x >> y;\n         ps[i] = Point(x, y);\n      }\n      auto\
    \ ans = convex_hull(ps);\n      cout << size(ans) << \"\\n\";\n      for(auto&\
    \ p : ans) cout << int(round(p.X)) << \" \" << int(round(p.Y)) << \"\\n\";\n \
    \  }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_convex_hull\"\n\n\
    #include \"test/template.hpp\"\n#include \"src/geometry/base.hpp\"\n#include \"\
    src/geometry/convex_hull.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   cout << fixed << setprecision(10);\n   int T;\n   cin >> T;\n   while(T--)\
    \ {\n      int N;\n      cin >> N;\n      vector<Point> ps(N);\n      for(int\
    \ i = 0; i < N; i++) {\n         double x, y;\n         cin >> x >> y;\n     \
    \    ps[i] = Point(x, y);\n      }\n      auto ans = convex_hull(ps);\n      cout\
    \ << size(ans) << \"\\n\";\n      for(auto& p : ans) cout << int(round(p.X)) <<\
    \ \" \" << int(round(p.Y)) << \"\\n\";\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/geometry/base.hpp
  - src/geometry/convex_hull.hpp
  isVerificationFile: true
  path: test/geometry/convex_hull.test.cpp
  requiredBy: []
  timestamp: '2024-12-14 05:43:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/convex_hull.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/convex_hull.test.cpp
- /verify/test/geometry/convex_hull.test.cpp.html
title: test/geometry/convex_hull.test.cpp
---
