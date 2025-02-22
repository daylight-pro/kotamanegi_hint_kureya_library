---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/max_flow.test.2.cpp
    title: test/graph/max_flow.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/max_flow.test.3.cpp
    title: test/graph/max_flow.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/max_flow.test.cpp
    title: test/graph/max_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/max_flow.hpp\"\n// base: 9927a4\ntemplate<class\
    \ Cap> struct mf_graph {\n   public:\n   mf_graph() : _n(0) {}\n   mf_graph(int\
    \ n) : _n(n), g(n) {}\n\n   int add_edge(int from, int to, Cap cap) {\n      //\
    \ assert(0 <= from && from < _n);\n      // assert(0 <= to && to < _n);\n    \
    \  // assert(0 <= cap);\n      int m = size(pos);\n      pos.push_back({from,\
    \ size(g[from])});\n      int from_id = size(g[from]);\n      int to_id = size(g[to]);\n\
    \      if(from == to) to_id++;\n      g[from].push_back(_edge{to, to_id, cap});\n\
    \      g[to].push_back(_edge{from, from_id, 0});\n      return m;\n   }\n\n  \
    \ Cap flow(int s, int t, Cap flow_limit = numeric_limits<Cap>::max()) {\n    \
    \  // assert(0 <= s && s < _n);\n      // assert(0 <= t && t < _n);\n      //\
    \ assert(s != t);\n\n      vector<int> level(_n), iter(_n);\n      queue<int>\
    \ que;\n      auto bfs = [&]() {\n         fill(all(level), -1);\n         level[s]\
    \ = 0;\n         while(!que.empty()) que.pop();\n         que.push(s);\n     \
    \    while(!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for(auto e : g[v]) {\n               if(e.cap == 0 || level[e.to]\
    \ >= 0) continue;\n               level[e.to] = level[v] + 1;\n              \
    \ if(e.to == t) return;\n               que.push(e.to);\n            }\n     \
    \    }\n      };\n      auto dfs = [&](auto self, int v, Cap up) {\n         if(v\
    \ == s) return up;\n         Cap res = 0;\n         int level_v = level[v];\n\
    \         for(int& i = iter[v]; i < size(g[v]); i++) {\n            _edge& e =\
    \ g[v][i];\n            if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0)\
    \ continue;\n            Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
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
    \ m = size(pos);\n      // assert(0 <= i && i < m);\n      auto _e = g[pos[i].first][pos[i].second];\n\
    \      auto _re = g[_e.to][_e.rev];\n      return edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n   }  // ad4299\n\n   vector<edge> edges() {\n      int\
    \ m = size(pos);\n      vector<edge> result;\n      for(int i = 0; i < m; i++)\
    \ result.push_back(get_edge(i));\n      return result;\n   }  // 5948b8\n\n  \
    \ void change_edge(int i, Cap new_cap, Cap new_flow) {\n      int m = size(pos);\n\
    \      // assert(0 <= i && i < m);\n      // assert(0 <= new_flow && new_flow\
    \ <= new_cap);\n      auto& _e = g[pos[i].first][pos[i].second];\n      auto&\
    \ _re = g[_e.to][_e.rev];\n      _e.cap = new_cap - new_flow;\n      _re.cap =\
    \ new_flow;\n   }  // 558c35\n\n   private:\n   int _n;\n   struct _edge {\n \
    \     int to, rev;\n      Cap cap;\n   };\n   vector<pair<int, int>> pos;\n  \
    \ vector<vector<_edge>> g;\n};\n"
  code: "// base: 9927a4\ntemplate<class Cap> struct mf_graph {\n   public:\n   mf_graph()\
    \ : _n(0) {}\n   mf_graph(int n) : _n(n), g(n) {}\n\n   int add_edge(int from,\
    \ int to, Cap cap) {\n      // assert(0 <= from && from < _n);\n      // assert(0\
    \ <= to && to < _n);\n      // assert(0 <= cap);\n      int m = size(pos);\n \
    \     pos.push_back({from, size(g[from])});\n      int from_id = size(g[from]);\n\
    \      int to_id = size(g[to]);\n      if(from == to) to_id++;\n      g[from].push_back(_edge{to,\
    \ to_id, cap});\n      g[to].push_back(_edge{from, from_id, 0});\n      return\
    \ m;\n   }\n\n   Cap flow(int s, int t, Cap flow_limit = numeric_limits<Cap>::max())\
    \ {\n      // assert(0 <= s && s < _n);\n      // assert(0 <= t && t < _n);\n\
    \      // assert(s != t);\n\n      vector<int> level(_n), iter(_n);\n      queue<int>\
    \ que;\n      auto bfs = [&]() {\n         fill(all(level), -1);\n         level[s]\
    \ = 0;\n         while(!que.empty()) que.pop();\n         que.push(s);\n     \
    \    while(!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for(auto e : g[v]) {\n               if(e.cap == 0 || level[e.to]\
    \ >= 0) continue;\n               level[e.to] = level[v] + 1;\n              \
    \ if(e.to == t) return;\n               que.push(e.to);\n            }\n     \
    \    }\n      };\n      auto dfs = [&](auto self, int v, Cap up) {\n         if(v\
    \ == s) return up;\n         Cap res = 0;\n         int level_v = level[v];\n\
    \         for(int& i = iter[v]; i < size(g[v]); i++) {\n            _edge& e =\
    \ g[v][i];\n            if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0)\
    \ continue;\n            Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
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
    \ m = size(pos);\n      // assert(0 <= i && i < m);\n      auto _e = g[pos[i].first][pos[i].second];\n\
    \      auto _re = g[_e.to][_e.rev];\n      return edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n   }  // ad4299\n\n   vector<edge> edges() {\n      int\
    \ m = size(pos);\n      vector<edge> result;\n      for(int i = 0; i < m; i++)\
    \ result.push_back(get_edge(i));\n      return result;\n   }  // 5948b8\n\n  \
    \ void change_edge(int i, Cap new_cap, Cap new_flow) {\n      int m = size(pos);\n\
    \      // assert(0 <= i && i < m);\n      // assert(0 <= new_flow && new_flow\
    \ <= new_cap);\n      auto& _e = g[pos[i].first][pos[i].second];\n      auto&\
    \ _re = g[_e.to][_e.rev];\n      _e.cap = new_cap - new_flow;\n      _re.cap =\
    \ new_flow;\n   }  // 558c35\n\n   private:\n   int _n;\n   struct _edge {\n \
    \     int to, rev;\n      Cap cap;\n   };\n   vector<pair<int, int>> pos;\n  \
    \ vector<vector<_edge>> g;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/max_flow.hpp
  requiredBy: []
  timestamp: '2024-12-10 18:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/max_flow.test.cpp
  - test/graph/max_flow.test.3.cpp
  - test/graph/max_flow.test.2.cpp
documentation_of: src/graph/max_flow.hpp
layout: document
redirect_from:
- /library/src/graph/max_flow.hpp
- /library/src/graph/max_flow.hpp.html
title: src/graph/max_flow.hpp
---
