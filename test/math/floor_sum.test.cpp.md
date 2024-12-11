---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/floor_sum.hpp
    title: src/math/floor_sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/floor_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/floor_sum.hpp\"\
    \nll floor_sum(const ll& n, const ll& m, ll a, ll b) {\n   ll ret = 0;\n   if(a\
    \ >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n   if(b >= m) ret += n * (b\
    \ / m), b %= m;\n   ll y = (a * n + b) / m;\n   if(y == 0) return ret;\n   ll\
    \ x = y * m - b;\n   ret += (n - (x + a - 1) / a) * y;\n   ret += floor_sum(y,\
    \ a, m, (a - x % a) % a);\n   return ret;\n}\n#line 4 \"test/math/floor_sum.test.cpp\"\
    \n\nint main() {\n   int T;\n   cin >> T;\n   while(T--) {\n      ll N, M, A,\
    \ B;\n      cin >> N >> M >> A >> B;\n      cout << floor_sum(N, M, A, B) << '\\\
    n';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/floor_sum.hpp\"\n\nint main()\
    \ {\n   int T;\n   cin >> T;\n   while(T--) {\n      ll N, M, A, B;\n      cin\
    \ >> N >> M >> A >> B;\n      cout << floor_sum(N, M, A, B) << '\\n';\n   }\n\
    }\n"
  dependsOn:
  - test/template.hpp
  - src/math/floor_sum.hpp
  isVerificationFile: true
  path: test/math/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 18:11:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sum.test.cpp
- /verify/test/math/floor_sum.test.cpp.html
title: test/math/floor_sum.test.cpp
---
