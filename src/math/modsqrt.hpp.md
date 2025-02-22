---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm
  bundledCode: "#line 1 \"src/math/modsqrt.hpp\"\n// depends on modpow\n// a is a\
    \ quadratic residue modulo p?\nint Legendre(long long a, long long p) {\n\n  \
    \ long long ret = modpow(a, (p-1)/2, p);\n\n   if (ret == p-1)\n      ret = -1;\n\
    \n   return ret;\n}\n\n// Tonelli\u2013Shanks algorithm\n// calculate R such that\
    \ R^2 = n (mod p)\n// p is an odd prime\n// n is a positive integer that satisfies\
    \ (n/p) = 1\n// See http://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm\n\
    // O((log p)^2)\nlong long modsqrt(long long n, long long p) {\n\n   // step 1\n\
    \   long long Q = p-1;\n   long long S = 0;\n   while (Q % 2 == 0) {\n      ++S;\n\
    \      Q /= 2;\n   }\n\n   if (S == 1) {\n      return modpow(n, (p+1)/4, p);\n\
    \   }\n\n   // step 2\n   default_random_engine generator;\n   uniform_int_distribution<long\
    \ long> distribution(0, p);\n   \n   long long z = 1;\n   while (Legendre(z, p)\
    \ != -1) {\n      z = distribution(generator);\n   }\n\n   long long c = modpow(z,\
    \ Q, p);\n   \n   // step 3\n   long long R = modpow(n, (Q+1)/2, p);\n   long\
    \ long t = modpow(n, Q, p);\n   long long M = S;\n\n   // step 4\n   while (t\
    \ != 1) {\n      long long i;\n      long long t2 = t;\n      for (i = 1; i <\
    \ M; i++) {\n         t2 = t2 * t2 % p;\n         if (t2 == 1) break;\n      }\n\
    \n      long long b = modpow(c, 1LL<<(M-i-1), p);\n      R = R * b % p;\n    \
    \  t = (t * b % p) * b % p;\n      c = b * b % p;\n      M = i;\n   }\n   \n \
    \  return R;\n}\n"
  code: "// depends on modpow\n// a is a quadratic residue modulo p?\nint Legendre(long\
    \ long a, long long p) {\n\n   long long ret = modpow(a, (p-1)/2, p);\n\n   if\
    \ (ret == p-1)\n      ret = -1;\n\n   return ret;\n}\n\n// Tonelli\u2013Shanks\
    \ algorithm\n// calculate R such that R^2 = n (mod p)\n// p is an odd prime\n\
    // n is a positive integer that satisfies (n/p) = 1\n// See http://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm\n\
    // O((log p)^2)\nlong long modsqrt(long long n, long long p) {\n\n   // step 1\n\
    \   long long Q = p-1;\n   long long S = 0;\n   while (Q % 2 == 0) {\n      ++S;\n\
    \      Q /= 2;\n   }\n\n   if (S == 1) {\n      return modpow(n, (p+1)/4, p);\n\
    \   }\n\n   // step 2\n   default_random_engine generator;\n   uniform_int_distribution<long\
    \ long> distribution(0, p);\n   \n   long long z = 1;\n   while (Legendre(z, p)\
    \ != -1) {\n      z = distribution(generator);\n   }\n\n   long long c = modpow(z,\
    \ Q, p);\n   \n   // step 3\n   long long R = modpow(n, (Q+1)/2, p);\n   long\
    \ long t = modpow(n, Q, p);\n   long long M = S;\n\n   // step 4\n   while (t\
    \ != 1) {\n      long long i;\n      long long t2 = t;\n      for (i = 1; i <\
    \ M; i++) {\n         t2 = t2 * t2 % p;\n         if (t2 == 1) break;\n      }\n\
    \n      long long b = modpow(c, 1LL<<(M-i-1), p);\n      R = R * b % p;\n    \
    \  t = (t * b % p) * b % p;\n      c = b * b % p;\n      M = i;\n   }\n   \n \
    \  return R;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modsqrt.hpp
  requiredBy: []
  timestamp: '2025-02-21 23:52:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modsqrt.hpp
layout: document
redirect_from:
- /library/src/math/modsqrt.hpp
- /library/src/math/modsqrt.hpp.html
title: src/math/modsqrt.hpp
---
