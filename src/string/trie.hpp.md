---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/aho_corasick.test.2.cpp
    title: test/string/aho_corasick.test.2.cpp
  - icon: ':x:'
    path: test/string/aho_corasick.test.3.cpp
    title: test/string/aho_corasick.test.3.cpp
  - icon: ':x:'
    path: test/string/aho_corasick.test.cpp
    title: test/string/aho_corasick.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/trie.hpp\"\ntemplate<int char_size> struct TrieNode\
    \ {\n   int nxt[char_size];\n   int exist;\n   vector<int> accept;\n\n   TrieNode()\
    \ : exist(0) { memset(nxt, -1, sizeof(nxt)); }\n};\n\ntemplate<int char_size,\
    \ int margin> struct Trie {\n   using Node = TrieNode<char_size>;\n\n   vector<Node>\
    \ nodes;\n   int root;\n   Trie() : root(0) { nodes.push_back(Node()); }\n\n \
    \  void update_direct(int node, int id) { nodes[node].accept.push_back(id); }\n\
    \n   void update_child(int node, int child, int id) { ++nodes[node].exist; }\n\
    \n   void add(const string& str, int str_index, int node_index, int id) {\n  \
    \    if(str_index == size(str)) {\n         update_direct(node_index, id);\n \
    \     } else {\n         const int c = str[str_index] - margin;\n         if(nodes[node_index].nxt[c]\
    \ == -1) {\n            nodes[node_index].nxt[c] = size(nodes);\n            nodes.push_back(Node());\n\
    \         }\n         add(str, str_index + 1, nodes[node_index].nxt[c], id);\n\
    \         update_child(node_index, nodes[node_index].nxt[c], id);\n      }\n \
    \  }\n\n   void add(const string& str, int id = -1) {\n      if(id == -1) id =\
    \ nodes[0].exist;\n      add(str, 0, 0, id);\n   }\n\n   void query(const string&\
    \ str, const function<void(int)>& f, int str_index, int node_index) {\n      for(auto&\
    \ idx : nodes[node_index].accept) f(idx);\n      if(str_index == size(str)) {\n\
    \         return;\n      } else {\n         const int c = str[str_index] - margin;\n\
    \         if(nodes[node_index].nxt[c] == -1) return;\n         query(str, f, str_index\
    \ + 1, nodes[node_index].nxt[c]);\n      }\n   }\n\n   void query(const string&\
    \ str, const function<void(int)>& f) { query(str, f, 0, 0); }\n\n   int count()\
    \ const { return nodes[0].exist; }\n};\n"
  code: "template<int char_size> struct TrieNode {\n   int nxt[char_size];\n   int\
    \ exist;\n   vector<int> accept;\n\n   TrieNode() : exist(0) { memset(nxt, -1,\
    \ sizeof(nxt)); }\n};\n\ntemplate<int char_size, int margin> struct Trie {\n \
    \  using Node = TrieNode<char_size>;\n\n   vector<Node> nodes;\n   int root;\n\
    \   Trie() : root(0) { nodes.push_back(Node()); }\n\n   void update_direct(int\
    \ node, int id) { nodes[node].accept.push_back(id); }\n\n   void update_child(int\
    \ node, int child, int id) { ++nodes[node].exist; }\n\n   void add(const string&\
    \ str, int str_index, int node_index, int id) {\n      if(str_index == size(str))\
    \ {\n         update_direct(node_index, id);\n      } else {\n         const int\
    \ c = str[str_index] - margin;\n         if(nodes[node_index].nxt[c] == -1) {\n\
    \            nodes[node_index].nxt[c] = size(nodes);\n            nodes.push_back(Node());\n\
    \         }\n         add(str, str_index + 1, nodes[node_index].nxt[c], id);\n\
    \         update_child(node_index, nodes[node_index].nxt[c], id);\n      }\n \
    \  }\n\n   void add(const string& str, int id = -1) {\n      if(id == -1) id =\
    \ nodes[0].exist;\n      add(str, 0, 0, id);\n   }\n\n   void query(const string&\
    \ str, const function<void(int)>& f, int str_index, int node_index) {\n      for(auto&\
    \ idx : nodes[node_index].accept) f(idx);\n      if(str_index == size(str)) {\n\
    \         return;\n      } else {\n         const int c = str[str_index] - margin;\n\
    \         if(nodes[node_index].nxt[c] == -1) return;\n         query(str, f, str_index\
    \ + 1, nodes[node_index].nxt[c]);\n      }\n   }\n\n   void query(const string&\
    \ str, const function<void(int)>& f) { query(str, f, 0, 0); }\n\n   int count()\
    \ const { return nodes[0].exist; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy: []
  timestamp: '2024-12-09 18:01:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/aho_corasick.test.2.cpp
  - test/string/aho_corasick.test.3.cpp
  - test/string/aho_corasick.test.cpp
documentation_of: src/string/trie.hpp
layout: document
redirect_from:
- /library/src/string/trie.hpp
- /library/src/string/trie.hpp.html
title: src/string/trie.hpp
---
