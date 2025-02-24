---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/min_cost_flow.hpp
    title: src/graph/min_cost_flow.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
  bundledCode: "#line 1 \"test/graph/min_cost_flow.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja\"\n\n\
    #line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/min_cost_flow.hpp\"\
    \n// base: 4e9f1c\ntemplate<class Cap, class Cost> struct mcf_graph {\n   public:\n\
    \   mcf_graph() {}\n   mcf_graph(int n) : _n(n), g(n) {}\n\n   int add_edge(int\
    \ from, int to, Cap cap, Cost cost) {\n      int m = size(pos);\n      pos.push_back({from,\
    \ size(g[from])});\n      int from_id = size(g[from]);\n      int to_id = size(g[to]);\n\
    \      if(from == to) to_id++;\n      g[from].push_back(_edge{to, to_id, cap,\
    \ cost});\n      g[to].push_back(_edge{from, from_id, 0, -cost});\n      return\
    \ m;\n   }\n\n   pair<Cap, Cost> flow(int s, int t, Cap flow_limit = numeric_limits<Cap>::max())\
    \ {\n      return slope(s, t, flow_limit).back();\n   }\n   vector<pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit = numeric_limits<Cap>::max()) {\n      vector<Cost>\
    \ dual(_n, 0), dist(_n);\n      vector<int> pv(_n), pe(_n);\n      vector<bool>\
    \ vis(_n);\n      auto dual_ref = [&]() {\n         fill(all(dist), numeric_limits<Cost>::max());\n\
    \         fill(all(pv), -1);\n         fill(all(pe), -1);\n         fill(all(vis),\
    \ false);\n         struct Q {\n            Cost key;\n            int to;\n \
    \           bool operator<(const Q& r) const { return key > r.key; }\n       \
    \  };\n         priority_queue<Q> que;\n         dist[s] = 0;\n         que.push(Q{0,\
    \ s});\n         while(!que.empty()) {\n            int v = que.top().to;\n  \
    \          que.pop();\n            if(vis[v]) continue;\n            vis[v] =\
    \ true;\n            if(v == t) break;\n            for(int i = 0; i < size(g[v]);\
    \ i++) {\n               auto e = g[v][i];\n               if(vis[e.to] || !e.cap)\
    \ continue;\n               Cost cost = e.cost - dual[e.to] + dual[v];\n     \
    \          if(chmin(dist[e.to], dist[v] + cost)) {\n                  pv[e.to]\
    \ = v;\n                  pe[e.to] = i;\n                  que.push(Q{dist[e.to],\
    \ e.to});\n               }\n            }\n         }\n         if(!vis[t]) return\
    \ false;\n         for(int v = 0; v < _n; v++)\n            if(vis[v]) dual[v]\
    \ -= dist[t] - dist[v];\n         return true;\n      };\n      Cap flow = 0;\n\
    \      Cap cost = 0, prev_cost_per_flow = -1;\n      vector<pair<Cap, Cost>> result;\n\
    \      result.push_back({flow, cost});\n      while(flow < flow_limit) {\n   \
    \      if(!dual_ref()) break;\n         Cap c = flow_limit - flow;\n         for(int\
    \ v = t; v != s; v = pv[v]) { c = min(c, g[pv[v]][pe[v]].cap); }\n         for(int\
    \ v = t; v != s; v = pv[v]) {\n            auto& e = g[pv[v]][pe[v]];\n      \
    \      e.cap -= c;\n            g[v][e.rev].cap += c;\n         }\n         Cost\
    \ d = -dual[s];\n         flow += c;\n         cost += c * d;\n         if(prev_cost_per_flow\
    \ == d) { result.pop_back(); }\n         result.push_back({flow, cost});\n   \
    \      prev_cost_per_flow = d;\n      }\n      return result;\n   }\n\n   struct\
    \ edge {\n      int from, to;\n      Cap cap, flow;\n   };  // 9fe107\n\n   edge\
    \ get_edge(int i) {\n      int m = size(pos);\n      auto _e = g[pos[i].first][pos[i].second];\n\
    \      auto _re = g[_e.to][_e.rev];\n      return edge({pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap});\n   }  // d7bd7e\n\n   vector<edge> edges() {\n      int\
    \ m = size(pos);\n      vector<edge> result;\n      for(int i = 0; i < m; i++)\
    \ result.push_back(get_edge(i));\n      return result;\n   }  // 5948b8\n\n  \
    \ void change_edge(int i, Cap new_cap, Cap new_flow) {\n      int m = size(pos);\n\
    \      auto& _e = g[pos[i].first][pos[i].second];\n      auto& _re = g[_e.to][_e.rev];\n\
    \      _e.cap = new_cap - new_flow;\n      _re.cap = new_flow;\n   }  // 558c35\n\
    \n   private:\n   int _n;\n   struct _edge {\n      int to, rev;\n      Cap cap;\n\
    \      Cost cost;\n   };\n\n   vector<pair<int, int>> pos;\n   vector<vector<_edge>>\
    \ g;\n};\n#line 5 \"test/graph/min_cost_flow.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int n, e, f;\n   cin >> n >> e >> f;\n   mcf_graph<int, int> g(n);\n   for(int\
    \ i = 0; i < e; i++) {\n      int u, v, c, d;\n      cin >> u >> v >> c >> d;\n\
    \      g.add_edge(u, v, c, d);\n   }\n   auto ans = g.flow(0, n - 1, f);\n   if(ans.first\
    \ < f) {\n      cout << -1 << endl;\n   } else {\n      cout << ans.second <<\
    \ endl;\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/graph/min_cost_flow.hpp\"\n\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int n, e, f;\n   cin >>\
    \ n >> e >> f;\n   mcf_graph<int, int> g(n);\n   for(int i = 0; i < e; i++) {\n\
    \      int u, v, c, d;\n      cin >> u >> v >> c >> d;\n      g.add_edge(u, v,\
    \ c, d);\n   }\n   auto ans = g.flow(0, n - 1, f);\n   if(ans.first < f) {\n \
    \     cout << -1 << endl;\n   } else {\n      cout << ans.second << endl;\n  \
    \ }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/graph/min_cost_flow.hpp
  isVerificationFile: true
  path: test/graph/min_cost_flow.test.cpp
  requiredBy: []
  timestamp: '2025-02-25 03:49:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/min_cost_flow.test.cpp
layout: document
redirect_from:
- /verify/test/graph/min_cost_flow.test.cpp
- /verify/test/graph/min_cost_flow.test.cpp.html
title: test/graph/min_cost_flow.test.cpp
---
