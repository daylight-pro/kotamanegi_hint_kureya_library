---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/undo_dsu.hpp
    title: src/data-structure/undo_dsu.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0723
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0723
  bundledCode: "#line 1 \"test/data-structure/undo_dsu.test.2.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/0723\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/undo_dsu.hpp\"\n// base:\
    \ edf246\nstruct undo_dsu {\n   private:\n   int _n;\n   vector<int> p;\n   stack<pair<int,\
    \ int>> history;\n\n   public:\n   undo_dsu() : _n(0) {}\n   explicit undo_dsu(int\
    \ n) : _n(n), p(n, -1) {}\n\n   int merge(int a, int b) {\n      // assert(0 <=\
    \ a && a < _n);\n      // assert(0 <= b && b < _n);\n      int x = leader(a),\
    \ y = leader(b);\n      if(x == y) {\n         history.emplace(x, p[x]);\n   \
    \      history.emplace(y, p[y]);\n         return x;\n      }\n      if(-p[x]\
    \ < -p[y]) swap(x, y);\n      history.emplace(x, p[x]);\n      history.emplace(y,\
    \ p[y]);\n      p[x] += p[y];\n      p[y] = x;\n      return x;\n   }\n\n   bool\
    \ same(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      return leader(a) == leader(b);\n   }\n\n   int leader(int\
    \ a) {\n      // assert(0 <= a && a < _n);\n      while(p[a] >= 0) a = p[a];\n\
    \      return a;\n   }\n\n   void undo() {\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n      p[history.top().first] = history.top().second;\n\
    \      history.pop();\n   }\n\n   int snapshot() { return history.size(); }\n\n\
    \   void rollback(int snapshot = 0) {\n      while(history.size() > snapshot)\
    \ undo();\n   }\n\n   int size(int a) {\n      // assert(0 <= a && a < _n);\n\
    \      return -p[leader(a)];\n   }  // 818fe7\n};\n#line 5 \"test/data-structure/undo_dsu.test.2.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M, K;\n   cin\
    \ >> N >> M >> K;\n   vector<pair<int, int>> edges(M);\n   for(int i = 0; i <\
    \ M; i++) {\n      int u, v;\n      cin >> u >> v;\n      u--;\n      v--;\n \
    \     edges[i] = {u, v};\n   }\n\n   vector<int> S(N);\n   for(auto&& s : S) cin\
    \ >> s;\n   map<pair<int, int>, vector<pair<int, int>>> E;\n   undo_dsu dsu(N);\n\
    \   for(auto [u, v] : edges) {\n      int su = S[u], sv = S[v];\n      if(su ==\
    \ sv) {\n         dsu.merge(u, v);\n      } else {\n         if(su > sv) {\n \
    \           swap(u, v);\n            swap(su, sv);\n         }\n         E[{su,\
    \ sv}].push_back({u, v});\n      }\n   }\n   int snapshot = dsu.snapshot();\n\
    \   int Q;\n   cin >> Q;\n   vector<int> ans(Q);\n   map<pair<int, int>, vector<int>>\
    \ q;\n   vector<pair<int, int>> query(Q);\n\n   for(int i = 0; i < Q; i++) {\n\
    \      int A, B;\n      cin >> A >> B;\n      A--;\n      B--;\n      if(S[A]\
    \ > S[B]) swap(A, B);\n      int SA = A;\n      int SB = B;\n      query[i] =\
    \ {A, B};\n      q[{S[A], S[B]}].push_back(i);\n   }\n\n   for(auto [key, value]\
    \ : q) {\n      auto [su, sv] = key;\n      for(auto [u, v] : E[{su, sv}]) { dsu.merge(u,\
    \ v); }\n      for(auto i : value) {\n         auto [A, B] = query[i];\n     \
    \    ans[i] = dsu.same(A, B);\n      }\n      dsu.rollback(snapshot);\n   }\n\
    \   for(auto&& a : ans) cout << a << '\\n';\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0723\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/data-structure/undo_dsu.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M, K;\n   cin >> N >> M >>\
    \ K;\n   vector<pair<int, int>> edges(M);\n   for(int i = 0; i < M; i++) {\n \
    \     int u, v;\n      cin >> u >> v;\n      u--;\n      v--;\n      edges[i]\
    \ = {u, v};\n   }\n\n   vector<int> S(N);\n   for(auto&& s : S) cin >> s;\n  \
    \ map<pair<int, int>, vector<pair<int, int>>> E;\n   undo_dsu dsu(N);\n   for(auto\
    \ [u, v] : edges) {\n      int su = S[u], sv = S[v];\n      if(su == sv) {\n \
    \        dsu.merge(u, v);\n      } else {\n         if(su > sv) {\n          \
    \  swap(u, v);\n            swap(su, sv);\n         }\n         E[{su, sv}].push_back({u,\
    \ v});\n      }\n   }\n   int snapshot = dsu.snapshot();\n   int Q;\n   cin >>\
    \ Q;\n   vector<int> ans(Q);\n   map<pair<int, int>, vector<int>> q;\n   vector<pair<int,\
    \ int>> query(Q);\n\n   for(int i = 0; i < Q; i++) {\n      int A, B;\n      cin\
    \ >> A >> B;\n      A--;\n      B--;\n      if(S[A] > S[B]) swap(A, B);\n    \
    \  int SA = A;\n      int SB = B;\n      query[i] = {A, B};\n      q[{S[A], S[B]}].push_back(i);\n\
    \   }\n\n   for(auto [key, value] : q) {\n      auto [su, sv] = key;\n      for(auto\
    \ [u, v] : E[{su, sv}]) { dsu.merge(u, v); }\n      for(auto i : value) {\n  \
    \       auto [A, B] = query[i];\n         ans[i] = dsu.same(A, B);\n      }\n\
    \      dsu.rollback(snapshot);\n   }\n   for(auto&& a : ans) cout << a << '\\\
    n';\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/data-structure/undo_dsu.hpp
  isVerificationFile: true
  path: test/data-structure/undo_dsu.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-12 18:23:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/undo_dsu.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/undo_dsu.test.2.cpp
- /verify/test/data-structure/undo_dsu.test.2.cpp.html
title: test/data-structure/undo_dsu.test.2.cpp
---
