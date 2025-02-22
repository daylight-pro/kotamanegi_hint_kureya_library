---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/LCS_alphabet.test.cpp
    title: test/algorithm/LCS_alphabet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/LCS_alphabet.hpp\"\nvector<uint64_t> _lcs(const\
    \ string &s, const string &t) {\n   int n = s.size();\n   int w = (n + 63) >>\
    \ 6;\n   vector<vector<uint64_t>> m(26, vector<uint64_t>(w));\n   for (int i =\
    \ 0; i < n; ++i) {\n      m[s[i] - 'A'][i >> 6] |= 1ULL << (i & 63);\n   }\n \
    \  vector<uint64_t> b(w);\n   for (auto &c : t) {\n      const auto &mc = m[c\
    \ - 'A'];\n      for (int i = 0, borrow = 0; i < w; ++i) {\n         uint64_t\
    \ x = mc[i] & ~b[i];\n         int nx = b[i] < x || (b[i] == x && borrow);\n \
    \        b[i] = (b[i] - x - borrow) & (mc[i] | b[i]);\n         borrow = nx;\n\
    \      }\n   }\n   return b;\n}\n\nvoid lcs(string s, string t, string &result)\
    \ {\n   if (s.size() <= 1 || t.size() <= 1) {\n      for (auto &i : s) {\n   \
    \      for (auto &j : t) {\n            if (i == j) {\n               result +=\
    \ i;\n               return;\n            }\n         }\n      }\n      return;\n\
    \   }\n   int n = s.size();\n   int l1 = t.size() / 2;\n   int l2 = (int)t.size()\
    \ - l1;\n   auto lef = _lcs(s, t.substr(0, l1));\n   reverse(s.begin(), s.end());\n\
    \   reverse(t.begin(), t.end());\n   auto rig = _lcs(s, t.substr(0, l2));\n  \
    \ reverse(s.begin(), s.end());\n   reverse(t.begin(), t.end());\n   int lc = 0,\
    \ rc = 0;\n   for (auto &i : rig) {\n      rc += __builtin_popcountll(i);\n  \
    \ }\n   int max_val = lc + rc;\n   int max_idx = 0;\n   for (int i = 0; i < n;\
    \ ++i) {\n      lc += (lef[i >> 6] >> (i & 63)) & 1;\n      rc -= (rig[(n - i\
    \ - 1) >> 6] >> ((n - i - 1) & 63)) & 1;\n      if (max_val < lc + rc) {\n   \
    \      max_val = lc + rc;\n         max_idx = i + 1;\n      }\n   }\n   if (max_val\
    \ == 0) {\n      return;\n   }\n   lcs(s.substr(0, max_idx), t.substr(0, l1),\
    \ result);\n   lcs(s.substr(max_idx), t.substr(l1), result);\n}\n"
  code: "vector<uint64_t> _lcs(const string &s, const string &t) {\n   int n = s.size();\n\
    \   int w = (n + 63) >> 6;\n   vector<vector<uint64_t>> m(26, vector<uint64_t>(w));\n\
    \   for (int i = 0; i < n; ++i) {\n      m[s[i] - 'A'][i >> 6] |= 1ULL << (i &\
    \ 63);\n   }\n   vector<uint64_t> b(w);\n   for (auto &c : t) {\n      const auto\
    \ &mc = m[c - 'A'];\n      for (int i = 0, borrow = 0; i < w; ++i) {\n       \
    \  uint64_t x = mc[i] & ~b[i];\n         int nx = b[i] < x || (b[i] == x && borrow);\n\
    \         b[i] = (b[i] - x - borrow) & (mc[i] | b[i]);\n         borrow = nx;\n\
    \      }\n   }\n   return b;\n}\n\nvoid lcs(string s, string t, string &result)\
    \ {\n   if (s.size() <= 1 || t.size() <= 1) {\n      for (auto &i : s) {\n   \
    \      for (auto &j : t) {\n            if (i == j) {\n               result +=\
    \ i;\n               return;\n            }\n         }\n      }\n      return;\n\
    \   }\n   int n = s.size();\n   int l1 = t.size() / 2;\n   int l2 = (int)t.size()\
    \ - l1;\n   auto lef = _lcs(s, t.substr(0, l1));\n   reverse(s.begin(), s.end());\n\
    \   reverse(t.begin(), t.end());\n   auto rig = _lcs(s, t.substr(0, l2));\n  \
    \ reverse(s.begin(), s.end());\n   reverse(t.begin(), t.end());\n   int lc = 0,\
    \ rc = 0;\n   for (auto &i : rig) {\n      rc += __builtin_popcountll(i);\n  \
    \ }\n   int max_val = lc + rc;\n   int max_idx = 0;\n   for (int i = 0; i < n;\
    \ ++i) {\n      lc += (lef[i >> 6] >> (i & 63)) & 1;\n      rc -= (rig[(n - i\
    \ - 1) >> 6] >> ((n - i - 1) & 63)) & 1;\n      if (max_val < lc + rc) {\n   \
    \      max_val = lc + rc;\n         max_idx = i + 1;\n      }\n   }\n   if (max_val\
    \ == 0) {\n      return;\n   }\n   lcs(s.substr(0, max_idx), t.substr(0, l1),\
    \ result);\n   lcs(s.substr(max_idx), t.substr(l1), result);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/LCS_alphabet.hpp
  requiredBy: []
  timestamp: '2025-02-21 15:28:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/LCS_alphabet.test.cpp
documentation_of: src/algorithm/LCS_alphabet.hpp
layout: document
redirect_from:
- /library/src/algorithm/LCS_alphabet.hpp
- /library/src/algorithm/LCS_alphabet.hpp.html
title: src/algorithm/LCS_alphabet.hpp
---
