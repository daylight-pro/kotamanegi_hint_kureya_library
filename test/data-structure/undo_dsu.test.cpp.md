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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/data-structure/undo_dsu.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 1 \"test/template.hpp\"\
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
    \      return -p[leader(a)];\n   }  // 818fe7\n};\n#line 5 \"test/data-structure/undo_dsu.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n\n   undo_dsu d(N);\n   vector<vector<int>> graph(Q + 1);\n   vector<pair<int,\
    \ int>> queries;\n   vector<vector<int>> q(Q + 1);\n   for(int i = 0; i < Q; i++)\
    \ {\n      int t, k, u, v;\n      cin >> t >> k >> u >> v;\n      if(k == -1)\
    \ k = Q;\n      queries.emplace_back(u, v);\n      if(t == 0) {\n         graph[k].emplace_back(i);\n\
    \      } else {\n         q[k].emplace_back(i);\n      }\n   }\n   vector<int>\
    \ ans(Q, -1);\n   auto dfs = [&](auto&& f, int cur = -1) -> void {\n      if(cur\
    \ == -1) cur = Q;\n      else d.merge(queries[cur].first, queries[cur].second);\n\
    \      for(auto i : q[cur]) ans[i] = d.same(queries[i].first, queries[i].second);\n\
    \      for(auto i : graph[cur]) f(f, i);\n      if(cur != Q) d.undo();\n   };\n\
    \   dfs(dfs);\n   for(auto x : ans)\n      if(x != -1) cout << x << '\\n';\n \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/undo_dsu.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n\n   undo_dsu d(N);\n   vector<vector<int>> graph(Q + 1);\n   vector<pair<int,\
    \ int>> queries;\n   vector<vector<int>> q(Q + 1);\n   for(int i = 0; i < Q; i++)\
    \ {\n      int t, k, u, v;\n      cin >> t >> k >> u >> v;\n      if(k == -1)\
    \ k = Q;\n      queries.emplace_back(u, v);\n      if(t == 0) {\n         graph[k].emplace_back(i);\n\
    \      } else {\n         q[k].emplace_back(i);\n      }\n   }\n   vector<int>\
    \ ans(Q, -1);\n   auto dfs = [&](auto&& f, int cur = -1) -> void {\n      if(cur\
    \ == -1) cur = Q;\n      else d.merge(queries[cur].first, queries[cur].second);\n\
    \      for(auto i : q[cur]) ans[i] = d.same(queries[i].first, queries[i].second);\n\
    \      for(auto i : graph[cur]) f(f, i);\n      if(cur != Q) d.undo();\n   };\n\
    \   dfs(dfs);\n   for(auto x : ans)\n      if(x != -1) cout << x << '\\n';\n \
    \  return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/undo_dsu.hpp
  isVerificationFile: true
  path: test/data-structure/undo_dsu.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 18:01:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/undo_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/undo_dsu.test.cpp
- /verify/test/data-structure/undo_dsu.test.cpp.html
title: test/data-structure/undo_dsu.test.cpp
---
