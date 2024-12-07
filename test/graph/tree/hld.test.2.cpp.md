---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segtree.hpp
    title: src/data-structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/hld.hpp
    title: src/graph/tree/hld.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/graph/tree/hld.test.2.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/tree/hld.hpp\"\
    \nclass HLDcomposition {\n   private:\n   int V;\n   vector<vector<int>> G;\n\
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
    \ stsize(V, 0), parent(V, -1), pathtop(V, -1), in(V, -1), out(V, -1) {}\n};\n\
    #line 1 \"src/data-structure/segtree.hpp\"\n// base: bafcf8\nunsigned int bit_ceil(unsigned\
    \ int n) {\n   unsigned int x = 1;\n   while(x < (unsigned int)(n)) x *= 2;\n\
    \   return x;\n}\nint countr_zero(unsigned int n) { return __builtin_ctz(n); }\n\
    constexpr int countr_zero_constexpr(unsigned int n) {\n   int x = 0;\n   while(!(n\
    \ & (1 << x))) x++;\n   return x;\n}\ntemplate<class S, S (*op)(S, S), S (*e)()>\
    \ struct segtree {\n   public:\n   segtree() : segtree(0) {}\n   explicit segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n   explicit segtree(const vector<S>& v)\
    \ : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned int)(_n));\n   \
    \   log = countr_zero((unsigned int)size);\n      d = vector<S>(2 * size, e());\n\
    \      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n      for(int i = size\
    \ - 1; i >= 1; i--) { update(i); }\n   }\n\n   void set(int p, S x) {\n      //\
    \ assert(0 <= p && p < _n);\n      p += size;\n      d[p] = x;\n      for(int\
    \ i = 1; i <= log; i++) update(p >> i);\n   }\n\n   S get(int p) const {\n   \
    \   // assert(0 <= p && p < _n);\n      return d[p + size];\n   }\n\n   S prod(int\
    \ l, int r) const {\n      // assert(0 <= l && l <= r && r <= _n);\n      S sml\
    \ = e(), smr = e();\n      l += size;\n      r += size;\n\n      while(l < r)\
    \ {\n         if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr = op(d[--r],\
    \ smr);\n         l >>= 1;\n         r >>= 1;\n      }\n      return op(sml, smr);\n\
    \   }\n\n   S all_prod() const { return d[1]; }\n\n   template<class F> int max_right(int\
    \ l, F f) {\n      // assert(0 <= l && l <= _n);\n      // assert(f(e()));\n \
    \     if(l == _n) return _n;\n      l += size;\n      S sm = e();\n      do {\n\
    \         while(l % 2 == 0) l >>= 1;\n         if(!f(op(sm, d[l]))) {\n      \
    \      while(l < size) {\n               l = (2 * l);\n               if(f(op(sm,\
    \ d[l]))) {\n                  sm = op(sm, d[l]);\n                  l++;\n  \
    \             }\n            }\n            return l - size;\n         }\n   \
    \      sm = op(sm, d[l]);\n         l++;\n      } while((l & -l) != l);\n    \
    \  return _n;\n   }  // faa03f\n\n   template<class F> int min_left(int r, F f)\
    \ {\n      // assert(0 <= r && r <= _n);\n      // assert(f(e()));\n      if(r\
    \ == 0) return 0;\n      r += size;\n      S sm = e();\n      do {\n         r--;\n\
    \         while(r > 1 && (r % 2)) r >>= 1;\n         if(!f(op(d[r], sm))) {\n\
    \            while(r < size) {\n               r = (2 * r + 1);\n            \
    \   if(f(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n            \
    \      r--;\n               }\n            }\n            return r + 1 - size;\n\
    \         }\n         sm = op(d[r], sm);\n      } while((r & -r) != r);\n    \
    \  return 0;\n   }  // efa466\n\n   private:\n   int _n, size, log;\n   vector<S>\
    \ d;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n#line\
    \ 1 \"src/modint/modint.hpp\"\nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n\
    \   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend\
    \ mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend mm operator-(mm a,\
    \ mm b) { return a.x - b.x; }\n   friend mm operator*(mm a, mm b) { return a.x\
    \ * b.x; }\n   friend mm operator/(mm a, mm b) { return a * b.inv(); }\n   //\
    \ 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\
    \u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm& a, mm b) { return\
    \ a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x;\
    \ }\n   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }\n   friend\
    \ mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm inv() const {\
    \ return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a = *this, c = 1;\n\
    \      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n         b >>=\
    \ 1;\n      }\n      return c;\n   }\n};\n#line 7 \"test/graph/tree/hld.test.2.cpp\"\
    \n\nusing P = pair<mm, mm>;\nP op(P a, P b) { return {a.first * b.first, a.second\
    \ * b.first + b.second}; }\nP op2(P a, P b) { return {a.first * b.first, a.first\
    \ * b.second + a.second}; }\n\nP e() { return {1, 0}; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   HLDcomposition hld(N);\n   vector<int> A(N),\
    \ B(N);\n   rep(i, 0, N) { cin >> A[i] >> B[i]; }\n   rep(i, 0, N - 1) {\n   \
    \   int u, v;\n      cin >> u >> v;\n      hld.add_edge(u, v);\n   }\n   hld.build();\n\
    \   segtree<P, op, e> seg(N);\n   segtree<P, op2, e> seg2(N);\n   rep(i, 0, N)\
    \ {\n      seg.set(hld.index(i), {A[i], B[i]});\n      seg2.set(hld.index(i),\
    \ {A[i], B[i]});\n   }\n   while(Q--) {\n      int k;\n      cin >> k;\n     \
    \ if(k == 0) {\n         int p, c, d;\n         cin >> p >> c >> d;\n        \
    \ seg.set(hld.index(p), {c, d});\n         seg2.set(hld.index(p), {c, d});\n \
    \     } else {\n         int u, v;\n         cin >> u >> v;\n         int y;\n\
    \         cin >> y;\n         mm x(y);\n         for(auto [l, r, f] : hld.path_query(u,\
    \ v)) {\n            if(f) {\n               auto [c, d] = seg2.prod(l, r);\n\
    \               x = c * x + d;\n            } else {\n               auto [a,\
    \ b] = seg.prod(l, r);\n               x = a * x + b;\n            }\n       \
    \  }\n         cout << x.x << endl;\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/graph/tree/hld.hpp\"\n#include\
    \ \"src/data-structure/segtree.hpp\"\n#include \"src/modint/modint.hpp\"\n\nusing\
    \ P = pair<mm, mm>;\nP op(P a, P b) { return {a.first * b.first, a.second * b.first\
    \ + b.second}; }\nP op2(P a, P b) { return {a.first * b.first, a.first * b.second\
    \ + a.second}; }\n\nP e() { return {1, 0}; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   HLDcomposition hld(N);\n   vector<int> A(N),\
    \ B(N);\n   rep(i, 0, N) { cin >> A[i] >> B[i]; }\n   rep(i, 0, N - 1) {\n   \
    \   int u, v;\n      cin >> u >> v;\n      hld.add_edge(u, v);\n   }\n   hld.build();\n\
    \   segtree<P, op, e> seg(N);\n   segtree<P, op2, e> seg2(N);\n   rep(i, 0, N)\
    \ {\n      seg.set(hld.index(i), {A[i], B[i]});\n      seg2.set(hld.index(i),\
    \ {A[i], B[i]});\n   }\n   while(Q--) {\n      int k;\n      cin >> k;\n     \
    \ if(k == 0) {\n         int p, c, d;\n         cin >> p >> c >> d;\n        \
    \ seg.set(hld.index(p), {c, d});\n         seg2.set(hld.index(p), {c, d});\n \
    \     } else {\n         int u, v;\n         cin >> u >> v;\n         int y;\n\
    \         cin >> y;\n         mm x(y);\n         for(auto [l, r, f] : hld.path_query(u,\
    \ v)) {\n            if(f) {\n               auto [c, d] = seg2.prod(l, r);\n\
    \               x = c * x + d;\n            } else {\n               auto [a,\
    \ b] = seg.prod(l, r);\n               x = a * x + b;\n            }\n       \
    \  }\n         cout << x.x << endl;\n      }\n   }\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/graph/tree/hld.hpp
  - src/data-structure/segtree.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/graph/tree/hld.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-07 04:40:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/hld.test.2.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/hld.test.2.cpp
- /verify/test/graph/tree/hld.test.2.cpp.html
title: test/graph/tree/hld.test.2.cpp
---
