---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/persistent-segtree.hpp\"\ntemplate<typename\
    \ Monoid> struct PersistentSegmentTree {\n   using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n   struct Node {\n      Monoid data;\n      Node *l, *r;\n\n  \
    \    Node(const Monoid& data) : data(data), l(nullptr), r(nullptr) {}\n   };\n\
    \n   int sz;\n   const F f;\n   const Monoid M1;\n\n   PersistentSegmentTree(const\
    \ F f, const Monoid& M1) : f(f), M1(M1) {}\n\n   Node* build(vector<Monoid>& v)\
    \ {\n      sz = (int)v.size();\n      return build(0, (int)v.size(), v);\n   }\n\
    \n   Node* merge(Node* l, Node* r) {\n      auto t = new Node(f(l->data, r->data));\n\
    \      t->l = l;\n      t->r = r;\n      return t;\n   }\n\n   Node* build(int\
    \ l, int r, vector<Monoid>& v) {\n      if(l + 1 >= r) return new Node(v[l]);\n\
    \      return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n \
    \  }\n\n   Node* update(int a, const Monoid& x, Node* k, int l, int r) {\n   \
    \   if(r <= a || a + 1 <= l) return k;\n      else if(a <= l && r <= a + 1) return\
    \ new Node(x);\n      else return merge(update(a, x, k->l, l, (l + r) >> 1), update(a,\
    \ x, k->r, (l + r) >> 1, r));\n   }\n\n   Node* update(Node* t, int k, const Monoid&\
    \ x) { return update(k, x, t, 0, sz); }\n\n   Monoid query(int a, int b, Node*\
    \ k, int l, int r) {\n      if(r <= a || b <= l) return M1;\n      else if(a <=\
    \ l && r <= b) return k->data;\n      else return f(query(a, b, k->l, l, (l +\
    \ r) >> 1), query(a, b, k->r, (l + r) >> 1, r));\n   }\n\n   Monoid query(Node*\
    \ t, int a, int b) { return query(a, b, t, 0, sz); }\n};\n"
  code: "template<typename Monoid> struct PersistentSegmentTree {\n   using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n   struct Node {\n      Monoid data;\n      Node *l, *r;\n\n  \
    \    Node(const Monoid& data) : data(data), l(nullptr), r(nullptr) {}\n   };\n\
    \n   int sz;\n   const F f;\n   const Monoid M1;\n\n   PersistentSegmentTree(const\
    \ F f, const Monoid& M1) : f(f), M1(M1) {}\n\n   Node* build(vector<Monoid>& v)\
    \ {\n      sz = (int)v.size();\n      return build(0, (int)v.size(), v);\n   }\n\
    \n   Node* merge(Node* l, Node* r) {\n      auto t = new Node(f(l->data, r->data));\n\
    \      t->l = l;\n      t->r = r;\n      return t;\n   }\n\n   Node* build(int\
    \ l, int r, vector<Monoid>& v) {\n      if(l + 1 >= r) return new Node(v[l]);\n\
    \      return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n \
    \  }\n\n   Node* update(int a, const Monoid& x, Node* k, int l, int r) {\n   \
    \   if(r <= a || a + 1 <= l) return k;\n      else if(a <= l && r <= a + 1) return\
    \ new Node(x);\n      else return merge(update(a, x, k->l, l, (l + r) >> 1), update(a,\
    \ x, k->r, (l + r) >> 1, r));\n   }\n\n   Node* update(Node* t, int k, const Monoid&\
    \ x) { return update(k, x, t, 0, sz); }\n\n   Monoid query(int a, int b, Node*\
    \ k, int l, int r) {\n      if(r <= a || b <= l) return M1;\n      else if(a <=\
    \ l && r <= b) return k->data;\n      else return f(query(a, b, k->l, l, (l +\
    \ r) >> 1), query(a, b, k->r, (l + r) >> 1, r));\n   }\n\n   Monoid query(Node*\
    \ t, int a, int b) { return query(a, b, t, 0, sz); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/persistent-segtree.hpp
  requiredBy: []
  timestamp: '2025-02-26 00:49:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/persistent-segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/persistent-segtree.hpp
- /library/src/data-structure/persistent-segtree.hpp.html
title: src/data-structure/persistent-segtree.hpp
---
