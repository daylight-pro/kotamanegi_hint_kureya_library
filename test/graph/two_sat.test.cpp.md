---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/two_sat.hpp
    title: src/graph/two_sat.hpp
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/graph/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/graph/two_sat.test.cpp\"\
    \n\n#line 1 \"src/graph/scc.hpp\"\n// base: 3085f6\nstruct scc_graph {\n   public:\n\
    \   explicit scc_graph(int _n = 0) : n(_n), G(_n), rG(_n), comp(_n, -1), visited(_n,\
    \ 0) {}\n\n   void add_edge(int from, int to) {\n      // assert(0 <= from &&\
    \ from < n);\n      // assert(0 <= to && to < n);\n      G[from].push_back(to);\n\
    \      rG[to].push_back(from);\n   }\n\n   vector<vector<int>> scc() {\n     \
    \ fill(all(visited), 0);\n      fill(all(comp), -1);\n      order.clear();\n \
    \     for(int i = 0; i < n; i++)\n         if(!visited[i]) dfs(i);\n      comp_size\
    \ = 0;\n      for(int i = size(order) - 1; i >= 0; i--) {\n         if(comp[order[i]]\
    \ < 0) rdfs(order[i], comp_size++);\n      }\n      vector<vector<int>> v(comp_size);\n\
    \      for(int i = 0; i < n; i++) v[comp[i]].push_back(i);\n      return v;\n\
    \   }\n\n   vector<int> get_comp() { return comp; }  // bdafc0\n\n   vector<vector<int>>\
    \ dag() {\n      vector<vector<int>> res(comp_size);\n      for(int i = 0; i <\
    \ n; i++)\n         for(auto j : G[i]) {\n            if(comp[i] != comp[j]) res[comp[i]].push_back(comp[j]);\n\
    \         }\n      for(int i = 0; i < comp_size; i++) {\n         sort(all(res[i]));\n\
    \         res[i].erase(unique(all(res[i])), res[i].end());\n      }\n      return\
    \ res;\n   }  // 312650\n\n   private:\n   vector<vector<int>> G, rG;\n   vector<int>\
    \ order, comp;\n   vector<bool> visited;\n   int n, comp_size;\n\n   void dfs(int\
    \ v) {\n      visited[v] = true;\n      for(auto to : G[v])\n         if(!visited[to])\
    \ dfs(to);\n      order.push_back(v);\n   }\n\n   void rdfs(int v, int k) {\n\
    \      comp[v] = k;\n      for(auto to : rG[v]) {\n         if(comp[to] < 0) rdfs(to,\
    \ k);\n      }\n   }\n};\n#line 1 \"src/graph/two_sat.hpp\"\nstruct two_sat {\n\
    \   public:\n   two_sat() : _n(0), scc(0) {}\n   two_sat(int n) : _n(n), scc(2\
    \ * n), _answer(n) {}\n\n   void add_clause(int i, bool f, int j, bool g) {\n\
    \      // assert(0 <= i && i < _n);\n      // assert(0 <= j && j < _n);\n    \
    \  scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n      scc.add_edge(2\
    \ * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n   }\n\n   bool satisfiable() {\n\
    \      scc.scc();\n      auto comp = scc.get_comp();\n      for(int i = 0; i <\
    \ _n; i++) {\n         if(comp[2 * i] == comp[2 * i + 1]) return false;\n    \
    \     _answer[i] = comp[2 * i] < comp[2 * i + 1];\n      }\n      return true;\n\
    \   }\n\n   vector<bool> answer() { return _answer; }\n\n   private:\n   int _n;\n\
    \   vector<bool> _answer;\n   scc_graph scc;\n};\n#line 6 \"test/graph/two_sat.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string _;\n   cin >>\
    \ _ >> _;\n   int N, M;\n   cin >> N >> M;\n   two_sat ts(N);\n   for(int i =\
    \ 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b >> _;\n      bool f,\
    \ g;\n      if(a < 0) {\n         a = -a - 1;\n         f = false;\n      } else\
    \ {\n         a--;\n         f = true;\n      }\n\n      if(b < 0) {\n       \
    \  b = -b - 1;\n         g = false;\n      } else {\n         b--;\n         g\
    \ = true;\n      }\n      ts.add_clause(a, f, b, g);\n   }\n   if(!ts.satisfiable())\
    \ {\n      cout << \"s UNSATISFIABLE\" << endl;\n      return 0;\n   } else {\n\
    \      cout << \"s SATISFIABLE\" << endl;\n      auto ans = ts.answer();\n   \
    \   cout << \"v \";\n      for(int i = 0; i < N; i++) { cout << (ans[i] ? i +\
    \ 1 : -i - 1) << \" \"; }\n   }\n   cout << \"0\" << endl;\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    test/template.hpp\"\n\n#include \"src/graph/scc.hpp\"\n#include \"src/graph/two_sat.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string _;\n   cin >>\
    \ _ >> _;\n   int N, M;\n   cin >> N >> M;\n   two_sat ts(N);\n   for(int i =\
    \ 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b >> _;\n      bool f,\
    \ g;\n      if(a < 0) {\n         a = -a - 1;\n         f = false;\n      } else\
    \ {\n         a--;\n         f = true;\n      }\n\n      if(b < 0) {\n       \
    \  b = -b - 1;\n         g = false;\n      } else {\n         b--;\n         g\
    \ = true;\n      }\n      ts.add_clause(a, f, b, g);\n   }\n   if(!ts.satisfiable())\
    \ {\n      cout << \"s UNSATISFIABLE\" << endl;\n      return 0;\n   } else {\n\
    \      cout << \"s SATISFIABLE\" << endl;\n      auto ans = ts.answer();\n   \
    \   cout << \"v \";\n      for(int i = 0; i < N; i++) { cout << (ans[i] ? i +\
    \ 1 : -i - 1) << \" \"; }\n   }\n   cout << \"0\" << endl;\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/scc.hpp
  - src/graph/two_sat.hpp
  isVerificationFile: true
  path: test/graph/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/graph/two_sat.test.cpp
- /verify/test/graph/two_sat.test.cpp.html
title: test/graph/two_sat.test.cpp
---
