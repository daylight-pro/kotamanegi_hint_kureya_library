---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/dominator_tree.test.cpp
    title: test/graph/tree/dominator_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/tree/dominator_tree.hpp\"\nstruct DominatorTree\
    \ {\n   public:\n   DominatorTree(vector<vector<int>>& g_, int root = 0) : g(g_)\
    \ {\n      const int N = (int)g.size();\n      rg = vector<vector<int>>(N);\n\
    \      par.assign(N, 0);\n      idom.assign(N, -1);\n      semi.assign(N, -1);\n\
    \      ord.reserve(N);\n      UnionFind uf(semi);\n\n      dfs(root);\n      for(int\
    \ i = 0; i < N; i++) {\n         for(auto& to : g[i]) {\n            if(~semi[i])\
    \ rg[to].emplace_back(i);\n         }\n      }\n\n      vector<vector<int>> bucket(N);\n\
    \      vector<int> U(N);\n      for(int i = (int)ord.size() - 1; i >= 0; i--)\
    \ {\n         int x = ord[i];\n         for(int v : rg[x]) {\n            v =\
    \ uf.eval(v);\n            if(semi[x] > semi[v]) semi[x] = semi[v];\n        \
    \ }\n         bucket[ord[semi[x]]].emplace_back(x);\n         for(int v : bucket[par[x]])\
    \ U[v] = uf.eval(v);\n         bucket[par[x]].clear();\n         uf.link(par[x],\
    \ x);\n      }\n      for(int i = 1; i < (int)ord.size(); i++) {\n         int\
    \ x = ord[i], u = U[x];\n         idom[x] = semi[x] == semi[u] ? semi[x] : idom[u];\n\
    \      }\n      for(int i = 1; i < (int)ord.size(); i++) {\n         int x = ord[i];\n\
    \         idom[x] = ord[idom[x]];\n      }\n      idom[root] = root;\n   }\n\n\
    \   int operator[](const int& k) const { return idom[k]; }\n\n   private:\n  \
    \ vector<vector<int>> g, rg;\n\n   struct UnionFind {\n      const vector<int>&\
    \ semi;\n      vector<int> par, m;\n\n      explicit UnionFind(const vector<int>&\
    \ semi) : semi(semi), par(semi.size()), m(semi.size()) {\n         iota(begin(par),\
    \ end(par), 0);\n         iota(begin(m), end(m), 0);\n      }\n\n      int find(int\
    \ v) {\n         if(par[v] == v) return v;\n         int r = find(par[v]);\n \
    \        if(semi[m[v]] > semi[m[par[v]]]) m[v] = m[par[v]];\n         return par[v]\
    \ = r;\n      }\n\n      int eval(int v) {\n         find(v);\n         return\
    \ m[v];\n      }\n\n      void link(int p, int c) { par[c] = p; }\n   };\n\n \
    \  vector<int> ord, par;\n   vector<int> idom, semi;\n\n   void dfs(int idx) {\n\
    \      semi[idx] = (int)ord.size();\n      ord.emplace_back(idx);\n      for(auto&\
    \ to : g[idx]) {\n         if(~semi[to]) continue;\n         dfs(to);\n      \
    \   par[to] = idx;\n      }\n   }\n};\n"
  code: "struct DominatorTree {\n   public:\n   DominatorTree(vector<vector<int>>&\
    \ g_, int root = 0) : g(g_) {\n      const int N = (int)g.size();\n      rg =\
    \ vector<vector<int>>(N);\n      par.assign(N, 0);\n      idom.assign(N, -1);\n\
    \      semi.assign(N, -1);\n      ord.reserve(N);\n      UnionFind uf(semi);\n\
    \n      dfs(root);\n      for(int i = 0; i < N; i++) {\n         for(auto& to\
    \ : g[i]) {\n            if(~semi[i]) rg[to].emplace_back(i);\n         }\n  \
    \    }\n\n      vector<vector<int>> bucket(N);\n      vector<int> U(N);\n    \
    \  for(int i = (int)ord.size() - 1; i >= 0; i--) {\n         int x = ord[i];\n\
    \         for(int v : rg[x]) {\n            v = uf.eval(v);\n            if(semi[x]\
    \ > semi[v]) semi[x] = semi[v];\n         }\n         bucket[ord[semi[x]]].emplace_back(x);\n\
    \         for(int v : bucket[par[x]]) U[v] = uf.eval(v);\n         bucket[par[x]].clear();\n\
    \         uf.link(par[x], x);\n      }\n      for(int i = 1; i < (int)ord.size();\
    \ i++) {\n         int x = ord[i], u = U[x];\n         idom[x] = semi[x] == semi[u]\
    \ ? semi[x] : idom[u];\n      }\n      for(int i = 1; i < (int)ord.size(); i++)\
    \ {\n         int x = ord[i];\n         idom[x] = ord[idom[x]];\n      }\n   \
    \   idom[root] = root;\n   }\n\n   int operator[](const int& k) const { return\
    \ idom[k]; }\n\n   private:\n   vector<vector<int>> g, rg;\n\n   struct UnionFind\
    \ {\n      const vector<int>& semi;\n      vector<int> par, m;\n\n      explicit\
    \ UnionFind(const vector<int>& semi) : semi(semi), par(semi.size()), m(semi.size())\
    \ {\n         iota(begin(par), end(par), 0);\n         iota(begin(m), end(m),\
    \ 0);\n      }\n\n      int find(int v) {\n         if(par[v] == v) return v;\n\
    \         int r = find(par[v]);\n         if(semi[m[v]] > semi[m[par[v]]]) m[v]\
    \ = m[par[v]];\n         return par[v] = r;\n      }\n\n      int eval(int v)\
    \ {\n         find(v);\n         return m[v];\n      }\n\n      void link(int\
    \ p, int c) { par[c] = p; }\n   };\n\n   vector<int> ord, par;\n   vector<int>\
    \ idom, semi;\n\n   void dfs(int idx) {\n      semi[idx] = (int)ord.size();\n\
    \      ord.emplace_back(idx);\n      for(auto& to : g[idx]) {\n         if(~semi[to])\
    \ continue;\n         dfs(to);\n         par[to] = idx;\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/dominator_tree.hpp
  requiredBy: []
  timestamp: '2025-02-25 03:49:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/dominator_tree.test.cpp
documentation_of: src/graph/tree/dominator_tree.hpp
layout: document
redirect_from:
- /library/src/graph/tree/dominator_tree.hpp
- /library/src/graph/tree/dominator_tree.hpp.html
title: src/graph/tree/dominator_tree.hpp
---
