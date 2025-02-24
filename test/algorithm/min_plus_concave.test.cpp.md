---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/min_plus_concave.hpp
    title: src/algorithm/min_plus_concave.hpp
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
    - https://judge.yosupo.jp/submission/269644
  bundledCode: "#line 1 \"test/algorithm/min_plus_concave.test.cpp\"\n// AC\u78BA\u8A8D\
    \u6E08\u307F https://judge.yosupo.jp/submission/269644\n\n/*\n#include <bits/stdc++.h>\n\
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
    \   return ret;\n}\n\n// b is concave\ntemplate<typename T> vector<T> minplus_conv_concave(vector<T>\
    \ &a, vector<T> &b) {\n   int n = a.size(), m = b.size();\n   if(min(n, m) ==\
    \ 0) return vector<T> ();\n   int h = n + m - 1, w = n;\n   vector<int> ymin(h,\
    \ 0), ymax(h, w - 1), xmin(w), xmax(w);\n   for(int x = m; x < h; x ++) ymin[x]\
    \ = x - m + 1;\n   for(int x = 0; x <= h - m; x ++) ymax[x] = x;\n   iota(all(xmin),\
    \ 0); iota(all(xmax), m - 1);\n   vector<T> c(h, INF); // if long long\n   auto\
    \ rec = [&](auto&& rec, int x1, int x2, int y1, int y2) {\n      if(ymax[x1] >=\
    \ y2 and y1 >= ymin[x2]) {\n         auto A = [&](int i, int j) { return a[y2\
    \ - j] + b[x1 + i - y2 + j]; };\n         auto jmin = monotone_minima<T>(x2 -\
    \ x1 + 1, y2 - y1 + 1, A);\n         for(int i = x1; i <= x2; i ++) chmin(c[i],\
    \ A(i - x1, jmin[i - x1]));\n         return;\n      }\n      if((ll)(x2 - x1)\
    \ * (y2 - y1) < 1000) {\n         for(int x = x1; x <= x2; x ++) for(int y = max(ymin[x],\
    \ y1); y <= min(ymax[x], y2); y ++) chmin(c[x], a[y] + b[x - y]);\n         return;\n\
    \      }\n      if(x2 - x1 > y2 - y1) {\n         int xm = (x1 + x2) / 2;\n  \
    \       int ny2 = min(ymax[xm], y2), ny1 = max(ymin[xm], y1);\n         if(y1\
    \ <= ny2) rec(rec, x1, xm, y1, ny2);\n         if(ny1 <= y2) rec(rec, xm + 1,\
    \ x2, ny1, y2);\n\t\t} else {\n         int ym = (y1 + y2) / 2;\n         int\
    \ nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym], x1);\n         if(x1 <= nx2) rec(rec,\
    \ x1, nx2, y1, ym);\n         if(nx1 <= x2) rec(rec, nx1, x2, ym + 1, y2);\n \
    \     }\n\t};\n   rec(rec, 0, h - 1, 0, w - 1);\n   return c;\n}\nint main() {\n\
    \   int n, m; cin >> n >> m; vector<ll> a(n), b(m);\n   for(int i = 0; i < n;\
    \ i ++) cin >> a[i];\n   for(int i = 0; i < m; i ++) cin >> b[i];\n   auto c =\
    \ minplus_conv_concave(b, a);\n   for(ll e : c) cout << e << \" \";\n   cout <<\
    \ endl;\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    \ C[i] = x + y;\n   }\n   return C;\n}\n#line 1 \"src/algorithm/min_plus_concave.hpp\"\
    \n// b is concave\ntemplate<typename T> vector<T> minplus_conv_concave(vector<T>&\
    \ a, vector<T>& b) {\n   int n = a.size(), m = b.size();\n   if(min(n, m) == 0)\
    \ return vector<T>();\n   int h = n + m - 1, w = n;\n   vector<int> ymin(h, 0),\
    \ ymax(h, w - 1), xmin(w), xmax(w);\n   for(int x = m; x < h; x++) ymin[x] = x\
    \ - m + 1;\n   for(int x = 0; x <= h - m; x++) ymax[x] = x;\n   iota(all(xmin),\
    \ 0);\n   iota(all(xmax), m - 1);\n   vector<T> c(h, INF);  // if long long\n\
    \   auto rec = [&](auto&& rec, int x1, int x2, int y1, int y2) {\n      if(ymax[x1]\
    \ >= y2 and y1 >= ymin[x2]) {\n         auto A = [&](int i, int j) { return a[y2\
    \ - j] + b[x1 + i - y2 + j]; };\n         auto jmin = monotone_minima<T>(x2 -\
    \ x1 + 1, y2 - y1 + 1, A);\n         for(int i = x1; i <= x2; i++) chmin(c[i],\
    \ A(i - x1, jmin[i - x1]));\n         return;\n      }\n      if((ll)(x2 - x1)\
    \ * (y2 - y1) < 1000) {\n         for(int x = x1; x <= x2; x++)\n            for(int\
    \ y = max(ymin[x], y1); y <= min(ymax[x], y2); y++) chmin(c[x], a[y] + b[x - y]);\n\
    \         return;\n      }\n      if(x2 - x1 > y2 - y1) {\n         int xm = (x1\
    \ + x2) / 2;\n         int ny2 = min(ymax[xm], y2), ny1 = max(ymin[xm], y1);\n\
    \         if(y1 <= ny2) rec(rec, x1, xm, y1, ny2);\n         if(ny1 <= y2) rec(rec,\
    \ xm + 1, x2, ny1, y2);\n      } else {\n         int ym = (y1 + y2) / 2;\n  \
    \       int nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym], x1);\n         if(x1\
    \ <= nx2) rec(rec, x1, nx2, y1, ym);\n         if(nx1 <= x2) rec(rec, nx1, x2,\
    \ ym + 1, y2);\n      }\n   };\n   rec(rec, 0, h - 1, 0, w - 1);\n   return c;\n\
    }\n#line 80 \"test/algorithm/min_plus_concave.test.cpp\"\nint main() { puts(\"\
    Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/269644\n\
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
    \   for(auto [idx, val] : dp) ret.push_back(idx);\n   return ret;\n}\n\n// b is\
    \ concave\ntemplate<typename T> vector<T> minplus_conv_concave(vector<T> &a, vector<T>\
    \ &b) {\n   int n = a.size(), m = b.size();\n   if(min(n, m) == 0) return vector<T>\
    \ ();\n   int h = n + m - 1, w = n;\n   vector<int> ymin(h, 0), ymax(h, w - 1),\
    \ xmin(w), xmax(w);\n   for(int x = m; x < h; x ++) ymin[x] = x - m + 1;\n   for(int\
    \ x = 0; x <= h - m; x ++) ymax[x] = x;\n   iota(all(xmin), 0); iota(all(xmax),\
    \ m - 1);\n   vector<T> c(h, INF); // if long long\n   auto rec = [&](auto&& rec,\
    \ int x1, int x2, int y1, int y2) {\n      if(ymax[x1] >= y2 and y1 >= ymin[x2])\
    \ {\n         auto A = [&](int i, int j) { return a[y2 - j] + b[x1 + i - y2 +\
    \ j]; };\n         auto jmin = monotone_minima<T>(x2 - x1 + 1, y2 - y1 + 1, A);\n\
    \         for(int i = x1; i <= x2; i ++) chmin(c[i], A(i - x1, jmin[i - x1]));\n\
    \         return;\n      }\n      if((ll)(x2 - x1) * (y2 - y1) < 1000) {\n   \
    \      for(int x = x1; x <= x2; x ++) for(int y = max(ymin[x], y1); y <= min(ymax[x],\
    \ y2); y ++) chmin(c[x], a[y] + b[x - y]);\n         return;\n      }\n      if(x2\
    \ - x1 > y2 - y1) {\n         int xm = (x1 + x2) / 2;\n         int ny2 = min(ymax[xm],\
    \ y2), ny1 = max(ymin[xm], y1);\n         if(y1 <= ny2) rec(rec, x1, xm, y1, ny2);\n\
    \         if(ny1 <= y2) rec(rec, xm + 1, x2, ny1, y2);\n\t\t} else {\n       \
    \  int ym = (y1 + y2) / 2;\n         int nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym],\
    \ x1);\n         if(x1 <= nx2) rec(rec, x1, nx2, y1, ym);\n         if(nx1 <=\
    \ x2) rec(rec, nx1, x2, ym + 1, y2);\n      }\n\t};\n   rec(rec, 0, h - 1, 0,\
    \ w - 1);\n   return c;\n}\nint main() {\n   int n, m; cin >> n >> m; vector<ll>\
    \ a(n), b(m);\n   for(int i = 0; i < n; i ++) cin >> a[i];\n   for(int i = 0;\
    \ i < m; i ++) cin >> b[i];\n   auto c = minplus_conv_concave(b, a);\n   for(ll\
    \ e : c) cout << e << \" \";\n   cout << endl;\n   return 0;\n}\n*/\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/algorithm/min_plus_conv.hpp\"\
    \n#include \"src/algorithm/min_plus_concave.hpp\"\nint main() { puts(\"Hello World\"\
    ); }"
  dependsOn:
  - test/template.hpp
  - src/algorithm/min_plus_conv.hpp
  - src/algorithm/min_plus_concave.hpp
  isVerificationFile: true
  path: test/algorithm/min_plus_concave.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 17:43:49+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/min_plus_concave.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/min_plus_concave.test.cpp
- /verify/test/algorithm/min_plus_concave.test.cpp.html
title: test/algorithm/min_plus_concave.test.cpp
---
