---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary_trie.hpp
    title: src/data-structure/binary_trie.hpp
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data-structure/binary_trie.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/binary_trie.hpp\"\n//\
    \ base: b75bb1\ntemplate<typename T, int MAX_LOG = 32> struct BinaryTrie {\n \
    \  struct Node {\n      array<int, 2> next;\n      int common;\n      T lazy;\n\
    \      Node() : next{-1, -1}, common(), lazy() {}\n   };\n   vector<Node> nodes;\n\
    \   BinaryTrie() { nodes.push_back(Node()); }\n   void apply_xor(T val) { nodes[0].lazy\
    \ ^= val; }\n   void push(int cur, int b) {\n      if((nodes[cur].lazy >> b) &\
    \ 1) swap(nodes[cur].next[0], nodes[cur].next[1]);\n      for(int i = 0; i < 2;\
    \ i++) {\n         if(nodes[cur].next[i] == -1) nodes[nodes[cur].next[i]].lazy\
    \ ^= nodes[cur].lazy;\n      }\n      nodes[cur].lazy = 0;\n   }\n   void add(T\
    \ val, int cur = 0, int b = MAX_LOG - 1) {\n      nodes[cur].common++;\n     \
    \ if(b == -1) return;\n      push(cur, b);\n      int nxt = (val >> (T)b) & (T)1;\n\
    \      if(nodes[cur].next[nxt] == -1) {\n         nodes[cur].next[nxt] = size(nodes);\n\
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
    \   }  // 2a3342\n\n   int count() { return nodes[0].common; }  // 210f0e\n};\n\
    #line 5 \"test/data-structure/binary_trie.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int Q;\n   cin >> Q;\n   BinaryTrie<ll> trie;\n   while(Q--) {\n      int\
    \ t;\n      cin >> t;\n      if(t == 0) {\n         int x;\n         cin >> x;\n\
    \         if(trie.count(x) > 0) continue;\n         trie.add(x);\n      } else\
    \ if(t == 1) {\n         int x;\n         cin >> x;\n         if(trie.count(x)\
    \ == 0) continue;\n         trie.erase(x);\n      } else {\n         int x;\n\
    \         cin >> x;\n         cout << (trie.min_element(x) ^ x) << endl;\n   \
    \   }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/data-structure/binary_trie.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int Q;\n   cin >> Q;\n   BinaryTrie<ll>\
    \ trie;\n   while(Q--) {\n      int t;\n      cin >> t;\n      if(t == 0) {\n\
    \         int x;\n         cin >> x;\n         if(trie.count(x) > 0) continue;\n\
    \         trie.add(x);\n      } else if(t == 1) {\n         int x;\n         cin\
    \ >> x;\n         if(trie.count(x) == 0) continue;\n         trie.erase(x);\n\
    \      } else {\n         int x;\n         cin >> x;\n         cout << (trie.min_element(x)\
    \ ^ x) << endl;\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/binary_trie.hpp
  isVerificationFile: true
  path: test/data-structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 18:11:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary_trie.test.cpp
- /verify/test/data-structure/binary_trie.test.cpp.html
title: test/data-structure/binary_trie.test.cpp
---
