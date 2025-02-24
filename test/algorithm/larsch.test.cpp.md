---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/larsch.hpp
    title: src/algorithm/larsch.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/min_plus_conv.hpp
    title: src/algorithm/min_plus_conv.hpp
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
    - https://yukicoder.me/submissions/1045895
  bundledCode: "#line 1 \"test/algorithm/larsch.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\
    \u307F https://yukicoder.me/submissions/1045895\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n\ntemplate<typename\
    \ T, typename F> vector<int> monotone_minima(int h, int w, const F& f) {\n   vector<pair<int,\
    \ T>> dp(h, pair(-1, T()));\n   auto rec = [&](auto&& rec, int u, int d, int l,\
    \ int r) {\n      if(u > d) return;\n      int mid = (u + d) >> 1;\n      auto&\
    \ [idx, mi] = dp[mid];\n      idx = l, mi = f(mid, l);\n      for(int i = l +\
    \ 1; i <= r; i ++) if(chmin(mi, f(mid, i))) idx = i;\n      rec(rec, u, mid -\
    \ 1, l, idx);\n      rec(rec, mid + 1, d, idx, r);\n   };\n   rec(rec, 0, h -\
    \ 1, 0, w - 1);\n   vector<int> ret;\n   for(auto [idx, val] : dp) ret.push_back(idx);\n\
    \   return ret;\n}\n\ntemplate <typename T> // B is convex. if both A and B are\
    \ convex, do greedy. \nvector<T> minplus_conv(vector<T>& A, vector<T>& B) {\n\
    \   int n = A.size(), m = B.size();\n   if (n == 0 && m == 0) return {};\n   vector<T>\
    \ C(n + m - 1);\n\n   const ll inf = INF;\n   auto select = [&](int i, int j)\
    \ -> T {\n      if(i < j) return inf;\n      if(i - j >= m) return inf;\n    \
    \  return A[j] + B[i - j];\n   };\n   vector<int> J = monotone_minima<T>(n + m\
    \ - 1, n, select); \n   for(int i = 0; i < n + m - 1; i ++) {\n      T x = A[J[i]],\
    \ y = B[i - J[i]];\n      if (x < inf && y < inf) C[i] = x + y;\n   }\n   return\
    \ C;\n}\n\ntemplate <typename T>\nvector<T> monge_shortest_path(int N, const function<T(int,\
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
    \ f(midx[i], i);\n      ans[d] = dp[N];\n   }\n   return ans;\n}\n\nint main()\
    \ {\n   cin.tie(0);       \n   ios::sync_with_stdio(false);\n   int n; cin >>\
    \ n;\n   vector<ll> a(n);\n   for(int i = 0; i < n; i ++) cin >> a[i];\n   vector<ll>\
    \ r(n + 1);\n   for(int i = 0; i < n; i ++) r[i + 1] = r[i] + a[i];\n\n   auto\
    \ cost = [&](int i, int j) -> ll {\n      assert(i < j);\n      if (i + 1 == j)\
    \ return 0;\n      return (r[j - 1] - r[i]) * (r[j - 1] - r[i]);\n   };\n   auto\
    \ ans = enumerate_monge_d_edge_shortest_path(n + 1, cost);\n   for(int d = 0;\
    \ d < n; d ++) cout << ans[n - d] << '\\n';\n \n   // verify \u7528, \u4F55\u70B9\
    \u304B\u8ABF\u3079\u308B\n   {\n      vector<int> ds;\n      for(int i = 0; i\
    \ < 10; i ++) {\n         int num = (99824433 * i) % (n + 1);\n         num ++;\n\
    \         ds.push_back(num);\n      }\n      for(int d : ds) {\n         ll ans2\
    \ = monge_d_edge_shortest_path(n + 1, d, INF, cost);\n         assert(ans2 ==\
    \ ans[d]);\n      }\n   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/min_plus_conv.hpp\"\
    \ntemplate<typename T, typename F> vector<int> monotone_minima(int h, int w, const\
    \ F& f) {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto rec = [&](auto&&\
    \ rec, int u, int d, int l, int r) {\n      if(u > d) return;\n      int mid =\
    \ (u + d) >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx = l, mi = f(mid,\
    \ l);\n      for(int i = l + 1; i <= r; i ++) if(chmin(mi, f(mid, i))) idx = i;\n\
    \      rec(rec, u, mid - 1, l, idx);\n      rec(rec, mid + 1, d, idx, r);\n  \
    \ };\n   rec(rec, 0, h - 1, 0, w - 1);\n   vector<int> ret;\n   for(auto [idx,\
    \ val] : dp) ret.push_back(idx);\n   return ret;\n}\n\ntemplate <typename T> //\
    \ B is convex. if both A and B are convex, do greedy. \nvector<T> minplus_conv(vector<T>&\
    \ A, vector<T>& B) {\n   int n = A.size(), m = B.size();\n   if (n == 0 && m ==\
    \ 0) return {};\n   vector<T> C(n + m - 1);\n\n   const ll inf = INF;\n   auto\
    \ select = [&](int i, int j) -> T {\n      if(i < j) return inf;\n      if(i -\
    \ j >= m) return inf;\n      return A[j] + B[i - j];\n   };\n   vector<int> J\
    \ = monotone_minima<T>(n + m - 1, n, select); \n   for(int i = 0; i < n + m -\
    \ 1; i ++) {\n      T x = A[J[i]], y = B[i - J[i]];\n      if (x < inf && y <\
    \ inf) C[i] = x + y;\n   }\n   return C;\n}\n#line 1 \"src/algorithm/larsch.hpp\"\
    \ntemplate <typename T>\nvector<T> monge_shortest_path(int N, const function<T(int,\
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
    \ f(midx[i], i);\n      ans[d] = dp[N];\n   }\n   return ans;\n}\n#line 167 \"\
    test/algorithm/larsch.test.cpp\"\n\nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://yukicoder.me/submissions/1045895\n\n\
    /*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\ntemplate<typename T, typename F> vector<int> monotone_minima(int\
    \ h, int w, const F& f) {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto\
    \ rec = [&](auto&& rec, int u, int d, int l, int r) {\n      if(u > d) return;\n\
    \      int mid = (u + d) >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx =\
    \ l, mi = f(mid, l);\n      for(int i = l + 1; i <= r; i ++) if(chmin(mi, f(mid,\
    \ i))) idx = i;\n      rec(rec, u, mid - 1, l, idx);\n      rec(rec, mid + 1,\
    \ d, idx, r);\n   };\n   rec(rec, 0, h - 1, 0, w - 1);\n   vector<int> ret;\n\
    \   for(auto [idx, val] : dp) ret.push_back(idx);\n   return ret;\n}\n\ntemplate\
    \ <typename T> // B is convex. if both A and B are convex, do greedy. \nvector<T>\
    \ minplus_conv(vector<T>& A, vector<T>& B) {\n   int n = A.size(), m = B.size();\n\
    \   if (n == 0 && m == 0) return {};\n   vector<T> C(n + m - 1);\n\n   const ll\
    \ inf = INF;\n   auto select = [&](int i, int j) -> T {\n      if(i < j) return\
    \ inf;\n      if(i - j >= m) return inf;\n      return A[j] + B[i - j];\n   };\n\
    \   vector<int> J = monotone_minima<T>(n + m - 1, n, select); \n   for(int i =\
    \ 0; i < n + m - 1; i ++) {\n      T x = A[J[i]], y = B[i - J[i]];\n      if (x\
    \ < inf && y < inf) C[i] = x + y;\n   }\n   return C;\n}\n\ntemplate <typename\
    \ T>\nvector<T> monge_shortest_path(int N, const function<T(int, int)>& f) {\n\
    \   T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;\n   vector<T> dp(N + 1, INF);\n\
    \   vector<int> x(N + 1, 0);\n   auto check = [&](int from, int to) {\n      if\
    \ (from >= to) return;\n      T cost = f(from, to);\n      if (dp[from] + cost\
    \ < dp[to]) dp[to] = dp[from] + cost, x[to] = from;\n   };\n   auto dfs = [&](auto\
    \ rc, int l, int r) -> void {\n      if (l + 1 >= r) return;\n      int m = (l\
    \ + r) / 2;\n      for (int i = x[l]; i <= x[r]; i++) check(i, m);\n      rc(rc,\
    \ l, m);\n      for (int i = l + 1; i <= m; i++) check(i, r);\n      rc(rc, m,\
    \ r);\n   };\n   dp[0] = 0, check(0, N), dfs(dfs, 0, N);\n   return dp;\n}\n\n\
    \   // [min, max] \u306F\u9589\u533A\u9593\u3092\u5165\u529B\u3059\u308B\ntemplate\
    \ <typename T, bool get_min = true>\npair<ll, T> golden_section_search(const function<T(ll)>&\
    \ f, ll min,\n                                    ll max) {\n   assert(min <=\
    \ max);\n   ll a = min - 1, x, b;\n   {\n      ll s = 1, t = 2;\n      while (t\
    \ < max - min + 2) swap(s += t, t);\n      x = a + t - s, b = a + t;\n   }\n \
    \  T fx = f(x), fy;\n   while (a + b != 2 * x) {\n      ll y = a + b - x;\n  \
    \    if (max < y || (fy = f(y), get_min ? fx < fy : fx > fy)) {\n         b =\
    \ a;\n         a = y;\n      } else {\n         a = x;\n         x = y;\n    \
    \     fx = fy;\n      }\n   }\n   return {x, fx};\n}\n\n   // upper : max abs(\u8FBA\
    \u6570\u3092 1 \u5897\u6E1B\u3055\u305B\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\
    \u306E\u5909\u5316)\nll monge_d_edge_shortest_path(int N, int D, ll upper,\n \
    \     const function<ll(int, int)>& f) {\n   using T = __int128_t;\n   upper =\
    \ abs(upper);\n   auto dp = [&](ll x) -> T {\n      auto g = [&](int from, int\
    \ to) -> T { return f(from, to) + x; };\n      T cost = monge_shortest_path<T>(N,\
    \ g)[N];\n      return cost - T{1} * D * x;\n   };\n   auto [_, res] = golden_section_search<T,\
    \ false>(dp, -upper, upper);\n   return res;\n}\n\nvector<ll> enumerate_monge_d_edge_shortest_path(\n\
    \      int N, const function<ll(int, int)>& f,\n      ll unreached = (1LL << 62)\
    \ - 1) {\n   using T = __int128_t;\n   T INF = (T{1} << (sizeof(T) * 8 - 2)) -\
    \ 1;\n   vector<ll> ans(N + 1, unreached);\n   vector<T> dp(N + 1, INF);\n   dp[0]\
    \ = 0;\n   for (int d = 1; d <= N; d++) {\n      vector<int> midx = monotone_minima<T>(N\
    \ + 1, N + 1, [&](int j, int i) -> T {\n         return i < j ? dp[i] + f(i, j)\
    \ : INF;\n      });\n      for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] +\
    \ f(midx[i], i);\n      ans[d] = dp[N];\n   }\n   return ans;\n}\n\nint main()\
    \ {\n   cin.tie(0);       \n   ios::sync_with_stdio(false);\n   int n; cin >>\
    \ n;\n   vector<ll> a(n);\n   for(int i = 0; i < n; i ++) cin >> a[i];\n   vector<ll>\
    \ r(n + 1);\n   for(int i = 0; i < n; i ++) r[i + 1] = r[i] + a[i];\n\n   auto\
    \ cost = [&](int i, int j) -> ll {\n      assert(i < j);\n      if (i + 1 == j)\
    \ return 0;\n      return (r[j - 1] - r[i]) * (r[j - 1] - r[i]);\n   };\n   auto\
    \ ans = enumerate_monge_d_edge_shortest_path(n + 1, cost);\n   for(int d = 0;\
    \ d < n; d ++) cout << ans[n - d] << '\\n';\n \n   // verify \u7528, \u4F55\u70B9\
    \u304B\u8ABF\u3079\u308B\n   {\n      vector<int> ds;\n      for(int i = 0; i\
    \ < 10; i ++) {\n         int num = (99824433 * i) % (n + 1);\n         num ++;\n\
    \         ds.push_back(num);\n      }\n      for(int d : ds) {\n         ll ans2\
    \ = monge_d_edge_shortest_path(n + 1, d, INF, cost);\n         assert(ans2 ==\
    \ ans[d]);\n      }\n   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/algorithm/min_plus_conv.hpp\"\
    \n#include \"src/algorithm/larsch.hpp\"\n\nint main() { puts(\"Hello World\");\
    \ }"
  dependsOn:
  - test/template.hpp
  - src/algorithm/min_plus_conv.hpp
  - src/algorithm/larsch.hpp
  isVerificationFile: true
  path: test/algorithm/larsch.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 20:23:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/larsch.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/larsch.test.cpp
- /verify/test/algorithm/larsch.test.cpp.html
title: test/algorithm/larsch.test.cpp
---
