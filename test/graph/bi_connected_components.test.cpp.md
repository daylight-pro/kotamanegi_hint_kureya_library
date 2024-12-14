---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bi_connected_components.hpp
    title: src/graph/bi_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: src/graph/low_link.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/graph/bi_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n#line 1\
    \ \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/low_link.hpp\"\
    \nstruct LowLink {\n   vector<vector<int>> g;\n   vector<int> ord, low;\n   vector<int>\
    \ articulation;\n   vector<bool> visited;\n   vector<pair<int, int>> bridge;\n\
    \n   void dfs(int cur, int pre, int& k) {\n      visited[cur] = true;\n      ord[cur]\
    \ = low[cur] = k++;\n      bool isArticulation = false, beet = false;\n      int\
    \ cnt = 0;\n      for(auto to : g[cur]) {\n         if(to == pre && !exchange(beet,\
    \ true)) continue;\n         if(!visited[to]) {\n            cnt++;\n        \
    \    dfs(to, cur, k);\n            chmin(low[cur], low[to]);\n            isArticulation\
    \ |= pre != -1 && low[to] >= ord[cur];\n            if(ord[cur] < low[to]) bridge.emplace_back(min(cur,\
    \ to), max(cur, to));\n         } else chmin(low[cur], ord[to]);\n      }\n  \
    \    isArticulation |= pre == -1 && cnt > 1;\n      if(isArticulation) articulation.push_back(cur);\n\
    \   }\n\n   void build(const vector<vector<int>>& g) {\n      int n = g.size();\n\
    \      this->g = g;\n      ord.assign(n, -1);\n      low.assign(n, -1);\n    \
    \  visited.assign(n, false);\n      int k = 0;\n      for(int i = 0; i < n; i++)\n\
    \         if(!visited[i]) dfs(i, -1, k);\n   }\n\n   public:\n   LowLink(const\
    \ vector<vector<int>>& g) { build(g); }\n\n   vector<int>& getArticulations()\
    \ { return articulation; }\n   vector<pair<int, int>>& getBridges() { return bridge;\
    \ }\n   vector<int>& getOrd() { return ord; }\n   vector<int>& getLowlink() {\
    \ return low; }\n};\n#line 1 \"src/graph/bi_connected_components.hpp\"\nstruct\
    \ BiConnectedComponents : LowLink {\n   public:\n   using LowLink::bridge;\n \
    \  using LowLink::g;\n   using LowLink::low;\n   using LowLink::ord;\n\n   vector<int>\
    \ comp;\n   vector<vector<int>> tree;\n   vector<vector<int>> group;\n\n   void\
    \ build(const vector<vector<int>>& g) {\n      comp.assign(size(g), -1);\n   \
    \   int k = 0;\n      for(int i = 0; i < size(comp); i++) {\n         if(comp[i]\
    \ == -1) { dfs(i, -1, k); }\n      }\n      group.resize(k);\n      for(int i\
    \ = 0; i < size(g); i++) { group[comp[i]].push_back(i); }\n      tree.resize(k);\n\
    \      for(auto& e : bridge) {\n         tree[comp[e.first]].push_back(comp[e.second]);\n\
    \         tree[comp[e.second]].push_back(comp[e.first]);\n      }\n   }\n   vector<vector<int>>\
    \ getTree() { return tree; }\n   vector<vector<int>> getGroup() { return group;\
    \ }\n\n   explicit BiConnectedComponents(const vector<vector<int>>& g) : LowLink(g)\
    \ { build(g); }\n\n   private:\n   vector<int> used;\n   vector<pair<int, int>>\
    \ tmp;\n\n   void dfs(int cur, int pre, int& k) {\n      if(pre != -1 && ord[pre]\
    \ >= low[cur]) comp[cur] = comp[pre];\n      else comp[cur] = k++;\n      for(auto\
    \ to : g[cur]) {\n         if(comp[to] == -1) dfs(to, cur, k);\n      }\n   }\n\
    };\n#line 6 \"test/graph/bi_connected_components.test.cpp\"\n\nint main() {\n\
    \   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   cin >> N >> M;\n   vector<vector<int>>\
    \ g(N);\n   for(int i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n\
    \      g[a].push_back(b);\n      g[b].push_back(a);\n   }\n   BiConnectedComponents\
    \ bcc(g);\n   cout << bcc.getGroup().size() << \"\\n\";\n   for(auto& bg : bcc.getGroup())\
    \ {\n      cout << bg.size();\n      for(auto& v : bg) cout << \" \" << v;\n \
    \     cout << \"\\n\";\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/graph/low_link.hpp\"\n#include\
    \ \"src/graph/bi_connected_components.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, M;\n   cin >> N >> M;\n   vector<vector<int>> g(N);\n   for(int i =\
    \ 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      g[a].push_back(b);\n\
    \      g[b].push_back(a);\n   }\n   BiConnectedComponents bcc(g);\n   cout <<\
    \ bcc.getGroup().size() << \"\\n\";\n   for(auto& bg : bcc.getGroup()) {\n   \
    \   cout << bg.size();\n      for(auto& v : bg) cout << \" \" << v;\n      cout\
    \ << \"\\n\";\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/low_link.hpp
  - src/graph/bi_connected_components.hpp
  isVerificationFile: true
  path: test/graph/bi_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-12-15 04:32:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bi_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bi_connected_components.test.cpp
- /verify/test/graph/bi_connected_components.test.cpp.html
title: test/graph/bi_connected_components.test.cpp
---
