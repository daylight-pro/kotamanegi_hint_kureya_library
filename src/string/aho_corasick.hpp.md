---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick.test.2.cpp
    title: test/string/aho_corasick.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick.test.3.cpp
    title: test/string/aho_corasick.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick.test.cpp
    title: test/string/aho_corasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/aho_corasick.hpp\"\n// base: 822702\ntemplate<int\
    \ char_size, int margin> struct AhoCorasick : Trie<char_size + 1, margin> {\n\
    \   using Trie<char_size + 1, margin>::Trie;\n\n   const int FAIL = char_size;\n\
    \   vector<int> correct;\n\n   void build(bool heavy = true) {\n      correct.resize(this->nodes.size());\n\
    \      for(int i = 0; i < size(this->nodes); ++i) { correct[i] = size(this->nodes[i].accept);\
    \ }\n      queue<int> que;\n      for(int i = 0; i < char_size; ++i) {\n     \
    \    if(~this->nodes[0].nxt[i]) {\n            this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n            que.emplace(this->nodes[0].nxt[i]);\n         } else {\n \
    \           this->nodes[0].nxt[i] = 0;\n         }\n      }\n      while(!que.empty())\
    \ {\n         auto& now = this->nodes[que.front()];\n         int fail = now.nxt[FAIL];\n\
    \         correct[que.front()] += correct[fail];\n         que.pop();\n      \
    \   for(int i = 0; i < char_size; i++) {\n            if(~now.nxt[i]) {\n    \
    \           this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];\n  \
    \             if(heavy) {\n                  auto& u = this->nodes[now.nxt[i]].accept;\n\
    \                  auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;\n \
    \                 vector<int> accept;\n                  set_union(all(u), all(v),\
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
    \      }\n      return {res, now};\n   }  // b1949a\n};\n"
  code: "// base: 822702\ntemplate<int char_size, int margin> struct AhoCorasick :\
    \ Trie<char_size + 1, margin> {\n   using Trie<char_size + 1, margin>::Trie;\n\
    \n   const int FAIL = char_size;\n   vector<int> correct;\n\n   void build(bool\
    \ heavy = true) {\n      correct.resize(this->nodes.size());\n      for(int i\
    \ = 0; i < size(this->nodes); ++i) { correct[i] = size(this->nodes[i].accept);\
    \ }\n      queue<int> que;\n      for(int i = 0; i < char_size; ++i) {\n     \
    \    if(~this->nodes[0].nxt[i]) {\n            this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n            que.emplace(this->nodes[0].nxt[i]);\n         } else {\n \
    \           this->nodes[0].nxt[i] = 0;\n         }\n      }\n      while(!que.empty())\
    \ {\n         auto& now = this->nodes[que.front()];\n         int fail = now.nxt[FAIL];\n\
    \         correct[que.front()] += correct[fail];\n         que.pop();\n      \
    \   for(int i = 0; i < char_size; i++) {\n            if(~now.nxt[i]) {\n    \
    \           this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];\n  \
    \             if(heavy) {\n                  auto& u = this->nodes[now.nxt[i]].accept;\n\
    \                  auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;\n \
    \                 vector<int> accept;\n                  set_union(all(u), all(v),\
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
    \      }\n      return {res, now};\n   }  // b1949a\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2024-12-09 18:01:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho_corasick.test.3.cpp
  - test/string/aho_corasick.test.2.cpp
  - test/string/aho_corasick.test.cpp
documentation_of: src/string/aho_corasick.hpp
layout: document
redirect_from:
- /library/src/string/aho_corasick.hpp
- /library/src/string/aho_corasick.hpp.html
title: src/string/aho_corasick.hpp
---
