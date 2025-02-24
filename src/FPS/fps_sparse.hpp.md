---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/fps_sparse.test.cpp
    title: test/FPS/fps_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/fps_sparse.hpp\"\nusing vm = vector<mm>;\nvm fps_inv_sparse(vm&\
    \ f) {\n   int n = f.size();\n   vector<pair<int, mm>> dat;\n   for(int i = 0;\
    \ i < n; i++)\n      if(f[i].x) dat.emplace_back(i, f[i]);\n   vm g(n);\n   mm\
    \ g0 = f[0].inv();\n   g[0] = g0;\n   for(int i = 1; i < n; i++) {\n      mm rhs\
    \ = 0;\n      for(auto&& [k, fk] : dat) {\n         if(k > i) break;\n       \
    \  rhs -= fk * g[i - k];\n      }\n      g[i] = rhs * g0;\n   }\n   return g;\n\
    }\nvm fps_exp_sparse(vm& f) {\n   if((int)f.size() == 0) return {mm(1)};\n   int\
    \ N = f.size();\n   vector<pair<int, mm>> dat;\n   for(int i = 1; i < N; i++)\n\
    \      if(f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);\n   vm F(N);\n   F[0]\
    \ = 1;\n   for(int n = 1; n < N; n++) {\n      mm rhs = 0;\n      for(auto&& [k,\
    \ fk] : dat) {\n         if(k > n - 1) break;\n         rhs += fk * F[n - 1 -\
    \ k];\n      }\n      F[n] = rhs * mm(n).inv();\n   }\n   return F;\n}\nvm fps_log_sparse(vm&\
    \ f) {\n   int N = f.size();\n   vector<pair<int, mm>> dat;\n   for(int i = 1;\
    \ i < N; i++)\n      if(f[i].x) dat.emplace_back(i, f[i]);\n   vm F(N), g(N -\
    \ 1);\n   for(int n = 0; n < N - 1; n++) {\n      mm rhs = mm(n + 1) * f[n + 1];\n\
    \      for(auto&& [i, fi] : dat) {\n         if(i > n) break;\n         rhs -=\
    \ fi * g[n - i];\n      }\n      g[n] = rhs;\n      F[n + 1] = rhs * mm(n + 1).inv();\n\
    \   }\n   return F;\n}\nvm fps_pow_product(vm& f, vm& g, mm n, mm m) {\n   int\
    \ N = f.size();\n   using P = pair<int, mm>;\n   vector<P> dat_f, dat_g;\n   for(int\
    \ i = 0; i < (int)f.size(); i++)\n      if(f[i].x) dat_f.emplace_back(i, f[i]);\n\
    \   for(int i = 0; i < (int)g.size(); i++)\n      if(g[i].x) dat_g.emplace_back(i,\
    \ g[i]);\n   vm a(N), b(N);\n   for(auto&& [i, x] : dat_f)\n      for(auto&& [j,\
    \ y] : dat_g) {\n         if(i + j >= N + 1) continue;\n         mm xy = x * y;\n\
    \         if(i + j < N) a[i + j] += xy;\n         if(0 < i + j && i + j <= N)\
    \ b[i + j - 1] -= xy * (n * mm(i) + m * mm(j));\n      }\n   vector<P> dat_a,\
    \ dat_b;\n   for(int i = 1; i < N; i++)\n      if(a[i].x) dat_a.emplace_back(i,\
    \ a[i]);\n   for(int i = 0; i < N; i++)\n      if(b[i].x) dat_b.emplace_back(i,\
    \ b[i]);\n   vm F(N), df(N - 1);\n   F[0] = 1;\n   for(int n = 0; n < N - 1; n++)\
    \ {\n      mm v = 0;\n      for(auto&& [i, ai] : dat_a) {\n         if(i > n)\
    \ break;\n         v += ai * df[n - i];\n      }\n      for(auto&& [i, bi] : dat_b)\
    \ {\n         if(i > n) break;\n         v += bi * F[n - i];\n      }\n      df[n]\
    \ = -v;\n      F[n + 1] = df[n] * mm(n + 1).inv();\n   }\n   return F;\n}\n"
  code: "using vm = vector<mm>;\nvm fps_inv_sparse(vm& f) {\n   int n = f.size();\n\
    \   vector<pair<int, mm>> dat;\n   for(int i = 0; i < n; i++)\n      if(f[i].x)\
    \ dat.emplace_back(i, f[i]);\n   vm g(n);\n   mm g0 = f[0].inv();\n   g[0] = g0;\n\
    \   for(int i = 1; i < n; i++) {\n      mm rhs = 0;\n      for(auto&& [k, fk]\
    \ : dat) {\n         if(k > i) break;\n         rhs -= fk * g[i - k];\n      }\n\
    \      g[i] = rhs * g0;\n   }\n   return g;\n}\nvm fps_exp_sparse(vm& f) {\n \
    \  if((int)f.size() == 0) return {mm(1)};\n   int N = f.size();\n   vector<pair<int,\
    \ mm>> dat;\n   for(int i = 1; i < N; i++)\n      if(f[i].x) dat.emplace_back(i\
    \ - 1, mm(i) * f[i]);\n   vm F(N);\n   F[0] = 1;\n   for(int n = 1; n < N; n++)\
    \ {\n      mm rhs = 0;\n      for(auto&& [k, fk] : dat) {\n         if(k > n -\
    \ 1) break;\n         rhs += fk * F[n - 1 - k];\n      }\n      F[n] = rhs * mm(n).inv();\n\
    \   }\n   return F;\n}\nvm fps_log_sparse(vm& f) {\n   int N = f.size();\n   vector<pair<int,\
    \ mm>> dat;\n   for(int i = 1; i < N; i++)\n      if(f[i].x) dat.emplace_back(i,\
    \ f[i]);\n   vm F(N), g(N - 1);\n   for(int n = 0; n < N - 1; n++) {\n      mm\
    \ rhs = mm(n + 1) * f[n + 1];\n      for(auto&& [i, fi] : dat) {\n         if(i\
    \ > n) break;\n         rhs -= fi * g[n - i];\n      }\n      g[n] = rhs;\n  \
    \    F[n + 1] = rhs * mm(n + 1).inv();\n   }\n   return F;\n}\nvm fps_pow_product(vm&\
    \ f, vm& g, mm n, mm m) {\n   int N = f.size();\n   using P = pair<int, mm>;\n\
    \   vector<P> dat_f, dat_g;\n   for(int i = 0; i < (int)f.size(); i++)\n     \
    \ if(f[i].x) dat_f.emplace_back(i, f[i]);\n   for(int i = 0; i < (int)g.size();\
    \ i++)\n      if(g[i].x) dat_g.emplace_back(i, g[i]);\n   vm a(N), b(N);\n   for(auto&&\
    \ [i, x] : dat_f)\n      for(auto&& [j, y] : dat_g) {\n         if(i + j >= N\
    \ + 1) continue;\n         mm xy = x * y;\n         if(i + j < N) a[i + j] +=\
    \ xy;\n         if(0 < i + j && i + j <= N) b[i + j - 1] -= xy * (n * mm(i) +\
    \ m * mm(j));\n      }\n   vector<P> dat_a, dat_b;\n   for(int i = 1; i < N; i++)\n\
    \      if(a[i].x) dat_a.emplace_back(i, a[i]);\n   for(int i = 0; i < N; i++)\n\
    \      if(b[i].x) dat_b.emplace_back(i, b[i]);\n   vm F(N), df(N - 1);\n   F[0]\
    \ = 1;\n   for(int n = 0; n < N - 1; n++) {\n      mm v = 0;\n      for(auto&&\
    \ [i, ai] : dat_a) {\n         if(i > n) break;\n         v += ai * df[n - i];\n\
    \      }\n      for(auto&& [i, bi] : dat_b) {\n         if(i > n) break;\n   \
    \      v += bi * F[n - i];\n      }\n      df[n] = -v;\n      F[n + 1] = df[n]\
    \ * mm(n + 1).inv();\n   }\n   return F;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/fps_sparse.hpp
  requiredBy: []
  timestamp: '2025-02-24 17:43:49+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/fps_sparse.test.cpp
documentation_of: src/FPS/fps_sparse.hpp
layout: document
redirect_from:
- /library/src/FPS/fps_sparse.hpp
- /library/src/FPS/fps_sparse.hpp.html
title: src/FPS/fps_sparse.hpp
---
