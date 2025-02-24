---
data:
  _extendedDependsOn:
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
    - https://judge.yosupo.jp/submission/269550
  bundledCode: "#line 1 \"test/algorithm/min_plus_conv.test.cpp\"\n// AC\u78BA\u8A8D\
    \u6E08\u307F https://judge.yosupo.jp/submission/269550\n\n/*\n#include <bits/stdc++.h>\n\
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
    \ C;\n}\n\nint main() {\n   cin.tie(0);       \n   ios::sync_with_stdio(false);\n\
    \   ll n, m; cin >> n >> m;\n   vector<ll> a(n), b(m);\n   for(int i = 0; i <\
    \ n; i ++) cin >> a[i];\n   for(int i = 0; i < m; i ++) cin >> b[i];\n   auto\
    \ ret = minplus_conv(b, a);\n   for(ll e : ret) cout << e << \" \";\n   cout <<\
    \ '\\n';\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/min_plus_conv.hpp\"\
    \ntemplate<typename T, typename F> vector<int> monotone_minima(int h, int w, const\
    \ F& f) {\n   vector<pair<int, T>> dp(h, pair(-1, T()));\n   auto rec = [&](auto&&\
    \ rec, int u, int d, int l, int r) {\n      if(u > d) return;\n      int mid =\
    \ (u + d) >> 1;\n      auto& [idx, mi] = dp[mid];\n      idx = l, mi = f(mid,\
    \ l);\n      for(int i = l + 1; i <= r; i++)\n         if(chmin(mi, f(mid, i)))\
    \ idx = i;\n      rec(rec, u, mid - 1, l, idx);\n      rec(rec, mid + 1, d, idx,\
    \ r);\n   };\n   rec(rec, 0, h - 1, 0, w - 1);\n   vector<int> ret;\n   for(auto\
    \ [idx, val] : dp) ret.push_back(idx);\n   return ret;\n}\n\ntemplate<typename\
    \ T>  // B is convex. if both A and B are convex, do greedy.\nvector<T> minplus_conv(vector<T>&\
    \ A, vector<T>& B) {\n   int n = A.size(), m = B.size();\n   if(n == 0 && m ==\
    \ 0) return {};\n   vector<T> C(n + m - 1);\n\n   const ll inf = INF;\n   auto\
    \ select = [&](int i, int j) -> T {\n      if(i < j) return inf;\n      if(i -\
    \ j >= m) return inf;\n      return A[j] + B[i - j];\n   };\n   vector<int> J\
    \ = monotone_minima<T>(n + m - 1, n, select);\n   for(int i = 0; i < n + m - 1;\
    \ i++) {\n      T x = A[J[i]], y = B[i - J[i]];\n      if(x < inf && y < inf)\
    \ C[i] = x + y;\n   }\n   return C;\n}\n#line 66 \"test/algorithm/min_plus_conv.test.cpp\"\
    \nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/269550\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    const ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto&\
    \ a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
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
    \ < inf && y < inf) C[i] = x + y;\n   }\n   return C;\n}\n\nint main() {\n   cin.tie(0);\
    \       \n   ios::sync_with_stdio(false);\n   ll n, m; cin >> n >> m;\n   vector<ll>\
    \ a(n), b(m);\n   for(int i = 0; i < n; i ++) cin >> a[i];\n   for(int i = 0;\
    \ i < m; i ++) cin >> b[i];\n   auto ret = minplus_conv(b, a);\n   for(ll e :\
    \ ret) cout << e << \" \";\n   cout << '\\n';\n   return 0;\n}\n*/\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/algorithm/min_plus_conv.hpp\"\
    \nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/algorithm/min_plus_conv.hpp
  isVerificationFile: true
  path: test/algorithm/min_plus_conv.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 11:27:56+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/min_plus_conv.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/min_plus_conv.test.cpp
- /verify/test/algorithm/min_plus_conv.test.cpp.html
title: test/algorithm/min_plus_conv.test.cpp
---
