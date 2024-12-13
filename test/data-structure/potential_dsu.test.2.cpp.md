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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207
  bundledCode: "#line 1 \"test/data-structure/potential_dsu.test.2.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207\"\n\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
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
    */\n#line 5 \"test/data-structure/potential_dsu.test.2.cpp\"\n\nstruct Abel {\n\
    \   using T = int;\n   static T e() { return 0; }\n   static T op(T a, T b) {\
    \ return a + b; }\n   static T inv(T a) { return -a; }\n};\n\nint main() {\n \
    \  cin.tie(0)->sync_with_stdio(0);\n   int N;\n   while(cin >> N) {\n      if(N\
    \ == 0) break;\n      potential_dsu<Abel> dsu(2 * N);\n      map<string, int>\
    \ id;\n      int idx = 0;\n      bool flag = true;\n      while(N--) {\n     \
    \    string _, s1, s2, diff;\n         cin >> _ >> s1 >> _ >> diff >> s2;\n  \
    \       int d = stoi(diff.substr(3, diff.size() - 3));\n         if(!id.count(s1))\
    \ id[s1] = idx++;\n         if(!id.count(s2)) id[s2] = idx++;\n         if(dsu.same(id[s1],\
    \ id[s2])) {\n            if(dsu.diff(id[s1], id[s2]) != d) flag = false;\n  \
    \       } else {\n            dsu.merge(id[s1], id[s2], d);\n         }\n    \
    \  }\n      if(flag) {\n         cout << \"Yes\" << \"\\n\";\n      } else {\n\
    \         cout << \"No\" << \"\\n\";\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/potential_dsu.hpp\"\
    \n\nstruct Abel {\n   using T = int;\n   static T e() { return 0; }\n   static\
    \ T op(T a, T b) { return a + b; }\n   static T inv(T a) { return -a; }\n};\n\n\
    int main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   while(cin >> N)\
    \ {\n      if(N == 0) break;\n      potential_dsu<Abel> dsu(2 * N);\n      map<string,\
    \ int> id;\n      int idx = 0;\n      bool flag = true;\n      while(N--) {\n\
    \         string _, s1, s2, diff;\n         cin >> _ >> s1 >> _ >> diff >> s2;\n\
    \         int d = stoi(diff.substr(3, diff.size() - 3));\n         if(!id.count(s1))\
    \ id[s1] = idx++;\n         if(!id.count(s2)) id[s2] = idx++;\n         if(dsu.same(id[s1],\
    \ id[s2])) {\n            if(dsu.diff(id[s1], id[s2]) != d) flag = false;\n  \
    \       } else {\n            dsu.merge(id[s1], id[s2], d);\n         }\n    \
    \  }\n      if(flag) {\n         cout << \"Yes\" << \"\\n\";\n      } else {\n\
    \         cout << \"No\" << \"\\n\";\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/potential_dsu.hpp
  isVerificationFile: true
  path: test/data-structure/potential_dsu.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-13 15:27:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/potential_dsu.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/potential_dsu.test.2.cpp
- /verify/test/data-structure/potential_dsu.test.2.cpp.html
title: test/data-structure/potential_dsu.test.2.cpp
---
