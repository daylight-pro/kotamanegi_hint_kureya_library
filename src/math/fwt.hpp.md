---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/fwt.test.cpp
    title: test/math/fwt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/fwt.hpp\"\ntemplate <typename T>\nvoid fwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n       \
    \ for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n           \
    \     T x = f[j], y = f[j | i];\n                f[j] = x + y, f[j | i] = x -\
    \ y;\n            }\n        }\n    }\n}\ntemplate <typename T>\nvoid ifwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n       \
    \ for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n           \
    \     T x = f[j], y = f[j | i];\n                f[j] = (x + y) / 2, f[j | i]\
    \ = (x - y) / 2;\n            }\n        }\n    }\n}\n"
  code: "template <typename T>\nvoid fwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if ((j & i) == 0) {\n                T x = f[j], y = f[j | i];\n\
    \                f[j] = x + y, f[j | i] = x - y;\n            }\n        }\n \
    \   }\n}\ntemplate <typename T>\nvoid ifwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if ((j & i) == 0) {\n                T x = f[j], y = f[j | i];\n\
    \                f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;\n            }\n\
    \        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fwt.hpp
  requiredBy: []
  timestamp: '2025-02-22 00:33:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/fwt.test.cpp
documentation_of: src/math/fwt.hpp
layout: document
redirect_from:
- /library/src/math/fwt.hpp
- /library/src/math/fwt.hpp.html
title: src/math/fwt.hpp
---
