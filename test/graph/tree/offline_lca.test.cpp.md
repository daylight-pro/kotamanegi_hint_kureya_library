---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dsu.hpp
    title: src/data-structure/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/offline_lca.hpp
    title: src/graph/tree/offline_lca.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/graph/tree/offline_lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#line 1 \"test/template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/dsu.hpp\"\n// base: d569f4\n\
    struct dsu {\n   private:\n   int _n;\n   vector<int> p;\n\n   public:\n   dsu()\
    \ : _n(0) {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\n   int merge(int\
    \ a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0 <= b && b\
    \ < _n);\n      int x = leader(a), y = leader(b);\n      if(x == y) return x;\n\
    \      if(-p[x] < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y] = x;\n \
    \     return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0 <= a\
    \ && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a) == leader(b);\n\
    \   }\n\n   int leader(int a) {\n      // assert(0 <= a && a < _n);\n      if(p[a]\
    \ < 0) return a;\n      int x = a;\n      while(p[x] >= 0) x = p[x];\n      while(p[a]\
    \ >= 0) {\n         int t = p[a];\n         p[a] = x;\n         a = t;\n     \
    \ }\n      return x;\n   }\n\n   int size(int a) {\n      // assert(0 <= a &&\
    \ a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\n   vector<vector<int>>\
    \ groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n      for(int\
    \ i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n         group_size[leader_buf[i]]++;\n\
    \      }\n      vector<vector<int>> result(_n);\n      for(int i = 0; i < _n;\
    \ i++) result[i].reserve(group_size[i]);\n      for(int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n\
    \      result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>&\
    \ v) { return v.empty(); }),\n                   result.end());\n      return\
    \ result;\n   }  // bf3a1e\n};\n#line 1 \"src/graph/tree/offline_lca.hpp\"\nvector<int>\
    \ offline_lca(const vector<vector<int>>& g, const vector<pair<int, int>>& qs,\
    \ int root = 0) {\n   int N = size(g);\n   int Q = size(qs);\n   dsu d(N);\n \
    \  vector<int> mark(N), ptr(N), ans(Q, -1);\n   stack<int> st;\n   st.push(root);\n\
    \   for(auto& [l, r] : qs) {\n      mark[l]++;\n      mark[r]++;\n   }\n\n   vector<vector<pair<int,\
    \ int>>> q(N);\n   for(int i = 0; i < N; i++) {\n      q[i].reserve(mark[i]);\n\
    \      mark[i] = -1;\n      ptr[i] = size(g[i]);\n   }\n   for(int i = 0; i <\
    \ Q; i++) {\n      q[qs[i].first].emplace_back(qs[i].second, i);\n      q[qs[i].second].emplace_back(qs[i].first,\
    \ i);\n   }\n   auto run = [&](int u) -> bool {\n      while(ptr[u]) {\n     \
    \    int v = g[u][--ptr[u]];\n         if(mark[v] == -1) {\n            st.push(v);\n\
    \            return true;\n         }\n      }\n      return false;\n   };\n\n\
    \   while(!st.empty()) {\n      int u = st.top();\n      if(mark[u] == -1) mark[u]\
    \ = u;\n      else {\n         d.merge(u, g[u][ptr[u]]);\n         mark[d.leader(u)]\
    \ = u;\n      }\n      if(!run(u)) {\n         for(auto& [v, i] : q[u]) {\n  \
    \          if(~mark[v] && ans[i] == -1) { ans[i] = mark[d.leader(v)]; }\n    \
    \     }\n         st.pop();\n      }\n   }\n   return ans;\n};\n#line 5 \"test/graph/tree/offline_lca.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   vector<vector<int>> g(N);\n   for(int i = 1; i < N; i++) {\n   \
    \   int p;\n      cin >> p;\n      g[p].push_back(i);\n      g[i].push_back(p);\n\
    \   }\n   vector<pair<int, int>> qs(Q);\n   for(auto& [l, r] : qs) { cin >> l\
    \ >> r; }\n   auto ans = offline_lca(g, qs);\n   for(auto x : ans) { cout << x\
    \ << '\\n'; }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"test/template.hpp\"\
    \n#include \"src/data-structure/dsu.hpp\"\n#include \"src/graph/tree/offline_lca.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   vector<vector<int>> g(N);\n   for(int i = 1; i < N; i++) {\n   \
    \   int p;\n      cin >> p;\n      g[p].push_back(i);\n      g[i].push_back(p);\n\
    \   }\n   vector<pair<int, int>> qs(Q);\n   for(auto& [l, r] : qs) { cin >> l\
    \ >> r; }\n   auto ans = offline_lca(g, qs);\n   for(auto x : ans) { cout << x\
    \ << '\\n'; }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/dsu.hpp
  - src/graph/tree/offline_lca.hpp
  isVerificationFile: true
  path: test/graph/tree/offline_lca.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 23:28:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/offline_lca.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/offline_lca.test.cpp
- /verify/test/graph/tree/offline_lca.test.cpp.html
title: test/graph/tree/offline_lca.test.cpp
---
