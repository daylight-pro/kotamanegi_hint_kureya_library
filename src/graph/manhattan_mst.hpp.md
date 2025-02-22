---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/manhattan_mst.test.cpp
    title: test/graph/manhattan_mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/manhattan_mst.hpp\"\n// \u5019\u88DC\u306E\u8FBA\
    \u3092 O(N) \u672C\u306B\u6E1B\u3089\u3059\u3002MST\u6642\u306F\u8FFD\u52A0\u3067\
    sort, UF\u7B49\u306E\u5FC5\u8981\u3042\u308A\u3002\ntemplate<typename T>\nvector<tuple<T,\
    \ int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {\n   assert(xs.size()\
    \ == ys.size());\n   vector<tuple<T, int, int>> ret;\n   int n = (int) xs.size();\n\
    \n   vector<int> ord(n);\n   iota(ord.begin(), ord.end(), 0);\n\n   for(int s\
    \ = 0; s < 2; s++) {\n      for(int t = 0; t < 2; t++) {\n         auto cmp =\
    \ [&](int i, int j) -> bool {\n            return xs[i] + ys[i] < xs[j] + ys[j];\n\
    \         };\n         sort(ord.begin(), ord.end(), cmp);\n\n         map<T, int>\
    \ idx;\n         for(int i: ord) {\n            for(auto it = idx.lower_bound(-ys[i]);\n\
    \                  it != idx.end(); it = idx.erase(it)) {\n               int\
    \ j = it->second;\n               if(xs[i] - xs[j] < ys[i] - ys[j]) break;\n \
    \              ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);\n\
    \            }\n            idx[-ys[i]] = i;\n         }\n         swap(xs, ys);\n\
    \      }\n      for(int i = 0; i < n; i++) xs[i] *= -1;\n   }\n   return ret;\n\
    }\n"
  code: "// \u5019\u88DC\u306E\u8FBA\u3092 O(N) \u672C\u306B\u6E1B\u3089\u3059\u3002\
    MST\u6642\u306F\u8FFD\u52A0\u3067sort, UF\u7B49\u306E\u5FC5\u8981\u3042\u308A\u3002\
    \ntemplate<typename T>\nvector<tuple<T, int, int>> manhattan_mst(vector<T> xs,\
    \ vector<T> ys) {\n   assert(xs.size() == ys.size());\n   vector<tuple<T, int,\
    \ int>> ret;\n   int n = (int) xs.size();\n\n   vector<int> ord(n);\n   iota(ord.begin(),\
    \ ord.end(), 0);\n\n   for(int s = 0; s < 2; s++) {\n      for(int t = 0; t <\
    \ 2; t++) {\n         auto cmp = [&](int i, int j) -> bool {\n            return\
    \ xs[i] + ys[i] < xs[j] + ys[j];\n         };\n         sort(ord.begin(), ord.end(),\
    \ cmp);\n\n         map<T, int> idx;\n         for(int i: ord) {\n           \
    \ for(auto it = idx.lower_bound(-ys[i]);\n                  it != idx.end(); it\
    \ = idx.erase(it)) {\n               int j = it->second;\n               if(xs[i]\
    \ - xs[j] < ys[i] - ys[j]) break;\n               ret.emplace_back(abs(xs[i] -\
    \ xs[j]) + abs(ys[i] - ys[j]), i, j);\n            }\n            idx[-ys[i]]\
    \ = i;\n         }\n         swap(xs, ys);\n      }\n      for(int i = 0; i <\
    \ n; i++) xs[i] *= -1;\n   }\n   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2025-02-21 15:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/manhattan_mst.test.cpp
documentation_of: src/graph/manhattan_mst.hpp
layout: document
redirect_from:
- /library/src/graph/manhattan_mst.hpp
- /library/src/graph/manhattan_mst.hpp.html
title: src/graph/manhattan_mst.hpp
---
