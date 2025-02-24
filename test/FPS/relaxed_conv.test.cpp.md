---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/FFT.hpp
    title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
      \u307F)"
  - icon: ':heavy_check_mark:'
    path: src/FPS/relaxed_conv.hpp
    title: src/FPS/relaxed_conv.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: Modint
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
    - https://atcoder.jp/contests/abc315/submissions/63095397
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/FPS/relaxed_conv.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\
    \u307F https://atcoder.jp/contests/abc315/submissions/63095397\n\n/*\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n\nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll\
    \ x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator-(mm\
    \ a) { return -a.x; }\n   friend mm operator+(mm a, mm b) { return a.x + b.x;\
    \ }\n   friend mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm\
    \ a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return\
    \ a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\
    \u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm&\
    \ a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) {\
    \ return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a =\
    \ a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv();\
    \ }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n   \
    \   mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n     \
    \    a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\n// {998244353,\
    \ 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid\
    \ fft(vector<mm>& a) {\n   ll n = size(a), lg = __lg(n);\n   assert((1 << lg)\
    \ == n);\n   vector<mm> b(n);\n   for(int l = 1; l <= lg; l++) {\n      ll w =\
    \ n >> l;\n      mm s = 1, r = g.pow(mod >> l);\n      for(ll u = 0; u < n / 2;\
    \ u += w) {\n         for(int d = 0; d < w; d++) {\n            mm x = a[u <<\
    \ 1 | d], y = a[u << 1 | w | d] * s;\n            b[u | d] = x + y;\n        \
    \    b[n >> 1 | u | d] = x - y;\n         }\n         s *= r;\n      }\n     \
    \ swap(a, b);\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t s = size(a) + size(b) - 1, n = bit_ceil(s);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   for(int\
    \ i = 0; i < n; i++) a[i] *= b[i] * inv;\n   reverse(1 + all(a));\n   fft(a);\n\
    \   a.resize(s);\n   return a;\n}\n\n\ntemplate<typename T> class RelaxedConvolution\
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
    \   }\npublic:\n   RelaxedConvolution(int n) {\n      N = 1, pos = 0;\n      while(N\
    \ < n) N *= 2;\n      f.resize(N);\n      g.resize(N);\n      buf.resize(N);\n\
    \      event.resize(N+1);\n      dfs(N);\n   }\n   T get(T x, T y) {\n      f[pos]\
    \ = x, g[pos] = y;\n      for(auto [fl, fr, gl, gr] : event[pos]) {\n        \
    \ vector<T> A({f.begin() + fl, f.begin() + fr});\n         vector<T> B({g.begin()\
    \ + gl, g.begin() + gr});\n         auto ret = conv(A, B);\n         int sz =\
    \ ret.size();\n         for(int i = 0; i < sz; i ++) {\n            if(i + fl\
    \ + gl >= N) break;\n            buf[i + fl + gl] += ret[i];\n         }\n   \
    \   }\n      return buf[pos++];\n   }\n};\n\nint main() {\n   int n;\n   cin >>\
    \ n;\n   RelaxedConvolution<mm> f(n + 1);\n   mm sum = 0;\n   mm p = 1;\n\n  \
    \ vector<mm> ans;\n\n   for(int i = 0; i < n; i ++) {\n      ll x; cin >> x;\n\
    \      sum += f.get(p, p);\n      p = sum * mm(x);\n      ans.push_back(p);\n\
    \   }\n   for(mm x : ans) cout << x.x << \" \";\n   cout << endl;\n\n   return\
    \ 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\
    \nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ %\
    \ mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator-(mm a) { return\
    \ -a.x; }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend\
    \ mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a,\
    \ mm b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a *\
    \ b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\
    \u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm&\
    \ a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) {\
    \ return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a =\
    \ a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv();\
    \ }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n   \
    \   mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n     \
    \    a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\n#line 1 \"\
    src/FPS/FFT.hpp\"\n// {998244353, 3}, {1811939329, 13}, {2013265921, 31}\nmm g\
    \ = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n = size(a), lg\
    \ = __lg(n);\n   assert((1 << lg) == n);\n   vector<mm> b(n);\n   for(int l =\
    \ 1; l <= lg; l++) {\n      ll w = n >> l;\n      mm s = 1, r = g.pow(mod >> l);\n\
    \      for(ll u = 0; u < n / 2; u += w) {\n         for(int d = 0; d < w; d++)\
    \ {\n            mm x = a[u << 1 | d], y = a[u << 1 | w | d] * s;\n          \
    \  b[u | d] = x + y;\n            b[n >> 1 | u | d] = x - y;\n         }\n   \
    \      s *= r;\n      }\n      swap(a, b);\n   }\n}\nvector<mm> conv(vector<mm>\
    \ a, vector<mm> b) {\n   if(a.empty() || b.empty()) return {};\n   size_t s =\
    \ size(a) + size(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a), sz(b)) <= 60) \u611A\
    \u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n   fft(a);\n\
    \   fft(b);\n   mm inv = mm(n).inv();\n   for(int i = 0; i < n; i++) a[i] *= b[i]\
    \ * inv;\n   reverse(1 + all(a));\n   fft(a);\n   a.resize(s);\n   return a;\n\
    }\n#line 1 \"src/FPS/relaxed_conv.hpp\"\ntemplate<typename T> class RelaxedConvolution\
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
    \   }\npublic:\n   RelaxedConvolution(int n) {\n      N = 1, pos = 0;\n      while(N\
    \ < n) N *= 2;\n      f.resize(N);\n      g.resize(N);\n      buf.resize(N);\n\
    \      event.resize(N+1);\n      dfs(N);\n   }\n   T get(T x, T y) {\n      f[pos]\
    \ = x, g[pos] = y;\n      for(auto [fl, fr, gl, gr] : event[pos]) {\n        \
    \ vector<T> A({f.begin() + fl, f.begin() + fr});\n         vector<T> B({g.begin()\
    \ + gl, g.begin() + gr});\n         auto ret = conv(A, B);\n         int sz =\
    \ ret.size();\n         for(int i = 0; i < sz; i ++) {\n            if(i + fl\
    \ + gl >= N) break;\n            buf[i + fl + gl] += ret[i];\n         }\n   \
    \   }\n      return buf[pos++];\n   }\n};\n#line 166 \"test/FPS/relaxed_conv.test.cpp\"\
    \nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://atcoder.jp/contests/abc315/submissions/63095397\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    const ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto&\
    \ a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n\
    \   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend\
    \ mm operator-(mm a) { return -a.x; }\n   friend mm operator+(mm a, mm b) { return\
    \ a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend\
    \ mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm a,\
    \ mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift\
    \ + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend\
    \ mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm&\
    \ a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) {\
    \ return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a =\
    \ a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b)\
    \ const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c\
    \ *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n// {998244353, 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\
    \u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n = size(a), lg = __lg(n);\n  \
    \ assert((1 << lg) == n);\n   vector<mm> b(n);\n   for(int l = 1; l <= lg; l++)\
    \ {\n      ll w = n >> l;\n      mm s = 1, r = g.pow(mod >> l);\n      for(ll\
    \ u = 0; u < n / 2; u += w) {\n         for(int d = 0; d < w; d++) {\n       \
    \     mm x = a[u << 1 | d], y = a[u << 1 | w | d] * s;\n            b[u | d] =\
    \ x + y;\n            b[n >> 1 | u | d] = x - y;\n         }\n         s *= r;\n\
    \      }\n      swap(a, b);\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm>\
    \ b) {\n   if(a.empty() || b.empty()) return {};\n   size_t s = size(a) + size(b)\
    \ - 1, n = bit_ceil(s);\n   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\
    \u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n   fft(a);\n   fft(b);\n   mm\
    \ inv = mm(n).inv();\n   for(int i = 0; i < n; i++) a[i] *= b[i] * inv;\n   reverse(1\
    \ + all(a));\n   fft(a);\n   a.resize(s);\n   return a;\n}\n\n\ntemplate<typename\
    \ T> class RelaxedConvolution {\n   int N, pos;\n   vector<T> f, g, buf;\n   vector<vector<tuple<int,\
    \ int, int, int>>> event;\n   void dfs1(int le, int ri) {\n      if(ri - le ==\
    \ 1) {\n         event[le].push_back({le, le + 1, 0, 1});\n         return;\n\
    \      }\n      int mid = (le + ri) / 2;\n      event[mid].push_back({le, mid,\
    \ mid - le, ri - le});\n      event[ri].push_back({mid, ri, mid - le, ri - le});\n\
    \      dfs1(le, mid);\n      dfs1(mid, ri);\n   }\n   void dfs2(int le, int ri)\
    \ {\n      if(ri - le == 1) {\n         event[le].push_back({0, 1, le, le + 1});\n\
    \         return;\n      }\n      int mid = (le + ri) / 2;\n      event[mid].push_back({mid\
    \ - le, ri - le, le, mid});\n      event[ri].push_back({mid - le, ri - le, mid,\
    \ ri});\n      dfs2(le, mid);\n      dfs2(mid, ri);\n   }\n   void dfs(int len)\
    \ {\n      if(len == 1) {\n         event[0].push_back({0, 1, 0, 1});\n      \
    \   return;\n      }\n      int mid = len / 2;\n      event[len].push_back({mid,\
    \ len, mid, len});\n      dfs(mid);\n      dfs1(mid, len);\n      dfs2(mid, len);\n\
    \   }\npublic:\n   RelaxedConvolution(int n) {\n      N = 1, pos = 0;\n      while(N\
    \ < n) N *= 2;\n      f.resize(N);\n      g.resize(N);\n      buf.resize(N);\n\
    \      event.resize(N+1);\n      dfs(N);\n   }\n   T get(T x, T y) {\n      f[pos]\
    \ = x, g[pos] = y;\n      for(auto [fl, fr, gl, gr] : event[pos]) {\n        \
    \ vector<T> A({f.begin() + fl, f.begin() + fr});\n         vector<T> B({g.begin()\
    \ + gl, g.begin() + gr});\n         auto ret = conv(A, B);\n         int sz =\
    \ ret.size();\n         for(int i = 0; i < sz; i ++) {\n            if(i + fl\
    \ + gl >= N) break;\n            buf[i + fl + gl] += ret[i];\n         }\n   \
    \   }\n      return buf[pos++];\n   }\n};\n\nint main() {\n   int n;\n   cin >>\
    \ n;\n   RelaxedConvolution<mm> f(n + 1);\n   mm sum = 0;\n   mm p = 1;\n\n  \
    \ vector<mm> ans;\n\n   for(int i = 0; i < n; i ++) {\n      ll x; cin >> x;\n\
    \      sum += f.get(p, p);\n      p = sum * mm(x);\n      ans.push_back(p);\n\
    \   }\n   for(mm x : ans) cout << x.x << \" \";\n   cout << endl;\n\n   return\
    \ 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/FPS/FFT.hpp\"\n#include \"src/FPS/relaxed_conv.hpp\"\nint main() { puts(\"\
    Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/FFT.hpp
  - src/FPS/relaxed_conv.hpp
  isVerificationFile: true
  path: test/FPS/relaxed_conv.test.cpp
  requiredBy: []
  timestamp: '2025-02-23 20:16:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/relaxed_conv.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/relaxed_conv.test.cpp
- /verify/test/FPS/relaxed_conv.test.cpp.html
title: test/FPS/relaxed_conv.test.cpp
---
