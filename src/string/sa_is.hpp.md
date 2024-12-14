---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/sa_is.test.cpp
    title: test/string/sa_is.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/sa_is.hpp\"\nvector<int> sa_is(const vector<int>&\
    \ s, int upper) {\n   int n = s.size();\n   if(n == 0) return {};\n   if(n ==\
    \ 1) return {0};\n   if(n == 2) {\n      if(s[0] < s[1]) {\n         return {0,\
    \ 1};\n      } else {\n         return {1, 0};\n      }\n   }\n   vector<int>\
    \ sa(n);\n   vector<bool> ls(n);\n   for(int i = n - 2; i >= 0; i--) { ls[i] =\
    \ (s[i] == s[i + 1]) ? ls[i + 1] : s[i] < s[i + 1]; }\n   vector<int> sum_l(upper\
    \ + 1), sum_s(upper + 1);\n   for(int i = 0; i < n; i++) {\n      if(!ls[i]) sum_s[s[i]]++;\n\
    \      else sum_l[s[i] + 1]++;\n   }\n   for(int i = 0; i <= upper; i++) {\n \
    \     sum_s[i] += sum_l[i];\n      if(i < upper) sum_l[i + 1] += sum_s[i];\n \
    \  }\n\n   auto induce = [&](const vector<int>& lms) {\n      fill(all(sa), -1);\n\
    \      vector<int> buf(upper + 1);\n      copy(all(sum_s), buf.begin());\n   \
    \   for(auto d : lms) {\n         if(d == n) continue;\n         sa[buf[s[d]]++]\
    \ = d;\n      }\n      copy(all(sum_l), buf.begin());\n      sa[buf[s[n - 1]]++]\
    \ = n - 1;\n      for(int i = 0; i < n; i++) {\n         int v = sa[i];\n    \
    \     if(v >= 1 && !ls[v - 1]) sa[buf[s[v - 1]]++] = v - 1;\n      }\n      copy(all(sum_l),\
    \ buf.begin());\n      for(int i = n - 1; i >= 0; i--) {\n         int v = sa[i];\n\
    \         if(v >= 1 && ls[v - 1]) sa[--buf[s[v - 1] + 1]] = v - 1;\n      }\n\
    \   };\n\n   vector<int> lms_map(n + 1, -1);\n   int m = 0;\n   for(int i = 1;\
    \ i < n; i++) {\n      if(!ls[i - 1] && ls[i]) lms_map[i] = m++;\n   }\n   vector<int>\
    \ lms;\n   lms.reserve(m);\n   for(int i = 1; i < n; i++) {\n      if(!ls[i -\
    \ 1] && ls[i]) lms.push_back(i);\n   }\n   induce(lms);\n\n   if(m) {\n      vector<int>\
    \ sorted_lms;\n      sorted_lms.reserve(m);\n      for(int v : sa) {\n       \
    \  if(lms_map[v] != -1) sorted_lms.push_back(v);\n      }\n      vector<int> rec_s(m);\n\
    \      int rec_upper = 0;\n      rec_s[lms_map[sorted_lms[0]]] = 0;\n      for(int\
    \ i = 1; i < m; i++) {\n         int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \         int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n      \
    \   int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n         bool\
    \ same = true;\n         if(end_l - l != end_r - r) same = false;\n         else\
    \ {\n            while(l < end_l) {\n               if(s[l] != s[r]) break;\n\
    \               l++;\n               r++;\n            }\n            if(l ==\
    \ n || s[l] != s[r]) same = false;\n         }\n         if(!same) rec_upper++;\n\
    \         rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n      }\n\n      auto rec_sa\
    \ = sa_is(rec_s, rec_upper);\n\n      for(int i = 0; i < m; i++) { sorted_lms[i]\
    \ = lms[rec_sa[i]]; }\n      induce(sorted_lms);\n   }\n   return sa;\n}\n"
  code: "vector<int> sa_is(const vector<int>& s, int upper) {\n   int n = s.size();\n\
    \   if(n == 0) return {};\n   if(n == 1) return {0};\n   if(n == 2) {\n      if(s[0]\
    \ < s[1]) {\n         return {0, 1};\n      } else {\n         return {1, 0};\n\
    \      }\n   }\n   vector<int> sa(n);\n   vector<bool> ls(n);\n   for(int i =\
    \ n - 2; i >= 0; i--) { ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : s[i] < s[i +\
    \ 1]; }\n   vector<int> sum_l(upper + 1), sum_s(upper + 1);\n   for(int i = 0;\
    \ i < n; i++) {\n      if(!ls[i]) sum_s[s[i]]++;\n      else sum_l[s[i] + 1]++;\n\
    \   }\n   for(int i = 0; i <= upper; i++) {\n      sum_s[i] += sum_l[i];\n   \
    \   if(i < upper) sum_l[i + 1] += sum_s[i];\n   }\n\n   auto induce = [&](const\
    \ vector<int>& lms) {\n      fill(all(sa), -1);\n      vector<int> buf(upper +\
    \ 1);\n      copy(all(sum_s), buf.begin());\n      for(auto d : lms) {\n     \
    \    if(d == n) continue;\n         sa[buf[s[d]]++] = d;\n      }\n      copy(all(sum_l),\
    \ buf.begin());\n      sa[buf[s[n - 1]]++] = n - 1;\n      for(int i = 0; i <\
    \ n; i++) {\n         int v = sa[i];\n         if(v >= 1 && !ls[v - 1]) sa[buf[s[v\
    \ - 1]]++] = v - 1;\n      }\n      copy(all(sum_l), buf.begin());\n      for(int\
    \ i = n - 1; i >= 0; i--) {\n         int v = sa[i];\n         if(v >= 1 && ls[v\
    \ - 1]) sa[--buf[s[v - 1] + 1]] = v - 1;\n      }\n   };\n\n   vector<int> lms_map(n\
    \ + 1, -1);\n   int m = 0;\n   for(int i = 1; i < n; i++) {\n      if(!ls[i -\
    \ 1] && ls[i]) lms_map[i] = m++;\n   }\n   vector<int> lms;\n   lms.reserve(m);\n\
    \   for(int i = 1; i < n; i++) {\n      if(!ls[i - 1] && ls[i]) lms.push_back(i);\n\
    \   }\n   induce(lms);\n\n   if(m) {\n      vector<int> sorted_lms;\n      sorted_lms.reserve(m);\n\
    \      for(int v : sa) {\n         if(lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \      }\n      vector<int> rec_s(m);\n      int rec_upper = 0;\n      rec_s[lms_map[sorted_lms[0]]]\
    \ = 0;\n      for(int i = 1; i < m; i++) {\n         int l = sorted_lms[i - 1],\
    \ r = sorted_lms[i];\n         int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l]\
    \ + 1] : n;\n         int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] :\
    \ n;\n         bool same = true;\n         if(end_l - l != end_r - r) same = false;\n\
    \         else {\n            while(l < end_l) {\n               if(s[l] != s[r])\
    \ break;\n               l++;\n               r++;\n            }\n          \
    \  if(l == n || s[l] != s[r]) same = false;\n         }\n         if(!same) rec_upper++;\n\
    \         rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n      }\n\n      auto rec_sa\
    \ = sa_is(rec_s, rec_upper);\n\n      for(int i = 0; i < m; i++) { sorted_lms[i]\
    \ = lms[rec_sa[i]]; }\n      induce(sorted_lms);\n   }\n   return sa;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/sa_is.hpp
  requiredBy: []
  timestamp: '2024-12-15 00:31:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/sa_is.test.cpp
documentation_of: src/string/sa_is.hpp
layout: document
redirect_from:
- /library/src/string/sa_is.hpp
- /library/src/string/sa_is.hpp.html
title: src/string/sa_is.hpp
---
