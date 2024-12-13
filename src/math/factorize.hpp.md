---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/factorize.test.cpp
    title: test/math/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/factorize.hpp\"\n// \\sqrt(n)\u306E\u7D20\u56E0\
    \u6570\u5206\u89E3 a01341\nmap<ll, int> prime_factor(ll n) {\n   map<ll, int>\
    \ ret;\n   for(ll i = 2; i * i <= n; i++) {\n      while(n % i == 0) {\n     \
    \    ret[i]++;\n         n /= i;\n      }\n   }\n   if(n != 1) ret[n] = 1;\n \
    \  return ret;\n}\n\n// \u7DDA\u5F62\u7BE9 1f4de3\nvector<int> preprocess(int\
    \ n) {\n   n++;\n   vector<int> res(n);\n   std::iota(res.begin(), res.end(),\
    \ 0);\n   for(int i = 2; i * i < n; ++i) {\n      if(res[i] < i) continue;\n \
    \     for(int j = i * i; j < n; j += i)\n         if(res[j] == j) res[j] = i;\n\
    \   }\n   return res;\n}\n\nmap<int, int> prime_factor(int n, const vector<int>&\
    \ lp) {\n   map<int, int> ret;\n   while(n > 1) {\n      ret[lp[n]]++;\n     \
    \ n /= lp[n];\n   }\n   return ret;\n}\n"
  code: "// \\sqrt(n)\u306E\u7D20\u56E0\u6570\u5206\u89E3 a01341\nmap<ll, int> prime_factor(ll\
    \ n) {\n   map<ll, int> ret;\n   for(ll i = 2; i * i <= n; i++) {\n      while(n\
    \ % i == 0) {\n         ret[i]++;\n         n /= i;\n      }\n   }\n   if(n !=\
    \ 1) ret[n] = 1;\n   return ret;\n}\n\n// \u7DDA\u5F62\u7BE9 1f4de3\nvector<int>\
    \ preprocess(int n) {\n   n++;\n   vector<int> res(n);\n   std::iota(res.begin(),\
    \ res.end(), 0);\n   for(int i = 2; i * i < n; ++i) {\n      if(res[i] < i) continue;\n\
    \      for(int j = i * i; j < n; j += i)\n         if(res[j] == j) res[j] = i;\n\
    \   }\n   return res;\n}\n\nmap<int, int> prime_factor(int n, const vector<int>&\
    \ lp) {\n   map<int, int> ret;\n   while(n > 1) {\n      ret[lp[n]]++;\n     \
    \ n /= lp[n];\n   }\n   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/factorize.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:36:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/factorize.test.cpp
documentation_of: src/math/factorize.hpp
layout: document
redirect_from:
- /library/src/math/factorize.hpp
- /library/src/math/factorize.hpp.html
title: src/math/factorize.hpp
---
