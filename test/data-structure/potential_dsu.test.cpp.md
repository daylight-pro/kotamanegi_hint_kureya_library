---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/potential_dsu.hpp
    title: src/data-structure/potential_dsu.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"test/data-structure/potential_dsu.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/potential_dsu.hpp\"\
    \n// base: 650ffa\ntemplate<typename Abel> struct potential_dsu {\n   using T\
    \ = typename Abel::T;\n   int tCount;\n   vector<int> p, rank;\n   vector<T> potential;\n\
    \   int N;\n   potential_dsu(int size) {\n      N = size;\n      p.resize(N, -1);\n\
    \      rank.resize(N, 0);\n      potential.resize(N, Abel::e());\n      tCount\
    \ = N;\n   }\n\n   bool same(int x, int y) { return leader(x) == leader(y); }\n\
    \n   // w[y] - w[x] = w\n   void merge(int x, int y, T w) {\n      w = Abel::op(w,\
    \ get_potential(x));\n      w = Abel::op(w, Abel::inv(get_potential(y)));\n  \
    \    link(leader(x), leader(y), w);\n   }\n\n   int leader(int x) {\n      if(p[x]\
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
    */\n#line 5 \"test/data-structure/potential_dsu.test.cpp\"\n\nstruct Abel {\n\
    \   using T = int;\n   static T e() { return 0; }\n   static T op(T a, T b) {\
    \ return a + b; }\n   static T inv(T a) { return -a; }\n};\n\nint main() {\n \
    \  cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   while(cin >> N >> M) {\n\
    \      if(N == 0 && M == 0) break;\n      potential_dsu<Abel> dsu(N);\n      while(M--)\
    \ {\n         char c;\n         cin >> c;\n         if(c == '!') {\n         \
    \   int a, b, c;\n            cin >> a >> b >> c;\n            a--;\n        \
    \    b--;\n            dsu.merge(a, b, c);\n         } else {\n            int\
    \ a, b;\n            cin >> a >> b;\n            a--;\n            b--;\n    \
    \        if(dsu.same(a, b)) {\n               cout << dsu.diff(a, b) << endl;\n\
    \            } else {\n               cout << \"UNKNOWN\" << endl;\n         \
    \   }\n         }\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/potential_dsu.hpp\"\
    \n\nstruct Abel {\n   using T = int;\n   static T e() { return 0; }\n   static\
    \ T op(T a, T b) { return a + b; }\n   static T inv(T a) { return -a; }\n};\n\n\
    int main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M;\n   while(cin >>\
    \ N >> M) {\n      if(N == 0 && M == 0) break;\n      potential_dsu<Abel> dsu(N);\n\
    \      while(M--) {\n         char c;\n         cin >> c;\n         if(c == '!')\
    \ {\n            int a, b, c;\n            cin >> a >> b >> c;\n            a--;\n\
    \            b--;\n            dsu.merge(a, b, c);\n         } else {\n      \
    \      int a, b;\n            cin >> a >> b;\n            a--;\n            b--;\n\
    \            if(dsu.same(a, b)) {\n               cout << dsu.diff(a, b) << endl;\n\
    \            } else {\n               cout << \"UNKNOWN\" << endl;\n         \
    \   }\n         }\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/potential_dsu.hpp
  isVerificationFile: true
  path: test/data-structure/potential_dsu.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 15:27:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/potential_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/potential_dsu.test.cpp
- /verify/test/data-structure/potential_dsu.test.cpp.html
title: test/data-structure/potential_dsu.test.cpp
---
