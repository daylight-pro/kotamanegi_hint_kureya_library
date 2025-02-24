---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/FFT.hpp
    title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
      \u307F)"
  - icon: ':heavy_check_mark:'
    path: src/FPS/fps.hpp
    title: src/FPS/fps.hpp
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
    - https://judge.yosupo.jp/submission/269563
  bundledCode: "#line 1 \"test/FPS/fps.test.cpp\"\n// \u3059\u3079\u3066AC\u6E08\u307F\
    \ https://judge.yosupo.jp/submission/269563\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define all(v) (v).begin(),(v).end()\n#define pb(a) push_back(a)\n\
    #define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e, v) for(auto&& e : v)\n\
    using ll = long long;\nconst ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL\
    \ << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\nconst ll\
    \ mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n\
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
    \nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty())\
    \ return {};\n   size_t s = size(a) + size(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   for(int i = 0; i < n; i++)\
    \ a[i] *= b[i] * inv;\n   reverse(1 + all(a));\n   fft(a);\n   a.resize(s);\n\
    \   return a;\n}\n\nusing vm = vector<mm>;\nvm pre(vm f, int sz) {return vm(f.begin(),\
    \ f.begin() + min((int)f.size(), sz));}\nvm inv(vm f, int deg = -1) {\n   if (deg\
    \ < 0) deg = (int)f.size();\n   vm res({mm(1) / f[0]});\n   for (int i = 1; i\
    \ < deg; i <<= 1) {\n      vm ff = conv(res, conv(res, pre(f, i << 1)));\n   \
    \   int sz = res.size();\n      for(int j = 0; j < sz; j ++) res[j] += res[j];\n\
    \      sz = max(sz, (int)ff.size());\n      res.resize(sz); sz = ff.size();\n\
    \      for(int j = 0; j < sz; j ++) res[j] -= ff[j];\n      res = pre(res, i <<\
    \ 1);\n   }\n   res.resize(deg); return res;\n}\nvm diff(vm f) {\n   int n = f.size();\
    \ vm res(n - 1);\n   for(int i = 1; i < n; i ++) res[i - 1] = f[i] * i;\n   return\
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
    \  for(int i = 0; i < n; i ++) f[i] *= finv[i];\n   return f;\n}\n\nint main()\
    \ {\n   cin.tie(0);\n   ios::sync_with_stdio(false);\n   int n, c; cin >> n >>\
    \ c;\n   vm a(n);\n   for(int i = 0; i < n; i ++) {\n      int x; cin >> x;\n\
    \      a[i] = x;\n   }\n   auto ret = taylor_shift(a, mm(c));\n   for(int i =\
    \ 0; i < n; i ++) cout << ret[i].x << endl;\n   return 0;\n}\n*/\n\n#define PROBLEM\
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
    }\n#line 1 \"src/FPS/fps.hpp\"\nusing vm = vector<mm>;\nvm pre(vm f, int sz) {\
    \ return vm(f.begin(), f.begin() + min((int)f.size(), sz)); }\nvm inv(vm f, int\
    \ deg = -1) {\n   if(deg < 0) deg = (int)f.size();\n   vm res({mm(1) / f[0]});\n\
    \   for(int i = 1; i < deg; i <<= 1) {\n      vm ff = conv(res, conv(res, pre(f,\
    \ i << 1)));\n      int sz = res.size();\n      for(int j = 0; j < sz; j++) res[j]\
    \ += res[j];\n      sz = max(sz, (int)ff.size());\n      res.resize(sz);\n   \
    \   sz = ff.size();\n      for(int j = 0; j < sz; j++) res[j] -= ff[j];\n    \
    \  res = pre(res, i << 1);\n   }\n   res.resize(deg);\n   return res;\n}\nvm diff(vm\
    \ f) {\n   int n = f.size();\n   vm res(n - 1);\n   for(int i = 1; i < n; i++)\
    \ res[i - 1] = f[i] * i;\n   return res;\n}\nvm intg(vm f) {\n   int n = (int)f.size();\n\
    \   vm res(n + 1, 0);\n   for(int i = 0; i < n; i++) res[i + 1] = f[i] / (i +\
    \ 1);\n   return res;\n}\nvm log(vm f, int deg = -1) {\n   if(deg == -1) deg =\
    \ f.size();\n   vm res = intg(conv(diff(f), inv(f, deg)));\n   res.resize(deg);\n\
    \   return res;\n}\nvm exp(vm f, int deg = -1) {\n   vm res(1, 1);\n   if(deg\
    \ == -1) deg = f.size();\n   for(int i = 1; i < deg; i <<= 1) {\n      vm ff1\
    \ = pre(f, i << 1);\n      vm ff2 = log(res, i << 1);\n      ff1.resize(max(ff1.size(),\
    \ ff2.size()));\n      ff1[0] += mm(1);\n      int sz = ff2.size();\n      for(int\
    \ j = 0; j < sz; j++) ff1[j] -= ff2[j];\n      res = conv(res, pre(ff1, i << 1));\n\
    \   }\n   res.resize(deg);\n   return res;\n}\nvm taylor_shift(vm f, mm a) {\n\
    \   int n = f.size();\n   vm fac(n, 1), inv(n, 1), finv(n, 1);\n   for(int i =\
    \ 2; i < n; i++) {\n      fac[i] = fac[i - 1] * i;\n      inv[i] = -inv[mod %\
    \ i] * (mod / i);\n      finv[i] = finv[i - 1] * inv[i];\n   }\n   for(int i =\
    \ 0; i < n; i++) f[i] *= fac[i];\n   std::reverse(f.begin(), f.end());\n   vm\
    \ g(n, 1);\n   for(int i = 1; i < n; i++) g[i] = g[i - 1] * a * inv[i];\n   f\
    \ = pre(conv(f, g), n);\n   reverse(f.begin(), f.end());\n   for(int i = 0; i\
    \ < n; i++) f[i] *= finv[i];\n   return f;\n}\n#line 162 \"test/FPS/fps.test.cpp\"\
    \nint main() { puts(\"Hello World\"); }\n"
  code: "// \u3059\u3079\u3066AC\u6E08\u307F https://judge.yosupo.jp/submission/269563\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\n#define all(v) (v).begin(),(v).end()\n\
    #define pb(a) push_back(a)\n#define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e,\
    \ v) for(auto&& e : v)\nusing ll = long long;\nconst ll MOD7 = 1000000007, MOD998\
    \ = 998244353, INF = (1LL << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\
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
    \    a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\n\n// {998244353,\
    \ 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid\
    \ fft(vector<mm>& a) {\n   ll n = size(a), lg = __lg(n);\n   assert((1 << lg)\
    \ == n);\n   vector<mm> b(n);\n   for(int l = 1; l <= lg; l++) {\n      ll w =\
    \ n >> l;\n      mm s = 1, r = g.pow(mod >> l);\n      for(ll u = 0; u < n / 2;\
    \ u += w) {\n         for(int d = 0; d < w; d++) {\n            mm x = a[u <<\
    \ 1 | d], y = a[u << 1 | w | d] * s;\n            b[u | d] = x + y;\n        \
    \    b[n >> 1 | u | d] = x - y;\n         }\n         s *= r;\n      }\n     \
    \ swap(a, b);\n   }\n}\n\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t s = size(a) + size(b) - 1, n = bit_ceil(s);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   for(int\
    \ i = 0; i < n; i++) a[i] *= b[i] * inv;\n   reverse(1 + all(a));\n   fft(a);\n\
    \   a.resize(s);\n   return a;\n}\n\nusing vm = vector<mm>;\nvm pre(vm f, int\
    \ sz) {return vm(f.begin(), f.begin() + min((int)f.size(), sz));}\nvm inv(vm f,\
    \ int deg = -1) {\n   if (deg < 0) deg = (int)f.size();\n   vm res({mm(1) / f[0]});\n\
    \   for (int i = 1; i < deg; i <<= 1) {\n      vm ff = conv(res, conv(res, pre(f,\
    \ i << 1)));\n      int sz = res.size();\n      for(int j = 0; j < sz; j ++) res[j]\
    \ += res[j];\n      sz = max(sz, (int)ff.size());\n      res.resize(sz); sz =\
    \ ff.size();\n      for(int j = 0; j < sz; j ++) res[j] -= ff[j];\n      res =\
    \ pre(res, i << 1);\n   }\n   res.resize(deg); return res;\n}\nvm diff(vm f) {\n\
    \   int n = f.size(); vm res(n - 1);\n   for(int i = 1; i < n; i ++) res[i - 1]\
    \ = f[i] * i;\n   return res;\n}\nvm intg(vm f) {\n   int n = (int)f.size(); vm\
    \ res(n+1, 0);\n   for (int i = 0; i < n; i ++) res[i + 1] = f[i] / (i+1);\n \
    \  return res;\n}\nvm log(vm f, int deg = -1) {\n   if(deg == -1) deg = f.size();\n\
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
    \ *= finv[i];\n   return f;\n}\n\nint main() {\n   cin.tie(0);\n   ios::sync_with_stdio(false);\n\
    \   int n, c; cin >> n >> c;\n   vm a(n);\n   for(int i = 0; i < n; i ++) {\n\
    \      int x; cin >> x;\n      a[i] = x;\n   }\n   auto ret = taylor_shift(a,\
    \ mm(c));\n   for(int i = 0; i < n; i ++) cout << ret[i].x << endl;\n   return\
    \ 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/FPS/FFT.hpp\"\n#include \"src/FPS/fps.hpp\"\nint main() { puts(\"Hello\
    \ World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/FFT.hpp
  - src/FPS/fps.hpp
  isVerificationFile: true
  path: test/FPS/fps.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 17:43:49+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/fps.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/fps.test.cpp
- /verify/test/FPS/fps.test.cpp.html
title: test/FPS/fps.test.cpp
---
