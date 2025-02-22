---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/dominator_tree.hpp
    title: src/graph/tree/dominator_tree.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://ei1333.github.io/library/graph/others/dominator-tree.hpp.html
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://www.acmicpc.net/problem/20174
  bundledCode: "#line 1 \"test/graph/tree/dominator_tree.test.cpp\"\n// AC\u78BA\u8A8D\
    \u6E08\u307F https://www.acmicpc.net/problem/20174\n// \u5C11\u3057\u6539\u5909\
    \u3057\u305F https://ei1333.github.io/library/graph/others/dominator-tree.hpp.html\n\
    /*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nstruct DominatorTree {\npublic:\n   DominatorTree(vector<vector<int>>\
    \ &g_, int root = 0) : g(g_) {\n      const int N = (int)g.size();\n      rg =\
    \ vector<vector<int>>(N);\n      par.assign(N, 0);\n      idom.assign(N, -1);\n\
    \      semi.assign(N, -1);\n      ord.reserve(N);\n      UnionFind uf(semi);\n\
    \      \n      dfs(root);\n      for (int i = 0; i < N; i++) {\n         for (auto\
    \ &to : g[i]) {\n         if (~semi[i]) rg[to].emplace_back(i);\n         }\n\
    \      }\n\n      vector<vector<int> > bucket(N);\n      vector<int> U(N);\n \
    \     for (int i = (int)ord.size() - 1; i >= 0; i--) {\n         int x = ord[i];\n\
    \         for (int v : rg[x]) {\n         v = uf.eval(v);\n         if (semi[x]\
    \ > semi[v]) semi[x] = semi[v];\n         }\n         bucket[ord[semi[x]]].emplace_back(x);\n\
    \         for (int v : bucket[par[x]]) U[v] = uf.eval(v);\n         bucket[par[x]].clear();\n\
    \         uf.link(par[x], x);\n      }\n      for (int i = 1; i < (int)ord.size();\
    \ i++) {\n         int x = ord[i], u = U[x];\n         idom[x] = semi[x] == semi[u]\
    \ ? semi[x] : idom[u];\n      }\n      for (int i = 1; i < (int)ord.size(); i++)\
    \ {\n         int x = ord[i];\n         idom[x] = ord[idom[x]];\n      }\n   \
    \   idom[root] = root;\n   }\n\n   int operator[](const int &k) const { return\
    \ idom[k]; }\n\nprivate:\n   vector<vector<int>> g, rg;\n\n   struct UnionFind\
    \ {\n      const vector<int> &semi;\n      vector<int> par, m;\n\n      explicit\
    \ UnionFind(const vector<int> &semi)\n         : semi(semi), par(semi.size()),\
    \ m(semi.size()) {\n         iota(begin(par), end(par), 0);\n         iota(begin(m),\
    \ end(m), 0);\n      }\n\n      int find(int v) {\n         if (par[v] == v) return\
    \ v;\n         int r = find(par[v]);\n         if (semi[m[v]] > semi[m[par[v]]])\
    \ m[v] = m[par[v]];\n         return par[v] = r;\n      }\n\n      int eval(int\
    \ v) {\n         find(v);\n         return m[v];\n      }\n\n      void link(int\
    \ p, int c) { par[c] = p; }\n   };\n\n   vector<int> ord, par;\n   vector<int>\
    \ idom, semi;\n\n   void dfs(int idx) {\n      semi[idx] = (int)ord.size();\n\
    \      ord.emplace_back(idx);\n      for (auto &to : g[idx]) {\n         if (~semi[to])\
    \ continue;\n         dfs(to);\n         par[to] = idx;\n      }\n   }\n};\n\n\
    int main() {\n   int n, m, k;\n   cin >> n >> m >> k;\n   vector<vector<int>>\
    \ v(n + 1);\n   for(int i = 1; i <= m; i ++) {\n      v[0].push_back(i);\n   }\n\
    \   for(int i = 0; i < k; i ++) {\n      int x, y; cin >> x >> y;\n      if(x\
    \ != y) v[x].push_back(y);\n   }\n   DominatorTree g(v, 0);\n   int cnt = 0;\n\
    \   for(int i = 1; i <= n; i ++) if(g[i] == 0) cnt ++;\n   cout << cnt << endl;\n\
    \   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/tree/dominator_tree.hpp\"\
    \n\nstruct DominatorTree {\npublic:\n   DominatorTree(vector<vector<int>> &g_,\
    \ int root = 0) : g(g_) {\n      const int N = (int)g.size();\n      rg = vector<vector<int>>(N);\n\
    \      par.assign(N, 0);\n      idom.assign(N, -1);\n      semi.assign(N, -1);\n\
    \      ord.reserve(N);\n      UnionFind uf(semi);\n      \n      dfs(root);\n\
    \      for (int i = 0; i < N; i++) {\n         for (auto &to : g[i]) {\n     \
    \    if (~semi[i]) rg[to].emplace_back(i);\n         }\n      }\n\n      vector<vector<int>\
    \ > bucket(N);\n      vector<int> U(N);\n      for (int i = (int)ord.size() -\
    \ 1; i >= 0; i--) {\n         int x = ord[i];\n         for (int v : rg[x]) {\n\
    \         v = uf.eval(v);\n         if (semi[x] > semi[v]) semi[x] = semi[v];\n\
    \         }\n         bucket[ord[semi[x]]].emplace_back(x);\n         for (int\
    \ v : bucket[par[x]]) U[v] = uf.eval(v);\n         bucket[par[x]].clear();\n \
    \        uf.link(par[x], x);\n      }\n      for (int i = 1; i < (int)ord.size();\
    \ i++) {\n         int x = ord[i], u = U[x];\n         idom[x] = semi[x] == semi[u]\
    \ ? semi[x] : idom[u];\n      }\n      for (int i = 1; i < (int)ord.size(); i++)\
    \ {\n         int x = ord[i];\n         idom[x] = ord[idom[x]];\n      }\n   \
    \   idom[root] = root;\n   }\n\n   int operator[](const int &k) const { return\
    \ idom[k]; }\n\nprivate:\n   vector<vector<int>> g, rg;\n\n   struct UnionFind\
    \ {\n      const vector<int> &semi;\n      vector<int> par, m;\n\n      explicit\
    \ UnionFind(const vector<int> &semi)\n         : semi(semi), par(semi.size()),\
    \ m(semi.size()) {\n         iota(begin(par), end(par), 0);\n         iota(begin(m),\
    \ end(m), 0);\n      }\n\n      int find(int v) {\n         if (par[v] == v) return\
    \ v;\n         int r = find(par[v]);\n         if (semi[m[v]] > semi[m[par[v]]])\
    \ m[v] = m[par[v]];\n         return par[v] = r;\n      }\n\n      int eval(int\
    \ v) {\n         find(v);\n         return m[v];\n      }\n\n      void link(int\
    \ p, int c) { par[c] = p; }\n   };\n\n   vector<int> ord, par;\n   vector<int>\
    \ idom, semi;\n\n   void dfs(int idx) {\n      semi[idx] = (int)ord.size();\n\
    \      ord.emplace_back(idx);\n      for (auto &to : g[idx]) {\n         if (~semi[to])\
    \ continue;\n         dfs(to);\n         par[to] = idx;\n      }\n   }\n};\n#line\
    \ 120 \"test/graph/tree/dominator_tree.test.cpp\"\nint main() { puts(\"Hello World\"\
    ); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://www.acmicpc.net/problem/20174\n// \u5C11\
    \u3057\u6539\u5909\u3057\u305F https://ei1333.github.io/library/graph/others/dominator-tree.hpp.html\n\
    /*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nstruct DominatorTree {\npublic:\n   DominatorTree(vector<vector<int>>\
    \ &g_, int root = 0) : g(g_) {\n      const int N = (int)g.size();\n      rg =\
    \ vector<vector<int>>(N);\n      par.assign(N, 0);\n      idom.assign(N, -1);\n\
    \      semi.assign(N, -1);\n      ord.reserve(N);\n      UnionFind uf(semi);\n\
    \      \n      dfs(root);\n      for (int i = 0; i < N; i++) {\n         for (auto\
    \ &to : g[i]) {\n         if (~semi[i]) rg[to].emplace_back(i);\n         }\n\
    \      }\n\n      vector<vector<int> > bucket(N);\n      vector<int> U(N);\n \
    \     for (int i = (int)ord.size() - 1; i >= 0; i--) {\n         int x = ord[i];\n\
    \         for (int v : rg[x]) {\n         v = uf.eval(v);\n         if (semi[x]\
    \ > semi[v]) semi[x] = semi[v];\n         }\n         bucket[ord[semi[x]]].emplace_back(x);\n\
    \         for (int v : bucket[par[x]]) U[v] = uf.eval(v);\n         bucket[par[x]].clear();\n\
    \         uf.link(par[x], x);\n      }\n      for (int i = 1; i < (int)ord.size();\
    \ i++) {\n         int x = ord[i], u = U[x];\n         idom[x] = semi[x] == semi[u]\
    \ ? semi[x] : idom[u];\n      }\n      for (int i = 1; i < (int)ord.size(); i++)\
    \ {\n         int x = ord[i];\n         idom[x] = ord[idom[x]];\n      }\n   \
    \   idom[root] = root;\n   }\n\n   int operator[](const int &k) const { return\
    \ idom[k]; }\n\nprivate:\n   vector<vector<int>> g, rg;\n\n   struct UnionFind\
    \ {\n      const vector<int> &semi;\n      vector<int> par, m;\n\n      explicit\
    \ UnionFind(const vector<int> &semi)\n         : semi(semi), par(semi.size()),\
    \ m(semi.size()) {\n         iota(begin(par), end(par), 0);\n         iota(begin(m),\
    \ end(m), 0);\n      }\n\n      int find(int v) {\n         if (par[v] == v) return\
    \ v;\n         int r = find(par[v]);\n         if (semi[m[v]] > semi[m[par[v]]])\
    \ m[v] = m[par[v]];\n         return par[v] = r;\n      }\n\n      int eval(int\
    \ v) {\n         find(v);\n         return m[v];\n      }\n\n      void link(int\
    \ p, int c) { par[c] = p; }\n   };\n\n   vector<int> ord, par;\n   vector<int>\
    \ idom, semi;\n\n   void dfs(int idx) {\n      semi[idx] = (int)ord.size();\n\
    \      ord.emplace_back(idx);\n      for (auto &to : g[idx]) {\n         if (~semi[to])\
    \ continue;\n         dfs(to);\n         par[to] = idx;\n      }\n   }\n};\n\n\
    int main() {\n   int n, m, k;\n   cin >> n >> m >> k;\n   vector<vector<int>>\
    \ v(n + 1);\n   for(int i = 1; i <= m; i ++) {\n      v[0].push_back(i);\n   }\n\
    \   for(int i = 0; i < k; i ++) {\n      int x, y; cin >> x >> y;\n      if(x\
    \ != y) v[x].push_back(y);\n   }\n   DominatorTree g(v, 0);\n   int cnt = 0;\n\
    \   for(int i = 1; i <= n; i ++) if(g[i] == 0) cnt ++;\n   cout << cnt << endl;\n\
    \   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/graph/tree/dominator_tree.hpp\"\
    \nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/graph/tree/dominator_tree.hpp
  isVerificationFile: true
  path: test/graph/tree/dominator_tree.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 00:56:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/dominator_tree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/dominator_tree.test.cpp
- /verify/test/graph/tree/dominator_tree.test.cpp.html
title: test/graph/tree/dominator_tree.test.cpp
---
