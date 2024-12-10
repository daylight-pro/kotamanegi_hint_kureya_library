---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/aho_corasick.hpp
    title: src/string/aho_corasick.hpp
  - icon: ':x:'
    path: src/string/trie.hpp
    title: src/string/trie.hpp
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"test/string/aho_corasick.test.3.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/430\"\n\n#line 1 \"test/template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n#line 1 \"src/string/trie.hpp\"\ntemplate<int char_size>\
    \ struct TrieNode {\n   int nxt[char_size];\n   int exist;\n   vector<int> accept;\n\
    \n   TrieNode() : exist(0) { memset(nxt, -1, sizeof(nxt)); }\n};\n\ntemplate<int\
    \ char_size, int margin> struct Trie {\n   using Node = TrieNode<char_size>;\n\
    \n   vector<Node> nodes;\n   int root;\n   Trie() : root(0) { nodes.push_back(Node());\
    \ }\n\n   void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n   void update_child(int node, int child, int id) { ++nodes[node].exist;\
    \ }\n\n   void add(const string& str, int str_index, int node_index, int id) {\n\
    \      if(str_index == size(str)) {\n         update_direct(node_index, id);\n\
    \      } else {\n         const int c = str[str_index] - margin;\n         if(nodes[node_index].nxt[c]\
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
    \ const { return nodes[0].exist; }\n};\n#line 1 \"src/string/aho_corasick.hpp\"\
    \n// base: 822702\ntemplate<int char_size, int margin> struct AhoCorasick : Trie<char_size\
    \ + 1, margin> {\n   using Trie<char_size + 1, margin>::Trie;\n\n   const int\
    \ FAIL = char_size;\n   vector<int> correct;\n\n   void build(bool heavy = true)\
    \ {\n      correct.resize(this->nodes.size());\n      for(int i = 0; i < size(this->nodes);\
    \ ++i) { correct[i] = size(this->nodes[i].accept); }\n      queue<int> que;\n\
    \      for(int i = 0; i < char_size; ++i) {\n         if(~this->nodes[0].nxt[i])\
    \ {\n            this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;\n         \
    \   que.emplace(this->nodes[0].nxt[i]);\n         } else {\n            this->nodes[0].nxt[i]\
    \ = 0;\n         }\n      }\n      while(!que.empty()) {\n         auto& now =\
    \ this->nodes[que.front()];\n         int fail = now.nxt[FAIL];\n         correct[que.front()]\
    \ += correct[fail];\n         que.pop();\n         for(int i = 0; i < char_size;\
    \ i++) {\n            if(~now.nxt[i]) {\n               this->nodes[now.nxt[i]].nxt[FAIL]\
    \ = this->nodes[fail].nxt[i];\n               if(heavy) {\n                  auto&\
    \ u = this->nodes[now.nxt[i]].accept;\n                  auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                  vector<int> accept;\n                  set_union(all(u), all(v),\
    \ back_inserter(accept));\n                  u = accept;\n               }\n \
    \              que.emplace(now.nxt[i]);\n            } else {\n              \
    \ now.nxt[i] = this->nodes[fail].nxt[i];\n            }\n         }\n      }\n\
    \   }\n\n   vector<int> match(const char& c, int now = 0) {\n      vector<int>\
    \ res;\n      now = this->nodes[now].nxt[c - margin];\n      for(auto& v : this->nodes[now].accept)\
    \ res.push_back(v);\n      return res;\n   }  // 68ef6b\n\n   unordered_map<int,\
    \ int> match(const string& str, int now = 0) {\n      unordered_map<int, int>\
    \ res, visit_cnt;\n      for(auto& c : str) {\n         now = this->nodes[now].nxt[c\
    \ - margin];\n         visit_cnt[now]++;\n      }\n      for(auto& [now, cnt]\
    \ : visit_cnt) {\n         for(auto& v : this->nodes[now].accept) res[v] += cnt;\n\
    \      }\n      return res;\n   }  // 36fe6c\n\n   pair<ll, int> move(const char&\
    \ c, int now = 0) {\n      now = this->nodes[now].nxt[c - margin];\n      return\
    \ {correct[now], now};\n   }  // 43ccad\n\n   pair<ll, int> move(const string&\
    \ str, int now = 0) {\n      ll res = 0;\n      for(auto& c : str) {\n       \
    \  auto [cnt, nxt] = move(c, now);\n         res += cnt;\n         now = nxt;\n\
    \      }\n      return {res, now};\n   }  // b1949a\n};\n#line 6 \"test/string/aho_corasick.test.3.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   int M;\n   cin >> M;\n   AhoCorasick<26, 'A'> aho;\n   for(int i = 0;\
    \ i < M; i++) {\n      string s;\n      cin >> s;\n      aho.add(s);\n   }\n \
    \  aho.build();\n   cout << aho.move(S).first << endl;\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include \"test/template.hpp\"\
    \n#include \"src/string/trie.hpp\"\n#include \"src/string/aho_corasick.hpp\"\n\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n\
    \   int M;\n   cin >> M;\n   AhoCorasick<26, 'A'> aho;\n   for(int i = 0; i <\
    \ M; i++) {\n      string s;\n      cin >> s;\n      aho.add(s);\n   }\n   aho.build();\n\
    \   cout << aho.move(S).first << endl;\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/trie.hpp
  - src/string/aho_corasick.hpp
  isVerificationFile: true
  path: test/string/aho_corasick.test.3.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/aho_corasick.test.3.cpp
layout: document
redirect_from:
- /verify/test/string/aho_corasick.test.3.cpp
- /verify/test/string/aho_corasick.test.3.cpp.html
title: test/string/aho_corasick.test.3.cpp
---
