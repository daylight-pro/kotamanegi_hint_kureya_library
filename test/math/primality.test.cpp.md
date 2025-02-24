---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modinv.hpp
    title: src/math/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/primality.hpp
    title: src/math/primality.hpp
  - icon: ':heavy_check_mark:'
    path: test/math/modpow.hpp
    title: test/math/modpow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/math/primality.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/modinv.hpp\"\
    \nll modinv(ll a, ll MOD) {\n   ll b = MOD, u = 1, v = 0;\n   while(b) {\n   \
    \   ll t = a / b;\n      a -= t * b;\n      swap(a, b);\n      u -= t * v;\n \
    \     swap(u, v);\n   }\n   u %= MOD;\n   if(u < 0) u += MOD;\n   return u;\n\
    }\n#line 1 \"test/math/modpow.hpp\"\nll modpow(ll a, ll n, ll MOD) {\n   using\
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
    }\n#line 7 \"test/math/primality.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int Q;\n   cin >> Q;\n   while(Q--) {\n      ll N;\n      cin >> N;\n    \
    \  if(is_prime(N)) {\n         cout << \"Yes\" << endl;\n      } else {\n    \
    \     cout << \"No\" << endl;\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/math/modinv.hpp\"\n#include \"test/math/modpow.hpp\"\
    \n#include \"src/math/primality.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int Q;\n   cin >> Q;\n   while(Q--) {\n      ll N;\n      cin >> N;\n    \
    \  if(is_prime(N)) {\n         cout << \"Yes\" << endl;\n      } else {\n    \
    \     cout << \"No\" << endl;\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/math/modinv.hpp
  - test/math/modpow.hpp
  - src/math/primality.hpp
  isVerificationFile: true
  path: test/math/primality.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 20:29:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/primality.test.cpp
layout: document
redirect_from:
- /verify/test/math/primality.test.cpp
- /verify/test/math/primality.test.cpp.html
title: test/math/primality.test.cpp
---
