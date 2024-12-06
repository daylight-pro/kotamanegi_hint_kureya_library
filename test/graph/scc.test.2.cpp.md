---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"test/graph/scc.test.2.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/scc.hpp\"\n\
    // base: 1e9c3f\nstruct scc_graph {\n   public:\n   explicit scc_graph(int _n\
    \ = 0) : n(_n), G(_n), rG(_n), comp(_n, -1), visited(_n, 0) {}\n\n   void add_edge(int\
    \ from, int to) {\n      // assert(0 <= from && from < n);\n      // assert(0\
    \ <= to && to < n);\n      G[from].push_back(to);\n      rG[to].push_back(from);\n\
    \   }\n\n   vector<vector<int>> scc() {\n      fill(all(visited), 0);\n      fill(all(comp),\
    \ -1);\n      order.clear();\n      rep(i, 0, n) if(!visited[i]) dfs(i);\n   \
    \   comp_size = 0;\n      for(int i = sz(order) - 1; i >= 0; i--) {\n        \
    \ if(comp[order[i]] < 0) rdfs(order[i], comp_size++);\n      }\n      vector<vector<int>>\
    \ v(comp_size);\n      rep(i, 0, n) v[comp[i]].push_back(i);\n      return v;\n\
    \   }\n\n   vector<int> get_comp() { return comp; }  // bdafc0\n\n   vector<vector<int>>\
    \ dag() {\n      vector<vector<int>> res(comp_size);\n      rep(i, 0, n) for(auto\
    \ j : G[i]) {\n         if(comp[i] != comp[j]) res[comp[i]].push_back(comp[j]);\n\
    \      }\n      rep(i, 0, comp_size) {\n         sort(all(res[i]));\n        \
    \ res[i].erase(unique(all(res[i])), res[i].end());\n      }\n      return res;\n\
    \   }  // da3a19\n\n   private:\n   vector<vector<int>> G, rG;\n   vector<int>\
    \ order, comp;\n   vector<bool> visited;\n   int n, comp_size;\n\n   void dfs(int\
    \ v) {\n      visited[v] = true;\n      for(auto to : G[v])\n         if(!visited[to])\
    \ dfs(to);\n      order.push_back(v);\n   }\n\n   void rdfs(int v, int k) {\n\
    \      comp[v] = k;\n      for(auto to : rG[v]) {\n         if(comp[to] < 0) rdfs(to,\
    \ k);\n      }\n   }\n};\n#line 5 \"test/graph/scc.test.2.cpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int V, E;\n   cin >> V >> E;\n   scc_graph\
    \ g(V);\n   rep(i, 0, E) {\n      int s, t;\n      cin >> s >> t;\n      g.add_edge(s,\
    \ t);\n   }\n   auto scc = g.scc();\n   auto rev = vector<int>(V);\n   rep(i,\
    \ 0, sz(scc)) for(auto v : scc[i]) rev[v] = i;\n   int Q;\n   cin >> Q;\n   while(Q--)\
    \ {\n      int u, v;\n      cin >> u >> v;\n      cout << (rev[u] == rev[v]) <<\
    \ '\\n';\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\n\n\
    #include \"test/template.hpp\"\n#include \"src/graph/scc.hpp\"\n\nint main() {\n\
    \   cin.tie(0)->sync_with_stdio(0);\n   int V, E;\n   cin >> V >> E;\n   scc_graph\
    \ g(V);\n   rep(i, 0, E) {\n      int s, t;\n      cin >> s >> t;\n      g.add_edge(s,\
    \ t);\n   }\n   auto scc = g.scc();\n   auto rev = vector<int>(V);\n   rep(i,\
    \ 0, sz(scc)) for(auto v : scc[i]) rev[v] = i;\n   int Q;\n   cin >> Q;\n   while(Q--)\
    \ {\n      int u, v;\n      cin >> u >> v;\n      cout << (rev[u] == rev[v]) <<\
    \ '\\n';\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/graph/scc.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-07 01:03:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/scc.test.2.cpp
layout: document
redirect_from:
- /verify/test/graph/scc.test.2.cpp
- /verify/test/graph/scc.test.2.cpp.html
title: test/graph/scc.test.2.cpp
---
