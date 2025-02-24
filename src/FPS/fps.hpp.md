---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/fps.test.cpp
    title: test/FPS/fps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/fps.hpp\"\nusing vm = vector<mm>;\nvm pre(vm f,\
    \ int sz) {return vm(f.begin(), f.begin() + min((int)f.size(), sz));}\nvm inv(vm\
    \ f, int deg = -1) {\n   if (deg < 0) deg = (int)f.size();\n   vm res({mm(1) /\
    \ f[0]});\n   for (int i = 1; i < deg; i <<= 1) {\n      vm ff = conv(res, conv(res,\
    \ pre(f, i << 1)));\n      int sz = res.size();\n      for(int j = 0; j < sz;\
    \ j ++) res[j] += res[j];\n      sz = max(sz, (int)ff.size());\n      res.resize(sz);\
    \ sz = ff.size();\n      for(int j = 0; j < sz; j ++) res[j] -= ff[j];\n     \
    \ res = pre(res, i << 1);\n   }\n   res.resize(deg); return res;\n}\nvm diff(vm\
    \ f) {\n   int n = f.size(); vm res(n - 1);\n   for(int i = 1; i < n; i ++) res[i\
    \ - 1] = f[i] * i;\n   return res;\n}\nvm intg(vm f) {\n   int n = (int)f.size();\
    \ vm res(n+1, 0);\n   for (int i = 0; i < n; i ++) res[i + 1] = f[i] / (i+1);\n\
    \   return res;\n}\nvm log(vm f, int deg = -1) {\n   if(deg == -1) deg = f.size();\n\
    \   vm res = intg(conv(diff(f), inv(f, deg)));\n   res.resize(deg); return res;\n\
    }\nvm exp(vm f, int deg = -1) {\n   vm res(1, 1);\n   if(deg == -1) deg = f.size();\n\
    \   for(int i = 1; i < deg; i <<= 1) {\n      vm ff1 = pre(f, i << 1);\n     \
    \ vm ff2 = log(res, i << 1);\n      ff1.resize(max(ff1.size(), ff2.size()));\n\
    \      ff1[0] += mm(1);\n      int sz = ff2.size();\n      for(int j = 0; j <\
    \ sz; j ++) ff1[j] -= ff2[j];\n      res = conv(res, pre(ff1, i << 1));\n   }\n\
    \   res.resize(deg); return res;\n}\nvm taylor_shift(vm f, mm a) {\n   int n =\
    \ f.size();\n   vm fac(n, 1), inv(n, 1), finv(n, 1);\n   for(int i = 2; i < n;\
    \ i ++) {\n      fac[i] = fac[i - 1] * i;\n      inv[i] = -inv[mod % i] * (mod\
    \ / i);\n      finv[i] = finv[i - 1] * inv[i];\n   }\n   for(int i = 0; i < n;\
    \ i ++) f[i] *= fac[i];\n   std::reverse(f.begin(), f.end());\n   vm g(n, 1);\n\
    \   for(int i = 1; i < n; i ++) g[i] = g[i - 1] * a * inv[i];\n   f = pre(conv(f,\
    \ g), n);\n   reverse(f.begin(), f.end());\n   for(int i = 0; i < n; i ++) f[i]\
    \ *= finv[i];\n   return f;\n}\n"
  code: "using vm = vector<mm>;\nvm pre(vm f, int sz) {return vm(f.begin(), f.begin()\
    \ + min((int)f.size(), sz));}\nvm inv(vm f, int deg = -1) {\n   if (deg < 0) deg\
    \ = (int)f.size();\n   vm res({mm(1) / f[0]});\n   for (int i = 1; i < deg; i\
    \ <<= 1) {\n      vm ff = conv(res, conv(res, pre(f, i << 1)));\n      int sz\
    \ = res.size();\n      for(int j = 0; j < sz; j ++) res[j] += res[j];\n      sz\
    \ = max(sz, (int)ff.size());\n      res.resize(sz); sz = ff.size();\n      for(int\
    \ j = 0; j < sz; j ++) res[j] -= ff[j];\n      res = pre(res, i << 1);\n   }\n\
    \   res.resize(deg); return res;\n}\nvm diff(vm f) {\n   int n = f.size(); vm\
    \ res(n - 1);\n   for(int i = 1; i < n; i ++) res[i - 1] = f[i] * i;\n   return\
    \ res;\n}\nvm intg(vm f) {\n   int n = (int)f.size(); vm res(n+1, 0);\n   for\
    \ (int i = 0; i < n; i ++) res[i + 1] = f[i] / (i+1);\n   return res;\n}\nvm log(vm\
    \ f, int deg = -1) {\n   if(deg == -1) deg = f.size();\n   vm res = intg(conv(diff(f),\
    \ inv(f, deg)));\n   res.resize(deg); return res;\n}\nvm exp(vm f, int deg = -1)\
    \ {\n   vm res(1, 1);\n   if(deg == -1) deg = f.size();\n   for(int i = 1; i <\
    \ deg; i <<= 1) {\n      vm ff1 = pre(f, i << 1);\n      vm ff2 = log(res, i <<\
    \ 1);\n      ff1.resize(max(ff1.size(), ff2.size()));\n      ff1[0] += mm(1);\n\
    \      int sz = ff2.size();\n      for(int j = 0; j < sz; j ++) ff1[j] -= ff2[j];\n\
    \      res = conv(res, pre(ff1, i << 1));\n   }\n   res.resize(deg); return res;\n\
    }\nvm taylor_shift(vm f, mm a) {\n   int n = f.size();\n   vm fac(n, 1), inv(n,\
    \ 1), finv(n, 1);\n   for(int i = 2; i < n; i ++) {\n      fac[i] = fac[i - 1]\
    \ * i;\n      inv[i] = -inv[mod % i] * (mod / i);\n      finv[i] = finv[i - 1]\
    \ * inv[i];\n   }\n   for(int i = 0; i < n; i ++) f[i] *= fac[i];\n   std::reverse(f.begin(),\
    \ f.end());\n   vm g(n, 1);\n   for(int i = 1; i < n; i ++) g[i] = g[i - 1] *\
    \ a * inv[i];\n   f = pre(conv(f, g), n);\n   reverse(f.begin(), f.end());\n \
    \  for(int i = 0; i < n; i ++) f[i] *= finv[i];\n   return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/fps.hpp
  requiredBy: []
  timestamp: '2025-02-24 21:38:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/fps.test.cpp
documentation_of: src/FPS/fps.hpp
layout: document
redirect_from:
- /library/src/FPS/fps.hpp
- /library/src/FPS/fps.hpp.html
title: src/FPS/fps.hpp
---
