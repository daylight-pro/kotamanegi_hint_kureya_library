---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/persistent-array.cpp\"\ntemplate<typename\
    \ T, int LOG> struct PersistentArray {\n   struct Node {\n      T data;\n    \
    \  Node* child[1 << LOG] = {};\n      Node() {}\n      Node(const T& data) : data(data)\
    \ {}\n   };\n\n   Node* root;\n   PersistentArray() : root(nullptr) {}\n\n   T\
    \ get(Node* t, int k) {\n      if(k == 0) return t->data;\n      return get(t->child[k\
    \ & ((1 << LOG) - 1)], k >> LOG);\n   }\n\n   T get(const int& k) { return get(root,\
    \ k); }\n\n   pair<Node*, T*> mutable_get(Node* t, int k) {\n      t = t ? new\
    \ Node(*t) : new Node();\n      if(k == 0) return {t, &t->data};\n      auto p\
    \ = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n      t->child[k &\
    \ ((1 << LOG) - 1)] = p.first;\n      return {t, p.second};\n   }\n\n   T* mutable_get(const\
    \ int& k) {\n      auto ret = mutable_get(root, k);\n      root = ret.first;\n\
    \      return ret.second;\n   }\n\n   Node* build(Node* t, const T& data, int\
    \ k) {\n      if(!t) t = new Node();\n      if(k == 0) {\n         t->data = data;\n\
    \         return t;\n      }\n      auto p = build(t->child[k & ((1 << LOG) -\
    \ 1)], data, k >> LOG);\n      t->child[k & ((1 << LOG) - 1)] = p;\n      return\
    \ t;\n   }\n\n   void build(const vector<T>& v) {\n      root = nullptr;\n   \
    \   for(int i = 0; i < v.size(); i++) { root = build(root, v[i], i); }\n   }\n\
    };\n"
  code: "template<typename T, int LOG> struct PersistentArray {\n   struct Node {\n\
    \      T data;\n      Node* child[1 << LOG] = {};\n      Node() {}\n      Node(const\
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
    \ i); }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/persistent-array.cpp
  requiredBy: []
  timestamp: '2025-02-25 03:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/persistent-array.cpp
layout: document
redirect_from:
- /library/src/data-structure/persistent-array.cpp
- /library/src/data-structure/persistent-array.cpp.html
title: src/data-structure/persistent-array.cpp
---
