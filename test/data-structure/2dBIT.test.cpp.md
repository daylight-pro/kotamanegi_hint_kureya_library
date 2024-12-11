---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/2dBIT.hpp
    title: src/data-structure/2dBIT.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/data-structure/2dBIT.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\n\n#line 1\
    \ \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/2dBIT.hpp\"\
    \ntemplate<typename T> struct BinaryIndexedTree2D {\n   int H, W;\n   vector<vector<T>>\
    \ bit;\n\n   BinaryIndexedTree2D(int H, int W) : H(H), W(W), bit(H + 3, vector<T>(W\
    \ + 3, 0)) {}\n   void add(int x, int y, T w) {\n      if(x < 0 || x >= H || y\
    \ < 0 || y >= W) return;\n      for(int a = (++y, ++x); a <= H; a += a & -a) {\n\
    \         for(int b = y; b <= W; b += b & -b) { bit[a][b] += w; }\n      }\n \
    \  }\n\n   void imos(int x1, int y1, int x2, int y2, T w) {\n      add(x1, y1,\
    \ w);\n      add(x2, y2, w);\n      add(x1, y2, -w);\n      add(x2, y1, -w);\n\
    \   }\n\n   T sum(int x, int y) {\n      if(x < 0 || x >= H || y < 0 || y >= W)\
    \ return 0;\n      if(x >= H) x = H - 1;\n      if(y >= W) y = W - 1;\n      T\
    \ ret = 0;\n      for(int a = (++y, ++x); a > 0; a -= a & -a) {\n         for(int\
    \ b = y; b > 0; b -= b & -b) { ret += bit[a][b]; }\n      }\n      return ret;\n\
    \   }\n\n   T sum(int x1, int y1, int x2, int y2) {\n      return sum(x2, y2)\
    \ - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);\n   }\n};\n#line\
    \ 5 \"test/data-structure/2dBIT.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N;\n   cin >> N;\n   BinaryIndexedTree2D<ll> bit(1003, 1003);\n   while(N--)\
    \ {\n      int x1, y1, x2, y2;\n      cin >> x1 >> y1 >> x2 >> y2;\n      bit.imos(x1,\
    \ y1, x2, y2, 1);\n   }\n   int ans = 0;\n   for(int i = 0; i < 1003; i++) {\n\
    \      for(int j = 0; j < 1003; j++) { chmax(ans, bit.sum(i, j)); }\n   }\n  \
    \ cout << ans << '\\n';\n\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/2dBIT.hpp\"\n\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n\
    \   BinaryIndexedTree2D<ll> bit(1003, 1003);\n   while(N--) {\n      int x1, y1,\
    \ x2, y2;\n      cin >> x1 >> y1 >> x2 >> y2;\n      bit.imos(x1, y1, x2, y2,\
    \ 1);\n   }\n   int ans = 0;\n   for(int i = 0; i < 1003; i++) {\n      for(int\
    \ j = 0; j < 1003; j++) { chmax(ans, bit.sum(i, j)); }\n   }\n   cout << ans <<\
    \ '\\n';\n\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/2dBIT.hpp
  isVerificationFile: true
  path: test/data-structure/2dBIT.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 20:28:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/2dBIT.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/2dBIT.test.cpp
- /verify/test/data-structure/2dBIT.test.cpp.html
title: test/data-structure/2dBIT.test.cpp
---
