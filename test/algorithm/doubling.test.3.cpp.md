---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/doubling_monoid.hpp
    title: src/algorithm/doubling_monoid.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/1097
    links:
    - https://yukicoder.me/problems/no/1097
  bundledCode: "#line 1 \"test/algorithm/doubling.test.3.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1097\"\n\n#line 1 \"test/template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/doubling_monoid.hpp\"\ntemplate<int\
    \ L, class T, auto op, auto e> struct Doubling {\n   private:\n   vector<vector<int>>\
    \ V;\n   vector<vector<T>> data;\n\n   public:\n   Doubling(const vector<int>&\
    \ to, const vector<T>& v) {\n      int N = size(to);\n      V = vector<vector<int>>(L,\
    \ vector<int>(N, -1));\n      data = vector<vector<T>>(L, vector<T>(N, e()));\n\
    \      for(int i = 0; i < N; i++) {\n         V[0][i] = to[i];\n         data[0][i]\
    \ = v[i];\n      }\n\n      for(int i = 0; i < L - 1; i++) {\n         for(int\
    \ j = 0; j < N; j++) {\n            if(V[i][j] != -1) {\n               V[i +\
    \ 1][j] = V[i][V[i][j]];\n               data[i + 1][j] = op(data[i][j], data[i][V[i][j]]);\n\
    \            } else {\n               V[i + 1][j] = V[i][j];\n               data[i\
    \ + 1][j] = data[i][j];\n            }\n         }\n      }\n   }\n\n   pair<int,\
    \ T> jump(int from, ll k) {\n      T res = e();\n      for(int cnt = 0; k > 0;\
    \ k >>= 1, ++cnt) {\n         if((k & 1) && from != -1) {\n            res = op(res,\
    \ data[cnt][from]);\n            from = V[cnt][from];\n         }\n      }\n \
    \     return {from, res};\n   }\n};\n#line 5 \"test/algorithm/doubling.test.3.cpp\"\
    \n\nll op(ll a, ll b) { return a + b; };\nll e() { return 0LL; };\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n   vector<int>\
    \ P(N);\n   for(int i = 0; i < N; i++) cin >> P[i];\n\n   vector<ll> data(N);\n\
    \n   for(int i = 0; i < N; i++) {\n      P[i] += i;\n      data[i] += P[i] / N;\n\
    \      P[i] %= N;\n   }\n\n   Doubling<64, ll, op, e> doubling(P, data);\n   int\
    \ Q;\n   cin >> Q;\n\n   while(Q--) {\n      ll K;\n      cin >> K;\n      auto\
    \ [pos, cnt] = doubling.jump(0, K);\n      cout << pos + cnt * N << '\\n';\n \
    \  }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1097\"\n\n#include \"\
    test/template.hpp\"\n#include \"src/algorithm/doubling_monoid.hpp\"\n\nll op(ll\
    \ a, ll b) { return a + b; };\nll e() { return 0LL; };\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N;\n   cin >> N;\n   vector<int> P(N);\n   for(int i = 0; i < N; i++)\
    \ cin >> P[i];\n\n   vector<ll> data(N);\n\n   for(int i = 0; i < N; i++) {\n\
    \      P[i] += i;\n      data[i] += P[i] / N;\n      P[i] %= N;\n   }\n\n   Doubling<64,\
    \ ll, op, e> doubling(P, data);\n   int Q;\n   cin >> Q;\n\n   while(Q--) {\n\
    \      ll K;\n      cin >> K;\n      auto [pos, cnt] = doubling.jump(0, K);\n\
    \      cout << pos + cnt * N << '\\n';\n   }\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/algorithm/doubling_monoid.hpp
  isVerificationFile: true
  path: test/algorithm/doubling.test.3.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/doubling.test.3.cpp
layout: document
redirect_from:
- /verify/test/algorithm/doubling.test.3.cpp
- /verify/test/algorithm/doubling.test.3.cpp.html
title: test/algorithm/doubling.test.3.cpp
---
