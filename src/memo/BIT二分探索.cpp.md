---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/memo/BIT\\u4e8c\\u5206\\u63a2\\u7d22.cpp\"\n// minimize\
    \ i s.t. sum(i) >= w\nint lower_bound(ll w) {\n    if(w <= 0) return 0;\n    int\
    \ x = 0, N = si(a) + 1;\n    for(int k = 1 << __lg(N); k; k >>= 1) {\n       \
    \ if(x + k <= N - 1 && a[x + k] < w) {\n        w -= a[x + k];\n        x += k;\n\
    \        }\n    }\n    return x;\n}\n"
  code: "// minimize i s.t. sum(i) >= w\nint lower_bound(ll w) {\n    if(w <= 0) return\
    \ 0;\n    int x = 0, N = si(a) + 1;\n    for(int k = 1 << __lg(N); k; k >>= 1)\
    \ {\n        if(x + k <= N - 1 && a[x + k] < w) {\n        w -= a[x + k];\n  \
    \      x += k;\n        }\n    }\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: "src/memo/BIT\u4E8C\u5206\u63A2\u7D22.cpp"
  requiredBy: []
  timestamp: '2025-02-25 15:42:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: "src/memo/BIT\u4E8C\u5206\u63A2\u7D22.cpp"
layout: document
redirect_from:
- "/library/src/memo/BIT\u4E8C\u5206\u63A2\u7D22.cpp"
- "/library/src/memo/BIT\u4E8C\u5206\u63A2\u7D22.cpp.html"
title: "src/memo/BIT\u4E8C\u5206\u63A2\u7D22.cpp"
---
