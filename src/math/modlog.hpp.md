---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/modlog.hpp\"\n// depends on modpow and modinv\n\
    // a^x \u2261 b (mod. m) \u3068\u306A\u308B\u6700\u5C0F\u306E\u6B63\u306E\u6574\
    \u6570 x \u3092\u6C42\u3081\u308B\nlong long modlog(long long a, long long b,\
    \ int m) {\n   a %= m, b %= m;\n\n   // calc sqrt{M}\n   long long le = -1, ri\
    \ = m;\n   while(ri - le > 1) {\n      long long mid = (le + ri) >> 1;\n     \
    \ if(mid * mid >= m) ri = mid;\n      else le = mid;\n   }\n   long long sqrtM\
    \ = ri;\n\n   // {a^0, a^1, a^2, ..., a^sqrt(m)}\n   map<long long, long long>\
    \ apow;\n   long long r = a;\n   for(long long i = 1; i < sqrtM; ++i) {\n    \
    \  if(!apow.count(r)) apow[r] = i;\n      (r *= a) %= m;\n   }\n\n   // check\
    \ each A^p\n   long long A = modpow(modinv(a, m), sqrtM, m);\n   r = b;\n   for(long\
    \ long q = 0; q < sqrtM; ++q) {\n      if(r == 1 && q > 0) return q * sqrtM;\n\
    \      else if(apow.count(r)) return q * sqrtM + apow[r];\n      (r *= A) %= m;\n\
    \   }\n\n   // no solutions\n   return -1;\n}\n"
  code: "// depends on modpow and modinv\n// a^x \u2261 b (mod. m) \u3068\u306A\u308B\
    \u6700\u5C0F\u306E\u6B63\u306E\u6574\u6570 x \u3092\u6C42\u3081\u308B\nlong long\
    \ modlog(long long a, long long b, int m) {\n   a %= m, b %= m;\n\n   // calc\
    \ sqrt{M}\n   long long le = -1, ri = m;\n   while(ri - le > 1) {\n      long\
    \ long mid = (le + ri) >> 1;\n      if(mid * mid >= m) ri = mid;\n      else le\
    \ = mid;\n   }\n   long long sqrtM = ri;\n\n   // {a^0, a^1, a^2, ..., a^sqrt(m)}\n\
    \   map<long long, long long> apow;\n   long long r = a;\n   for(long long i =\
    \ 1; i < sqrtM; ++i) {\n      if(!apow.count(r)) apow[r] = i;\n      (r *= a)\
    \ %= m;\n   }\n\n   // check each A^p\n   long long A = modpow(modinv(a, m), sqrtM,\
    \ m);\n   r = b;\n   for(long long q = 0; q < sqrtM; ++q) {\n      if(r == 1 &&\
    \ q > 0) return q * sqrtM;\n      else if(apow.count(r)) return q * sqrtM + apow[r];\n\
    \      (r *= A) %= m;\n   }\n\n   // no solutions\n   return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modlog.hpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modlog.hpp
layout: document
redirect_from:
- /library/src/math/modlog.hpp
- /library/src/math/modlog.hpp.html
title: src/math/modlog.hpp
---
