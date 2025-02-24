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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://judge.yosupo.jp/submission/269321
  bundledCode: "#line 1 \"test/FPS/fps_sparse.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\u307F\
    \ https://judge.yosupo.jp/submission/269321\n\n/*\n#include <bits/stdc++.h>\n\
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
    \         b >>= 1;\n      }\n      return c;\n   }\n};\n\nvector<mm> fps_inv_sparse(const\
    \ vector<pair<int, mm>> &dat, int n = -1) {\n   // assert(dat[0].first == 0 and\
    \ dat[0].second.x != 0);\n   if(n == -1) n = dat.back().first + 1;\n   vector<mm>\
    \ g(n);\n   mm g0 = dat[0].second.inv();\n   g[0] = g0;\n   for(int i = 1; i <\
    \ n; i ++) {\n      mm rhs = 0;\n      for(auto&& [k, fk] : dat) {\n         if(k\
    \ > i) break;\n         rhs -= fk * g[i - k];\n      }\n      g[i] = rhs * g0;\n\
    \   }\n   return g;\n}\n\nint main() {\n   int n, k;\n   cin >> n >> k;\n   vector<pair<int,\
    \ mm>> vec;\n   for(int i = 0; i < k; i ++) {\n      ll x, y; cin >> x >> y;\n\
    \      vec.push_back({x, y});\n   }\n   auto ret = fps_inv_sparse(vec, n);\n \
    \  for(int i = 0; i < n; i ++) {\n      cout << ret[i].x << \" \";\n   }\n   cout\
    \ << '\\n';\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    src/FPS/fps_sparse.hpp\"\nvector<mm> fps_inv_sparse(const vector<pair<int, mm>>\
    \ &dat, int n = -1) {\n   // assert(dat[0].first == 0 and dat[0].second.x != 0);\n\
    \   if(n == -1) n = dat.back().first + 1;\n   vector<mm> g(n);\n   mm g0 = dat[0].second.inv();\n\
    \   g[0] = g0;\n   for(int i = 1; i < n; i ++) {\n      mm rhs = 0;\n      for(auto&&\
    \ [k, fk] : dat) {\n         if(k > i) break;\n         rhs -= fk * g[i - k];\n\
    \      }\n      g[i] = rhs * g0;\n   }\n   return g;\n}\n\nvector<mm> fps_exp_sparse(vector<mm>&\
    \ f) {\n   if ((int)f.size() == 0) return {mm(1)};\n   // assert(f[0].x == 0);\n\
    \   int N = f.size();\n   vector<pair<int, mm>> dat;\n   for(int i = 1; i < N;\
    \ i ++) if (f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);\n   vector<mm> F(N);\n\
    \   F[0] = 1;\n   for(int n = 1; n < N; n ++) {\n      mm rhs = 0;\n      for\
    \ (auto&& [k, fk]: dat) {\n         if (k > n - 1) break;\n         rhs += fk\
    \ * F[n - 1 - k];\n      }\n      F[n] = rhs * mm(n).inv();\n   }\n   return F;\n\
    }\n#line 78 \"test/FPS/fps_sparse.test.cpp\"\nint main() { puts(\"Hello World\"\
    ); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/269321\n\
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
    };\n\nvector<mm> fps_inv_sparse(const vector<pair<int, mm>> &dat, int n = -1)\
    \ {\n   // assert(dat[0].first == 0 and dat[0].second.x != 0);\n   if(n == -1)\
    \ n = dat.back().first + 1;\n   vector<mm> g(n);\n   mm g0 = dat[0].second.inv();\n\
    \   g[0] = g0;\n   for(int i = 1; i < n; i ++) {\n      mm rhs = 0;\n      for(auto&&\
    \ [k, fk] : dat) {\n         if(k > i) break;\n         rhs -= fk * g[i - k];\n\
    \      }\n      g[i] = rhs * g0;\n   }\n   return g;\n}\n\nint main() {\n   int\
    \ n, k;\n   cin >> n >> k;\n   vector<pair<int, mm>> vec;\n   for(int i = 0; i\
    \ < k; i ++) {\n      ll x, y; cin >> x >> y;\n      vec.push_back({x, y});\n\
    \   }\n   auto ret = fps_inv_sparse(vec, n);\n   for(int i = 0; i < n; i ++) {\n\
    \      cout << ret[i].x << \" \";\n   }\n   cout << '\\n';\n   return 0;\n}\n\
    */\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/FPS/fps_sparse.hpp\"\nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/fps_sparse.hpp
  isVerificationFile: true
  path: test/FPS/fps_sparse.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 05:53:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/fps_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/fps_sparse.test.cpp
- /verify/test/FPS/fps_sparse.test.cpp.html
title: test/FPS/fps_sparse.test.cpp
---
