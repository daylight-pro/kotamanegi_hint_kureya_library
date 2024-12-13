---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/base.hpp
    title: src/geometry/base.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/geometry/base.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/geometry/base.hpp\"\
    \nusing Point = complex<double>;\nusing Line = vector<Point>;\n\n#define X real()\n\
    #define Y imag()\nconst double EPS = 1e-10;\n\ninline double dot(const Point&\
    \ a, const Point& b) { return a.X * b.X + a.Y * b.Y; }\ninline double cross(const\
    \ Point& a, const Point& b) { return a.X * b.Y - a.Y * b.X; }\ninline double abs(const\
    \ Point& a) { return sqrt(dot(a, a)); }\n#line 5 \"test/geometry/base.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   Point p(1, 2);\n   p\
    \ *= 3;\n   assert(p.X == 3);\n   assert(p.Y == 6);\n   puts(\"Hello World\");\n\
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/geometry/base.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   Point p(1, 2);\n   p *= 3;\n\
    \   assert(p.X == 3);\n   assert(p.Y == 6);\n   puts(\"Hello World\");\n   return\
    \ 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/geometry/base.hpp
  isVerificationFile: true
  path: test/geometry/base.test.cpp
  requiredBy: []
  timestamp: '2024-12-14 05:43:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/base.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/base.test.cpp
- /verify/test/geometry/base.test.cpp.html
title: test/geometry/base.test.cpp
---
