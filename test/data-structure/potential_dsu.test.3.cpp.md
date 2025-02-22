---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/potential_dsu.hpp
    title: src/data-structure/potential_dsu.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"test/data-structure/potential_dsu.test.3.cpp\"\n\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\
    \nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ %\
    \ mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator-(mm a) { return\
    \ -a.x; }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend\
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
    src/data-structure/potential_dsu.hpp\"\n// base: 650ffa\ntemplate<typename Abel>\
    \ struct potential_dsu {\n   using T = typename Abel::T;\n   int tCount;\n   vector<int>\
    \ p, rank;\n   vector<T> potential;\n   int N;\n   potential_dsu(int size) {\n\
    \      N = size;\n      p.resize(N, -1);\n      rank.resize(N, 0);\n      potential.resize(N,\
    \ Abel::e());\n      tCount = N;\n   }\n\n   bool same(int x, int y) { return\
    \ leader(x) == leader(y); }\n\n   // w[y] - w[x] = w\n   void merge(int x, int\
    \ y, T w) {\n      w = Abel::op(w, get_potential(x));\n      w = Abel::op(w, Abel::inv(get_potential(y)));\n\
    \      link(leader(x), leader(y), w);\n   }\n\n   int leader(int x) {\n      if(p[x]\
    \ < 0) return x;\n      int l = leader(p[x]);\n      potential[x] = Abel::op(potential[x],\
    \ potential[p[x]]);\n      return p[x] = l;\n   }\n\n   T get_potential(int x)\
    \ {\n      leader(x);\n      return potential[x];\n   }\n\n   // w[y] - w[x]\n\
    \   T diff(int x, int y) { return Abel::op(get_potential(y), Abel::inv(get_potential(x)));\
    \ }\n\n   int count() { return tCount; }  // 154012\n\n   int size(int a) {\n\
    \      // assert(0 <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(N), group_size(N);\n\
    \      for(int i = 0; i < N; i++) {\n         leader_buf[i] = leader(i);\n   \
    \      group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(N);\n\
    \      for(int i = 0; i < N; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < N; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // 92d7ce\n\n   private:\n\
    \   void link(int x, int y, T w) {\n      if(x == y) return;\n      tCount--;\n\
    \      if(rank[x] < rank[y]) {\n         swap(x, y);\n         w = Abel::inv(w);\n\
    \      }\n      p[x] += p[y];\n      p[y] = x;\n      if(rank[x] == rank[y]) rank[x]++;\n\
    \      tCount--;\n      potential[y] = w;\n   }\n};\n\n/*\nstruct Abel {\n   using\
    \ T = int;\n   static T e() { return 0; }\n   static T op(T a, T b) { return a\
    \ + b; }\n   static T inv(T a) { return -a; }\n};\n\npotential_dsu<Abel> dsu(N);\n\
    */\n#line 7 \"test/data-structure/potential_dsu.test.3.cpp\"\n\nstruct Abel {\n\
    \   using T = mm;\n   static T e() { return 0; }\n   static T op(T a, T b) { return\
    \ a + b; }\n   static T inv(T a) { return mm(-a.x); }\n};\n\nint main() {\n  \
    \ cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >> N >> Q;\n   potential_dsu<Abel>\
    \ dsu(N);\n   while(Q--) {\n      int t;\n      cin >> t;\n      if(t == 0) {\n\
    \         int a, b, c;\n         cin >> a >> b >> c;\n         if(dsu.same(b,\
    \ a) && dsu.diff(b, a).x != c) {\n            cout << 0 << endl;\n           \
    \ continue;\n         }\n         if(!dsu.same(b, a)) dsu.merge(b, a, c);\n  \
    \       cout << 1 << endl;\n      } else {\n         int a, b;\n         cin >>\
    \ a >> b;\n         if(dsu.same(a, b)) cout << dsu.diff(b, a).x << endl;\n   \
    \      else cout << -1 << endl;\n      }\n   }\n   return 0;\n}\n"
  code: "\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/data-structure/potential_dsu.hpp\"\n\nstruct Abel {\n   using T = mm;\n\
    \   static T e() { return 0; }\n   static T op(T a, T b) { return a + b; }\n \
    \  static T inv(T a) { return mm(-a.x); }\n};\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   potential_dsu<Abel> dsu(N);\n   while(Q--)\
    \ {\n      int t;\n      cin >> t;\n      if(t == 0) {\n         int a, b, c;\n\
    \         cin >> a >> b >> c;\n         if(dsu.same(b, a) && dsu.diff(b, a).x\
    \ != c) {\n            cout << 0 << endl;\n            continue;\n         }\n\
    \         if(!dsu.same(b, a)) dsu.merge(b, a, c);\n         cout << 1 << endl;\n\
    \      } else {\n         int a, b;\n         cin >> a >> b;\n         if(dsu.same(a,\
    \ b)) cout << dsu.diff(b, a).x << endl;\n         else cout << -1 << endl;\n \
    \     }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/data-structure/potential_dsu.hpp
  isVerificationFile: true
  path: test/data-structure/potential_dsu.test.3.cpp
  requiredBy: []
  timestamp: '2025-02-23 00:00:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/potential_dsu.test.3.cpp
layout: document
redirect_from:
- /verify/test/data-structure/potential_dsu.test.3.cpp
- /verify/test/data-structure/potential_dsu.test.3.cpp.html
title: test/data-structure/potential_dsu.test.3.cpp
---
