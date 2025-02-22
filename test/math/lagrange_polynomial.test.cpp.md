---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/combination.hpp
    title: src/math/combination.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/lagrange_polynomial.hpp
    title: src/math/lagrange_polynomial.hpp
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
    - https://atcoder.jp/contests/arc033/submissions/62970727
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/math/lagrange_polynomial.test.cpp\"\n// AC\u78BA\u8A8D\
    \u6E08\u307F https://atcoder.jp/contests/arc033/submissions/62970727\n\n/*\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n\nconst ll mod = 1000000007;\nstruct mm {\n   ll x;\n   mm(ll\
    \ x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator+(mm\
    \ a, mm b) { return a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return\
    \ a.x - b.x; }\n   friend mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend\
    \ mm operator/(mm a, mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\
    \u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\
    \u30EB\n   friend mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend\
    \ mm& operator-=(mm& a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm&\
    \ a, mm b) { return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) {\
    \ return a = a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm\
    \ pow(ll b) const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b\
    \ & 1) c *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n\
    \   }\n};\n\n\nstruct Combination {\n   ll C_MOD;\n   vector<ll> fac, finv, inv;\n\
    \   Combination(ll n, ll mod) : C_MOD(mod) {\n      n = max(n, 2LL);\n      fac.resize(n,\
    \ 0);\n      finv.resize(n, 0);\n      inv.resize(n, 0);\n      fac[0] = fac[1]\
    \ = finv[0] = finv[1] = inv[1] = 1;\n      for(int i = 2; i < n; i ++) {\n   \
    \      fac[i] = fac[i - 1] * i % mod;\n         inv[i] = mod - inv[mod % i] *\
    \ (mod / i) % mod;\n         finv[i] = finv[i - 1] * inv[i] % mod;\n      }\n\
    \   }\n   ll com(ll n, ll k) {\n      if(n < k || n < 0 || k < 0) return 0;\n\
    \      return fac[n] * (finv[k] * finv[n - k] % C_MOD) % C_MOD;\n   }\n};\n\n\
    template<typename T> T lagrange_polynomial(const vector<T>& y, ll t, ll mod =\
    \ 1000000007) {\n   int n = y.size() - 1;\n   if(t <= n) return y[t];\n   T ret(0);\n\
    \   Combination comb(n + 1, mod);\n   vector<T> dp(n + 1, 1), pd(n + 1, 1);\n\
    \   for(int i = 0; i < n; i ++) dp[i + 1] = dp[i] * (t - i);\n   for(int i = n;\
    \ i > 0; i --) pd[i - 1] = pd[i] * (t - i);\n   for(int i = 0; i <= n; i ++) {\n\
    \      T tmp = y[i] * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];\n     \
    \ ret -= ((n - i) & 1 ? tmp : T(0) - tmp);\n   }\n   return ret;\n}\n\nint main()\
    \ {\n   int N, T;\n   cin >> N;\n   vector<mm> A(N + 1);\n   for(int i = 0; i\
    \ <= N; i ++) {\n      ll x; cin >> x;\n      A[i] = x;\n   }\n   cin >> T;\n\
    \   cout << lagrange_polynomial(A, T).x << endl;   \n   return 0;\n}\n*/\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    src/math/combination.hpp\"\nstruct Combination {\n   ll C_MOD;\n   vector<ll>\
    \ fac, finv, inv;\n   Combination(ll n, ll mod) : C_MOD(mod) {\n      n = max(n,\
    \ 2LL);\n      fac.resize(n, 0);\n      finv.resize(n, 0);\n      inv.resize(n,\
    \ 0);\n      fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;\n      for(int\
    \ i = 2; i < n; i++) {\n         fac[i] = fac[i - 1] * i % mod;\n         inv[i]\
    \ = mod - inv[mod % i] * (mod / i) % mod;\n         finv[i] = finv[i - 1] * inv[i]\
    \ % mod;\n      }\n   }\n   ll com(ll n, ll k) {\n      if(n < k || n < 0 || k\
    \ < 0) return 0;\n      return fac[n] * (finv[k] * finv[n - k] % C_MOD) % C_MOD;\n\
    \   }\n};\n#line 1 \"src/math/lagrange_polynomial.hpp\"\ntemplate<typename T>\
    \ T lagrange_polynomial(const vector<T>& y, ll t, ll mod = 1000000007) {\n   int\
    \ n = y.size() - 1;\n   if(t <= n) return y[t];\n   T ret(0);\n   Combination\
    \ comb(n + 1, mod);\n   vector<T> dp(n + 1, 1), pd(n + 1, 1);\n   for(int i =\
    \ 0; i < n; i++) dp[i + 1] = dp[i] * (t - i);\n   for(int i = n; i > 0; i--) pd[i\
    \ - 1] = pd[i] * (t - i);\n   for(int i = 0; i <= n; i++) {\n      T tmp = y[i]\
    \ * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];\n      ret -= ((n - i) &\
    \ 1 ? tmp : T(0) - tmp);\n   }\n   return ret;\n}\n#line 95 \"test/math/lagrange_polynomial.test.cpp\"\
    \n\nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://atcoder.jp/contests/arc033/submissions/62970727\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    const ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto&\
    \ a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nconst ll mod = 1000000007;\nstruct mm {\n   ll x;\n\
    \   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend\
    \ mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend mm operator-(mm a,\
    \ mm b) { return a.x - b.x; }\n   friend mm operator*(mm a, mm b) { return a.x\
    \ * b.x; }\n   friend mm operator/(mm a, mm b) { return a * b.inv(); }\n   //\
    \ 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\
    \u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm& a, mm b) { return\
    \ a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x;\
    \ }\n   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }\n   friend\
    \ mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm inv() const {\
    \ return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a = *this, c = 1;\n\
    \      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n         b >>=\
    \ 1;\n      }\n      return c;\n   }\n};\n\n\nstruct Combination {\n   ll C_MOD;\n\
    \   vector<ll> fac, finv, inv;\n   Combination(ll n, ll mod) : C_MOD(mod) {\n\
    \      n = max(n, 2LL);\n      fac.resize(n, 0);\n      finv.resize(n, 0);\n \
    \     inv.resize(n, 0);\n      fac[0] = fac[1] = finv[0] = finv[1] = inv[1] =\
    \ 1;\n      for(int i = 2; i < n; i ++) {\n         fac[i] = fac[i - 1] * i %\
    \ mod;\n         inv[i] = mod - inv[mod % i] * (mod / i) % mod;\n         finv[i]\
    \ = finv[i - 1] * inv[i] % mod;\n      }\n   }\n   ll com(ll n, ll k) {\n    \
    \  if(n < k || n < 0 || k < 0) return 0;\n      return fac[n] * (finv[k] * finv[n\
    \ - k] % C_MOD) % C_MOD;\n   }\n};\n\ntemplate<typename T> T lagrange_polynomial(const\
    \ vector<T>& y, ll t, ll mod = 1000000007) {\n   int n = y.size() - 1;\n   if(t\
    \ <= n) return y[t];\n   T ret(0);\n   Combination comb(n + 1, mod);\n   vector<T>\
    \ dp(n + 1, 1), pd(n + 1, 1);\n   for(int i = 0; i < n; i ++) dp[i + 1] = dp[i]\
    \ * (t - i);\n   for(int i = n; i > 0; i --) pd[i - 1] = pd[i] * (t - i);\n  \
    \ for(int i = 0; i <= n; i ++) {\n      T tmp = y[i] * dp[i] * pd[i] * comb.finv[i]\
    \ * comb.finv[n - i];\n      ret -= ((n - i) & 1 ? tmp : T(0) - tmp);\n   }\n\
    \   return ret;\n}\n\nint main() {\n   int N, T;\n   cin >> N;\n   vector<mm>\
    \ A(N + 1);\n   for(int i = 0; i <= N; i ++) {\n      ll x; cin >> x;\n      A[i]\
    \ = x;\n   }\n   cin >> T;\n   cout << lagrange_polynomial(A, T).x << endl;  \
    \ \n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/math/combination.hpp\"\n#include \"src/math/lagrange_polynomial.hpp\"\n\
    \nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/math/combination.hpp
  - src/math/lagrange_polynomial.hpp
  isVerificationFile: true
  path: test/math/lagrange_polynomial.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/lagrange_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/lagrange_polynomial.test.cpp
- /verify/test/math/lagrange_polynomial.test.cpp.html
title: test/math/lagrange_polynomial.test.cpp
---
