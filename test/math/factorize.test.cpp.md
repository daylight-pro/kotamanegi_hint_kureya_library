---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/factorize.hpp
    title: src/math/factorize.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
  bundledCode: "#line 1 \"test/math/factorize.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/factorize.hpp\"\
    \n// \\sqrt(n)\u306E\u7D20\u56E0\u6570\u5206\u89E3 a01341\nmap<ll, int> prime_factor(ll\
    \ n) {\n   map<ll, int> ret;\n   for(ll i = 2; i * i <= n; i++) {\n      while(n\
    \ % i == 0) {\n         ret[i]++;\n         n /= i;\n      }\n   }\n   if(n !=\
    \ 1) ret[n] = 1;\n   return ret;\n}\n\n// \u7DDA\u5F62\u7BE9 1f4de3\nvector<int>\
    \ preprocess(int n) {\n   n++;\n   vector<int> res(n);\n   std::iota(res.begin(),\
    \ res.end(), 0);\n   for(int i = 2; i * i < n; ++i) {\n      if(res[i] < i) continue;\n\
    \      for(int j = i * i; j < n; j += i)\n         if(res[j] == j) res[j] = i;\n\
    \   }\n   return res;\n}\n\nmap<int, int> prime_factor(int n, const vector<int>&\
    \ lp) {\n   map<int, int> ret;\n   while(n > 1) {\n      ret[lp[n]]++;\n     \
    \ n /= lp[n];\n   }\n   return ret;\n}\n#line 4 \"test/math/factorize.test.cpp\"\
    \n\nint main() {\n   int N;\n   cin >> N;\n   cout << N << \":\";\n   for(auto\
    \ [k, v] : prime_factor(N)) {\n      while(v--) { cout << \" \" << k; }\n   }\n\
    \   cout << endl;\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/factorize.hpp\"\n\nint main()\
    \ {\n   int N;\n   cin >> N;\n   cout << N << \":\";\n   for(auto [k, v] : prime_factor(N))\
    \ {\n      while(v--) { cout << \" \" << k; }\n   }\n   cout << endl;\n   return\
    \ 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/math/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 18:36:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/math/factorize.test.cpp
- /verify/test/math/factorize.test.cpp.html
title: test/math/factorize.test.cpp
---
