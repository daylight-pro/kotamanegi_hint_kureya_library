---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: src/graph/low_link.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
  bundledCode: "#line 1 \"test/graph/low_link.test.2.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/low_link.hpp\"\
    \nstruct LowLink {\n   public:\n   vector<vector<int>> g;\n   vector<int> ord,\
    \ low;\n   vector<int> articulation;\n   vector<bool> visited;\n   vector<pair<int,\
    \ int>> bridge;\n\n   void dfs(int cur, int pre, int& k) {\n      visited[cur]\
    \ = true;\n      ord[cur] = low[cur] = k++;\n      bool isArticulation = false;\n\
    \      int cnt = 0;\n      for(auto to : g[cur]) {\n         if(!visited[to])\
    \ {\n            cnt++;\n            dfs(to, cur, k);\n            chmin(low[cur],\
    \ low[to]);\n            if(pre != -1 && ord[cur] <= low[to]) isArticulation =\
    \ true;\n            if(ord[cur] < low[to]) bridge.emplace_back(min(cur, to),\
    \ max(cur, to));\n         } else if(to != pre) chmin(low[cur], ord[to]);\n  \
    \    }\n      if(pre == -1 && cnt > 1) isArticulation = true;\n      if(isArticulation)\
    \ articulation.push_back(cur);\n   }\n\n   void build(const vector<vector<int>>&\
    \ g) {\n      int n = g.size();\n      this->g = g;\n      ord.assign(n, -1);\n\
    \      low.assign(n, -1);\n      visited.assign(n, false);\n      int k = 0;\n\
    \      for(int i = 0; i < n; i++)\n         if(!visited[i]) dfs(i, -1, k);\n \
    \  }\n   LowLink(const vector<vector<int>>& g) { build(g); }\n\n   vector<int>&\
    \ getArticulations() { return articulation; }\n   vector<pair<int, int>>& getBridges()\
    \ { return bridge; }\n   vector<int>& getOrd() { return ord; }\n   vector<int>&\
    \ getLowlink() { return low; }\n};\n#line 5 \"test/graph/low_link.test.2.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   cin >>\
    \ N >> M;\n   vector<vector<int>> G(N);\n   for(int i = 0; i < M; i++) {\n   \
    \   int u, v;\n      cin >> u >> v;\n      G[u].push_back(v);\n      G[v].push_back(u);\n\
    \   }\n   LowLink lowlink(G);\n   auto bridge = lowlink.getBridges();\n   for(auto&&\
    \ [u, v] : bridge) {\n      if(u > v) swap(u, v);\n   }\n   sort(all(bridge));\n\
    \   for(auto& [u, v] : bridge) cout << u << ' ' << v << '\\n';\n   return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\n\n\
    #include \"test/template.hpp\"\n#include \"src/graph/low_link.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   cin >> N >> M;\n   vector<vector<int>>\
    \ G(N);\n   for(int i = 0; i < M; i++) {\n      int u, v;\n      cin >> u >> v;\n\
    \      G[u].push_back(v);\n      G[v].push_back(u);\n   }\n   LowLink lowlink(G);\n\
    \   auto bridge = lowlink.getBridges();\n   for(auto&& [u, v] : bridge) {\n  \
    \    if(u > v) swap(u, v);\n   }\n   sort(all(bridge));\n   for(auto& [u, v] :\
    \ bridge) cout << u << ' ' << v << '\\n';\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: test/graph/low_link.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/low_link.test.2.cpp
layout: document
redirect_from:
- /verify/test/graph/low_link.test.2.cpp
- /verify/test/graph/low_link.test.2.cpp.html
title: test/graph/low_link.test.2.cpp
---
