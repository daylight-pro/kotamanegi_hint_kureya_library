---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/base.test.cpp
    title: test/geometry/base.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/ccw.test.cpp
    title: test/geometry/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/closest_pair.test.2.cpp
    title: test/geometry/closest_pair.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/closest_pair.test.cpp
    title: test/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull.test.cpp
    title: test/geometry/convex_hull.test.cpp
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
  bundledCode: '#line 1 "src/geometry/base.hpp"

    using Point = complex<double>;

    using Line = vector<Point>;


    #define X real()

    #define Y imag()

    const double EPS = 1e-10;


    inline double dot(const Point& a, const Point& b) { return a.X * b.X + a.Y * b.Y;
    }

    inline double cross(const Point& a, const Point& b) { return a.X * b.Y - a.Y *
    b.X; }

    inline double abs(const Point& a) { return sqrt(dot(a, a)); }

    '
  code: 'using Point = complex<double>;

    using Line = vector<Point>;


    #define X real()

    #define Y imag()

    const double EPS = 1e-10;


    inline double dot(const Point& a, const Point& b) { return a.X * b.X + a.Y * b.Y;
    }

    inline double cross(const Point& a, const Point& b) { return a.X * b.Y - a.Y *
    b.X; }

    inline double abs(const Point& a) { return sqrt(dot(a, a)); }

    '
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/base.hpp
  requiredBy: []
  timestamp: '2024-12-14 05:43:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/is_convex.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/polygon_point_containment.test.cpp
  - test/geometry/ccw.test.cpp
  - test/geometry/crosspoint.test.cpp
  - test/geometry/closest_pair.test.2.cpp
  - test/geometry/convex_hull.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/area.test.cpp
  - test/geometry/intersect.test.cpp
  - test/geometry/closest_pair.test.cpp
  - test/geometry/base.test.cpp
  - test/geometry/diameter.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
documentation_of: src/geometry/base.hpp
layout: document
redirect_from:
- /library/src/geometry/base.hpp
- /library/src/geometry/base.hpp.html
title: src/geometry/base.hpp
---
