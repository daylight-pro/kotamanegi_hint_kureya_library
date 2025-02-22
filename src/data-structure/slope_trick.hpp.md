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
  bundledCode: "#line 1 \"src/data-structure/slope_trick.hpp\"\ntemplate <typename\
    \ T>\nclass SlopeTrick {\n   T min_f;\n   priority_queue<T> left;\n   priority_queue<T,\
    \ vector<T>, greater<>> right;\n   T l_shift, r_shift;\npublic:\n   SlopeTrick()\
    \ : min_f(0), l_shift(0), r_shift(0) {}\n   T get_min() const { return min_f;\
    \ }\n   void add_all(const T &a) { min_f += a; }\n   void add_a_minus_x(const\
    \ T &a) {\n      if(right.empty() || a < right.top() + r_shift) {\n         left.push(a\
    \ - l_shift);\n      } else {\n         min_f += a - right.top() - r_shift;\n\
    \         left.push(right.top() + r_shift - l_shift);\n         right.pop();\n\
    \         right.push(a - r_shift);\n      }\n   }\n   void add_x_minus_a(const\
    \ T &a) {\n      if(left.empty() || left.top() + l_shift < a) {\n         right.push(a\
    \ - r_shift);\n      } else {\n         min_f += left.top() + l_shift - a;\n \
    \        right.push(left.top() + l_shift - r_shift);\n         left.pop();\n \
    \        left.push(a - l_shift);\n      }\n   }\n   void add_abs(const T &a) {\n\
    \      add_a_minus_x(a);\n      add_x_minus_a(a);\n   }\n   void clear_right()\
    \ {\n      while(!right.empty()) right.pop();\n   }\n   void clear_left() {\n\
    \      while(!left.empty()) left.pop();\n   }\n   void shift(const T &a) {\n \
    \     l_shift += a;\n      r_shift += a;\n   }\n   void shift(const T &a, const\
    \ T &b) {\n      l_shift += a;\n      r_shift += b;\n   }\n};\n"
  code: "template <typename T>\nclass SlopeTrick {\n   T min_f;\n   priority_queue<T>\
    \ left;\n   priority_queue<T, vector<T>, greater<>> right;\n   T l_shift, r_shift;\n\
    public:\n   SlopeTrick() : min_f(0), l_shift(0), r_shift(0) {}\n   T get_min()\
    \ const { return min_f; }\n   void add_all(const T &a) { min_f += a; }\n   void\
    \ add_a_minus_x(const T &a) {\n      if(right.empty() || a < right.top() + r_shift)\
    \ {\n         left.push(a - l_shift);\n      } else {\n         min_f += a - right.top()\
    \ - r_shift;\n         left.push(right.top() + r_shift - l_shift);\n         right.pop();\n\
    \         right.push(a - r_shift);\n      }\n   }\n   void add_x_minus_a(const\
    \ T &a) {\n      if(left.empty() || left.top() + l_shift < a) {\n         right.push(a\
    \ - r_shift);\n      } else {\n         min_f += left.top() + l_shift - a;\n \
    \        right.push(left.top() + l_shift - r_shift);\n         left.pop();\n \
    \        left.push(a - l_shift);\n      }\n   }\n   void add_abs(const T &a) {\n\
    \      add_a_minus_x(a);\n      add_x_minus_a(a);\n   }\n   void clear_right()\
    \ {\n      while(!right.empty()) right.pop();\n   }\n   void clear_left() {\n\
    \      while(!left.empty()) left.pop();\n   }\n   void shift(const T &a) {\n \
    \     l_shift += a;\n      r_shift += a;\n   }\n   void shift(const T &a, const\
    \ T &b) {\n      l_shift += a;\n      r_shift += b;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2025-02-21 16:47:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/slope_trick.hpp
layout: document
redirect_from:
- /library/src/data-structure/slope_trick.hpp
- /library/src/data-structure/slope_trick.hpp.html
title: src/data-structure/slope_trick.hpp
---
