---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/topological_sort.hpp
    title: src/graph/topological_sort.hpp
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
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=9994177
  bundledCode: "#line 1 \"test/graph/topological_sort.test.cpp\"\n/*\n\u30B9\u30DA\
    \u30B7\u30E3\u30EB\u30B8\u30E3\u30C3\u30B8\u306E\u305F\u3081verify\u3067\u304D\
    \u306A\u3044\u304CAC\u78BA\u8A8D\u6E08\u307F\nhttps://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=9994177\n\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/graph/topological_sort.hpp\"\
    \n\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   cin >>\
    \ N >> M;\n   vector<vector<int>> g(N);\n   for(int i = 0; i < M; i++) {\n   \
    \   int u, v;\n      cin >> u >> v;\n      g[u].push_back(v);\n   }\n   auto res\
    \ = topological_sort(g);\n   for(auto x : res) cout << x << '\\n';\n   return\
    \ 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/topological_sort.hpp\"\
    \nvector<int> topological_sort(vector<vector<int>>& g) {\n   int n = g.size();\n\
    \   vector<int> indeg(n);\n   for(int i = 0; i < n; i++)\n      for(int j : g[i])\
    \ indeg[j]++;\n   vector<int> res;\n   queue<int> q;\n   for(int i = 0; i < n;\
    \ i++)\n      if(indeg[i] == 0) q.push(i);\n   while(!q.empty()) {\n      auto\
    \ v = q.front();\n      q.pop();\n      res.push_back(v);\n      for(auto u :\
    \ g[v]) {\n         indeg[u]--;\n         if(indeg[u] == 0) q.push(u);\n     \
    \ }\n   }\n   return res;\n}\n#line 30 \"test/graph/topological_sort.test.cpp\"\
    \n\nint main() { puts(\"Hello World\"); }\n"
  code: "/*\n\u30B9\u30DA\u30B7\u30E3\u30EB\u30B8\u30E3\u30C3\u30B8\u306E\u305F\u3081\
    verify\u3067\u304D\u306A\u3044\u304CAC\u78BA\u8A8D\u6E08\u307F\nhttps://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=9994177\n\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/graph/topological_sort.hpp\"\
    \n\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   cin >>\
    \ N >> M;\n   vector<vector<int>> g(N);\n   for(int i = 0; i < M; i++) {\n   \
    \   int u, v;\n      cin >> u >> v;\n      g[u].push_back(v);\n   }\n   auto res\
    \ = topological_sort(g);\n   for(auto x : res) cout << x << '\\n';\n   return\
    \ 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/graph/topological_sort.hpp\"\n\
    \nint main() { puts(\"Hello World\"); }\n"
  dependsOn:
  - test/template.hpp
  - src/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/graph/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 01:52:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/graph/topological_sort.test.cpp
- /verify/test/graph/topological_sort.test.cpp.html
title: test/graph/topological_sort.test.cpp
---
