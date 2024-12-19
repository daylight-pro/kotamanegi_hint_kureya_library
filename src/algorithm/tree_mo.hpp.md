---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/tree_mo.test.cpp
    title: test/algorithm/tree_mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/tree_mo.hpp\"\ntemplate<class T> struct MoTree_edge\
    \ {\n   int n;\n   vector<vector<pair<int, T>>> es;\n   vector<int> in;\n   vector<pair<int,\
    \ T>> vals;\n   Mo mo;\n   MoTree_edge(int _n) : n(_n), es(_n), mo(0, 0) {}\n\n\
    \   void add_edge(int u, int v, T w) {\n      es[u].emplace_back(v, w);\n    \
    \  es[v].emplace_back(u, w);\n   }\n\n   void build(int q) {\n      int tnow =\
    \ 0;\n      auto dfs = [&](auto dfs, int v, int f) -> void {\n         in[v] =\
    \ tnow++;\n         for(auto [u, w] : es[v]) {\n            if(u == f) continue;\n\
    \            vals.emplace_back(u, w);\n            dfs(dfs, u, v);\n         \
    \   vals.emplace_back(u, w);\n            tnow++;\n         }\n      };\n    \
    \  in.resize(n);\n      dfs(dfs, 0, -1);\n      mo = Mo(2 * n - 2, q);\n   }\n\
    \n   void insert(int u, int v) {\n      u = in[u];\n      v = in[v];\n      if(u\
    \ > v) swap(u, v);\n      mo.insert(u, v);\n   }\n\n   void run(const auto& add,\
    \ const auto& del, const auto& rem) {\n      vector<bool> contain(n, false);\n\
    \      auto change = [&](int i) {\n         int id = vals[i].first;\n        \
    \ if(contain[id]) {\n            del(vals[i].second);\n            contain[id]\
    \ = false;\n         } else {\n            add(vals[i].second);\n            contain[id]\
    \ = true;\n         }\n      };\n      mo.run(change, change, change, change,\
    \ rem);\n   }\n};  // b505c7\n\ntemplate<class T> struct MoTree_vertex {\n   int\
    \ n;\n   vector<vector<int>> es;\n   vector<T> b;\n   vector<int> in, lcas;\n\
    \   vector<pair<int, T>> vals;\n   Mo mo;\n   MoTree_vertex(int _n, vector<T>\
    \ _b) : n(_n), b(_b), mo(0, 0) { es.resize(n); }\n\n   void add_edge(int u, int\
    \ v) {\n      es[u].push_back(v);\n      es[v].push_back(u);\n   }\n\n   void\
    \ build(int q) {\n      vals.reserve(2 * n - 2);\n      lcas.reserve(q);\n   \
    \   int tnow = 0;\n      auto dfs = [&](auto dfs, int v, int f) -> void {\n  \
    \       in[v] = tnow++;\n         for(auto u : es[v]) {\n            if(u == f)\
    \ continue;\n            vals.emplace_back(u, b[u]);\n            dfs(dfs, u,\
    \ v);\n            vals.emplace_back(u, b[u]);\n            tnow++;\n        \
    \ }\n      };\n      in.resize(n);\n      dfs(dfs, 0, -1);\n      mo = Mo(2 *\
    \ n - 2, q);\n   }\n\n   void insert(int u, int v, int lca) {\n      u = in[u],\
    \ v = in[v];\n      if(u > v) swap(u, v);\n      mo.insert(u, v);\n      lcas.push_back(lca);\n\
    \   }\n\n   void run(const auto& add, const auto& del, const auto& rem) {\n  \
    \    vector<bool> contain(n, false);\n      auto change = [&](int i) {\n     \
    \    int id = vals[i].first;\n         if(contain[id]) {\n            del(vals[i].second);\n\
    \            contain[id] = false;\n         } else {\n            add(vals[i].second);\n\
    \            contain[id] = true;\n         }\n      };\n      auto rem_add_lca\
    \ = [&](int i) {\n         add(b[lcas[i]]);\n         rem(i);\n         del(b[lcas[i]]);\n\
    \      };\n      mo.run(change, change, change, change, rem_add_lca);\n   }\n\
    };  // da9ab0\n"
  code: "template<class T> struct MoTree_edge {\n   int n;\n   vector<vector<pair<int,\
    \ T>>> es;\n   vector<int> in;\n   vector<pair<int, T>> vals;\n   Mo mo;\n   MoTree_edge(int\
    \ _n) : n(_n), es(_n), mo(0, 0) {}\n\n   void add_edge(int u, int v, T w) {\n\
    \      es[u].emplace_back(v, w);\n      es[v].emplace_back(u, w);\n   }\n\n  \
    \ void build(int q) {\n      int tnow = 0;\n      auto dfs = [&](auto dfs, int\
    \ v, int f) -> void {\n         in[v] = tnow++;\n         for(auto [u, w] : es[v])\
    \ {\n            if(u == f) continue;\n            vals.emplace_back(u, w);\n\
    \            dfs(dfs, u, v);\n            vals.emplace_back(u, w);\n         \
    \   tnow++;\n         }\n      };\n      in.resize(n);\n      dfs(dfs, 0, -1);\n\
    \      mo = Mo(2 * n - 2, q);\n   }\n\n   void insert(int u, int v) {\n      u\
    \ = in[u];\n      v = in[v];\n      if(u > v) swap(u, v);\n      mo.insert(u,\
    \ v);\n   }\n\n   void run(const auto& add, const auto& del, const auto& rem)\
    \ {\n      vector<bool> contain(n, false);\n      auto change = [&](int i) {\n\
    \         int id = vals[i].first;\n         if(contain[id]) {\n            del(vals[i].second);\n\
    \            contain[id] = false;\n         } else {\n            add(vals[i].second);\n\
    \            contain[id] = true;\n         }\n      };\n      mo.run(change, change,\
    \ change, change, rem);\n   }\n};  // b505c7\n\ntemplate<class T> struct MoTree_vertex\
    \ {\n   int n;\n   vector<vector<int>> es;\n   vector<T> b;\n   vector<int> in,\
    \ lcas;\n   vector<pair<int, T>> vals;\n   Mo mo;\n   MoTree_vertex(int _n, vector<T>\
    \ _b) : n(_n), b(_b), mo(0, 0) { es.resize(n); }\n\n   void add_edge(int u, int\
    \ v) {\n      es[u].push_back(v);\n      es[v].push_back(u);\n   }\n\n   void\
    \ build(int q) {\n      vals.reserve(2 * n - 2);\n      lcas.reserve(q);\n   \
    \   int tnow = 0;\n      auto dfs = [&](auto dfs, int v, int f) -> void {\n  \
    \       in[v] = tnow++;\n         for(auto u : es[v]) {\n            if(u == f)\
    \ continue;\n            vals.emplace_back(u, b[u]);\n            dfs(dfs, u,\
    \ v);\n            vals.emplace_back(u, b[u]);\n            tnow++;\n        \
    \ }\n      };\n      in.resize(n);\n      dfs(dfs, 0, -1);\n      mo = Mo(2 *\
    \ n - 2, q);\n   }\n\n   void insert(int u, int v, int lca) {\n      u = in[u],\
    \ v = in[v];\n      if(u > v) swap(u, v);\n      mo.insert(u, v);\n      lcas.push_back(lca);\n\
    \   }\n\n   void run(const auto& add, const auto& del, const auto& rem) {\n  \
    \    vector<bool> contain(n, false);\n      auto change = [&](int i) {\n     \
    \    int id = vals[i].first;\n         if(contain[id]) {\n            del(vals[i].second);\n\
    \            contain[id] = false;\n         } else {\n            add(vals[i].second);\n\
    \            contain[id] = true;\n         }\n      };\n      auto rem_add_lca\
    \ = [&](int i) {\n         add(b[lcas[i]]);\n         rem(i);\n         del(b[lcas[i]]);\n\
    \      };\n      mo.run(change, change, change, change, rem_add_lca);\n   }\n\
    };  // da9ab0"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/tree_mo.hpp
  requiredBy: []
  timestamp: '2024-12-19 17:08:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/tree_mo.test.cpp
documentation_of: src/algorithm/tree_mo.hpp
layout: document
redirect_from:
- /library/src/algorithm/tree_mo.hpp
- /library/src/algorithm/tree_mo.hpp.html
title: src/algorithm/tree_mo.hpp
---
