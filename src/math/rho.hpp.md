---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/rho.test.cpp
    title: test/math/rho.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/rho.hpp\"\nll find_prime_factor(ll N) {\n   using\
    \ i128 = __int128_t;\n   if(N % 2 == 0) { return 2; }\n   int b = int(sqrt(sqrt(sqrt(N))))\
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
    \  }\n   if(N > 1) { ret[N] = 1; }\n   return ret;\n}\n"
  code: "ll find_prime_factor(ll N) {\n   using i128 = __int128_t;\n   if(N % 2 ==\
    \ 0) { return 2; }\n   int b = int(sqrt(sqrt(sqrt(N)))) + 1;\n   for(ll c = 1;\
    \ c < N; c++) {\n      auto f = [&](ll a) -> ll { return modpow(a, 2, N) + c;\
    \ };\n      ll y = 6;\n      ll g = 1;\n      i128 q = 1;\n      int r = 1;\n\
    \      int k = 0;\n      ll ys = 0;\n      ll x = 0;\n      while(g == 1) {\n\
    \         x = y;\n         while(k < 3 * r / 4) {\n            y = f(y);\n   \
    \         k++;\n         }\n         while(k < r && g == 1) {\n            ys\
    \ = y;\n            for(ll i = 0; i < min(b, r - k); i++) {\n               y\
    \ = f(y);\n               q *= abs(x - y);\n               q %= N;\n         \
    \   }\n            g = gcd(ll(q), N);\n            k += b;\n         }\n     \
    \    k = r;\n         r *= 2;\n      }\n      if(g == N) {\n         g = 1;\n\
    \         y = ys;\n         while(g == 1) {\n            y = f(y);\n         \
    \   g = gcd(abs(x - y), N);\n         }\n      }\n      if(g == N) { continue;\
    \ }\n      if(is_prime(g)) { return g; }\n      if(is_prime(N / g)) { return N\
    \ / g; }\n      return find_prime_factor(g);\n   }\n   assert(false);\n}\n\nmap<ll,\
    \ int> factorize(ll N) {\n   map<ll, int> ret;\n   while(!is_prime(N) && N > 1)\
    \ {\n      ll p = find_prime_factor(N);\n      int s = 0;\n      while(N % p ==\
    \ 0) {\n         N /= p;\n         s++;\n      }\n      ret[p] = s;\n   }\n  \
    \ if(N > 1) { ret[N] = 1; }\n   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/rho.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/rho.test.cpp
documentation_of: src/math/rho.hpp
layout: document
redirect_from:
- /library/src/math/rho.hpp
- /library/src/math/rho.hpp.html
title: src/math/rho.hpp
---
