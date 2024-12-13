---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modinv.hpp
    title: src/math/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modpow.hpp
    title: src/math/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/primality.hpp
    title: src/math/primality.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: src/math/rho.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/math/rho.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/modinv.hpp\"\
    \nll modinv(ll a, ll MOD) {\n   ll b = MOD, u = 1, v = 0;\n   while(b) {\n   \
    \   ll t = a / b;\n      a -= t * b;\n      swap(a, b);\n      u -= t * v;\n \
    \     swap(u, v);\n   }\n   u %= MOD;\n   if(u < 0) u += MOD;\n   return u;\n\
    }\n#line 1 \"src/math/modpow.hpp\"\nll modpow(ll a, ll n, ll MOD) {\n   using\
    \ T = __int128_t;\n   // using T = ll;\n   T res = 1;\n   T mul = a;\n   mul %=\
    \ MOD;\n   if(n < 0) {\n      n = -n;\n      mul = modinv(mul, MOD);\n   }\n \
    \  while(n > 0) {\n      if(n & 1) res = (res * mul) % MOD;\n      mul = (mul\
    \ * mul) % MOD;\n      n >>= 1;\n   }\n   return ll(res);\n}\n#line 1 \"src/math/primality.hpp\"\
    \nbool is_prime(ll N) {\n   if(N == 2) return true;\n   if(N == 1 || N % 2 ==\
    \ 0) return false;\n   ll s = 0;\n   ll d = N - 1;\n   while(d % 2 == 0) {\n \
    \     s++;\n      d /= 2;\n   }\n   vector<ll> tests = {2, 3, 5, 7, 11, 13, 17,\
    \ 19, 23, 29, 31, 37};\n   for(auto a : tests) {\n      if(a == N) continue;\n\
    \      ll X = modpow(a, d, N);\n      int r = 0;\n      if(X == 1) { continue;\
    \ }\n      while(X != N - 1) {\n         X = modpow(X, 2, N);\n         r++;\n\
    \         if(X == 1 || r == s) return false;\n      }\n   }\n   return true;\n\
    }\n#line 1 \"src/math/rho.hpp\"\nll find_prime_factor(ll N) {\n   using i128 =\
    \ __int128_t;\n   if(N % 2 == 0) { return 2; }\n   int b = int(sqrt(sqrt(sqrt(N))))\
    \ + 1;\n   for(ll c = 1; c < N; c++) {\n      auto f = [&](ll a) -> ll { return\
    \ modpow(a, 2, N) + c; };\n      ll y = 6;\n      ll g = 1;\n      i128 q = 1;\n\
    \      int r = 1;\n      int k = 0;\n      ll ys = 0;\n      ll x = 0;\n     \
    \ while(g == 1) {\n         x = y;\n         while(k < 3 * r / 4) {\n        \
    \    y = f(y);\n            k++;\n         }\n         while(k < r && g == 1)\
    \ {\n            ys = y;\n            for(ll i = 0; i < min(b, r - k); i++) {\n\
    \               y = f(y);\n               q *= abs(x - y);\n               q %=\
    \ N;\n            }\n            g = gcd(ll(q), N);\n            k += b;\n   \
    \      }\n         k = r;\n         r *= 2;\n      }\n      if(g == N) {\n   \
    \      g = 1;\n         y = ys;\n         while(g == 1) {\n            y = f(y);\n\
    \            g = gcd(abs(x - y), N);\n         }\n      }\n      if(g == N) {\
    \ continue; }\n      if(is_prime(g)) { return g; }\n      if(is_prime(N / g))\
    \ { return N / g; }\n      return find_prime_factor(g);\n   }\n   assert(false);\n\
    }\n\nmap<ll, int> factorize(ll N) {\n   map<ll, int> ret;\n   while(!is_prime(N)\
    \ && N > 1) {\n      ll p = find_prime_factor(N);\n      int s = 0;\n      while(N\
    \ % p == 0) {\n         N /= p;\n         s++;\n      }\n      ret[p] = s;\n \
    \  }\n   if(N > 1) { ret[N] = 1; }\n   return ret;\n}\n#line 7 \"test/math/rho.test.cpp\"\
    \n\nint main() {\n   int Q;\n   cin >> Q;\n   while(Q--) {\n      ll N;\n    \
    \  cin >> N;\n      auto mp = factorize(N);\n      vector<ll> ans;\n      for(auto\
    \ [k, v] : mp) {\n         while(v--) ans.push_back(k);\n      }\n      cout <<\
    \ size(ans);\n      for(auto x : ans) cout << \" \" << x;\n      cout << \"\\\
    n\";\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    test/template.hpp\"\n#include \"src/math/modinv.hpp\"\n#include \"src/math/modpow.hpp\"\
    \n#include \"src/math/primality.hpp\"\n#include \"src/math/rho.hpp\"\n\nint main()\
    \ {\n   int Q;\n   cin >> Q;\n   while(Q--) {\n      ll N;\n      cin >> N;\n\
    \      auto mp = factorize(N);\n      vector<ll> ans;\n      for(auto [k, v] :\
    \ mp) {\n         while(v--) ans.push_back(k);\n      }\n      cout << size(ans);\n\
    \      for(auto x : ans) cout << \" \" << x;\n      cout << \"\\n\";\n   }\n}"
  dependsOn:
  - test/template.hpp
  - src/math/modinv.hpp
  - src/math/modpow.hpp
  - src/math/primality.hpp
  - src/math/rho.hpp
  isVerificationFile: true
  path: test/math/rho.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 18:21:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/rho.test.cpp
layout: document
redirect_from:
- /verify/test/math/rho.test.cpp
- /verify/test/math/rho.test.cpp.html
title: test/math/rho.test.cpp
---
