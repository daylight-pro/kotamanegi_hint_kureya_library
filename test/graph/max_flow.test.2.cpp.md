---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/max_flow.hpp
    title: src/graph/max_flow.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/graph/max_flow.test.2.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/max_flow.hpp\"\
    \n// base: 9927a4\ntemplate<class Cap> struct mf_graph {\n   public:\n   mf_graph()\
    \ : _n(0) {}\n   mf_graph(int n) : _n(n), g(n) {}\n\n   int add_edge(int from,\
    \ int to, Cap cap) {\n      int m = size(pos);\n      pos.push_back({from, size(g[from])});\n\
    \      int from_id = size(g[from]);\n      int to_id = size(g[to]);\n      if(from\
    \ == to) to_id++;\n      g[from].push_back(_edge{to, to_id, cap});\n      g[to].push_back(_edge{from,\
    \ from_id, 0});\n      return m;\n   }\n\n   Cap flow(int s, int t, Cap flow_limit\
    \ = numeric_limits<Cap>::max()) {\n      vector<int> level(_n), iter(_n);\n  \
    \    queue<int> que;\n      auto bfs = [&]() {\n         fill(all(level), -1);\n\
    \         level[s] = 0;\n         while(!que.empty()) que.pop();\n         que.push(s);\n\
    \         while(!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for(auto e : g[v]) {\n               if(e.cap == 0\
    \ || level[e.to] >= 0) continue;\n               level[e.to] = level[v] + 1;\n\
    \               if(e.to == t) return;\n               que.push(e.to);\n      \
    \      }\n         }\n      };\n      auto dfs = [&](auto self, int v, Cap up)\
    \ {\n         if(v == s) return up;\n         Cap res = 0;\n         int level_v\
    \ = level[v];\n         for(int& i = iter[v]; i < size(g[v]); i++) {\n       \
    \     _edge& e = g[v][i];\n            if(level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n            Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \            if(d <= 0) continue;\n            g[v][i].cap += d;\n           \
    \ g[e.to][e.rev].cap -= d;\n            res += d;\n            if(res == up) break;\n\
    \         }\n         return res;\n      };\n\n      Cap flow = 0;\n      while(flow\
    \ < flow_limit) {\n         bfs();\n         if(level[t] == -1) break;\n     \
    \    fill(all(iter), 0);\n         while(flow < flow_limit) {\n            Cap\
    \ f = dfs(dfs, t, flow_limit - flow);\n            if(!f) break;\n           \
    \ flow += f;\n         }\n      }\n      return flow;\n   }\n\n   vector<bool>\
    \ min_cut(int s) {\n      vector<bool> visited(_n);\n      queue<int> que;\n \
    \     que.push(s);\n      visited[s] = true;\n      while(!que.empty()) {\n  \
    \       int v = que.front();\n         que.pop();\n         for(auto e : g[v])\
    \ {\n            if(e.cap && !visited[e.to]) {\n               visited[e.to] =\
    \ true;\n               que.push(e.to);\n            }\n         }\n      }\n\
    \      return visited;\n   }  // 8735cf\n\n   struct edge {\n      int from, to;\n\
    \      Cap cap, flow;\n   };  // 9fe107\n\n   edge get_edge(int i) {\n      int\
    \ m = size(pos);\n      auto _e = g[pos[i].first][pos[i].second];\n      auto\
    \ _re = g[_e.to][_e.rev];\n      return edge{pos[i].first, _e.to, _e.cap + _re.cap,\
    \ _re.cap};\n   }  // ad4299\n\n   vector<edge> edges() {\n      int m = size(pos);\n\
    \      vector<edge> result;\n      for(int i = 0; i < m; i++) result.push_back(get_edge(i));\n\
    \      return result;\n   }  // 5948b8\n\n   void change_edge(int i, Cap new_cap,\
    \ Cap new_flow) {\n      int m = size(pos);\n      auto& _e = g[pos[i].first][pos[i].second];\n\
    \      auto& _re = g[_e.to][_e.rev];\n      _e.cap = new_cap - new_flow;\n   \
    \   _re.cap = new_flow;\n   }  // 558c35\n\n   private:\n   int _n;\n   struct\
    \ _edge {\n      int to, rev;\n      Cap cap;\n   };\n   vector<pair<int, int>>\
    \ pos;\n   vector<vector<_edge>> g;\n};\n#line 5 \"test/graph/max_flow.test.2.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int n, m;\n   cin >>\
    \ n >> m;\n\n   mf_graph<int> g(n);\n   for(int i = 0; i < m; i++) {\n      int\
    \ u, v, c;\n      cin >> u >> v >> c;\n      g.add_edge(u, v, c);\n   }\n   cout\
    \ << g.flow(0, n - 1) << \"\\n\";\n\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n\n\
    #include \"test/template.hpp\"\n#include \"src/graph/max_flow.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int n, m;\n   cin >> n >> m;\n\n \
    \  mf_graph<int> g(n);\n   for(int i = 0; i < m; i++) {\n      int u, v, c;\n\
    \      cin >> u >> v >> c;\n      g.add_edge(u, v, c);\n   }\n   cout << g.flow(0,\
    \ n - 1) << \"\\n\";\n\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/max_flow.hpp
  isVerificationFile: true
  path: test/graph/max_flow.test.2.cpp
  requiredBy: []
  timestamp: '2025-02-25 03:49:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/max_flow.test.2.cpp
layout: document
redirect_from:
- /verify/test/graph/max_flow.test.2.cpp
- /verify/test/graph/max_flow.test.2.cpp.html
title: test/graph/max_flow.test.2.cpp
---
