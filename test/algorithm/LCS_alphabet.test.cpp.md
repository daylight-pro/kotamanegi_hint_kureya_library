---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/LCS_alphabet.hpp
    title: src/algorithm/LCS_alphabet.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://www.acmicpc.net/problem/18440
  bundledCode: "#line 1 \"test/algorithm/LCS_alphabet.test.cpp\"\n// https://www.acmicpc.net/problem/18440\
    \ AC\u78BA\u8A8D\u6E08\u307F\n\n/*\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n\nvector<uint64_t> _lcs(const string\
    \ &s, const string &t) {\n   int n = s.size();\n   int w = (n + 63) >> 6;\n  \
    \ vector<vector<uint64_t>> m(26, vector<uint64_t>(w));\n   for (int i = 0; i <\
    \ n; ++i) {\n      m[s[i] - 'A'][i >> 6] |= 1ULL << (i & 63);\n   }\n   vector<uint64_t>\
    \ b(w);\n   for (auto &c : t) {\n      const auto &mc = m[c - 'A'];\n      for\
    \ (int i = 0, borrow = 0; i < w; ++i) {\n         uint64_t x = mc[i] & ~b[i];\n\
    \         int nx = b[i] < x || (b[i] == x && borrow);\n         b[i] = (b[i] -\
    \ x - borrow) & (mc[i] | b[i]);\n         borrow = nx;\n      }\n   }\n   return\
    \ b;\n}\n\nvoid lcs(string s, string t, string &result) {\n   if (s.size() <=\
    \ 1 || t.size() <= 1) {\n      for (auto &i : s) {\n         for (auto &j : t)\
    \ {\n            if (i == j) {\n               result += i;\n               return;\n\
    \            }\n         }\n      }\n      return;\n   }\n   int n = s.size();\n\
    \   int l1 = t.size() / 2;\n   int l2 = (int)t.size() - l1;\n   auto lef = _lcs(s,\
    \ t.substr(0, l1));\n   reverse(s.begin(), s.end());\n   reverse(t.begin(), t.end());\n\
    \   auto rig = _lcs(s, t.substr(0, l2));\n   reverse(s.begin(), s.end());\n  \
    \ reverse(t.begin(), t.end());\n   int lc = 0, rc = 0;\n   for (auto &i : rig)\
    \ {\n      rc += __builtin_popcountll(i);\n   }\n   int max_val = lc + rc;\n \
    \  int max_idx = 0;\n   for (int i = 0; i < n; ++i) {\n      lc += (lef[i >> 6]\
    \ >> (i & 63)) & 1;\n      rc -= (rig[(n - i - 1) >> 6] >> ((n - i - 1) & 63))\
    \ & 1;\n      if (max_val < lc + rc) {\n         max_val = lc + rc;\n        \
    \ max_idx = i + 1;\n      }\n   }\n   if (max_val == 0) {\n      return;\n   }\n\
    \   lcs(s.substr(0, max_idx), t.substr(0, l1), result);\n   lcs(s.substr(max_idx),\
    \ t.substr(l1), result);\n}\n\nint main() {\n   cin.tie(0);       \n   ios::sync_with_stdio(false);\n\
    \   string s, t;\n   cin >> s >> t;\n   string ans;\n   lcs(s, t, ans);\n   cout\
    \ << ans.size() << endl;\n   cout << ans << endl;\n   return 0;\n}\n*/\n\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/LCS_alphabet.hpp\"\
    \nvector<uint64_t> _lcs(const string& s, const string& t) {\n   int n = s.size();\n\
    \   int w = (n + 63) >> 6;\n   vector<vector<uint64_t>> m(26, vector<uint64_t>(w));\n\
    \   for(int i = 0; i < n; ++i) { m[s[i] - 'A'][i >> 6] |= 1ULL << (i & 63); }\n\
    \   vector<uint64_t> b(w);\n   for(auto& c : t) {\n      const auto& mc = m[c\
    \ - 'A'];\n      for(int i = 0, borrow = 0; i < w; ++i) {\n         uint64_t x\
    \ = mc[i] & ~b[i];\n         int nx = b[i] < x || (b[i] == x && borrow);\n   \
    \      b[i] = (b[i] - x - borrow) & (mc[i] | b[i]);\n         borrow = nx;\n \
    \     }\n   }\n   return b;\n}\n\nvoid lcs(string s, string t, string& result)\
    \ {\n   if(s.size() <= 1 || t.size() <= 1) {\n      for(auto& i : s) {\n     \
    \    for(auto& j : t) {\n            if(i == j) {\n               result += i;\n\
    \               return;\n            }\n         }\n      }\n      return;\n \
    \  }\n   int n = s.size();\n   int l1 = t.size() / 2;\n   int l2 = (int)t.size()\
    \ - l1;\n   auto lef = _lcs(s, t.substr(0, l1));\n   reverse(s.begin(), s.end());\n\
    \   reverse(t.begin(), t.end());\n   auto rig = _lcs(s, t.substr(0, l2));\n  \
    \ reverse(s.begin(), s.end());\n   reverse(t.begin(), t.end());\n   int lc = 0,\
    \ rc = 0;\n   for(auto& i : rig) { rc += __builtin_popcountll(i); }\n   int max_val\
    \ = lc + rc;\n   int max_idx = 0;\n   for(int i = 0; i < n; ++i) {\n      lc +=\
    \ (lef[i >> 6] >> (i & 63)) & 1;\n      rc -= (rig[(n - i - 1) >> 6] >> ((n -\
    \ i - 1) & 63)) & 1;\n      if(max_val < lc + rc) {\n         max_val = lc + rc;\n\
    \         max_idx = i + 1;\n      }\n   }\n   if(max_val == 0) { return; }\n \
    \  lcs(s.substr(0, max_idx), t.substr(0, l1), result);\n   lcs(s.substr(max_idx),\
    \ t.substr(l1), result);\n}\n#line 90 \"test/algorithm/LCS_alphabet.test.cpp\"\
    \n\nint main() { puts(\"Hello World\"); }\n"
  code: "// https://www.acmicpc.net/problem/18440 AC\u78BA\u8A8D\u6E08\u307F\n\n/*\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll\
    \ INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto\
    \ b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a\
    \ < b ? a = b, 1 : 0; }\n\nvector<uint64_t> _lcs(const string &s, const string\
    \ &t) {\n   int n = s.size();\n   int w = (n + 63) >> 6;\n   vector<vector<uint64_t>>\
    \ m(26, vector<uint64_t>(w));\n   for (int i = 0; i < n; ++i) {\n      m[s[i]\
    \ - 'A'][i >> 6] |= 1ULL << (i & 63);\n   }\n   vector<uint64_t> b(w);\n   for\
    \ (auto &c : t) {\n      const auto &mc = m[c - 'A'];\n      for (int i = 0, borrow\
    \ = 0; i < w; ++i) {\n         uint64_t x = mc[i] & ~b[i];\n         int nx =\
    \ b[i] < x || (b[i] == x && borrow);\n         b[i] = (b[i] - x - borrow) & (mc[i]\
    \ | b[i]);\n         borrow = nx;\n      }\n   }\n   return b;\n}\n\nvoid lcs(string\
    \ s, string t, string &result) {\n   if (s.size() <= 1 || t.size() <= 1) {\n \
    \     for (auto &i : s) {\n         for (auto &j : t) {\n            if (i ==\
    \ j) {\n               result += i;\n               return;\n            }\n \
    \        }\n      }\n      return;\n   }\n   int n = s.size();\n   int l1 = t.size()\
    \ / 2;\n   int l2 = (int)t.size() - l1;\n   auto lef = _lcs(s, t.substr(0, l1));\n\
    \   reverse(s.begin(), s.end());\n   reverse(t.begin(), t.end());\n   auto rig\
    \ = _lcs(s, t.substr(0, l2));\n   reverse(s.begin(), s.end());\n   reverse(t.begin(),\
    \ t.end());\n   int lc = 0, rc = 0;\n   for (auto &i : rig) {\n      rc += __builtin_popcountll(i);\n\
    \   }\n   int max_val = lc + rc;\n   int max_idx = 0;\n   for (int i = 0; i <\
    \ n; ++i) {\n      lc += (lef[i >> 6] >> (i & 63)) & 1;\n      rc -= (rig[(n -\
    \ i - 1) >> 6] >> ((n - i - 1) & 63)) & 1;\n      if (max_val < lc + rc) {\n \
    \        max_val = lc + rc;\n         max_idx = i + 1;\n      }\n   }\n   if (max_val\
    \ == 0) {\n      return;\n   }\n   lcs(s.substr(0, max_idx), t.substr(0, l1),\
    \ result);\n   lcs(s.substr(max_idx), t.substr(l1), result);\n}\n\nint main()\
    \ {\n   cin.tie(0);       \n   ios::sync_with_stdio(false);\n   string s, t;\n\
    \   cin >> s >> t;\n   string ans;\n   lcs(s, t, ans);\n   cout << ans.size()\
    \ << endl;\n   cout << ans << endl;\n   return 0;\n}\n*/\n\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/algorithm/LCS_alphabet.hpp\"\n\nint main()\
    \ { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/algorithm/LCS_alphabet.hpp
  isVerificationFile: true
  path: test/algorithm/LCS_alphabet.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/LCS_alphabet.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/LCS_alphabet.test.cpp
- /verify/test/algorithm/LCS_alphabet.test.cpp.html
title: test/algorithm/LCS_alphabet.test.cpp
---
