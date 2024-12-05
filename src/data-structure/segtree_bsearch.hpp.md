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
  bundledCode: "#line 1 \"src/data-structure/segtree_bsearch.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), class F> int max_right(segtree<S, op, e>& seg, int\
    \ l, F f) {\n   auto& _n = seg._n;\n   auto& size = seg.size;\n   auto& d = seg.d;\n\
    \   // assert(0 <= l && l <= _n);\n   // assert(f(e()));\n   if(l == _n) return\
    \ _n;\n   l += size;\n   S sm = e();\n   do {\n      while(l % 2 == 0) l >>= 1;\n\
    \      if(!f(op(sm, d[l]))) {\n         while(l < size) {\n            l = (2\
    \ * l);\n            if(f(op(sm, d[l]))) {\n               sm = op(sm, d[l]);\n\
    \               l++;\n            }\n         }\n         return l - size;\n \
    \     }\n      sm = op(sm, d[l]);\n      l++;\n   } while((l & -l) != l);\n  \
    \ return _n;\n}\n\ntemplate<class S, S (*op)(S, S), S (*e)(), class F> int min_left(segtree<S,\
    \ op, e>& seg, int r, F f) {\n   auto& _n = seg._n;\n   auto& size = seg.size;\n\
    \   auto& d = seg.d;\n   // assert(0 <= r && r <= _n);\n   // assert(f(e()));\n\
    \   if(r == 0) return 0;\n   r += size;\n   S sm = e();\n   do {\n      r--;\n\
    \      while(r > 1 && (r % 2)) r >>= 1;\n      if(!f(op(d[r], sm))) {\n      \
    \   while(r < size) {\n            r = (2 * r + 1);\n            if(f(op(d[r],\
    \ sm))) {\n               sm = op(d[r], sm);\n               r--;\n          \
    \  }\n         }\n         return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n   } while((r & -r) != r);\n   return 0;\n}\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), class F> int max_right(segtree<S,\
    \ op, e>& seg, int l, F f) {\n   auto& _n = seg._n;\n   auto& size = seg.size;\n\
    \   auto& d = seg.d;\n   // assert(0 <= l && l <= _n);\n   // assert(f(e()));\n\
    \   if(l == _n) return _n;\n   l += size;\n   S sm = e();\n   do {\n      while(l\
    \ % 2 == 0) l >>= 1;\n      if(!f(op(sm, d[l]))) {\n         while(l < size) {\n\
    \            l = (2 * l);\n            if(f(op(sm, d[l]))) {\n               sm\
    \ = op(sm, d[l]);\n               l++;\n            }\n         }\n         return\
    \ l - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n   } while((l & -l)\
    \ != l);\n   return _n;\n}\n\ntemplate<class S, S (*op)(S, S), S (*e)(), class\
    \ F> int min_left(segtree<S, op, e>& seg, int r, F f) {\n   auto& _n = seg._n;\n\
    \   auto& size = seg.size;\n   auto& d = seg.d;\n   // assert(0 <= r && r <= _n);\n\
    \   // assert(f(e()));\n   if(r == 0) return 0;\n   r += size;\n   S sm = e();\n\
    \   do {\n      r--;\n      while(r > 1 && (r % 2)) r >>= 1;\n      if(!f(op(d[r],\
    \ sm))) {\n         while(r < size) {\n            r = (2 * r + 1);\n        \
    \    if(f(op(d[r], sm))) {\n               sm = op(d[r], sm);\n              \
    \ r--;\n            }\n         }\n         return r + 1 - size;\n      }\n  \
    \    sm = op(d[r], sm);\n   } while((r & -r) != r);\n   return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree_bsearch.hpp
  requiredBy: []
  timestamp: '2024-12-05 18:17:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/segtree_bsearch.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree_bsearch.hpp
- /library/src/data-structure/segtree_bsearch.hpp.html
title: src/data-structure/segtree_bsearch.hpp
---
