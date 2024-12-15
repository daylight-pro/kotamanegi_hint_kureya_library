---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/base.hpp
    title: src/geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/etc.hpp
    title: src/geometry/etc.hpp
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
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B
  bundledCode: "#line 1 \"test/geometry/diameter.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B\"\
    \n#define ERROR \"1e-8\"\n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n#line\
    \ 1 \"src/geometry/base.hpp\"\nusing Point = complex<double>;\nusing Line = vector<Point>;\n\
    \n#define X real()\n#define Y imag()\nconst double EPS = 1e-10;\n\ninline double\
    \ dot(const Point& a, const Point& b) { return a.X * b.X + a.Y * b.Y; }\ninline\
    \ double cross(const Point& a, const Point& b) { return a.X * b.Y - a.Y * b.X;\
    \ }\ninline double abs(const Point& a) { return sqrt(dot(a, a)); }\n#line 1 \"\
    src/geometry/etc.hpp\"\n// 1: a-b\u304B\u3089\u898B\u3066a-c\u304C\u53CD\u6642\
    \u8A08\u56DE\u308A\n// -1: a-b\u304B\u3089\u898B\u3066a-c\u304C\u6642\u8A08\u56DE\
    \u308A\n// 0: a-c-b\u304C\u3053\u306E\u9806\u3067\u76F4\u7DDA\n// 2: c-a-b\u306E\
    \u9806\u3067\u76F4\u7DDA\n// -2: a-b-c\u306E\u9806\u3067\u76F4\u7DDA\n\nint ccw(const\
    \ Point& a, const Point& b, const Point& c) {\n   if(cross(b - a, c - a) > EPS)\
    \ return 1;\n   if(cross(b - a, c - a) < -EPS) return -1;\n   if(dot(b - a, c\
    \ - a) < -EPS) return 2;\n   if(norm(b - a) < norm(c - a) - EPS) return -2;\n\
    \   return 0;\n}  // 6f1927\n\nPoint projection(const Point& p, const Line& l)\
    \ {\n   double t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n   return\
    \ l[0] + t * (l[1] - l[0]);\n}  // b9dbd7\n\nPoint reflection(const Point& p,\
    \ const Line& l) { return 2.0 * projection(p, l) - p; }\n// 65ba76\n\n// point\
    \ and line intersection\nbool isinterPL(const Point& p, const Line& l) { return\
    \ abs(p - projection(p, l)) < EPS; }\n// e9d393\n\n// point and segment intersection\n\
    bool isinterPS(const Point& p, const Line& s) { return ccw(s[0], s[1], p) == 0;\
    \ }\n// 79c17b\n\n// two lines intersection\nbool isinterLL(const Line& l, const\
    \ Line& m) {\n   return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || abs(cross(l[1]\
    \ - l[0], m[0] - l[0])) < EPS;\n}  // b58dbd\n\n// two segments intersection\n\
    bool isinterSS(const Line& s, const Line& t) {\n   if(norm(s[1] - s[0]) < EPS)\
    \ return isinterPS(s[0], t);\n   if(norm(t[1] - t[0]) < EPS) return isinterPS(t[0],\
    \ s);\n   return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0) && (ccw(t[0],\
    \ t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);\n}  // a499ea\n\ndouble distancePL(const\
    \ Point& p, const Line& l) { return abs(p - projection(p, l)); }\n// c77772\n\n\
    double distancePS(const Point& p, const Line& s) {\n   Point h = projection(p,\
    \ s);\n   if(isinterPS(h, s)) return abs(p - h);\n   return min(abs(p - s[0]),\
    \ abs(p - s[1]));\n}  // 3bd780\n\ndouble distanceLL(const Line& l, const Line&\
    \ m) {\n   if(isinterLL(l, m)) return 0;\n   return distancePL(l[0], m);\n}  //\
    \ ab4ace\n\ndouble distanceSS(const Line& s, const Line& t) {\n   if(isinterSS(s,\
    \ t)) return 0;\n   return min(min(distancePS(s[0], t), distancePS(s[1], t)),\
    \ min(distancePS(t[0], s), distancePS(t[1], s)));\n}  // c284e5\n\n// if(ans){\
    \ x = p->X; y = q->Y} else {cout << \"not cross\"}\noptional<Point> crosspoint(const\
    \ Line& l, const Line& m) {\n   double d = cross(m[1] - m[0], l[1] - l[0]);\n\
    \   if(abs(d) < EPS) return nullopt;\n   return l[0] + (l[1] - l[0]) * cross(m[1]\
    \ - m[0], m[1] - l[0]) / d;\n}  // 687c0c\n\ndouble area(const vector<Point>&\
    \ ps) {\n   double res = 0;\n   for(int i = 0; i < size(ps); i++) res += cross(ps[i],\
    \ ps[(i + 1) % size(ps)]);\n   return res / 2;\n}  // 3b832b\n\nbool is_convex(vector<Point>&\
    \ ps) {\n   int n = (int)ps.size();\n   for(int i = 0; i < n; ++i) {\n      if(ccw(ps[i],\
    \ ps[(i + 1) % n], ps[(i + 2) % n]) == -1) return false;\n   }\n   return true;\n\
    }  // 52fb34\n\ntuple<double, int, int> diameter(const vector<Point> ps) {\n \
    \  int n = (int)ps.size();\n   int si = 0, sj = 0;\n   for(int i = 1; i < n; i++)\
    \ {\n      if(ps[i].Y > ps[si].Y) si = i;\n      if(ps[i].Y < ps[sj].Y) sj = i;\n\
    \   }\n\n   double res = 0;\n   int i = si, j = sj;\n   int ri = i, rj = j;\n\
    \   do {\n      if(chmax(res, abs(ps[i] - ps[j]))) {\n         ri = i;\n     \
    \    rj = j;\n      }\n      if(cross(ps[(i + 1) % n] - ps[i], ps[(j + 1) % n]\
    \ - ps[j]) < 0) i = (i + 1) % n;\n      else j = (j + 1) % n;\n   } while(i !=\
    \ si || j != sj);\n   return {res, min(ri, rj), max(ri, rj)};\n}  // cae9ad\n\n\
    // 2: inside, 1: border, 0: outside\nint contains(const vector<Point>& ps, const\
    \ Point& p) {\n   int n = ps.size();\n   bool in = false;\n   for(int i = 0; i\
    \ < n; i++) {\n      Point a = ps[i] - p, b = ps[(i + 1) % n] - p;\n      if(a.Y\
    \ > b.Y) swap(a, b);\n      if(a.Y <= EPS && EPS < b.Y && cross(a, b) < -EPS)\
    \ in = !in;\n      if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;\n \
    \  }\n   return in ? 2 : 0;\n}  // fd7e87\n\ntuple<double, int, int> closest_pair(vector<Point>\
    \ ps) {\n   const double INF = 1e18;\n   int n = (int)ps.size();\n   if(n <= 1)\
    \ return {INF, -1, -1};\n\n   using P = pair<Point, int>;\n   vector<P> V(n);\n\
    \   for(int i = 0; i < n; i++) V[i] = {ps[i], i};\n   sort(begin(V), end(V), [](const\
    \ P& a, const P& b) {\n      if(fabs(a.first.X - b.first.X) > EPS) return a.first.X\
    \ < b.first.X;\n      else if(fabs(a.first.Y - b.first.Y) > EPS) return a.first.Y\
    \ < b.first.Y;\n      return a.second < b.second;\n   });\n\n   auto rec = [&](auto&&\
    \ self, auto it, int n) -> tuple<double, int, int> {\n      if(n <= 1) return\
    \ {INF, -1, -1};\n      int m = n / 2;\n      double x = it[m].first.X;\n    \
    \  auto [d1, a1, b1] = self(self, it, m);\n      auto [d2, a2, b2] = self(self,\
    \ it + m, n - m);\n      double d;\n      int a, b;\n      if(d1 < d2) {\n   \
    \      d = d1;\n         a = a1;\n         b = b1;\n      } else {\n         d\
    \ = d2;\n         a = a2;\n         b = b2;\n      }\n\n      inplace_merge(it,\
    \ it + m, it + n, [](const P& a, const P& b) { return a.first.Y < b.first.Y; });\n\
    \n      vector<P> vec;\n      for(int i = 0; i < n; i++) {\n         if(fabs(it[i].first.X\
    \ - x) >= d) continue;\n         for(int j = 0; j < size(vec); j++) {\n      \
    \      double dx = fabs(it[i].first.X - vec[size(vec) - j - 1].first.X);\n   \
    \         double dy = fabs(it[i].first.Y - vec[size(vec) - j - 1].first.Y);\n\
    \            if(dy >= d) break;\n            if(chmin(d, sqrt(dx * dx + dy * dy)))\
    \ {\n               a = it[i].second;\n               b = vec[size(vec) - j -\
    \ 1].second;\n            }\n         }\n         vec.emplace_back(it[i]);\n \
    \     }\n      return {d, a, b};\n   };\n   auto [d, a, b] = rec(rec, V.begin(),\
    \ n);\n   return {d, min(a, b), max(a, b)};\n}  // 12a9dc\n#line 7 \"test/geometry/diameter.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n\
    \   vector<Point> ps(N);\n   for(int i = 0; i < N; i++) {\n      double x, y;\n\
    \      cin >> x >> y;\n      ps[i] = Point(x, y);\n   }\n   auto [d, i, j] = diameter(ps);\n\
    \   cout << fixed << setprecision(10) << d << \"\\n\";\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B\"\
    \n#define ERROR \"1e-8\"\n\n#include \"test/template.hpp\"\n#include \"src/geometry/base.hpp\"\
    \n#include \"src/geometry/etc.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N;\n   cin >> N;\n   vector<Point> ps(N);\n   for(int i = 0; i < N; i++)\
    \ {\n      double x, y;\n      cin >> x >> y;\n      ps[i] = Point(x, y);\n  \
    \ }\n   auto [d, i, j] = diameter(ps);\n   cout << fixed << setprecision(10) <<\
    \ d << \"\\n\";\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/geometry/base.hpp
  - src/geometry/etc.hpp
  isVerificationFile: true
  path: test/geometry/diameter.test.cpp
  requiredBy: []
  timestamp: '2024-12-16 02:36:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/diameter.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/diameter.test.cpp
- /verify/test/geometry/diameter.test.cpp.html
title: test/geometry/diameter.test.cpp
---
