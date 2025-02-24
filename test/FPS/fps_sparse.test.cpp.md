---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/fps_sparse.hpp
    title: src/FPS/fps_sparse.hpp
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
    - https://atcoder.jp/contests/abc276/submissions/63131136
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://judge.yosupo.jp/submission/269611
    - https://judge.yosupo.jp/submission/269612
    - https://judge.yosupo.jp/submission/269613
  bundledCode: "#line 1 \"test/FPS/fps_sparse.test.cpp\"\n/* AC\u78BA\u8A8D\u6E08\u307F\
    \nhttps://judge.yosupo.jp/submission/269611\nhttps://judge.yosupo.jp/submission/269612\n\
    https://judge.yosupo.jp/submission/269613\nhttps://atcoder.jp/contests/abc276/submissions/63131136\n\
    */\n\n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
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
    };\n\nusing vm = vector<mm>;\nvm fps_inv_sparse(vm& f) {\n   int n = f.size();\
    \ vector<pair<int, mm>> dat;\n   for(int i = 0; i < n; i++) if(f[i].x) dat.emplace_back(i,\
    \ f[i]);\n   vm g(n); mm g0 = f[0].inv(); g[0] = g0;\n   for(int i = 1; i < n;\
    \ i++) {\n      mm rhs = 0;\n      for(auto&& [k, fk] : dat) { if(k > i) break;\
    \ rhs -= fk * g[i - k]; }\n      g[i] = rhs * g0;\n   }\n   return g;\n}\nvm fps_exp_sparse(vm&\
    \ f) {\n   if((int)f.size() == 0) return {mm(1)};\n   int N = f.size(); vector<pair<int,\
    \ mm>> dat;\n   for(int i = 1; i < N; i++) if(f[i].x) dat.emplace_back(i - 1,\
    \ mm(i) * f[i]);\n   vm F(N); F[0] = 1;\n   for(int n = 1; n < N; n++) {\n   \
    \   mm rhs = 0;\n      for(auto&& [k, fk] : dat) { if(k > n - 1) break; rhs +=\
    \ fk * F[n - 1 - k]; }\n      F[n] = rhs * mm(n).inv();\n   }\n   return F;\n\
    }\nvm fps_log_sparse(vm& f) {\n   int N = f.size(); vector<pair<int, mm>> dat;\n\
    \   for(int i = 1; i < N; i ++) if(f[i].x) dat.emplace_back(i, f[i]);\n   vm F(N),\
    \ g(N - 1);\n   for(int n = 0; n < N - 1; n ++) {\n      mm rhs = mm(n + 1) *\
    \ f[n + 1];\n      for(auto &&[i, fi] : dat) { if(i > n) break; rhs -= fi * g[n\
    \ - i]; }\n      g[n] = rhs; F[n + 1] = rhs * mm(n + 1).inv();\n   }\n   return\
    \ F;\n}\nvm fps_pow_product(vm& f, vm& g, mm n, mm m) {\n   int N = f.size();\
    \ using P = pair<int, mm>;\n   vector<P> dat_f, dat_g;\n   for(int i = 0; i <\
    \ (int)f.size(); i ++) if(f[i].x) dat_f.emplace_back(i, f[i]);\n   for(int i =\
    \ 0; i < (int)g.size(); i ++) if(g[i].x) dat_g.emplace_back(i, g[i]);\n   vm a(N),\
    \ b(N);\n   for (auto&& [i, x]: dat_f) for (auto&& [j, y]: dat_g) {\n      if\
    \ (i + j >= N + 1) continue; \n      mm xy = x * y; if (i + j < N) a[i + j] +=\
    \ xy;\n      if (0 < i + j && i + j <= N) b[i + j - 1] -= xy * (n * mm(i) + m\
    \ * mm(j));\n   }\n   vector<P> dat_a, dat_b;\n   for(int i = 1; i < N; i ++)\
    \ if(a[i].x) dat_a.emplace_back(i, a[i]);\n   for(int i = 0; i < N; i ++) if(b[i].x)\
    \ dat_b.emplace_back(i, b[i]);\n   vm F(N), df(N - 1); F[0] = 1;\n   for(int n\
    \ = 0; n < N - 1; n ++) {\n      mm v = 0;\n      for(auto&& [i, ai] : dat_a)\
    \ { if(i > n) break; v += ai * df[n - i]; }\n      for(auto&& [i, bi] : dat_b)\
    \ { if(i > n) break; v += bi * F[n - i]; }\n      df[n] = -v; F[n + 1] = df[n]\
    \ * mm(n + 1).inv();\n   }\n   return F;\n}\n\nint main() {\n   ll n, m; cin >>\
    \ n >> m;\n   n --;\n   m -= n;\n   if(m < 0) {\n      cout << 0 << endl;\n  \
    \    return 0;\n   }\n   vm f = {1, 1}, g = {1, 0, 0, -1};\n   f.resize(m + 1);\n\
    \   g.resize(m + 1);\n   f = fps_pow_product(f, g, n, -n);\n   n = f.size();\n\
    \   for(int j = 0; j < 2; j ++) for(int i = 1; i < n; i ++) f[i] += f[i - 1];\n\
    \   cout << f[m].x << endl;\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    src/FPS/fps_sparse.hpp\"\nusing vm = vector<mm>;\nvm fps_inv_sparse(vm& f) {\n\
    \   int n = f.size(); vector<pair<int, mm>> dat;\n   for(int i = 0; i < n; i++)\
    \ if(f[i].x) dat.emplace_back(i, f[i]);\n   vm g(n); mm g0 = f[0].inv(); g[0]\
    \ = g0;\n   for(int i = 1; i < n; i++) {\n      mm rhs = 0;\n      for(auto&&\
    \ [k, fk] : dat) { if(k > i) break; rhs -= fk * g[i - k]; }\n      g[i] = rhs\
    \ * g0;\n   }\n   return g;\n}\nvm fps_exp_sparse(vm& f) {\n   if((int)f.size()\
    \ == 0) return {mm(1)};\n   int N = f.size(); vector<pair<int, mm>> dat;\n   for(int\
    \ i = 1; i < N; i++) if(f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);\n   vm\
    \ F(N); F[0] = 1;\n   for(int n = 1; n < N; n++) {\n      mm rhs = 0;\n      for(auto&&\
    \ [k, fk] : dat) { if(k > n - 1) break; rhs += fk * F[n - 1 - k]; }\n      F[n]\
    \ = rhs * mm(n).inv();\n   }\n   return F;\n}\nvm fps_log_sparse(vm& f) {\n  \
    \ int N = f.size(); vector<pair<int, mm>> dat;\n   for(int i = 1; i < N; i ++)\
    \ if(f[i].x) dat.emplace_back(i, f[i]);\n   vm F(N), g(N - 1);\n   for(int n =\
    \ 0; n < N - 1; n ++) {\n      mm rhs = mm(n + 1) * f[n + 1];\n      for(auto\
    \ &&[i, fi] : dat) { if(i > n) break; rhs -= fi * g[n - i]; }\n      g[n] = rhs;\
    \ F[n + 1] = rhs * mm(n + 1).inv();\n   }\n   return F;\n}\nvm fps_pow_product(vm&\
    \ f, vm& g, mm n, mm m) {\n   int N = f.size(); using P = pair<int, mm>;\n   vector<P>\
    \ dat_f, dat_g;\n   for(int i = 0; i < (int)f.size(); i ++) if(f[i].x) dat_f.emplace_back(i,\
    \ f[i]);\n   for(int i = 0; i < (int)g.size(); i ++) if(g[i].x) dat_g.emplace_back(i,\
    \ g[i]);\n   vm a(N), b(N);\n   for (auto&& [i, x]: dat_f) for (auto&& [j, y]:\
    \ dat_g) {\n      if (i + j >= N + 1) continue; \n      mm xy = x * y; if (i +\
    \ j < N) a[i + j] += xy;\n      if (0 < i + j && i + j <= N) b[i + j - 1] -= xy\
    \ * (n * mm(i) + m * mm(j));\n   }\n   vector<P> dat_a, dat_b;\n   for(int i =\
    \ 1; i < N; i ++) if(a[i].x) dat_a.emplace_back(i, a[i]);\n   for(int i = 0; i\
    \ < N; i ++) if(b[i].x) dat_b.emplace_back(i, b[i]);\n   vm F(N), df(N - 1); F[0]\
    \ = 1;\n   for(int n = 0; n < N - 1; n ++) {\n      mm v = 0;\n      for(auto&&\
    \ [i, ai] : dat_a) { if(i > n) break; v += ai * df[n - i]; }\n      for(auto&&\
    \ [i, bi] : dat_b) { if(i > n) break; v += bi * F[n - i]; }\n      df[n] = -v;\
    \ F[n + 1] = df[n] * mm(n + 1).inv();\n   }\n   return F;\n}\n#line 127 \"test/FPS/fps_sparse.test.cpp\"\
    \nint main() { puts(\"Hello World\"); }\n"
  code: "/* AC\u78BA\u8A8D\u6E08\u307F\nhttps://judge.yosupo.jp/submission/269611\n\
    https://judge.yosupo.jp/submission/269612\nhttps://judge.yosupo.jp/submission/269613\n\
    https://atcoder.jp/contests/abc276/submissions/63131136\n*/\n\n/*\n#include <bits/stdc++.h>\n\
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
    \         b >>= 1;\n      }\n      return c;\n   }\n};\n\nusing vm = vector<mm>;\n\
    vm fps_inv_sparse(vm& f) {\n   int n = f.size(); vector<pair<int, mm>> dat;\n\
    \   for(int i = 0; i < n; i++) if(f[i].x) dat.emplace_back(i, f[i]);\n   vm g(n);\
    \ mm g0 = f[0].inv(); g[0] = g0;\n   for(int i = 1; i < n; i++) {\n      mm rhs\
    \ = 0;\n      for(auto&& [k, fk] : dat) { if(k > i) break; rhs -= fk * g[i - k];\
    \ }\n      g[i] = rhs * g0;\n   }\n   return g;\n}\nvm fps_exp_sparse(vm& f) {\n\
    \   if((int)f.size() == 0) return {mm(1)};\n   int N = f.size(); vector<pair<int,\
    \ mm>> dat;\n   for(int i = 1; i < N; i++) if(f[i].x) dat.emplace_back(i - 1,\
    \ mm(i) * f[i]);\n   vm F(N); F[0] = 1;\n   for(int n = 1; n < N; n++) {\n   \
    \   mm rhs = 0;\n      for(auto&& [k, fk] : dat) { if(k > n - 1) break; rhs +=\
    \ fk * F[n - 1 - k]; }\n      F[n] = rhs * mm(n).inv();\n   }\n   return F;\n\
    }\nvm fps_log_sparse(vm& f) {\n   int N = f.size(); vector<pair<int, mm>> dat;\n\
    \   for(int i = 1; i < N; i ++) if(f[i].x) dat.emplace_back(i, f[i]);\n   vm F(N),\
    \ g(N - 1);\n   for(int n = 0; n < N - 1; n ++) {\n      mm rhs = mm(n + 1) *\
    \ f[n + 1];\n      for(auto &&[i, fi] : dat) { if(i > n) break; rhs -= fi * g[n\
    \ - i]; }\n      g[n] = rhs; F[n + 1] = rhs * mm(n + 1).inv();\n   }\n   return\
    \ F;\n}\nvm fps_pow_product(vm& f, vm& g, mm n, mm m) {\n   int N = f.size();\
    \ using P = pair<int, mm>;\n   vector<P> dat_f, dat_g;\n   for(int i = 0; i <\
    \ (int)f.size(); i ++) if(f[i].x) dat_f.emplace_back(i, f[i]);\n   for(int i =\
    \ 0; i < (int)g.size(); i ++) if(g[i].x) dat_g.emplace_back(i, g[i]);\n   vm a(N),\
    \ b(N);\n   for (auto&& [i, x]: dat_f) for (auto&& [j, y]: dat_g) {\n      if\
    \ (i + j >= N + 1) continue; \n      mm xy = x * y; if (i + j < N) a[i + j] +=\
    \ xy;\n      if (0 < i + j && i + j <= N) b[i + j - 1] -= xy * (n * mm(i) + m\
    \ * mm(j));\n   }\n   vector<P> dat_a, dat_b;\n   for(int i = 1; i < N; i ++)\
    \ if(a[i].x) dat_a.emplace_back(i, a[i]);\n   for(int i = 0; i < N; i ++) if(b[i].x)\
    \ dat_b.emplace_back(i, b[i]);\n   vm F(N), df(N - 1); F[0] = 1;\n   for(int n\
    \ = 0; n < N - 1; n ++) {\n      mm v = 0;\n      for(auto&& [i, ai] : dat_a)\
    \ { if(i > n) break; v += ai * df[n - i]; }\n      for(auto&& [i, bi] : dat_b)\
    \ { if(i > n) break; v += bi * F[n - i]; }\n      df[n] = -v; F[n + 1] = df[n]\
    \ * mm(n + 1).inv();\n   }\n   return F;\n}\n\nint main() {\n   ll n, m; cin >>\
    \ n >> m;\n   n --;\n   m -= n;\n   if(m < 0) {\n      cout << 0 << endl;\n  \
    \    return 0;\n   }\n   vm f = {1, 1}, g = {1, 0, 0, -1};\n   f.resize(m + 1);\n\
    \   g.resize(m + 1);\n   f = fps_pow_product(f, g, n, -n);\n   n = f.size();\n\
    \   for(int j = 0; j < 2; j ++) for(int i = 1; i < n; i ++) f[i] += f[i - 1];\n\
    \   cout << f[m].x << endl;\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/FPS/fps_sparse.hpp\"\nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/fps_sparse.hpp
  isVerificationFile: true
  path: test/FPS/fps_sparse.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 23:46:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/fps_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/fps_sparse.test.cpp
- /verify/test/FPS/fps_sparse.test.cpp.html
title: test/FPS/fps_sparse.test.cpp
---
