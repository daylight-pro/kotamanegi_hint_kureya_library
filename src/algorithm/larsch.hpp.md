---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/larsch.test.cpp
    title: test/algorithm/larsch.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/larsch.hpp\"\ntemplate <typename T>\nvector<T>\
    \ monge_shortest_path(int N, const function<T(int, int)>& f) {\n   T INF = (T{1}\
    \ << (sizeof(T) * 8 - 2)) - 1;\n   vector<T> dp(N + 1, INF);\n   vector<int> x(N\
    \ + 1, 0);\n   auto check = [&](int from, int to) {\n      if (from >= to) return;\n\
    \      T cost = f(from, to);\n      if (dp[from] + cost < dp[to]) dp[to] = dp[from]\
    \ + cost, x[to] = from;\n   };\n   auto dfs = [&](auto rc, int l, int r) -> void\
    \ {\n      if (l + 1 >= r) return;\n      int m = (l + r) / 2;\n      for (int\
    \ i = x[l]; i <= x[r]; i++) check(i, m);\n      rc(rc, l, m);\n      for (int\
    \ i = l + 1; i <= m; i++) check(i, r);\n      rc(rc, m, r);\n   };\n   dp[0] =\
    \ 0, check(0, N), dfs(dfs, 0, N);\n   return dp;\n}\n\n   // [min, max] \u306F\
    \u9589\u533A\u9593\u3092\u5165\u529B\u3059\u308B\ntemplate <typename T, bool get_min\
    \ = true>\npair<ll, T> golden_section_search(const function<T(ll)>& f, ll min,\n\
    \                                    ll max) {\n   assert(min <= max);\n   ll\
    \ a = min - 1, x, b;\n   {\n      ll s = 1, t = 2;\n      while (t < max - min\
    \ + 2) swap(s += t, t);\n      x = a + t - s, b = a + t;\n   }\n   T fx = f(x),\
    \ fy;\n   while (a + b != 2 * x) {\n      ll y = a + b - x;\n      if (max < y\
    \ || (fy = f(y), get_min ? fx < fy : fx > fy)) {\n         b = a;\n         a\
    \ = y;\n      } else {\n         a = x;\n         x = y;\n         fx = fy;\n\
    \      }\n   }\n   return {x, fx};\n}\n\n   // upper : max abs(\u8FBA\u6570\u3092\
    \ 1 \u5897\u6E1B\u3055\u305B\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\u306E\u5909\
    \u5316)\nll monge_d_edge_shortest_path(int N, int D, ll upper,\n      const function<ll(int,\
    \ int)>& f) {\n   using T = __int128_t;\n   upper = abs(upper);\n   auto dp =\
    \ [&](ll x) -> T {\n      auto g = [&](int from, int to) -> T { return f(from,\
    \ to) + x; };\n      T cost = monge_shortest_path<T>(N, g)[N];\n      return cost\
    \ - T{1} * D * x;\n   };\n   auto [_, res] = golden_section_search<T, false>(dp,\
    \ -upper, upper);\n   return res;\n}\n\nvector<ll> enumerate_monge_d_edge_shortest_path(\n\
    \      int N, const function<ll(int, int)>& f,\n      ll unreached = (1LL << 62)\
    \ - 1) {\n   using T = __int128_t;\n   T INF = (T{1} << (sizeof(T) * 8 - 2)) -\
    \ 1;\n   vector<ll> ans(N + 1, unreached);\n   vector<T> dp(N + 1, INF);\n   dp[0]\
    \ = 0;\n   for (int d = 1; d <= N; d++) {\n      vector<int> midx = monotone_minima<T>(N\
    \ + 1, N + 1, [&](int j, int i) -> T {\n         return i < j ? dp[i] + f(i, j)\
    \ : INF;\n      });\n      for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] +\
    \ f(midx[i], i);\n      ans[d] = dp[N];\n   }\n   return ans;\n}\n"
  code: "template <typename T>\nvector<T> monge_shortest_path(int N, const function<T(int,\
    \ int)>& f) {\n   T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;\n   vector<T> dp(N\
    \ + 1, INF);\n   vector<int> x(N + 1, 0);\n   auto check = [&](int from, int to)\
    \ {\n      if (from >= to) return;\n      T cost = f(from, to);\n      if (dp[from]\
    \ + cost < dp[to]) dp[to] = dp[from] + cost, x[to] = from;\n   };\n   auto dfs\
    \ = [&](auto rc, int l, int r) -> void {\n      if (l + 1 >= r) return;\n    \
    \  int m = (l + r) / 2;\n      for (int i = x[l]; i <= x[r]; i++) check(i, m);\n\
    \      rc(rc, l, m);\n      for (int i = l + 1; i <= m; i++) check(i, r);\n  \
    \    rc(rc, m, r);\n   };\n   dp[0] = 0, check(0, N), dfs(dfs, 0, N);\n   return\
    \ dp;\n}\n\n   // [min, max] \u306F\u9589\u533A\u9593\u3092\u5165\u529B\u3059\u308B\
    \ntemplate <typename T, bool get_min = true>\npair<ll, T> golden_section_search(const\
    \ function<T(ll)>& f, ll min,\n                                    ll max) {\n\
    \   assert(min <= max);\n   ll a = min - 1, x, b;\n   {\n      ll s = 1, t = 2;\n\
    \      while (t < max - min + 2) swap(s += t, t);\n      x = a + t - s, b = a\
    \ + t;\n   }\n   T fx = f(x), fy;\n   while (a + b != 2 * x) {\n      ll y = a\
    \ + b - x;\n      if (max < y || (fy = f(y), get_min ? fx < fy : fx > fy)) {\n\
    \         b = a;\n         a = y;\n      } else {\n         a = x;\n         x\
    \ = y;\n         fx = fy;\n      }\n   }\n   return {x, fx};\n}\n\n   // upper\
    \ : max abs(\u8FBA\u6570\u3092 1 \u5897\u6E1B\u3055\u305B\u305F\u3068\u304D\u306E\
    \u30B3\u30B9\u30C8\u306E\u5909\u5316)\nll monge_d_edge_shortest_path(int N, int\
    \ D, ll upper,\n      const function<ll(int, int)>& f) {\n   using T = __int128_t;\n\
    \   upper = abs(upper);\n   auto dp = [&](ll x) -> T {\n      auto g = [&](int\
    \ from, int to) -> T { return f(from, to) + x; };\n      T cost = monge_shortest_path<T>(N,\
    \ g)[N];\n      return cost - T{1} * D * x;\n   };\n   auto [_, res] = golden_section_search<T,\
    \ false>(dp, -upper, upper);\n   return res;\n}\n\nvector<ll> enumerate_monge_d_edge_shortest_path(\n\
    \      int N, const function<ll(int, int)>& f,\n      ll unreached = (1LL << 62)\
    \ - 1) {\n   using T = __int128_t;\n   T INF = (T{1} << (sizeof(T) * 8 - 2)) -\
    \ 1;\n   vector<ll> ans(N + 1, unreached);\n   vector<T> dp(N + 1, INF);\n   dp[0]\
    \ = 0;\n   for (int d = 1; d <= N; d++) {\n      vector<int> midx = monotone_minima<T>(N\
    \ + 1, N + 1, [&](int j, int i) -> T {\n         return i < j ? dp[i] + f(i, j)\
    \ : INF;\n      });\n      for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] +\
    \ f(midx[i], i);\n      ans[d] = dp[N];\n   }\n   return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/larsch.hpp
  requiredBy: []
  timestamp: '2025-02-24 20:23:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/larsch.test.cpp
documentation_of: src/algorithm/larsch.hpp
layout: document
redirect_from:
- /library/src/algorithm/larsch.hpp
- /library/src/algorithm/larsch.hpp.html
title: src/algorithm/larsch.hpp
---
