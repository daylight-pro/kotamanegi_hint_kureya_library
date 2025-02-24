---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/fps_sparse.test.2.cpp
    title: test/FPS/fps_sparse.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPS/fps_sparse.test.cpp
    title: test/FPS/fps_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/fps_sparse.hpp\"\nvector<mm> fps_inv_sparse(const\
    \ vector<pair<int, mm>> &dat, int n = -1) {\n   // assert(dat[0].first == 0 and\
    \ dat[0].second.x != 0);\n   if(n == -1) n = dat.back().first + 1;\n   vector<mm>\
    \ g(n);\n   mm g0 = dat[0].second.inv();\n   g[0] = g0;\n   for(int i = 1; i <\
    \ n; i ++) {\n      mm rhs = 0;\n      for(auto&& [k, fk] : dat) {\n         if(k\
    \ > i) break;\n         rhs -= fk * g[i - k];\n      }\n      g[i] = rhs * g0;\n\
    \   }\n   return g;\n}\n\nvector<mm> fps_exp_sparse(vector<mm>& f) {\n   if ((int)f.size()\
    \ == 0) return {mm(1)};\n   // assert(f[0].x == 0);\n   int N = f.size();\n  \
    \ vector<pair<int, mm>> dat;\n   for(int i = 1; i < N; i ++) if (f[i].x) dat.emplace_back(i\
    \ - 1, mm(i) * f[i]);\n   vector<mm> F(N);\n   F[0] = 1;\n   for(int n = 1; n\
    \ < N; n ++) {\n      mm rhs = 0;\n      for (auto&& [k, fk]: dat) {\n       \
    \  if (k > n - 1) break;\n         rhs += fk * F[n - 1 - k];\n      }\n      F[n]\
    \ = rhs * mm(n).inv();\n   }\n   return F;\n}\n"
  code: "vector<mm> fps_inv_sparse(const vector<pair<int, mm>> &dat, int n = -1) {\n\
    \   // assert(dat[0].first == 0 and dat[0].second.x != 0);\n   if(n == -1) n =\
    \ dat.back().first + 1;\n   vector<mm> g(n);\n   mm g0 = dat[0].second.inv();\n\
    \   g[0] = g0;\n   for(int i = 1; i < n; i ++) {\n      mm rhs = 0;\n      for(auto&&\
    \ [k, fk] : dat) {\n         if(k > i) break;\n         rhs -= fk * g[i - k];\n\
    \      }\n      g[i] = rhs * g0;\n   }\n   return g;\n}\n\nvector<mm> fps_exp_sparse(vector<mm>&\
    \ f) {\n   if ((int)f.size() == 0) return {mm(1)};\n   // assert(f[0].x == 0);\n\
    \   int N = f.size();\n   vector<pair<int, mm>> dat;\n   for(int i = 1; i < N;\
    \ i ++) if (f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);\n   vector<mm> F(N);\n\
    \   F[0] = 1;\n   for(int n = 1; n < N; n ++) {\n      mm rhs = 0;\n      for\
    \ (auto&& [k, fk]: dat) {\n         if (k > n - 1) break;\n         rhs += fk\
    \ * F[n - 1 - k];\n      }\n      F[n] = rhs * mm(n).inv();\n   }\n   return F;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/fps_sparse.hpp
  requiredBy: []
  timestamp: '2025-02-24 04:44:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/fps_sparse.test.2.cpp
  - test/FPS/fps_sparse.test.cpp
documentation_of: src/FPS/fps_sparse.hpp
layout: document
redirect_from:
- /library/src/FPS/fps_sparse.hpp
- /library/src/FPS/fps_sparse.hpp.html
title: src/FPS/fps_sparse.hpp
---
