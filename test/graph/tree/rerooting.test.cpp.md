---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/rerooting.hpp
    title: src/graph/tree/rerooting.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: Modint
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/graph/tree/rerooting.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\nconst ll mod = 998244353;\n\
    struct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x +=\
    \ mod;\n   }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend\
    \ mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a,\
    \ mm b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a *\
    \ b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\
    \u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm&\
    \ a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) {\
    \ return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a =\
    \ a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv();\
    \ }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n   \
    \   mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n     \
    \    a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\n#line 1 \"\
    src/graph/tree/rerooting.hpp\"\n// base: 166a6d\ntemplate<class M, bool calc_contribution\
    \ = false> struct Rerooting {\n   using S = typename M::S;\n   using C = typename\
    \ M::C;\n   vector<S> dp, memo;\n   vector<vector<pair<int, C>>> g;\n   map<ll,\
    \ S> hash;\n   int N;\n\n   Rerooting(int n) : N(n), g(n) {}\n\n   void add_edge(int\
    \ f, int t, const C& c) {\n      g[f].emplace_back(t, c);\n      g[t].emplace_back(f,\
    \ c);\n   }\n\n   vector<S> build() {\n      memo.resize(N, M::e());\n      dp.resize(N,\
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
    \ * N + c)) return hash[p * N + c];\n      return M::e();\n   }  // e6000f\n};\n\
    #line 6 \"test/graph/tree/rerooting.test.cpp\"\n\nvector<int> A;\nstruct M {\n\
    \   using S = pair<mm, int>;\n   using C = pair<mm, mm>;\n   static S merge(S\
    \ a, S b) { return {a.first + b.first, a.second + b.second}; }\n   static S apply(S\
    \ a, int from, int to, C b) {\n      return {(a.first + A[from]) * b.first + b.second\
    \ * (a.second + 1), a.second + 1};\n   }\n   static S e() { return {0, 0}; }\n\
    \   static S leaf() { return {0, 0}; }\n};\n\nint main() {\n   cin.tie(0)->sync_with_stdio(false);\n\
    \   int N;\n   cin >> N;\n   A.resize(N);\n   for(auto& a : A) cin >> a;\n   Rerooting<M>\
    \ reroot(N);\n   for(int i = 0; i < N - 1; i++) {\n      int u, v, b, c;\n   \
    \   cin >> u >> v >> b >> c;\n      reroot.add_edge(u, v, {b, c});\n   }\n   auto\
    \ v = reroot.build();\n   auto ans = vector<mm>(N);\n   for(int i = 0; i < N;\
    \ i++) ans[i] = v[i].first + A[i];\n   for(int i = 0; i < N; i++) cout << ans[i].x\
    \ << \" \\n\"[i == N - 1];\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/graph/tree/rerooting.hpp\"\n\nvector<int> A;\nstruct M {\n   using S =\
    \ pair<mm, int>;\n   using C = pair<mm, mm>;\n   static S merge(S a, S b) { return\
    \ {a.first + b.first, a.second + b.second}; }\n   static S apply(S a, int from,\
    \ int to, C b) {\n      return {(a.first + A[from]) * b.first + b.second * (a.second\
    \ + 1), a.second + 1};\n   }\n   static S e() { return {0, 0}; }\n   static S\
    \ leaf() { return {0, 0}; }\n};\n\nint main() {\n   cin.tie(0)->sync_with_stdio(false);\n\
    \   int N;\n   cin >> N;\n   A.resize(N);\n   for(auto& a : A) cin >> a;\n   Rerooting<M>\
    \ reroot(N);\n   for(int i = 0; i < N - 1; i++) {\n      int u, v, b, c;\n   \
    \   cin >> u >> v >> b >> c;\n      reroot.add_edge(u, v, {b, c});\n   }\n   auto\
    \ v = reroot.build();\n   auto ans = vector<mm>(N);\n   for(int i = 0; i < N;\
    \ i++) ans[i] = v[i].first + A[i];\n   for(int i = 0; i < N; i++) cout << ans[i].x\
    \ << \" \\n\"[i == N - 1];\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/graph/tree/rerooting.hpp
  isVerificationFile: true
  path: test/graph/tree/rerooting.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 16:16:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/rerooting.test.cpp
- /verify/test/graph/tree/rerooting.test.cpp.html
title: test/graph/tree/rerooting.test.cpp
---
