---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/rerooting.test.cpp
    title: test/graph/tree/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/tree/rerooting.hpp\"\n// base: 166a6d\ntemplate<class\
    \ M, bool calc_contribution = false> struct Rerooting {\n   using S = typename\
    \ M::S;\n   using C = typename M::C;\n   vector<S> dp, memo;\n   vector<vector<pair<int,\
    \ C>>> g;\n   map<ll, S> hash;\n   int N;\n\n   Rerooting(int n) : N(n), g(n)\
    \ {}\n\n   void add_edge(int f, int t, const C& c) {\n      g[f].emplace_back(t,\
    \ c);\n      g[t].emplace_back(f, c);\n   }\n\n   vector<S> build() {\n      memo.resize(N,\
    \ M::e());\n      dp.resize(N, M::e());\n      dfs(0, -1);\n      reroot(0, M::e());\n\
    \      return dp;\n   }\n\n   private:\n   void dfs(int cur, int pre = -1) {\n\
    \      bool is_leaf = true;\n      for(auto [to, c] : g[cur]) {\n         if(to\
    \ == pre) continue;\n         is_leaf = false;\n         dfs(to, cur);\n     \
    \    memo[cur] = M::merge(memo[cur], M::apply(memo[to], to, cur, c));\n      }\n\
    \      if(is_leaf) { memo[cur] = M::leaf(); }\n   }\n\n   void reroot(int cur,\
    \ const S val, int pre = -1) {\n      vector<S> ds;\n      ds.push_back(val);\n\
    \      if(calc_contribution) {\n         if(pre == -1) hash[cur * N + pre] = val;\n\
    \      }\n      for(auto [to, c] : g[cur]) {\n         if(to == pre) continue;\n\
    \         ds.push_back(M::apply(memo[to], to, cur, c));\n         if(calc_contribution)\
    \ { hash[cur * N + to] = ds.back(); }\n      }\n      int n = size(ds);\n    \
    \  vector<S> l(n + 1, M::e()), r(n + 1, M::e());\n      for(int i = 0; i < n;\
    \ i++) l[i + 1] = M::merge(l[i], ds[i]);\n      for(int i = n - 1; i >= 0; i--)\
    \ r[i] = M::merge(ds[i], r[i + 1]);\n      dp[cur] = r[0];\n      int ind = 1;\n\
    \      for(auto [to, c] : g[cur]) {\n         if(to == pre) continue;\n      \
    \   S sub = M::merge(l[ind], r[ind + 1]);\n         reroot(to, M::apply(sub, cur,\
    \ to, c), cur);\n         ind++;\n      }\n   }\n\n   public:\n   S get_contribution(int\
    \ p, int c) {\n      if(hash.count(p * N + c)) return hash[p * N + c];\n     \
    \ return M::e();\n   }  // e6000f\n};\n"
  code: "// base: 166a6d\ntemplate<class M, bool calc_contribution = false> struct\
    \ Rerooting {\n   using S = typename M::S;\n   using C = typename M::C;\n   vector<S>\
    \ dp, memo;\n   vector<vector<pair<int, C>>> g;\n   map<ll, S> hash;\n   int N;\n\
    \n   Rerooting(int n) : N(n), g(n) {}\n\n   void add_edge(int f, int t, const\
    \ C& c) {\n      g[f].emplace_back(t, c);\n      g[t].emplace_back(f, c);\n  \
    \ }\n\n   vector<S> build() {\n      memo.resize(N, M::e());\n      dp.resize(N,\
    \ M::e());\n      dfs(0, -1);\n      reroot(0, M::e());\n      return dp;\n  \
    \ }\n\n   private:\n   void dfs(int cur, int pre = -1) {\n      bool is_leaf =\
    \ true;\n      for(auto [to, c] : g[cur]) {\n         if(to == pre) continue;\n\
    \         is_leaf = false;\n         dfs(to, cur);\n         memo[cur] = M::merge(memo[cur],\
    \ M::apply(memo[to], to, cur, c));\n      }\n      if(is_leaf) { memo[cur] = M::leaf();\
    \ }\n   }\n\n   void reroot(int cur, const S val, int pre = -1) {\n      vector<S>\
    \ ds;\n      ds.push_back(val);\n      if(calc_contribution) {\n         if(pre\
    \ == -1) hash[cur * N + pre] = val;\n      }\n      for(auto [to, c] : g[cur])\
    \ {\n         if(to == pre) continue;\n         ds.push_back(M::apply(memo[to],\
    \ to, cur, c));\n         if(calc_contribution) { hash[cur * N + to] = ds.back();\
    \ }\n      }\n      int n = size(ds);\n      vector<S> l(n + 1, M::e()), r(n +\
    \ 1, M::e());\n      for(int i = 0; i < n; i++) l[i + 1] = M::merge(l[i], ds[i]);\n\
    \      for(int i = n - 1; i >= 0; i--) r[i] = M::merge(ds[i], r[i + 1]);\n   \
    \   dp[cur] = r[0];\n      int ind = 1;\n      for(auto [to, c] : g[cur]) {\n\
    \         if(to == pre) continue;\n         S sub = M::merge(l[ind], r[ind + 1]);\n\
    \         reroot(to, M::apply(sub, cur, to, c), cur);\n         ind++;\n     \
    \ }\n   }\n\n   public:\n   S get_contribution(int p, int c) {\n      if(hash.count(p\
    \ * N + c)) return hash[p * N + c];\n      return M::e();\n   }  // e6000f\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2024-12-12 16:16:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/rerooting.test.cpp
documentation_of: src/graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/src/graph/tree/rerooting.hpp
- /library/src/graph/tree/rerooting.hpp.html
title: src/graph/tree/rerooting.hpp
---
