---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/relaxed_conv.test.cpp
    title: test/FPS/relaxed_conv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/relaxed_conv.hpp\"\ntemplate<typename T> class RelaxedConvolution\
    \ {\n   int N, pos;\n   vector<T> f, g, buf;\n   vector<vector<tuple<int, int,\
    \ int, int>>> event;\n   void dfs1(int le, int ri) {\n      if(ri - le == 1) {\n\
    \         event[le].push_back({le, le + 1, 0, 1});\n         return;\n      }\n\
    \      int mid = (le + ri) / 2;\n      event[mid].push_back({le, mid, mid - le,\
    \ ri - le});\n      event[ri].push_back({mid, ri, mid - le, ri - le});\n     \
    \ dfs1(le, mid);\n      dfs1(mid, ri);\n   }\n   void dfs2(int le, int ri) {\n\
    \      if(ri - le == 1) {\n         event[le].push_back({0, 1, le, le + 1});\n\
    \         return;\n      }\n      int mid = (le + ri) / 2;\n      event[mid].push_back({mid\
    \ - le, ri - le, le, mid});\n      event[ri].push_back({mid - le, ri - le, mid,\
    \ ri});\n      dfs2(le, mid);\n      dfs2(mid, ri);\n   }\n   void dfs(int len)\
    \ {\n      if(len == 1) {\n         event[0].push_back({0, 1, 0, 1});\n      \
    \   return;\n      }\n      int mid = len / 2;\n      event[len].push_back({mid,\
    \ len, mid, len});\n      dfs(mid);\n      dfs1(mid, len);\n      dfs2(mid, len);\n\
    \   }\n\n   public:\n   RelaxedConvolution(int n) {\n      N = 1, pos = 0;\n \
    \     while(N < n) N *= 2;\n      f.resize(N);\n      g.resize(N);\n      buf.resize(N);\n\
    \      event.resize(N + 1);\n      dfs(N);\n   }\n   T get(T x, T y) {\n     \
    \ f[pos] = x, g[pos] = y;\n      for(auto [fl, fr, gl, gr] : event[pos]) {\n \
    \        vector<T> A({f.begin() + fl, f.begin() + fr});\n         vector<T> B({g.begin()\
    \ + gl, g.begin() + gr});\n         auto ret = conv(A, B);\n         int sz =\
    \ ret.size();\n         for(int i = 0; i < sz; i++) {\n            if(i + fl +\
    \ gl >= N) break;\n            buf[i + fl + gl] += ret[i];\n         }\n     \
    \ }\n      return buf[pos++];\n   }\n};\n"
  code: "template<typename T> class RelaxedConvolution {\n   int N, pos;\n   vector<T>\
    \ f, g, buf;\n   vector<vector<tuple<int, int, int, int>>> event;\n   void dfs1(int\
    \ le, int ri) {\n      if(ri - le == 1) {\n         event[le].push_back({le, le\
    \ + 1, 0, 1});\n         return;\n      }\n      int mid = (le + ri) / 2;\n  \
    \    event[mid].push_back({le, mid, mid - le, ri - le});\n      event[ri].push_back({mid,\
    \ ri, mid - le, ri - le});\n      dfs1(le, mid);\n      dfs1(mid, ri);\n   }\n\
    \   void dfs2(int le, int ri) {\n      if(ri - le == 1) {\n         event[le].push_back({0,\
    \ 1, le, le + 1});\n         return;\n      }\n      int mid = (le + ri) / 2;\n\
    \      event[mid].push_back({mid - le, ri - le, le, mid});\n      event[ri].push_back({mid\
    \ - le, ri - le, mid, ri});\n      dfs2(le, mid);\n      dfs2(mid, ri);\n   }\n\
    \   void dfs(int len) {\n      if(len == 1) {\n         event[0].push_back({0,\
    \ 1, 0, 1});\n         return;\n      }\n      int mid = len / 2;\n      event[len].push_back({mid,\
    \ len, mid, len});\n      dfs(mid);\n      dfs1(mid, len);\n      dfs2(mid, len);\n\
    \   }\n\n   public:\n   RelaxedConvolution(int n) {\n      N = 1, pos = 0;\n \
    \     while(N < n) N *= 2;\n      f.resize(N);\n      g.resize(N);\n      buf.resize(N);\n\
    \      event.resize(N + 1);\n      dfs(N);\n   }\n   T get(T x, T y) {\n     \
    \ f[pos] = x, g[pos] = y;\n      for(auto [fl, fr, gl, gr] : event[pos]) {\n \
    \        vector<T> A({f.begin() + fl, f.begin() + fr});\n         vector<T> B({g.begin()\
    \ + gl, g.begin() + gr});\n         auto ret = conv(A, B);\n         int sz =\
    \ ret.size();\n         for(int i = 0; i < sz; i++) {\n            if(i + fl +\
    \ gl >= N) break;\n            buf[i + fl + gl] += ret[i];\n         }\n     \
    \ }\n      return buf[pos++];\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/relaxed_conv.hpp
  requiredBy: []
  timestamp: '2025-02-24 10:33:49+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/relaxed_conv.test.cpp
documentation_of: src/FPS/relaxed_conv.hpp
layout: document
redirect_from:
- /library/src/FPS/relaxed_conv.hpp
- /library/src/FPS/relaxed_conv.hpp.html
title: src/FPS/relaxed_conv.hpp
---
