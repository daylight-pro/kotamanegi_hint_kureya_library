---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/crt.hpp
    title: src/math/crt.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modinv.hpp
    title: src/math/modinv.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/187
    links:
    - https://yukicoder.me/problems/no/187
  bundledCode: "#line 1 \"test/math/crt.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/187\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/modinv.hpp\"\
    \nll modinv(ll a, ll MOD) {\n   ll b = MOD, u = 1, v = 0;\n   while(b) {\n   \
    \   ll t = a / b;\n      a -= t * b;\n      swap(a, b);\n      u -= t * v;\n \
    \     swap(u, v);\n   }\n   u %= MOD;\n   if(u < 0) u += MOD;\n   return u;\n\
    }\n#line 1 \"src/math/crt.hpp\"\n// m\u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\
    \u308B\u3088\u3046\u306B\u524D\u51E6\u7406\n// lcm(m) % MOD\u3092\u8FD4\u3059\n\
    // crt\u306E\u89E3\u304C\u306A\u3051\u308C\u3070-1\u3092\u8FD4\u3059\nll pre_garner(vector<ll>&\
    \ b, vector<ll>& m, ll MOD) {\n   ll res = 1;\n   for(int i = 0; i < (int)b.size();\
    \ i++) {\n      for(int j = 0; j < i; j++) {\n         ll g = gcd(m[i], m[j]);\n\
    \         if((b[i] - b[j]) % g != 0) return -1;\n         m[i] /= g;\n       \
    \  m[j] /= g;\n         ll gi = gcd(m[i], g);\n         ll gj = g / gi;\n    \
    \     do {\n            g = gcd(gi, gj);\n            gi *= g;\n            gj\
    \ /= g;\n         } while(g != 1);\n         m[i] *= gi;\n         m[j] *= gj;\n\
    \         b[i] %= m[i];\n         b[j] %= m[j];\n      }\n   }\n   for(int i =\
    \ 0; i < size(b); i++) (res *= m[i]) %= MOD;\n   return res;\n}\n\n// m \u304C\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\u5834\u5408\n// b[i] = x (mod m[i]) \u3068\u306A\u308B\
    \u6700\u5C0F\u306E x \\le 0 \u3092\u6C42\u3081\u308B\nll garner(vector<ll> b,\
    \ vector<ll> m, ll MOD) {\n   m.push_back(MOD);\n   vector<ll> coeffs(size(m),\
    \ 1);\n   vector<ll> constants(size(m), 0);\n   for(int k = 0; k < size(b); k++)\
    \ {\n      ll t = ((b[k] - constants[k]) * modinv(coeffs[k], m[k])) % m[k];\n\
    \      if(t < 0) t += m[k];\n      for(int i = k + 1; i < size(m); i++) {\n  \
    \       (constants[i] += t * coeffs[i]) %= m[i];\n         (coeffs[i] *= m[k])\
    \ %= m[i];\n      }\n   }\n   return constants.back();\n}\n#line 6 \"test/math/crt.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n\
    \   vector<ll> b(N), m(N);\n   for(int i = 0; i < N; i++) cin >> b[i] >> m[i];\n\
    \   bool nonzero = false;\n   for(int i = 0; i < N; i++) {\n      if(b[i] != 0)\
    \ {\n         nonzero = true;\n         break;\n      }\n   }\n   const ll MOD\
    \ = 1000000007;\n   ll lcm = pre_garner(b, m, MOD);\n\n   if(!nonzero) {\n   \
    \   // \u6700\u5C0F\u306F0\u306B\u306A\u3063\u3061\u3083\u3046\u306E\u3067\u3001\
    \u6B21\u306B\u5C0F\u3055\u3044lcm\u3092\u8FD4\u3059\n      cout << lcm << endl;\n\
    \   } else if(lcm == -1) {\n      cout << -1 << endl;\n   } else {\n      cout\
    \ << garner(b, m, MOD) << endl;\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/187\"\n\n#include \"test/template.hpp\"\
    \n#include \"src/math/modinv.hpp\"\n#include \"src/math/crt.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n   vector<ll>\
    \ b(N), m(N);\n   for(int i = 0; i < N; i++) cin >> b[i] >> m[i];\n   bool nonzero\
    \ = false;\n   for(int i = 0; i < N; i++) {\n      if(b[i] != 0) {\n         nonzero\
    \ = true;\n         break;\n      }\n   }\n   const ll MOD = 1000000007;\n   ll\
    \ lcm = pre_garner(b, m, MOD);\n\n   if(!nonzero) {\n      // \u6700\u5C0F\u306F\
    0\u306B\u306A\u3063\u3061\u3083\u3046\u306E\u3067\u3001\u6B21\u306B\u5C0F\u3055\
    \u3044lcm\u3092\u8FD4\u3059\n      cout << lcm << endl;\n   } else if(lcm == -1)\
    \ {\n      cout << -1 << endl;\n   } else {\n      cout << garner(b, m, MOD) <<\
    \ endl;\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/math/modinv.hpp
  - src/math/crt.hpp
  isVerificationFile: true
  path: test/math/crt.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 18:20:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/crt.test.cpp
layout: document
redirect_from:
- /verify/test/math/crt.test.cpp
- /verify/test/math/crt.test.cpp.html
title: test/math/crt.test.cpp
---
