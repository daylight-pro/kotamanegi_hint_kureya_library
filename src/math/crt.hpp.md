---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/crt.test.cpp
    title: test/math/crt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/crt.hpp\"\n// m\u304C\u4E92\u3044\u306B\u7D20\u306B\
    \u306A\u308B\u3088\u3046\u306B\u524D\u51E6\u7406\n// lcm(m) % MOD\u3092\u8FD4\u3059\
    \n// crt\u306E\u89E3\u304C\u306A\u3051\u308C\u3070-1\u3092\u8FD4\u3059\nll pre_garner(vector<ll>&\
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
    \ %= m[i];\n      }\n   }\n   return constants.back();\n}\n"
  code: "// m\u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u3088\u3046\u306B\u524D\
    \u51E6\u7406\n// lcm(m) % MOD\u3092\u8FD4\u3059\n// crt\u306E\u89E3\u304C\u306A\
    \u3051\u308C\u3070-1\u3092\u8FD4\u3059\nll pre_garner(vector<ll>& b, vector<ll>&\
    \ m, ll MOD) {\n   ll res = 1;\n   for(int i = 0; i < (int)b.size(); i++) {\n\
    \      for(int j = 0; j < i; j++) {\n         ll g = gcd(m[i], m[j]);\n      \
    \   if((b[i] - b[j]) % g != 0) return -1;\n         m[i] /= g;\n         m[j]\
    \ /= g;\n         ll gi = gcd(m[i], g);\n         ll gj = g / gi;\n         do\
    \ {\n            g = gcd(gi, gj);\n            gi *= g;\n            gj /= g;\n\
    \         } while(g != 1);\n         m[i] *= gi;\n         m[j] *= gj;\n     \
    \    b[i] %= m[i];\n         b[j] %= m[j];\n      }\n   }\n   for(int i = 0; i\
    \ < size(b); i++) (res *= m[i]) %= MOD;\n   return res;\n}\n\n// m \u304C\u4E92\
    \u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\
    \u3066\u3044\u308B\u5834\u5408\n// b[i] = x (mod m[i]) \u3068\u306A\u308B\u6700\
    \u5C0F\u306E x \\le 0 \u3092\u6C42\u3081\u308B\nll garner(vector<ll> b, vector<ll>\
    \ m, ll MOD) {\n   m.push_back(MOD);\n   vector<ll> coeffs(size(m), 1);\n   vector<ll>\
    \ constants(size(m), 0);\n   for(int k = 0; k < size(b); k++) {\n      ll t =\
    \ ((b[k] - constants[k]) * modinv(coeffs[k], m[k])) % m[k];\n      if(t < 0) t\
    \ += m[k];\n      for(int i = k + 1; i < size(m); i++) {\n         (constants[i]\
    \ += t * coeffs[i]) %= m[i];\n         (coeffs[i] *= m[k]) %= m[i];\n      }\n\
    \   }\n   return constants.back();\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/crt.hpp
  requiredBy: []
  timestamp: '2024-12-13 18:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/crt.test.cpp
documentation_of: src/math/crt.hpp
layout: document
redirect_from:
- /library/src/math/crt.hpp
- /library/src/math/crt.hpp.html
title: src/math/crt.hpp
---
