---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/FFT.hpp
    title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
      \u307F)"
  - icon: ':heavy_check_mark:'
    path: src/FPS/bostan_mori.hpp
    title: src/FPS/bostan_mori.hpp
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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://judge.yosupo.jp/submission/269281
  bundledCode: "#line 1 \"test/FPS/bostan_mori.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\
    \u307F https://judge.yosupo.jp/submission/269281\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n\nconst\
    \ ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n\
    \      if(x < 0) x += mod;\n   }\n   friend mm operator-(mm a) { return -a.x;\
    \ }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend mm operator-(mm\
    \ a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a, mm b) { return\
    \ a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a * b.inv(); }\n \
    \  // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\
    \u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm& a, mm b) {\
    \ return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) { return a =\
    \ a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x;\
    \ }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm\
    \ inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a =\
    \ *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n\
    \         b >>= 1;\n      }\n      return c;\n   }\n};\n\n// {998244353, 3}, {1811939329,\
    \ 13}, {2013265921, 31}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>&\
    \ a) {\n   ll n = size(a), lg = __lg(n);\n   assert((1 << lg) == n);\n   vector<mm>\
    \ b(n);\n   for(int l = 1; l <= lg; l++) {\n      ll w = n >> l;\n      mm s =\
    \ 1, r = g.pow(mod >> l);\n      for(ll u = 0; u < n / 2; u += w) {\n        \
    \ for(int d = 0; d < w; d++) {\n            mm x = a[u << 1 | d], y = a[u << 1\
    \ | w | d] * s;\n            b[u | d] = x + y;\n            b[n >> 1 | u | d]\
    \ = x - y;\n         }\n         s *= r;\n      }\n      swap(a, b);\n   }\n}\n\
    vector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty()) return\
    \ {};\n   size_t s = size(a) + size(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   for(int i = 0; i < n; i++)\
    \ a[i] *= b[i] * inv;\n   reverse(1 + all(a));\n   fft(a);\n   a.resize(s);\n\
    \   return a;\n}\n\n// Bostan-Mori\n// find [x^N] P(x)/Q(x), O(K log K log N)\n\
    // deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1\nmm BostanMori(vector<mm> P, vector<mm>\
    \ Q, ll N) {\n   const int d = Q.size();\n   for (; N; N >>= 1) {\n      auto\
    \ Q_neg = Q;\n      for (size_t i = 1; i < Q.size(); i += 2) Q_neg[i] *= -1;\n\
    \      P = conv(P, Q_neg);\n      Q = conv(Q, Q_neg);\n      for (size_t i = N\
    \ & 1; i < P.size(); i += 2) P[i >> 1] = P[i];\n      for (size_t i = 0; i < Q.size();\
    \ i += 2) Q[i >> 1] = Q[i];\n      P.resize(d - 1);\n      Q.resize(d);\n   }\n\
    \   return P[0];\n}\n\nint main() {\n   ll d, k; cin >> d >> k;\n   vector<mm>\
    \ a(d), c(d + 1);\n   for(int i = 0; i < d; i ++) {\n      ll x; cin >> x;\n \
    \     a[i] = x;\n   }\n   c[0] = 1;\n   for(int i = 1; i <= d; i ++) {\n     \
    \ ll x; cin >> x;\n      c[i] = -x;\n   }\n   a = conv(a, c);\n   a.resize(d);\n\
    \   cout << BostanMori(a, c, k).x << endl;\n   return 0;\n}\n*/\n\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
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
    }\n#line 1 \"src/FPS/bostan_mori.hpp\"\n// find [x^N] P(x)/Q(x), O(K log K log\
    \ N)\n// deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1\nmm BostanMori(vector<mm> P, vector<mm>\
    \ Q, ll N) {\n   const int d = Q.size();\n   for(; N; N >>= 1) {\n      auto Q_neg\
    \ = Q;\n      for(size_t i = 1; i < Q.size(); i += 2) Q_neg[i] *= -1;\n      P\
    \ = conv(P, Q_neg);\n      Q = conv(Q, Q_neg);\n      for(size_t i = N & 1; i\
    \ < P.size(); i += 2) P[i >> 1] = P[i];\n      for(size_t i = 0; i < Q.size();\
    \ i += 2) Q[i >> 1] = Q[i];\n      P.resize(d - 1);\n      Q.resize(d);\n   }\n\
    \   return P[0];\n}\n#line 118 \"test/FPS/bostan_mori.test.cpp\"\nint main() {\
    \ puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/269281\n\
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
    };\n\n// {998244353, 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\
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
    \ + all(a));\n   fft(a);\n   a.resize(s);\n   return a;\n}\n\n// Bostan-Mori\n\
    // find [x^N] P(x)/Q(x), O(K log K log N)\n// deg(Q(x)) = K, deg(P(x)) < K, Q[0]\
    \ = 1\nmm BostanMori(vector<mm> P, vector<mm> Q, ll N) {\n   const int d = Q.size();\n\
    \   for (; N; N >>= 1) {\n      auto Q_neg = Q;\n      for (size_t i = 1; i <\
    \ Q.size(); i += 2) Q_neg[i] *= -1;\n      P = conv(P, Q_neg);\n      Q = conv(Q,\
    \ Q_neg);\n      for (size_t i = N & 1; i < P.size(); i += 2) P[i >> 1] = P[i];\n\
    \      for (size_t i = 0; i < Q.size(); i += 2) Q[i >> 1] = Q[i];\n      P.resize(d\
    \ - 1);\n      Q.resize(d);\n   }\n   return P[0];\n}\n\nint main() {\n   ll d,\
    \ k; cin >> d >> k;\n   vector<mm> a(d), c(d + 1);\n   for(int i = 0; i < d; i\
    \ ++) {\n      ll x; cin >> x;\n      a[i] = x;\n   }\n   c[0] = 1;\n   for(int\
    \ i = 1; i <= d; i ++) {\n      ll x; cin >> x;\n      c[i] = -x;\n   }\n   a\
    \ = conv(a, c);\n   a.resize(d);\n   cout << BostanMori(a, c, k).x << endl;\n\
    \   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/FPS/FFT.hpp\"\n#include \"src/FPS/bostan_mori.hpp\"\nint main() { puts(\"\
    Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/FFT.hpp
  - src/FPS/bostan_mori.hpp
  isVerificationFile: true
  path: test/FPS/bostan_mori.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 10:33:49+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/bostan_mori.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/bostan_mori.test.cpp
- /verify/test/FPS/bostan_mori.test.cpp.html
title: test/FPS/bostan_mori.test.cpp
---
