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
  bundledCode: "#line 1 \"src/memo/ext.cpp\"\n#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/priority_queue.hpp>\n\
    #include <ext/rope>\n\nusing namespace __gnu_pbds;\nusing namespace __gnu_cxx;\
    \  // for ext/rope\nusing namespace std;\n\nint main() {\n   tree<int, null_type,\
    \ less<int>, rb_tree_tag, tree_order_statistics_node_update> tree;\n   tree.insert(1);\
    \                       // 1\n   tree.insert(10);                      // 1 10\n\
    \   tree.insert(6);                       // 1 6 10\n   tree.insert(7);      \
    \                 // 1 6 7 10\n   tree.insert(4);                       // 1 4\
    \ 6 7 10\n   tree.erase(6);                        // 1 4 7 10\n   assert(tree.order_of_key(5)\
    \ == 2);    // 5\u672A\u6E80\u306E\u8981\u7D20\u6570\n   assert(*tree.find_by_order(2)\
    \ == 7);  // 0-indexed\u30672\u756A\u76EE\u306E\u8981\u7D20\n\n   gp_hash_table<int,\
    \ int> m;\n   m[2] = 5;\n   m[1] = 10;\n   m[3] = 7;\n\n   __gnu_pbds::priority_queue<int,\
    \ greater<int>, rc_binomial_heap_tag> pq;\n   auto it = pq.push(1);  // 1\n  \
    \ pq.push(10);           // 1 10\n   assert(pq.top() == 1);\n   pq.modify(it,\
    \ 20);  // 10 20\n   assert(pq.top() == 10);\n   pq.erase_if([](int x) { return\
    \ x <= 10; });  // 20\n   assert(pq.top() == 20);\n   assert(pq.size() == 1);\n\
    \   pq.erase(it);  // empty\n   assert(pq.empty());\n\n   // access, insert, erase:\
    \ O(log n)\n   rope<int> v;\n   v.insert(0, 1);  // 1\n   v.insert(0, 2);  //\
    \ 2 1\n   v.insert(1, 3);  // 2 3 1\n   v.insert(2, 4);  // 2 3 4 1\n   v.erase(1,\
    \ 2);   // 2 1\n   assert(v.size() == 2);\n   assert(v[0] == 2);\n   assert(v[1]\
    \ == 1);\n\n   return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/priority_queue.hpp>\n#include\
    \ <ext/rope>\n\nusing namespace __gnu_pbds;\nusing namespace __gnu_cxx;  // for\
    \ ext/rope\nusing namespace std;\n\nint main() {\n   tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update> tree;\n   tree.insert(1);  \
    \                     // 1\n   tree.insert(10);                      // 1 10\n\
    \   tree.insert(6);                       // 1 6 10\n   tree.insert(7);      \
    \                 // 1 6 7 10\n   tree.insert(4);                       // 1 4\
    \ 6 7 10\n   tree.erase(6);                        // 1 4 7 10\n   assert(tree.order_of_key(5)\
    \ == 2);    // 5\u672A\u6E80\u306E\u8981\u7D20\u6570\n   assert(*tree.find_by_order(2)\
    \ == 7);  // 0-indexed\u30672\u756A\u76EE\u306E\u8981\u7D20\n\n   gp_hash_table<int,\
    \ int> m;\n   m[2] = 5;\n   m[1] = 10;\n   m[3] = 7;\n\n   __gnu_pbds::priority_queue<int,\
    \ greater<int>, rc_binomial_heap_tag> pq;\n   auto it = pq.push(1);  // 1\n  \
    \ pq.push(10);           // 1 10\n   assert(pq.top() == 1);\n   pq.modify(it,\
    \ 20);  // 10 20\n   assert(pq.top() == 10);\n   pq.erase_if([](int x) { return\
    \ x <= 10; });  // 20\n   assert(pq.top() == 20);\n   assert(pq.size() == 1);\n\
    \   pq.erase(it);  // empty\n   assert(pq.empty());\n\n   // access, insert, erase:\
    \ O(log n)\n   rope<int> v;\n   v.insert(0, 1);  // 1\n   v.insert(0, 2);  //\
    \ 2 1\n   v.insert(1, 3);  // 2 3 1\n   v.insert(2, 4);  // 2 3 4 1\n   v.erase(1,\
    \ 2);   // 2 1\n   assert(v.size() == 2);\n   assert(v[0] == 2);\n   assert(v[1]\
    \ == 1);\n\n   return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/memo/ext.cpp
  requiredBy: []
  timestamp: '2024-12-13 16:25:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/memo/ext.cpp
layout: document
redirect_from:
- /library/src/memo/ext.cpp
- /library/src/memo/ext.cpp.html
title: src/memo/ext.cpp
---
