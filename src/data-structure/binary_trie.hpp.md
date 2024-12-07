---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary_trie.test.2.cpp
    title: test/data-structure/binary_trie.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary_trie.test.3.cpp
    title: test/data-structure/binary_trie.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary_trie.test.cpp
    title: test/data-structure/binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/binary_trie.hpp\"\n// base: 69a9e9\n\
    template<typename T, int MAX_LOG = 32> struct BinaryTrie {\n   struct Node {\n\
    \      array<int, 2> next;\n      int common;\n      T lazy;\n      Node() : next{-1,\
    \ -1}, common(), lazy() {}\n   };\n   vector<Node> nodes;\n   BinaryTrie() { nodes.push_back(Node());\
    \ }\n   void apply_xor(T val) { nodes[0].lazy ^= val; }\n   void push(int cur,\
    \ int b) {\n      if((nodes[cur].lazy >> b) & 1) swap(nodes[cur].next[0], nodes[cur].next[1]);\n\
    \      rep(i, 0, 2) {\n         if(nodes[cur].next[i] == -1) nodes[nodes[cur].next[i]].lazy\
    \ ^= nodes[cur].lazy;\n      }\n      nodes[cur].lazy = 0;\n   }\n   void add(T\
    \ val, int cur = 0, int b = MAX_LOG - 1) {\n      nodes[cur].common++;\n     \
    \ if(b == -1) return;\n      push(cur, b);\n      int nxt = (val >> (T)b) & (T)1;\n\
    \      if(nodes[cur].next[nxt] == -1) {\n         nodes[cur].next[nxt] = sz(nodes);\n\
    \         nodes.push_back(Node());\n      }\n      add(val, nodes[cur].next[nxt],\
    \ b - 1);\n   }\n\n   void erase(T val, int cur = 0, int b = MAX_LOG - 1) {\n\
    \      nodes[cur].common--;\n      if(b == -1) return;\n      push(cur, b);\n\
    \      erase(val, nodes[cur].next[(val >> b) & 1], b - 1);\n   }\n\n   T min_element(T\
    \ val = 0, int cur = 0, int b = MAX_LOG - 1) {\n      if(b == -1) return 0;\n\
    \      push(cur, b);\n      T nxt = (val >> b) & 1;\n      int ind = nodes[cur].next[nxt];\n\
    \      if(ind == -1 || nodes[ind].common == 0) nxt ^= 1;\n      return min_element(val,\
    \ nodes[cur].next[nxt], b - 1) | (nxt << b);\n   }  // ddf699\n\n   T max_element(T\
    \ val = 0, int cur = 0, int b = MAX_LOG - 1) { return min_element(~val); }  //\
    \ 5e1a86\n\n   int lower_bound_rank(T val, int cur = 0, int b = MAX_LOG - 1) {\n\
    \      if(cur == -1 || b == -1) return 0;\n      push(cur, b);\n      T nxt =\
    \ (val >> b) & 1;\n      int ret = lower_bound_rank(val, nodes[cur].next[nxt],\
    \ b - 1);\n      if(nxt == 1 && nodes[cur].next[0] != -1) { ret += nodes[nodes[cur].next[0]].common;\
    \ }\n      return ret;\n   }  // 05b14c\n\n   int upper_bound_rank(T val) { return\
    \ lower_bound_rank(val + 1); }  // 70e301\n\n   T kth_smallest(int k, int cur\
    \ = 0, int b = MAX_LOG - 1) {\n      if(b == -1) return 0;\n      int lower_ind\
    \ = nodes[cur].next[0];\n      int lower_cnt = 0;\n      if(lower_ind != -1) lower_cnt\
    \ = nodes[lower_ind].common;\n      if(k < lower_cnt) return kth_smallest(k, nodes[cur].next[0],\
    \ b - 1);\n      return kth_smallest(k - lower_cnt, nodes[cur].next[1], b - 1)\
    \ | (T(1) << b);\n   }  // b85845\n\n   T kth_largest(int k) { return kth_smallest(nodes[0].common\
    \ - k); }  // 1df41b\n\n   int count(T val) {\n      int cur = 0;\n      for(int\
    \ b = MAX_LOG - 1; b >= 0; b--) {\n         push(cur, b);\n         cur = nodes[cur].next[(val\
    \ >> b) & 1];\n         if(cur == -1) return 0;\n      }\n      return nodes[cur].common;\n\
    \   }  // 2a3342\n\n   int size() { return nodes[0].common; }  // 5f9f13\n};\n"
  code: "// base: 69a9e9\ntemplate<typename T, int MAX_LOG = 32> struct BinaryTrie\
    \ {\n   struct Node {\n      array<int, 2> next;\n      int common;\n      T lazy;\n\
    \      Node() : next{-1, -1}, common(), lazy() {}\n   };\n   vector<Node> nodes;\n\
    \   BinaryTrie() { nodes.push_back(Node()); }\n   void apply_xor(T val) { nodes[0].lazy\
    \ ^= val; }\n   void push(int cur, int b) {\n      if((nodes[cur].lazy >> b) &\
    \ 1) swap(nodes[cur].next[0], nodes[cur].next[1]);\n      rep(i, 0, 2) {\n   \
    \      if(nodes[cur].next[i] == -1) nodes[nodes[cur].next[i]].lazy ^= nodes[cur].lazy;\n\
    \      }\n      nodes[cur].lazy = 0;\n   }\n   void add(T val, int cur = 0, int\
    \ b = MAX_LOG - 1) {\n      nodes[cur].common++;\n      if(b == -1) return;\n\
    \      push(cur, b);\n      int nxt = (val >> (T)b) & (T)1;\n      if(nodes[cur].next[nxt]\
    \ == -1) {\n         nodes[cur].next[nxt] = sz(nodes);\n         nodes.push_back(Node());\n\
    \      }\n      add(val, nodes[cur].next[nxt], b - 1);\n   }\n\n   void erase(T\
    \ val, int cur = 0, int b = MAX_LOG - 1) {\n      nodes[cur].common--;\n     \
    \ if(b == -1) return;\n      push(cur, b);\n      erase(val, nodes[cur].next[(val\
    \ >> b) & 1], b - 1);\n   }\n\n   T min_element(T val = 0, int cur = 0, int b\
    \ = MAX_LOG - 1) {\n      if(b == -1) return 0;\n      push(cur, b);\n      T\
    \ nxt = (val >> b) & 1;\n      int ind = nodes[cur].next[nxt];\n      if(ind ==\
    \ -1 || nodes[ind].common == 0) nxt ^= 1;\n      return min_element(val, nodes[cur].next[nxt],\
    \ b - 1) | (nxt << b);\n   }  // ddf699\n\n   T max_element(T val = 0, int cur\
    \ = 0, int b = MAX_LOG - 1) { return min_element(~val); }  // 5e1a86\n\n   int\
    \ lower_bound_rank(T val, int cur = 0, int b = MAX_LOG - 1) {\n      if(cur ==\
    \ -1 || b == -1) return 0;\n      push(cur, b);\n      T nxt = (val >> b) & 1;\n\
    \      int ret = lower_bound_rank(val, nodes[cur].next[nxt], b - 1);\n      if(nxt\
    \ == 1 && nodes[cur].next[0] != -1) { ret += nodes[nodes[cur].next[0]].common;\
    \ }\n      return ret;\n   }  // 05b14c\n\n   int upper_bound_rank(T val) { return\
    \ lower_bound_rank(val + 1); }  // 70e301\n\n   T kth_smallest(int k, int cur\
    \ = 0, int b = MAX_LOG - 1) {\n      if(b == -1) return 0;\n      int lower_ind\
    \ = nodes[cur].next[0];\n      int lower_cnt = 0;\n      if(lower_ind != -1) lower_cnt\
    \ = nodes[lower_ind].common;\n      if(k < lower_cnt) return kth_smallest(k, nodes[cur].next[0],\
    \ b - 1);\n      return kth_smallest(k - lower_cnt, nodes[cur].next[1], b - 1)\
    \ | (T(1) << b);\n   }  // b85845\n\n   T kth_largest(int k) { return kth_smallest(nodes[0].common\
    \ - k); }  // 1df41b\n\n   int count(T val) {\n      int cur = 0;\n      for(int\
    \ b = MAX_LOG - 1; b >= 0; b--) {\n         push(cur, b);\n         cur = nodes[cur].next[(val\
    \ >> b) & 1];\n         if(cur == -1) return 0;\n      }\n      return nodes[cur].common;\n\
    \   }  // 2a3342\n\n   int size() { return nodes[0].common; }  // 5f9f13\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-12-08 03:39:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary_trie.test.3.cpp
  - test/data-structure/binary_trie.test.cpp
  - test/data-structure/binary_trie.test.2.cpp
documentation_of: src/data-structure/binary_trie.hpp
layout: document
redirect_from:
- /library/src/data-structure/binary_trie.hpp
- /library/src/data-structure/binary_trie.hpp.html
title: src/data-structure/binary_trie.hpp
---
