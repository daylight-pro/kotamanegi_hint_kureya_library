---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: BIT (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/hld.hpp
    title: src/graph/tree/hld.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/graph/tree/hld.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/BIT.hpp\"\
    \nstruct BIT {\n   vector<ll> a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i,\
    \ ll x) {  // A[i] += x\n      i++;\n      while(i < size(a)) {\n         a[i]\
    \ += x;\n         i += i & -i;\n      }\n   }\n   ll sum(ll r) {\n      ll s =\
    \ 0;\n      while(r) {\n         s += a[r];\n         r -= r & -r;\n      }\n\
    \      return s;\n   }\n   ll sum(ll l, ll r) {  // sum of A[l, r)\n      return\
    \ sum(r) - sum(l);\n   }\n};\n#line 1 \"src/graph/tree/hld.hpp\"\nclass HLDcomposition\
    \ {\n   private:\n   int V;\n   vector<vector<int>> G;\n   vector<int> stsize,\
    \ parent, pathtop, in, out;\n   int root;\n   void build_stsize(int u, int p)\
    \ {\n      stsize[u] = 1, parent[u] = p;\n      for(auto&& v : G[u]) {\n     \
    \    if(v == p) {\n            if(v == G[u].back()) break;\n            else swap(v,\
    \ G[u].back());\n         }\n         build_stsize(v, u);\n         stsize[u]\
    \ += stsize[v];\n         if(stsize[v] > stsize[G[u][0]]) swap(v, G[u][0]);\n\
    \      }\n   }\n\n   void build_path(int u, int p, int& tm) {\n      in[u] = tm++;\n\
    \      for(auto v : G[u]) {\n         if(v == p) continue;\n         pathtop[v]\
    \ = (v == G[u][0] ? pathtop[u] : v);\n         build_path(v, u, tm);\n      }\n\
    \      out[u] = tm;\n   }\n\n   public:\n   void add_edge(int u, int v) {\n  \
    \    G[u].push_back(v);\n      G[v].push_back(u);\n   }\n\n   void build(int _root\
    \ = 0) {\n      root = _root;\n      int tm = 0;\n      build_stsize(root, -1);\n\
    \      pathtop[root] = root;\n      build_path(root, -1, tm);\n   }\n\n   inline\
    \ int index(int a) { return in[a]; }\n\n   int lca(int a, int b) {\n      int\
    \ pa = pathtop[a], pb = pathtop[b];\n      while(pa != pb) {\n         if(in[pa]\
    \ > in[pb]) {\n            a = parent[pa], pa = pathtop[a];\n         } else {\n\
    \            b = parent[pb], pb = pathtop[b];\n         }\n      }\n      if(in[a]\
    \ > in[b]) swap(a, b);\n      return a;\n   }\n\n   pair<int, int> subtree_query(int\
    \ a) { return {in[a], out[a]}; }\n\n   vector<tuple<int, int, bool>> path_query(int\
    \ from, int to) {\n      int pf = pathtop[from], pt = pathtop[to];\n      using\
    \ T = tuple<int, int, bool>;\n      deque<T> front, back;\n      while(pf != pt)\
    \ {\n         if(in[pf] > in[pt]) {\n            front.push_back({in[pf], in[from]\
    \ + 1, true});\n            from = parent[pf], pf = pathtop[from];\n         }\
    \ else {\n            back.push_front({in[pt], in[to] + 1, false});\n        \
    \    to = parent[pt], pt = pathtop[to];\n         }\n      }\n      if(in[from]\
    \ > in[to]) front.push_back({in[to], in[from] + 1, true});\n      else front.push_back({in[from],\
    \ in[to] + 1, false});\n      vector<T> ret;\n      while(!front.empty()) {\n\
    \         ret.push_back(front.front());\n         front.pop_front();\n      }\n\
    \      while(!back.empty()) {\n         ret.push_back(back.front());\n       \
    \  back.pop_front();\n      }\n      return ret;\n   }\n\n   HLDcomposition(int\
    \ node_size)\n       : V(node_size), G(V), stsize(V, 0), parent(V, -1), pathtop(V,\
    \ -1), in(V, -1), out(V, -1) {}\n};\n#line 6 \"test/graph/tree/hld.test.cpp\"\n\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >> N\
    \ >> Q;\n   vector<ll> A(N);\n   for(auto&& a : A) cin >> a;\n   HLDcomposition\
    \ hld(N);\n   for(int i = 0; i < N - 1; i++) {\n      int u, v;\n      cin >>\
    \ u >> v;\n      hld.add_edge(u, v);\n   }\n   hld.build();\n   auto fw = BIT(N);\n\
    \   for(int i = 0; i < N; i++) fw.add(hld.index(i), A[i]);\n   while(Q--) {\n\
    \      int k;\n      cin >> k;\n      if(k == 0) {\n         int p, x;\n     \
    \    cin >> p >> x;\n         fw.add(hld.index(p), x);\n      } else {\n     \
    \    int u, v;\n         cin >> u >> v;\n         ll ans = 0;\n         for(auto\
    \ [l, r, f] : hld.path_query(u, v)) ans += fw.sum(l, r);\n         cout << ans\
    \ << endl;\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/BIT.hpp\"\n#include\
    \ \"src/graph/tree/hld.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   vector<ll> A(N);\n   for(auto&& a : A) cin\
    \ >> a;\n   HLDcomposition hld(N);\n   for(int i = 0; i < N - 1; i++) {\n    \
    \  int u, v;\n      cin >> u >> v;\n      hld.add_edge(u, v);\n   }\n   hld.build();\n\
    \   auto fw = BIT(N);\n   for(int i = 0; i < N; i++) fw.add(hld.index(i), A[i]);\n\
    \   while(Q--) {\n      int k;\n      cin >> k;\n      if(k == 0) {\n        \
    \ int p, x;\n         cin >> p >> x;\n         fw.add(hld.index(p), x);\n    \
    \  } else {\n         int u, v;\n         cin >> u >> v;\n         ll ans = 0;\n\
    \         for(auto [l, r, f] : hld.path_query(u, v)) ans += fw.sum(l, r);\n  \
    \       cout << ans << endl;\n      }\n   }\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/data-structure/BIT.hpp
  - src/graph/tree/hld.hpp
  isVerificationFile: true
  path: test/graph/tree/hld.test.cpp
  requiredBy: []
  timestamp: '2025-01-03 11:14:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/hld.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/hld.test.cpp
- /verify/test/graph/tree/hld.test.cpp.html
title: test/graph/tree/hld.test.cpp
---
