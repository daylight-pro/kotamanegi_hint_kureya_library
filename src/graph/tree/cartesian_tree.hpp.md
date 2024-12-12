---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/cartesian_tree.test.cpp
    title: test/graph/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/tree/cartesian_tree.hpp\"\ntemplate<class T> struct\
    \ cartesian_tree {\n   int root;\n   vector<int> par, left, right;\n\n   cartesian_tree(const\
    \ vector<T>& v) : root(0), par(size(v), -1), left(size(v), -1), right(size(v),\
    \ -1) {\n      stack<int> st;\n      int N = size(v);\n      for(int i = 0; i\
    \ < N; i++) {\n         int prev = -1;\n         while(!st.empty() && v[st.top()]\
    \ > v[i]) {\n            prev = st.top();\n            st.pop();\n         }\n\
    \         if(prev != -1) par[prev] = i;\n         if(!st.empty()) par[i] = st.top();\n\
    \         st.push(i);\n      }\n\n      root = -1;\n      for(int i = 0; i < N;\
    \ i++) {\n         if(par[i] == -1) root = i;\n         else if(par[i] < i) right[par[i]]\
    \ = i;\n         else left[par[i]] = i;\n      }\n   }\n};\n"
  code: "template<class T> struct cartesian_tree {\n   int root;\n   vector<int> par,\
    \ left, right;\n\n   cartesian_tree(const vector<T>& v) : root(0), par(size(v),\
    \ -1), left(size(v), -1), right(size(v), -1) {\n      stack<int> st;\n      int\
    \ N = size(v);\n      for(int i = 0; i < N; i++) {\n         int prev = -1;\n\
    \         while(!st.empty() && v[st.top()] > v[i]) {\n            prev = st.top();\n\
    \            st.pop();\n         }\n         if(prev != -1) par[prev] = i;\n \
    \        if(!st.empty()) par[i] = st.top();\n         st.push(i);\n      }\n\n\
    \      root = -1;\n      for(int i = 0; i < N; i++) {\n         if(par[i] == -1)\
    \ root = i;\n         else if(par[i] < i) right[par[i]] = i;\n         else left[par[i]]\
    \ = i;\n      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-12-12 19:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/cartesian_tree.test.cpp
documentation_of: src/graph/tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/src/graph/tree/cartesian_tree.hpp
- /library/src/graph/tree/cartesian_tree.hpp.html
title: src/graph/tree/cartesian_tree.hpp
---
