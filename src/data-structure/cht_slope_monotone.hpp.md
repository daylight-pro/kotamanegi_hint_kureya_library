---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/cht_slope_monotone.test.cpp
    title: test/data-structure/cht_slope_monotone.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/cht_slope_monotone.hpp\"\ntemplate<typename\
    \ T> class CHT {\n   using P = pair<T, T>;\n\n   private:\n   int head;\n   vector<P>\
    \ lines;\n   // \u6700\u5C0F\u5024(\u6700\u5927\u5024)\u3092\u6C42\u3081\u308B\
    x\u304C\u5358\u8ABF\u3067\u3042\u308B\u304B\n   bool isMonotonicX;\n   function<bool(T\
    \ l, T r)> comp;\n\n   public:\n   // \u30AF\u30A8\u30EA\u304C\u5358\u8ABF\u3067\
    \u3042\u3063\u305F\u5834\u5408\u306Fflag = true\u3068\u3059\u308B\n   CHT(\n \
    \      bool flagX = false, function<bool(T l, T r)> compFunc = [](T l, T r) {\
    \ return l >= r; })\n       : isMonotonicX(flagX), comp(compFunc), head(0){};\n\
    \n   bool check(P l1, P l2, P l3) {\n      if(l1 < l3) swap(l1, l3);\n      return\
    \ (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) *\
    \ (l3.first - l2.first);\n   }\n\n   void add(T a, T b) {\n      P line(a, b);\n\
    \      while(lines.size() >= 2 + head && check(*(lines.end() - 2), lines.back(),\
    \ line)) lines.pop_back();\n      lines.emplace_back(line);\n   }\n\n   T f(int\
    \ i, T x) { return lines[i].first * x + lines[i].second; }\n\n   T f(P line, T\
    \ x) { return line.first * x + line.second; }\n\n   T get(T x) {\n      if(isMonotonicX)\
    \ {\n         while(lines.size() >= 2 + head && comp(f(head, x), f(head + 1, x)))\
    \ ++head;\n         return f(head, x);\n      } else {\n         int low = -1,\
    \ high = lines.size() - 1;\n         while(high - low > 1) {\n            int\
    \ mid = (high + low) / 2;\n            (comp(f(mid, x), f(mid + 1, x)) ? low :\
    \ high) = mid;\n         }\n         return f(high, x);\n      }\n   }\n};\n"
  code: "template<typename T> class CHT {\n   using P = pair<T, T>;\n\n   private:\n\
    \   int head;\n   vector<P> lines;\n   // \u6700\u5C0F\u5024(\u6700\u5927\u5024\
    )\u3092\u6C42\u3081\u308Bx\u304C\u5358\u8ABF\u3067\u3042\u308B\u304B\n   bool\
    \ isMonotonicX;\n   function<bool(T l, T r)> comp;\n\n   public:\n   // \u30AF\
    \u30A8\u30EA\u304C\u5358\u8ABF\u3067\u3042\u3063\u305F\u5834\u5408\u306Fflag =\
    \ true\u3068\u3059\u308B\n   CHT(\n       bool flagX = false, function<bool(T\
    \ l, T r)> compFunc = [](T l, T r) { return l >= r; })\n       : isMonotonicX(flagX),\
    \ comp(compFunc), head(0){};\n\n   bool check(P l1, P l2, P l3) {\n      if(l1\
    \ < l3) swap(l1, l3);\n      return (l3.second - l2.second) * (l2.first - l1.first)\
    \ >= (l2.second - l1.second) * (l3.first - l2.first);\n   }\n\n   void add(T a,\
    \ T b) {\n      P line(a, b);\n      while(lines.size() >= 2 + head && check(*(lines.end()\
    \ - 2), lines.back(), line)) lines.pop_back();\n      lines.emplace_back(line);\n\
    \   }\n\n   T f(int i, T x) { return lines[i].first * x + lines[i].second; }\n\
    \n   T f(P line, T x) { return line.first * x + line.second; }\n\n   T get(T x)\
    \ {\n      if(isMonotonicX) {\n         while(lines.size() >= 2 + head && comp(f(head,\
    \ x), f(head + 1, x))) ++head;\n         return f(head, x);\n      } else {\n\
    \         int low = -1, high = lines.size() - 1;\n         while(high - low >\
    \ 1) {\n            int mid = (high + low) / 2;\n            (comp(f(mid, x),\
    \ f(mid + 1, x)) ? low : high) = mid;\n         }\n         return f(high, x);\n\
    \      }\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/cht_slope_monotone.hpp
  requiredBy: []
  timestamp: '2025-02-24 10:33:49+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/cht_slope_monotone.test.cpp
documentation_of: src/data-structure/cht_slope_monotone.hpp
layout: document
redirect_from:
- /library/src/data-structure/cht_slope_monotone.hpp
- /library/src/data-structure/cht_slope_monotone.hpp.html
title: src/data-structure/cht_slope_monotone.hpp
---
