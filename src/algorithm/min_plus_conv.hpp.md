---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/larsch.test.cpp
    title: test/algorithm/larsch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/algorithm/min_plus_conv.test.cpp
    title: test/algorithm/min_plus_conv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/min_plus_conv.hpp\"\ntemplate<typename T,\
    \ typename F> vector<int> monotone_minima(int h, int w, const F& f) {\n   vector<pair<int,\
    \ T>> dp(h, pair(-1, T()));\n   auto rec = [&](auto&& rec, int u, int d, int l,\
    \ int r) {\n      if(u > d) return;\n      int mid = (u + d) >> 1;\n      auto&\
    \ [idx, mi] = dp[mid];\n      idx = l, mi = f(mid, l);\n      for(int i = l +\
    \ 1; i <= r; i++)\n         if(chmin(mi, f(mid, i))) idx = i;\n      rec(rec,\
    \ u, mid - 1, l, idx);\n      rec(rec, mid + 1, d, idx, r);\n   };\n   rec(rec,\
    \ 0, h - 1, 0, w - 1);\n   vector<int> ret;\n   for(auto [idx, val] : dp) ret.push_back(idx);\n\
    \   return ret;\n}\n\ntemplate<typename T>  // B is convex. if both A and B are\
    \ convex, do greedy.\nvector<T> minplus_conv(vector<T>& A, vector<T>& B) {\n \
    \  int n = A.size(), m = B.size();\n   if(n == 0 && m == 0) return {};\n   vector<T>\
    \ C(n + m - 1);\n\n   const ll inf = INF;\n   auto select = [&](int i, int j)\
    \ -> T {\n      if(i < j) return inf;\n      if(i - j >= m) return inf;\n    \
    \  return A[j] + B[i - j];\n   };\n   vector<int> J = monotone_minima<T>(n + m\
    \ - 1, n, select);\n   for(int i = 0; i < n + m - 1; i++) {\n      T x = A[J[i]],\
    \ y = B[i - J[i]];\n      if(x < inf && y < inf) C[i] = x + y;\n   }\n   return\
    \ C;\n}\n"
  code: "template<typename T, typename F> vector<int> monotone_minima(int h, int w,\
    \ const F& f) {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto rec =\
    \ [&](auto&& rec, int u, int d, int l, int r) {\n      if(u > d) return;\n   \
    \   int mid = (u + d) >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx = l,\
    \ mi = f(mid, l);\n      for(int i = l + 1; i <= r; i++)\n         if(chmin(mi,\
    \ f(mid, i))) idx = i;\n      rec(rec, u, mid - 1, l, idx);\n      rec(rec, mid\
    \ + 1, d, idx, r);\n   };\n   rec(rec, 0, h - 1, 0, w - 1);\n   vector<int> ret;\n\
    \   for(auto [idx, val] : dp) ret.push_back(idx);\n   return ret;\n}\n\ntemplate<typename\
    \ T>  // B is convex. if both A and B are convex, do greedy.\nvector<T> minplus_conv(vector<T>&\
    \ A, vector<T>& B) {\n   int n = A.size(), m = B.size();\n   if(n == 0 && m ==\
    \ 0) return {};\n   vector<T> C(n + m - 1);\n\n   const ll inf = INF;\n   auto\
    \ select = [&](int i, int j) -> T {\n      if(i < j) return inf;\n      if(i -\
    \ j >= m) return inf;\n      return A[j] + B[i - j];\n   };\n   vector<int> J\
    \ = monotone_minima<T>(n + m - 1, n, select);\n   for(int i = 0; i < n + m - 1;\
    \ i++) {\n      T x = A[J[i]], y = B[i - J[i]];\n      if(x < inf && y < inf)\
    \ C[i] = x + y;\n   }\n   return C;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/min_plus_conv.hpp
  requiredBy: []
  timestamp: '2025-02-24 11:27:56+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/larsch.test.cpp
  - test/algorithm/min_plus_conv.test.cpp
documentation_of: src/algorithm/min_plus_conv.hpp
layout: document
redirect_from:
- /library/src/algorithm/min_plus_conv.hpp
- /library/src/algorithm/min_plus_conv.hpp.html
title: src/algorithm/min_plus_conv.hpp
---
