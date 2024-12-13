---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/ccw.test.cpp
    title: test/geometry/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/crosspoint.test.cpp
    title: test/geometry/crosspoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/diameter.test.cpp
    title: test/geometry/diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersect.test.cpp
    title: test/geometry/intersect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/polygon_point_containment.test.cpp
    title: test/geometry/polygon_point_containment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/geometry/etc.hpp\"\n// 1: a-b\u304B\u3089\u898B\u3066\
    a-c\u304C\u53CD\u6642\u8A08\u56DE\u308A\n// -1: a-b\u304B\u3089\u898B\u3066a-c\u304C\
    \u6642\u8A08\u56DE\u308A\n// 0: a-c-b\u304C\u3053\u306E\u9806\u3067\u76F4\u7DDA\
    \n// 2: c-a-b\u306E\u9806\u3067\u76F4\u7DDA\n// -2: a-b-c\u306E\u9806\u3067\u76F4\
    \u7DDA\n\nint ccw(const Point& a, const Point& b, const Point& c) {\n   if(cross(b\
    \ - a, c - a) > EPS) return 1;\n   if(cross(b - a, c - a) < -EPS) return -1;\n\
    \   if(dot(b - a, c - a) < -EPS) return 2;\n   if(norm(b - a) < norm(c - a) -\
    \ EPS) return -2;\n   return 0;\n}  // 6f1927\n\nPoint projection(const Point&\
    \ p, const Line& l) {\n   double t = dot(p - l[0], l[1] - l[0]) / norm(l[1] -\
    \ l[0]);\n   return l[0] + t * (l[1] - l[0]);\n}  // b9dbd7\n\nPoint reflection(const\
    \ Point& p, const Line& l) { return 2.0 * projection(p, l) - p; }\n// 65ba76\n\
    \n// point and line intersection\nbool isinterPL(const Point& p, const Line& l)\
    \ { return abs(p - projection(p, l)) < EPS; }\n// e9d393\n\n// point and segment\
    \ intersection\nbool isinterPS(const Point& p, const Line& s) { return ccw(s[0],\
    \ s[1], p) == 0; }\n// 79c17b\n\n// two lines intersection\nbool isinterLL(const\
    \ Line& l, const Line& m) {\n   return abs(cross(l[1] - l[0], m[1] - m[0])) >\
    \ EPS || abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;\n}  // b58dbd\n\n// two segments\
    \ intersection\nbool isinterSS(const Line& s, const Line& t) {\n   if(norm(s[1]\
    \ - s[0]) < EPS) return isinterPS(s[0], t);\n   if(norm(t[1] - t[0]) < EPS) return\
    \ isinterPS(t[0], s);\n   return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1])\
    \ <= 0) && (ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);\n}  // a499ea\n\
    \ndouble distancePL(const Point& p, const Line& l) { return abs(p - projection(p,\
    \ l)); }\n// c77772\n\ndouble distancePS(const Point& p, const Line& s) {\n  \
    \ Point h = projection(p, s);\n   if(isinterPS(h, s)) return abs(p - h);\n   return\
    \ min(abs(p - s[0]), abs(p - s[1]));\n}  // 3bd780\n\ndouble distanceLL(const\
    \ Line& l, const Line& m) {\n   if(isinterLL(l, m)) return 0;\n   return distancePL(l[0],\
    \ m);\n}  // ab4ace\n\ndouble distanceSS(const Line& s, const Line& t) {\n   if(isinterSS(s,\
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
    }  // 52fb34\n\ndouble diameter(const vector<Point> ps) {\n   int n = (int)ps.size();\n\
    \   int si = 0, sj = 0;\n   for(int i = 1; i < n; i++) {\n      if(ps[i].Y > ps[si].Y)\
    \ si = i;\n      if(ps[i].Y < ps[sj].Y) sj = i;\n   }\n\n   double res = 0;\n\
    \   int i = si, j = sj;\n   do {\n      res = max(res, abs(ps[i] - ps[j]));\n\
    \      if(cross(ps[(i + 1) % n] - ps[i], ps[(j + 1) % n] - ps[j]) < 0) i = (i\
    \ + 1) % n;\n      else j = (j + 1) % n;\n   } while(i != si || j != sj);\n  \
    \ return res;\n}  // ea6b63\n\n// 2: inside, 1: border, 0: outside\nint contains(const\
    \ vector<Point>& ps, const Point& p) {\n   int n = ps.size();\n   bool in = false;\n\
    \   for(int i = 0; i < n; i++) {\n      Point a = ps[i] - p, b = ps[(i + 1) %\
    \ n] - p;\n      if(a.Y > b.Y) swap(a, b);\n      if(a.Y <= EPS && EPS < b.Y &&\
    \ cross(a, b) < -EPS) in = !in;\n      if(abs(cross(a, b)) < EPS && dot(a, b)\
    \ < EPS) return 1;\n   }\n   return in ? 2 : 0;\n}  // fd7e87\n"
  code: "// 1: a-b\u304B\u3089\u898B\u3066a-c\u304C\u53CD\u6642\u8A08\u56DE\u308A\n\
    // -1: a-b\u304B\u3089\u898B\u3066a-c\u304C\u6642\u8A08\u56DE\u308A\n// 0: a-c-b\u304C\
    \u3053\u306E\u9806\u3067\u76F4\u7DDA\n// 2: c-a-b\u306E\u9806\u3067\u76F4\u7DDA\
    \n// -2: a-b-c\u306E\u9806\u3067\u76F4\u7DDA\n\nint ccw(const Point& a, const\
    \ Point& b, const Point& c) {\n   if(cross(b - a, c - a) > EPS) return 1;\n  \
    \ if(cross(b - a, c - a) < -EPS) return -1;\n   if(dot(b - a, c - a) < -EPS) return\
    \ 2;\n   if(norm(b - a) < norm(c - a) - EPS) return -2;\n   return 0;\n}  // 6f1927\n\
    \nPoint projection(const Point& p, const Line& l) {\n   double t = dot(p - l[0],\
    \ l[1] - l[0]) / norm(l[1] - l[0]);\n   return l[0] + t * (l[1] - l[0]);\n}  //\
    \ b9dbd7\n\nPoint reflection(const Point& p, const Line& l) { return 2.0 * projection(p,\
    \ l) - p; }\n// 65ba76\n\n// point and line intersection\nbool isinterPL(const\
    \ Point& p, const Line& l) { return abs(p - projection(p, l)) < EPS; }\n// e9d393\n\
    \n// point and segment intersection\nbool isinterPS(const Point& p, const Line&\
    \ s) { return ccw(s[0], s[1], p) == 0; }\n// 79c17b\n\n// two lines intersection\n\
    bool isinterLL(const Line& l, const Line& m) {\n   return abs(cross(l[1] - l[0],\
    \ m[1] - m[0])) > EPS || abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;\n}  // b58dbd\n\
    \n// two segments intersection\nbool isinterSS(const Line& s, const Line& t) {\n\
    \   if(norm(s[1] - s[0]) < EPS) return isinterPS(s[0], t);\n   if(norm(t[1] -\
    \ t[0]) < EPS) return isinterPS(t[0], s);\n   return (ccw(s[0], s[1], t[0]) *\
    \ ccw(s[0], s[1], t[1]) <= 0) && (ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1])\
    \ <= 0);\n}  // a499ea\n\ndouble distancePL(const Point& p, const Line& l) { return\
    \ abs(p - projection(p, l)); }\n// c77772\n\ndouble distancePS(const Point& p,\
    \ const Line& s) {\n   Point h = projection(p, s);\n   if(isinterPS(h, s)) return\
    \ abs(p - h);\n   return min(abs(p - s[0]), abs(p - s[1]));\n}  // 3bd780\n\n\
    double distanceLL(const Line& l, const Line& m) {\n   if(isinterLL(l, m)) return\
    \ 0;\n   return distancePL(l[0], m);\n}  // ab4ace\n\ndouble distanceSS(const\
    \ Line& s, const Line& t) {\n   if(isinterSS(s, t)) return 0;\n   return min(min(distancePS(s[0],\
    \ t), distancePS(s[1], t)), min(distancePS(t[0], s), distancePS(t[1], s)));\n\
    }  // c284e5\n\n// if(ans){ x = p->X; y = q->Y} else {cout << \"not cross\"}\n\
    optional<Point> crosspoint(const Line& l, const Line& m) {\n   double d = cross(m[1]\
    \ - m[0], l[1] - l[0]);\n   if(abs(d) < EPS) return nullopt;\n   return l[0] +\
    \ (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d;\n}  // 687c0c\n\ndouble\
    \ area(const vector<Point>& ps) {\n   double res = 0;\n   for(int i = 0; i < size(ps);\
    \ i++) res += cross(ps[i], ps[(i + 1) % size(ps)]);\n   return res / 2;\n}  //\
    \ 3b832b\n\nbool is_convex(vector<Point>& ps) {\n   int n = (int)ps.size();\n\
    \   for(int i = 0; i < n; ++i) {\n      if(ccw(ps[i], ps[(i + 1) % n], ps[(i +\
    \ 2) % n]) == -1) return false;\n   }\n   return true;\n}  // 52fb34\n\ndouble\
    \ diameter(const vector<Point> ps) {\n   int n = (int)ps.size();\n   int si =\
    \ 0, sj = 0;\n   for(int i = 1; i < n; i++) {\n      if(ps[i].Y > ps[si].Y) si\
    \ = i;\n      if(ps[i].Y < ps[sj].Y) sj = i;\n   }\n\n   double res = 0;\n   int\
    \ i = si, j = sj;\n   do {\n      res = max(res, abs(ps[i] - ps[j]));\n      if(cross(ps[(i\
    \ + 1) % n] - ps[i], ps[(j + 1) % n] - ps[j]) < 0) i = (i + 1) % n;\n      else\
    \ j = (j + 1) % n;\n   } while(i != si || j != sj);\n   return res;\n}  // ea6b63\n\
    \n// 2: inside, 1: border, 0: outside\nint contains(const vector<Point>& ps, const\
    \ Point& p) {\n   int n = ps.size();\n   bool in = false;\n   for(int i = 0; i\
    \ < n; i++) {\n      Point a = ps[i] - p, b = ps[(i + 1) % n] - p;\n      if(a.Y\
    \ > b.Y) swap(a, b);\n      if(a.Y <= EPS && EPS < b.Y && cross(a, b) < -EPS)\
    \ in = !in;\n      if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;\n \
    \  }\n   return in ? 2 : 0;\n}  // fd7e87"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/etc.hpp
  requiredBy: []
  timestamp: '2024-12-14 06:06:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/is_convex.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/polygon_point_containment.test.cpp
  - test/geometry/ccw.test.cpp
  - test/geometry/crosspoint.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/area.test.cpp
  - test/geometry/intersect.test.cpp
  - test/geometry/diameter.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
documentation_of: src/geometry/etc.hpp
layout: document
redirect_from:
- /library/src/geometry/etc.hpp
- /library/src/geometry/etc.hpp.html
title: src/geometry/etc.hpp
---
