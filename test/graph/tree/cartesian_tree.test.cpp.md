---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/cartesian_tree.hpp
    title: src/graph/tree/cartesian_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/graph/tree/cartesian_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/tree/cartesian_tree.hpp\"\ntemplate<class\
    \ T> struct cartesian_tree {\n   int root;\n   vector<int> par, left, right;\n\
    \n   cartesian_tree(const vector<T>& v) : root(0), par(size(v), -1), left(size(v),\
    \ -1), right(size(v), -1) {\n      stack<int> st;\n      int N = size(v);\n  \
    \    for(int i = 0; i < N; i++) {\n         int prev = -1;\n         while(!st.empty()\
    \ && v[st.top()] > v[i]) {\n            prev = st.top();\n            st.pop();\n\
    \         }\n         if(prev != -1) par[prev] = i;\n         if(!st.empty())\
    \ par[i] = st.top();\n         st.push(i);\n      }\n\n      root = -1;\n    \
    \  for(int i = 0; i < N; i++) {\n         if(par[i] == -1) root = i;\n       \
    \  else if(par[i] < i) right[par[i]] = i;\n         else left[par[i]] = i;\n \
    \     }\n   }\n};\n#line 5 \"test/graph/tree/cartesian_tree.test.cpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n   vector<int>\
    \ A(N);\n   for(auto&& a : A) cin >> a;\n   cartesian_tree<int> ct(A);\n   for(int\
    \ i = 0; i < N; i++) {\n      if(ct.par[i] != -1) cout << ct.par[i];\n      else\
    \ cout << i;\n      cout << \" \\n\"[i == N - 1];\n   }\n   for(int i = 0; i <\
    \ N; i++) {\n      assert(ct.par[i] != -1 || ct.root == i);\n      if(ct.left[i]\
    \ != -1) assert(ct.left[i] < i && A[ct.left[i]] > A[i] && ct.par[ct.left[i]] ==\
    \ i);\n      if(ct.right[i] != -1) assert(ct.right[i] > i && A[ct.right[i]] >\
    \ A[i] && ct.par[ct.right[i]] == i);\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/graph/tree/cartesian_tree.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N;\n   cin >> N;\n   vector<int>\
    \ A(N);\n   for(auto&& a : A) cin >> a;\n   cartesian_tree<int> ct(A);\n   for(int\
    \ i = 0; i < N; i++) {\n      if(ct.par[i] != -1) cout << ct.par[i];\n      else\
    \ cout << i;\n      cout << \" \\n\"[i == N - 1];\n   }\n   for(int i = 0; i <\
    \ N; i++) {\n      assert(ct.par[i] != -1 || ct.root == i);\n      if(ct.left[i]\
    \ != -1) assert(ct.left[i] < i && A[ct.left[i]] > A[i] && ct.par[ct.left[i]] ==\
    \ i);\n      if(ct.right[i] != -1) assert(ct.right[i] > i && A[ct.right[i]] >\
    \ A[i] && ct.par[ct.right[i]] == i);\n   }\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/graph/tree/cartesian_tree.hpp
  isVerificationFile: true
  path: test/graph/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 19:26:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/cartesian_tree.test.cpp
- /verify/test/graph/tree/cartesian_tree.test.cpp.html
title: test/graph/tree/cartesian_tree.test.cpp
---
