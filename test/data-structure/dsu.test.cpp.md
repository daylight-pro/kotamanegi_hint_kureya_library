---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dsu.hpp
    title: src/data-structure/dsu.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data-structure/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/dsu.hpp\"\
    \n// base: d569f4\nstruct dsu {\n   private:\n   int _n;\n   vector<int> p;\n\n\
    \   public:\n   dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\
    \n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      int x = leader(a), y = leader(b);\n      if(x == y)\
    \ return x;\n      if(-p[x] < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y]\
    \ = x;\n      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0\
    \ <= a && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a)\
    \ == leader(b);\n   }\n\n   int leader(int a) {\n      // assert(0 <= a && a <\
    \ _n);\n      if(p[a] < 0) return a;\n      int x = a;\n      while(p[x] >= 0)\
    \ x = p[x];\n      while(p[a] >= 0) {\n         int t = p[a];\n         p[a] =\
    \ x;\n         a = t;\n      }\n      return x;\n   }\n\n   int size(int a) {\n\
    \      // assert(0 <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n\
    \      for(int i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n  \
    \       group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(_n);\n\
    \      for(int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // bf3a1e\n};\n#line 5 \"\
    test/data-structure/dsu.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   int n, q;\n   cin >> n >> q;\n   dsu uf(n);\n   while(q--) {\n      int t,\
    \ u, v;\n      cin >> t >> u >> v;\n      if(t == 0) uf.merge(u, v);\n      else\
    \ cout << uf.same(u, v) << \"\\n\";\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/data-structure/dsu.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n\n   int n, q;\n   cin >> n >> q;\n \
    \  dsu uf(n);\n   while(q--) {\n      int t, u, v;\n      cin >> t >> u >> v;\n\
    \      if(t == 0) uf.merge(u, v);\n      else cout << uf.same(u, v) << \"\\n\"\
    ;\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/data-structure/dsu.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 18:01:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/dsu.test.cpp
- /verify/test/data-structure/dsu.test.cpp.html
title: test/data-structure/dsu.test.cpp
---
