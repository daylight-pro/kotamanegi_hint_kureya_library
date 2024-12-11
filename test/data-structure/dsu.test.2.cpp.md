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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/data-structure/dsu.test.2.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/dsu.hpp\"\
    \n// base: c45937\nstruct dsu {\n   private:\n   int _n;\n   vector<int> parent_or_size;\n\
    \n   public:\n   dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n\
    \      // assert(0 <= b && b < _n);\n      int x = leader(a), y = leader(b);\n\
    \      if(x == y) return x;\n      if(-parent_or_size[x] < -parent_or_size[y])\
    \ swap(x, y);\n      parent_or_size[x] += parent_or_size[y];\n      parent_or_size[y]\
    \ = x;\n      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0\
    \ <= a && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a)\
    \ == leader(b);\n   }\n\n   int leader(int a) {\n      // assert(0 <= a && a <\
    \ _n);\n      if(parent_or_size[a] < 0) return a;\n      int x = a;\n      while(parent_or_size[x]\
    \ >= 0) x = parent_or_size[x];\n      while(parent_or_size[a] >= 0) {\n      \
    \   int t = parent_or_size[a];\n         parent_or_size[a] = x;\n         a =\
    \ t;\n      }\n      return x;\n   }\n\n   int size(int a) {\n      // assert(0\
    \ <= a && a < _n);\n      return -parent_or_size[leader(a)];\n   }  // 1ff997\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n\
    \      for(int i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n  \
    \       group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(_n);\n\
    \      for(int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // bf3a1e\n};\n#line 5 \"\
    test/data-structure/dsu.test.2.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   dsu d(10);\n   d.merge(3, 5);\n   d.merge(5, 7);\n   d.merge(2, 3);\n   d.merge(8,\
    \ 9);\n   d.merge(0, 1);\n   d.merge(2, 7);\n   assert(d.size(7) == 4);\n   assert(size(d.groups())\
    \ == 5);\n   set<set<int>> s;\n   s.insert({0, 1});\n   s.insert({2, 3, 5, 7});\n\
    \   s.insert({4});\n   s.insert({6});\n   s.insert({8, 9});\n   for(auto i : d.groups())\
    \ {\n      set<int> t(all(i));\n      assert(s.count(t));\n   }\n   cout << \"\
    Hello World\" << endl;\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/dsu.hpp\"\n\n\
    int main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   dsu d(10);\n   d.merge(3,\
    \ 5);\n   d.merge(5, 7);\n   d.merge(2, 3);\n   d.merge(8, 9);\n   d.merge(0,\
    \ 1);\n   d.merge(2, 7);\n   assert(d.size(7) == 4);\n   assert(size(d.groups())\
    \ == 5);\n   set<set<int>> s;\n   s.insert({0, 1});\n   s.insert({2, 3, 5, 7});\n\
    \   s.insert({4});\n   s.insert({6});\n   s.insert({8, 9});\n   for(auto i : d.groups())\
    \ {\n      set<int> t(all(i));\n      assert(s.count(t));\n   }\n   cout << \"\
    Hello World\" << endl;\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/data-structure/dsu.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/dsu.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/dsu.test.2.cpp
- /verify/test/data-structure/dsu.test.2.cpp.html
title: test/data-structure/dsu.test.2.cpp
---
