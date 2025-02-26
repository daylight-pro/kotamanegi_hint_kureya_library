---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/persistent-array.hpp
    title: src/data-structure/persistent-array.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/persistent-uf.hpp
    title: src/data-structure/persistent-uf.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/data-structure/persistent_uf.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/persistent-array.hpp\"\
    \ntemplate<typename T, int LOG> struct PersistentArray {\n   struct Node {\n \
    \     T data;\n      Node* child[1 << LOG] = {};\n      Node() {}\n      Node(const\
    \ T& data) : data(data) {}\n   };\n\n   Node* root;\n   PersistentArray() : root(nullptr)\
    \ {}\n\n   T get(Node* t, int k) {\n      if(k == 0) return t->data;\n      return\
    \ get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n   }\n\n   T get(const int&\
    \ k) { return get(root, k); }\n\n   pair<Node*, T*> mutable_get(Node* t, int k)\
    \ {\n      t = t ? new Node(*t) : new Node();\n      if(k == 0) return {t, &t->data};\n\
    \      auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n     \
    \ t->child[k & ((1 << LOG) - 1)] = p.first;\n      return {t, p.second};\n   }\n\
    \n   T* mutable_get(const int& k) {\n      auto ret = mutable_get(root, k);\n\
    \      root = ret.first;\n      return ret.second;\n   }\n\n   Node* build(Node*\
    \ t, const T& data, int k) {\n      if(!t) t = new Node();\n      if(k == 0) {\n\
    \         t->data = data;\n         return t;\n      }\n      auto p = build(t->child[k\
    \ & ((1 << LOG) - 1)], data, k >> LOG);\n      t->child[k & ((1 << LOG) - 1)]\
    \ = p;\n      return t;\n   }\n\n   void build(const vector<T>& v) {\n      root\
    \ = nullptr;\n      for(int i = 0; i < v.size(); i++) { root = build(root, v[i],\
    \ i); }\n   }\n};\n#line 1 \"src/data-structure/persistent-uf.hpp\"\nstruct PersistentUnionFind\
    \ {\n   PersistentArray<int, 3> data;\n\n   PersistentUnionFind() {}\n\n   PersistentUnionFind(int\
    \ sz) { data.build(vector<int>(sz, -1)); }\n\n   int find(int k) {\n      int\
    \ p = data.get(k);\n      return p >= 0 ? find(p) : k;\n   }\n\n   int size(int\
    \ k) { return (-data.get(find(k))); }\n\n   bool unite(int x, int y) {\n     \
    \ x = find(x);\n      y = find(y);\n      if(x == y) return false;\n      auto\
    \ u = data.get(x);\n      auto v = data.get(y);\n\n      if(u < v) {\n       \
    \  auto a = data.mutable_get(x);\n         *a += v;\n         auto b = data.mutable_get(y);\n\
    \         *b = x;\n      } else {\n         auto a = data.mutable_get(y);\n  \
    \       *a += u;\n         auto b = data.mutable_get(x);\n         *b = y;\n \
    \     }\n      return true;\n   }\n};\n#line 6 \"test/data-structure/persistent_uf.test.cpp\"\
    \n\nint main() {\n   int N, Q;\n   cin >> N >> Q;\n   vector<PersistentUnionFind>\
    \ uf(Q + 1);\n   uf[0] = PersistentUnionFind(N);\n   for(int i = 0; i < Q; i++)\
    \ {\n      int t, k, u, v;\n      cin >> t >> k >> u >> v;\n      ++k;\n     \
    \ if(t == 0) {\n         uf[i + 1] = uf[k];\n         uf[i + 1].unite(u, v);\n\
    \      } else {\n         cout << (uf[k].find(u) == uf[k].find(v)) << \"\\n\"\
    ;\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/persistent-array.hpp\"\
    \n#include \"src/data-structure/persistent-uf.hpp\"\n\nint main() {\n   int N,\
    \ Q;\n   cin >> N >> Q;\n   vector<PersistentUnionFind> uf(Q + 1);\n   uf[0] =\
    \ PersistentUnionFind(N);\n   for(int i = 0; i < Q; i++) {\n      int t, k, u,\
    \ v;\n      cin >> t >> k >> u >> v;\n      ++k;\n      if(t == 0) {\n       \
    \  uf[i + 1] = uf[k];\n         uf[i + 1].unite(u, v);\n      } else {\n     \
    \    cout << (uf[k].find(u) == uf[k].find(v)) << \"\\n\";\n      }\n   }\n   return\
    \ 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/persistent-array.hpp
  - src/data-structure/persistent-uf.hpp
  isVerificationFile: true
  path: test/data-structure/persistent_uf.test.cpp
  requiredBy: []
  timestamp: '2025-02-26 00:49:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/persistent_uf.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/persistent_uf.test.cpp
- /verify/test/data-structure/persistent_uf.test.cpp.html
title: test/data-structure/persistent_uf.test.cpp
---
