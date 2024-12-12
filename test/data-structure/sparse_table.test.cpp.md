---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/sparse_table.hpp
    title: src/data-structure/sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data-structure/sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/sparse_table.hpp\"\ntemplate<typename\
    \ T, auto op> struct sparse_table {\n   vector<vector<T>> st;\n   vector<int>\
    \ lg;\n\n   sparse_table(const vector<T>& v) {\n      int b = 0;\n      while((1\
    \ << b) <= v.size()) b++;\n      st.assign(b, vector<T>(1 << b));\n      for(int\
    \ i = 0; i < size(v); i++) { st[0][i] = v[i]; }\n      for(int i = 1; i < b; i++)\
    \ {\n         for(int j = 0; j + (1 << i) <= (1 << b); j++) st[i][j] = op(st[i\
    \ - 1][j], st[i - 1][j + (1 << (i - 1))]);\n      }\n      lg.resize(v.size()\
    \ + 1);\n      for(int i = 2; i < size(lg); i++) lg[i] = lg[i >> 1] + 1;\n   }\n\
    \n   inline T prod(int l, int r) {\n      int b = lg[r - l];\n      return op(st[b][l],\
    \ st[b][r - (1 << b)]);\n   }\n};\n#line 5 \"test/data-structure/sparse_table.test.cpp\"\
    \n\nint op(int a, int b) { return min(a, b); }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   vector<int> A(N);\n   for(auto&& a : A) cin\
    \ >> a;\n   sparse_table<int, op> st(A);\n   while(Q--) {\n      int l, r;\n \
    \     cin >> l >> r;\n      cout << st.prod(l, r) << '\\n';\n   }\n   return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/data-structure/sparse_table.hpp\"\n\n\
    int op(int a, int b) { return min(a, b); }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   vector<int> A(N);\n   for(auto&& a : A) cin\
    \ >> a;\n   sparse_table<int, op> st(A);\n   while(Q--) {\n      int l, r;\n \
    \     cin >> l >> r;\n      cout << st.prod(l, r) << '\\n';\n   }\n   return 0;\n\
    }"
  dependsOn:
  - test/template.hpp
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data-structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 19:04:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/sparse_table.test.cpp
- /verify/test/data-structure/sparse_table.test.cpp.html
title: test/data-structure/sparse_table.test.cpp
---
