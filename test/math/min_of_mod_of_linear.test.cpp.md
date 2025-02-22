---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/floor_sum.hpp
    title: src/math/floor_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/min_of_mod_of_linear.hpp
    title: src/math/min_of_mod_of_linear.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://judge.yosupo.jp/submission/268935
  bundledCode: "#line 1 \"test/math/min_of_mod_of_linear.test.cpp\"\n// AC\u78BA\u8A8D\
    \u6E08\u307F https://judge.yosupo.jp/submission/268935\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n\nll\
    \ floor_sum(const ll& n, const ll& m, ll a, ll b) {\n   ll ret = 0;\n   if(a >=\
    \ m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n   if(b >= m) ret += n * (b /\
    \ m), b %= m;\n   ll y = (a * n + b) / m;\n   if(y == 0) return ret;\n   ll x\
    \ = y * m - b;\n   ret += (n - (x + a - 1) / a) * y;\n   ret += floor_sum(y, a,\
    \ m, (a - x % a) % a);\n   return ret;\n}\n\n// depends on floor_sum\n// \\sum_0^(n-1)\
    \ floor((a * i + b) / m)\nll min_of_mod_of_linear(ll n, ll m, ll a, ll b) {\n\
    \   ll fsum = floor_sum(n, m, a, b);\n   ll le = -1, ri = m - 1;\n   while(ri\
    \ - le > 1) {\n      ll mid = (le + ri) / 2;\n      if(floor_sum(n, m, a, b +\
    \ (m - 1 - mid)) < fsum + n) ri = mid;\n      else le = mid;\n   }\n   return\
    \ ri;\n}\n\nint main() {\n   int t; cin >> t;\n   while(t --) {\n      ll n, m,\
    \ a, b;\n      cin >> n >> m >> a >> b;\n      cout << min_of_mod_of_linear(n,\
    \ m, a, b) << endl;\n   }\n   \n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/floor_sum.hpp\"\
    \nll floor_sum(const ll& n, const ll& m, ll a, ll b) {\n   ll ret = 0;\n   if(a\
    \ >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n   if(b >= m) ret += n * (b\
    \ / m), b %= m;\n   ll y = (a * n + b) / m;\n   if(y == 0) return ret;\n   ll\
    \ x = y * m - b;\n   ret += (n - (x + a - 1) / a) * y;\n   ret += floor_sum(y,\
    \ a, m, (a - x % a) % a);\n   return ret;\n}\n#line 1 \"src/math/min_of_mod_of_linear.hpp\"\
    \n// depends on floor_sum\nll min_of_mod_of_linear(ll n, ll m, ll a, ll b) {\n\
    \    ll fsum = floor_sum(n, m, a, b);\n    ll le = -1, ri = m - 1;\n    while(ri\
    \ - le > 1) {\n       ll mid = (le + ri) / 2;\n       if(floor_sum(n, m, a, b\
    \ + (m - 1 - mid)) < fsum + n) ri = mid;\n       else le = mid;\n    }\n    return\
    \ ri;\n }\n#line 53 \"test/math/min_of_mod_of_linear.test.cpp\"\nint main() {\
    \ puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/268935\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    const ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto&\
    \ a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nll floor_sum(const ll& n, const ll& m, ll a, ll b)\
    \ {\n   ll ret = 0;\n   if(a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n\
    \   if(b >= m) ret += n * (b / m), b %= m;\n   ll y = (a * n + b) / m;\n   if(y\
    \ == 0) return ret;\n   ll x = y * m - b;\n   ret += (n - (x + a - 1) / a) * y;\n\
    \   ret += floor_sum(y, a, m, (a - x % a) % a);\n   return ret;\n}\n\n// depends\
    \ on floor_sum\n// \\sum_0^(n-1) floor((a * i + b) / m)\nll min_of_mod_of_linear(ll\
    \ n, ll m, ll a, ll b) {\n   ll fsum = floor_sum(n, m, a, b);\n   ll le = -1,\
    \ ri = m - 1;\n   while(ri - le > 1) {\n      ll mid = (le + ri) / 2;\n      if(floor_sum(n,\
    \ m, a, b + (m - 1 - mid)) < fsum + n) ri = mid;\n      else le = mid;\n   }\n\
    \   return ri;\n}\n\nint main() {\n   int t; cin >> t;\n   while(t --) {\n   \
    \   ll n, m, a, b;\n      cin >> n >> m >> a >> b;\n      cout << min_of_mod_of_linear(n,\
    \ m, a, b) << endl;\n   }\n   \n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/floor_sum.hpp\"\n#include\
    \ \"src/math/min_of_mod_of_linear.hpp\"\nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/math/floor_sum.hpp
  - src/math/min_of_mod_of_linear.hpp
  isVerificationFile: true
  path: test/math/min_of_mod_of_linear.test.cpp
  requiredBy: []
  timestamp: '2025-02-23 00:00:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/min_of_mod_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/math/min_of_mod_of_linear.test.cpp
- /verify/test/math/min_of_mod_of_linear.test.cpp.html
title: test/math/min_of_mod_of_linear.test.cpp
---
