---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_set.test.2.cpp
    title: test/data-structure/range_set.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_set.test.cpp
    title: test/data-structure/range_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/range_set.hpp\"\ntemplate<bool margeAdjacent\
    \ = true> struct range_set : public map<ll, ll> {\n   auto get(ll p) const {\n\
    \      auto it = upper_bound(p);\n      if(it == begin() || (--it)->second < p)\
    \ return end();\n      return it;\n   }\n\n   void insert(ll l, ll r) {\n    \
    \  auto itl = upper_bound(l), itr = upper_bound(r + margeAdjacent);\n      if(itl\
    \ != begin()) {\n         if((--itl)->second < l - margeAdjacent) ++itl;\n   \
    \   }\n      if(itl != itr) {\n         l = min(l, itl->first);\n         r =\
    \ max(r, prev(itr)->second);\n         erase(itl, itr);\n      }\n      (*this)[l]\
    \ = r;\n   }\n\n   void remove(ll l, ll r) {\n      auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n      if(itl != begin())\n         if((--itl)->second\
    \ < l) ++itl;\n      if(itl == itr) return;\n      int tl = min(l, itl->first),\
    \ tr = max(r, prev(itr)->second);\n      erase(itl, itr);\n      if(tl < l) (*this)[tl]\
    \ = l - 1;\n      if(r < tr) (*this)[r + 1] = tr;\n   }\n\n   bool same(ll p,\
    \ ll q) {\n      auto it = get(p);\n      return it != end() && it->first <= q\
    \ && q <= it->second;\n   }\n};\n"
  code: "template<bool margeAdjacent = true> struct range_set : public map<ll, ll>\
    \ {\n   auto get(ll p) const {\n      auto it = upper_bound(p);\n      if(it ==\
    \ begin() || (--it)->second < p) return end();\n      return it;\n   }\n\n   void\
    \ insert(ll l, ll r) {\n      auto itl = upper_bound(l), itr = upper_bound(r +\
    \ margeAdjacent);\n      if(itl != begin()) {\n         if((--itl)->second < l\
    \ - margeAdjacent) ++itl;\n      }\n      if(itl != itr) {\n         l = min(l,\
    \ itl->first);\n         r = max(r, prev(itr)->second);\n         erase(itl, itr);\n\
    \      }\n      (*this)[l] = r;\n   }\n\n   void remove(ll l, ll r) {\n      auto\
    \ itl = upper_bound(l), itr = upper_bound(r);\n      if(itl != begin())\n    \
    \     if((--itl)->second < l) ++itl;\n      if(itl == itr) return;\n      int\
    \ tl = min(l, itl->first), tr = max(r, prev(itr)->second);\n      erase(itl, itr);\n\
    \      if(tl < l) (*this)[tl] = l - 1;\n      if(r < tr) (*this)[r + 1] = tr;\n\
    \   }\n\n   bool same(ll p, ll q) {\n      auto it = get(p);\n      return it\
    \ != end() && it->first <= q && q <= it->second;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/range_set.hpp
  requiredBy: []
  timestamp: '2024-12-10 07:23:07+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range_set.test.cpp
  - test/data-structure/range_set.test.2.cpp
documentation_of: src/data-structure/range_set.hpp
layout: document
redirect_from:
- /library/src/data-structure/range_set.hpp
- /library/src/data-structure/range_set.hpp.html
title: src/data-structure/range_set.hpp
---
