---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/doubling.test.2.cpp
    title: test/algorithm/doubling.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/algorithm/doubling.test.3.cpp
    title: test/algorithm/doubling.test.3.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/doubling_monoid.hpp\"\ntemplate<int L, class\
    \ T, auto op, auto e> struct Doubling {\n   private:\n   vector<vector<int>> V;\n\
    \   vector<vector<T>> data;\n\n   public:\n   Doubling(const vector<int>& to,\
    \ const vector<T>& v) {\n      int N = size(to);\n      V = vector<vector<int>>(L,\
    \ vector<int>(N, -1));\n      data = vector<vector<T>>(L, vector<T>(N, e()));\n\
    \      rep(i, 0, N) {\n         V[0][i] = to[i];\n         data[0][i] = v[i];\n\
    \      }\n\n      rep(i, 0, L - 1) {\n         rep(j, 0, N) {\n            if(V[i][j]\
    \ != -1) {\n               V[i + 1][j] = V[i][V[i][j]];\n               data[i\
    \ + 1][j] = op(data[i][j], data[i][V[i][j]]);\n            } else {\n        \
    \       V[i + 1][j] = V[i][j];\n               data[i + 1][j] = data[i][j];\n\
    \            }\n         }\n      }\n   }\n\n   pair<int, T> jump(int from, ll\
    \ k) {\n      T res = e();\n      for(int cnt = 0; k > 0; k >>= 1, ++cnt) {\n\
    \         if((k & 1) && from != -1) {\n            res = op(res, data[cnt][from]);\n\
    \            from = V[cnt][from];\n         }\n      }\n      return {from, res};\n\
    \   }\n};\n"
  code: "template<int L, class T, auto op, auto e> struct Doubling {\n   private:\n\
    \   vector<vector<int>> V;\n   vector<vector<T>> data;\n\n   public:\n   Doubling(const\
    \ vector<int>& to, const vector<T>& v) {\n      int N = size(to);\n      V = vector<vector<int>>(L,\
    \ vector<int>(N, -1));\n      data = vector<vector<T>>(L, vector<T>(N, e()));\n\
    \      rep(i, 0, N) {\n         V[0][i] = to[i];\n         data[0][i] = v[i];\n\
    \      }\n\n      rep(i, 0, L - 1) {\n         rep(j, 0, N) {\n            if(V[i][j]\
    \ != -1) {\n               V[i + 1][j] = V[i][V[i][j]];\n               data[i\
    \ + 1][j] = op(data[i][j], data[i][V[i][j]]);\n            } else {\n        \
    \       V[i + 1][j] = V[i][j];\n               data[i + 1][j] = data[i][j];\n\
    \            }\n         }\n      }\n   }\n\n   pair<int, T> jump(int from, ll\
    \ k) {\n      T res = e();\n      for(int cnt = 0; k > 0; k >>= 1, ++cnt) {\n\
    \         if((k & 1) && from != -1) {\n            res = op(res, data[cnt][from]);\n\
    \            from = V[cnt][from];\n         }\n      }\n      return {from, res};\n\
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/doubling_monoid.hpp
  requiredBy: []
  timestamp: '2024-12-09 20:26:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/doubling.test.2.cpp
  - test/algorithm/doubling.test.3.cpp
documentation_of: src/algorithm/doubling_monoid.hpp
layout: document
redirect_from:
- /library/src/algorithm/doubling_monoid.hpp
- /library/src/algorithm/doubling_monoid.hpp.html
title: src/algorithm/doubling_monoid.hpp
---
