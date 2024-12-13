---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/eratos.hpp
    title: src/math/eratos.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276
  bundledCode: "#line 1 \"test/math/eratos.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/eratos.hpp\"\
    \nvoid eratos(int n, vector<bool>& isprime) {\n   isprime = vector<bool>(n + 1,\
    \ true);\n   isprime[0] = false;\n   isprime[1] = false;\n   int last = ((int)sqrt(n))\
    \ + 1;\n   for(int i = 2; i < last; i++) {\n      if(isprime[i]) {\n         int\
    \ j = i + i;\n         while(j <= n) {\n            isprime[j] = false;\n    \
    \        j += i;\n         }\n      }\n   }\n}\n#line 4 \"test/math/eratos.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int K;\n   cin >> K;\n\
    \   vector<bool> isPrime;\n   eratos(1299710, isPrime);\n   while(K != 0) {\n\
    \      if(isPrime[K]) {\n         cout << 0 << endl;\n         cin >> K;\n   \
    \      continue;\n      }\n      int ans = 1;\n      for(int i = K; !isPrime[i];\
    \ i++) { ans++; }\n      for(int i = K - 1; !isPrime[i]; i--) { ans++; }\n   \
    \   cout << ans << endl;\n      cin >> K;\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/eratos.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int K;\n   cin >> K;\n   vector<bool>\
    \ isPrime;\n   eratos(1299710, isPrime);\n   while(K != 0) {\n      if(isPrime[K])\
    \ {\n         cout << 0 << endl;\n         cin >> K;\n         continue;\n   \
    \   }\n      int ans = 1;\n      for(int i = K; !isPrime[i]; i++) { ans++; }\n\
    \      for(int i = K - 1; !isPrime[i]; i--) { ans++; }\n      cout << ans << endl;\n\
    \      cin >> K;\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/math/eratos.hpp
  isVerificationFile: true
  path: test/math/eratos.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 18:36:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/eratos.test.cpp
layout: document
redirect_from:
- /verify/test/math/eratos.test.cpp
- /verify/test/math/eratos.test.cpp.html
title: test/math/eratos.test.cpp
---
