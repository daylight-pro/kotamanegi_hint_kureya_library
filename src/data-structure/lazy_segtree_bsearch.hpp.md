---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy_segtree.test.2.cpp
    title: test/data-structure/lazy_segtree.test.2.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/lazy_segtree_bsearch.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F), F (*id)(), class G>\nint max_right(lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>& seg, int l, G g) {\n   auto& _n = seg._n;\n   auto& size = seg.size;\n\
    \   auto& d = seg.d;\n   auto& log = seg.log;\n   // assert(0 <= l && l <= _n);\n\
    \   // assert(g(e()));\n   if(l == _n) return _n;\n   l += size;\n   for(int i\
    \ = log; i >= 1; i--) seg.push(l >> i);\n   S sm = e();\n   do {\n      while(l\
    \ % 2 == 0) l >>= 1;\n      if(!g(op(sm, d[l]))) {\n         while(l < size) {\n\
    \            seg.push(l);\n            l = (2 * l);\n            if(g(op(sm, d[l])))\
    \ {\n               sm = op(sm, d[l]);\n               l++;\n            }\n \
    \        }\n         return l - size;\n      }\n      sm = op(sm, d[l]);\n   \
    \   l++;\n   } while((l & -l) != l);\n   return _n;\n}\n\ntemplate<class S, S\
    \ (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),\
    \ F (*id)(), class G>\nint min_left(lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>& seg, int r, G g) {\n   auto& _n = seg._n;\n   auto& size = seg.size;\n\
    \   auto& d = seg.d;\n   auto& log = seg.log;\n   // assert(0 <= r && r <= _n);\n\
    \   // assert(g(e()));\n   if(r == 0) return 0;\n   r += size;\n   for(int i =\
    \ log; i >= 1; i--) seg.push((r - 1) >> i);\n   S sm = e();\n   do {\n      r--;\n\
    \      while(r > 1 && (r % 2)) r >>= 1;\n      if(!g(op(d[r], sm))) {\n      \
    \   while(r < size) {\n            seg.push(r);\n            r = (2 * r + 1);\n\
    \            if(g(op(d[r], sm))) {\n               sm = op(d[r], sm);\n      \
    \         r--;\n            }\n         }\n         return r + 1 - size;\n   \
    \   }\n      sm = op(d[r], sm);\n   } while((r & -r) != r);\n   return 0;\n}\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)(), class G>\nint max_right(lazy_segtree<S, op,\
    \ e, F, mapping, composition, id>& seg, int l, G g) {\n   auto& _n = seg._n;\n\
    \   auto& size = seg.size;\n   auto& d = seg.d;\n   auto& log = seg.log;\n   //\
    \ assert(0 <= l && l <= _n);\n   // assert(g(e()));\n   if(l == _n) return _n;\n\
    \   l += size;\n   for(int i = log; i >= 1; i--) seg.push(l >> i);\n   S sm =\
    \ e();\n   do {\n      while(l % 2 == 0) l >>= 1;\n      if(!g(op(sm, d[l])))\
    \ {\n         while(l < size) {\n            seg.push(l);\n            l = (2\
    \ * l);\n            if(g(op(sm, d[l]))) {\n               sm = op(sm, d[l]);\n\
    \               l++;\n            }\n         }\n         return l - size;\n \
    \     }\n      sm = op(sm, d[l]);\n      l++;\n   } while((l & -l) != l);\n  \
    \ return _n;\n}\n\ntemplate<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F,\
    \ S), F (*composition)(F, F), F (*id)(), class G>\nint min_left(lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>& seg, int r, G g) {\n   auto& _n = seg._n;\n\
    \   auto& size = seg.size;\n   auto& d = seg.d;\n   auto& log = seg.log;\n   //\
    \ assert(0 <= r && r <= _n);\n   // assert(g(e()));\n   if(r == 0) return 0;\n\
    \   r += size;\n   for(int i = log; i >= 1; i--) seg.push((r - 1) >> i);\n   S\
    \ sm = e();\n   do {\n      r--;\n      while(r > 1 && (r % 2)) r >>= 1;\n   \
    \   if(!g(op(d[r], sm))) {\n         while(r < size) {\n            seg.push(r);\n\
    \            r = (2 * r + 1);\n            if(g(op(d[r], sm))) {\n           \
    \    sm = op(d[r], sm);\n               r--;\n            }\n         }\n    \
    \     return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n   } while((r &\
    \ -r) != r);\n   return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy_segtree_bsearch.hpp
  requiredBy: []
  timestamp: '2024-12-06 03:31:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/lazy_segtree.test.2.cpp
documentation_of: src/data-structure/lazy_segtree_bsearch.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy_segtree_bsearch.hpp
- /library/src/data-structure/lazy_segtree_bsearch.hpp.html
title: src/data-structure/lazy_segtree_bsearch.hpp
---
