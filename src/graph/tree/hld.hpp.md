---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.2.cpp
    title: test/graph/tree/hld.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.3.cpp
    title: test/graph/tree/hld.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.cpp
    title: test/graph/tree/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/tree/hld.hpp\"\nclass HLDcomposition {\n   private:\n\
    \   int V;\n   vector<vector<int>> G;\n   vector<int> stsize, parent, pathtop,\
    \ in, out;\n   int root;\n   void build_stsize(int u, int p) {\n      stsize[u]\
    \ = 1, parent[u] = p;\n      for(auto&& v : G[u]) {\n         if(v == p) {\n \
    \           if(v == G[u].back()) break;\n            else swap(v, G[u].back());\n\
    \         }\n         build_stsize(v, u);\n         stsize[u] += stsize[v];\n\
    \         if(stsize[v] > stsize[G[u][0]]) swap(v, G[u][0]);\n      }\n   }\n\n\
    \   void build_path(int u, int p, int& tm) {\n      in[u] = tm++;\n      for(auto\
    \ v : G[u]) {\n         if(v == p) continue;\n         pathtop[v] = (v == G[u][0]\
    \ ? pathtop[u] : v);\n         build_path(v, u, tm);\n      }\n      out[u] =\
    \ tm;\n   }\n\n   public:\n   void add_edge(int u, int v) {\n      G[u].push_back(v);\n\
    \      G[v].push_back(u);\n   }\n\n   void build(int _root = 0) {\n      root\
    \ = _root;\n      int tm = 0;\n      build_stsize(root, -1);\n      pathtop[root]\
    \ = root;\n      build_path(root, -1, tm);\n   }\n\n   inline int index(int a)\
    \ { return in[a]; }\n\n   int lca(int a, int b) {\n      int pa = pathtop[a],\
    \ pb = pathtop[b];\n      while(pa != pb) {\n         if(in[pa] > in[pb]) {\n\
    \            a = parent[pa], pa = pathtop[a];\n         } else {\n           \
    \ b = parent[pb], pb = pathtop[b];\n         }\n      }\n      if(in[a] > in[b])\
    \ swap(a, b);\n      return a;\n   }\n\n   pair<int, int> subtree_query(int a)\
    \ { return {in[a], out[a]}; }\n\n   vector<tuple<int, int, bool>> path_query(int\
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
    \ -1), in(V, -1), out(V, -1) {}\n};\n"
  code: "class HLDcomposition {\n   private:\n   int V;\n   vector<vector<int>> G;\n\
    \   vector<int> stsize, parent, pathtop, in, out;\n   int root;\n   void build_stsize(int\
    \ u, int p) {\n      stsize[u] = 1, parent[u] = p;\n      for(auto&& v : G[u])\
    \ {\n         if(v == p) {\n            if(v == G[u].back()) break;\n        \
    \    else swap(v, G[u].back());\n         }\n         build_stsize(v, u);\n  \
    \       stsize[u] += stsize[v];\n         if(stsize[v] > stsize[G[u][0]]) swap(v,\
    \ G[u][0]);\n      }\n   }\n\n   void build_path(int u, int p, int& tm) {\n  \
    \    in[u] = tm++;\n      for(auto v : G[u]) {\n         if(v == p) continue;\n\
    \         pathtop[v] = (v == G[u][0] ? pathtop[u] : v);\n         build_path(v,\
    \ u, tm);\n      }\n      out[u] = tm;\n   }\n\n   public:\n   void add_edge(int\
    \ u, int v) {\n      G[u].push_back(v);\n      G[v].push_back(u);\n   }\n\n  \
    \ void build(int _root = 0) {\n      root = _root;\n      int tm = 0;\n      build_stsize(root,\
    \ -1);\n      pathtop[root] = root;\n      build_path(root, -1, tm);\n   }\n\n\
    \   inline int index(int a) { return in[a]; }\n\n   int lca(int a, int b) {\n\
    \      int pa = pathtop[a], pb = pathtop[b];\n      while(pa != pb) {\n      \
    \   if(in[pa] > in[pb]) {\n            a = parent[pa], pa = pathtop[a];\n    \
    \     } else {\n            b = parent[pb], pb = pathtop[b];\n         }\n   \
    \   }\n      if(in[a] > in[b]) swap(a, b);\n      return a;\n   }\n\n   pair<int,\
    \ int> subtree_query(int a) { return {in[a], out[a]}; }\n\n   vector<tuple<int,\
    \ int, bool>> path_query(int from, int to) {\n      int pf = pathtop[from], pt\
    \ = pathtop[to];\n      using T = tuple<int, int, bool>;\n      deque<T> front,\
    \ back;\n      while(pf != pt) {\n         if(in[pf] > in[pt]) {\n           \
    \ front.push_back({in[pf], in[from] + 1, true});\n            from = parent[pf],\
    \ pf = pathtop[from];\n         } else {\n            back.push_front({in[pt],\
    \ in[to] + 1, false});\n            to = parent[pt], pt = pathtop[to];\n     \
    \    }\n      }\n      if(in[from] > in[to]) front.push_back({in[to], in[from]\
    \ + 1, true});\n      else front.push_back({in[from], in[to] + 1, false});\n \
    \     vector<T> ret;\n      while(!front.empty()) {\n         ret.push_back(front.front());\n\
    \         front.pop_front();\n      }\n      while(!back.empty()) {\n        \
    \ ret.push_back(back.front());\n         back.pop_front();\n      }\n      return\
    \ ret;\n   }\n\n   HLDcomposition(int node_size)\n       : V(node_size), G(V),\
    \ stsize(V, 0), parent(V, -1), pathtop(V, -1), in(V, -1), out(V, -1) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/hld.hpp
  requiredBy: []
  timestamp: '2024-12-07 04:40:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/hld.test.3.cpp
  - test/graph/tree/hld.test.cpp
  - test/graph/tree/hld.test.2.cpp
documentation_of: src/graph/tree/hld.hpp
layout: document
redirect_from:
- /library/src/graph/tree/hld.hpp
- /library/src/graph/tree/hld.hpp.html
title: src/graph/tree/hld.hpp
---
