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
  bundledCode: "#line 1 \"src/math/primitive-root.hpp\"\n// depends on modpow\nint\
    \ primitive_root(int m) {\n   if(m == 2) return 1;\n   if(m == 167772161) return\
    \ 3;\n   if(m == 469762049) return 3;\n   if(m == 754974721) return 11;\n   if(m\
    \ == 998244353) return 3;\n   int divs[20] = {};\n   divs[0] = 2;\n   int cnt\
    \ = 1;\n   int x = (m - 1) / 2;\n   while(x % 2 == 0) x /= 2;\n   for(int i =\
    \ 3; (long long)(i)*i <= x; i += 2) {\n      if(x % i == 0) {\n         divs[cnt++]\
    \ = i;\n         while(x % i == 0) { x /= i; }\n      }\n   }\n   if(x > 1) {\
    \ divs[cnt++] = x; }\n   for(int g = 2;; g++) {\n      bool ok = true;\n     \
    \ for(int i = 0; i < cnt; i++) {\n         if(modpow(g, (m - 1) / divs[i], m)\
    \ == 1) {\n            ok = false;\n            break;\n         }\n      }\n\
    \      if(ok) return g;\n   }\n}\n"
  code: "// depends on modpow\nint primitive_root(int m) {\n   if(m == 2) return 1;\n\
    \   if(m == 167772161) return 3;\n   if(m == 469762049) return 3;\n   if(m ==\
    \ 754974721) return 11;\n   if(m == 998244353) return 3;\n   int divs[20] = {};\n\
    \   divs[0] = 2;\n   int cnt = 1;\n   int x = (m - 1) / 2;\n   while(x % 2 ==\
    \ 0) x /= 2;\n   for(int i = 3; (long long)(i)*i <= x; i += 2) {\n      if(x %\
    \ i == 0) {\n         divs[cnt++] = i;\n         while(x % i == 0) { x /= i; }\n\
    \      }\n   }\n   if(x > 1) { divs[cnt++] = x; }\n   for(int g = 2;; g++) {\n\
    \      bool ok = true;\n      for(int i = 0; i < cnt; i++) {\n         if(modpow(g,\
    \ (m - 1) / divs[i], m) == 1) {\n            ok = false;\n            break;\n\
    \         }\n      }\n      if(ok) return g;\n   }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primitive-root.hpp
  requiredBy: []
  timestamp: '2025-02-24 10:33:49+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/primitive-root.hpp
layout: document
redirect_from:
- /library/src/math/primitive-root.hpp
- /library/src/math/primitive-root.hpp.html
title: src/math/primitive-root.hpp
---
