---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy_segtree.test.2.cpp
    title: test/data-structure/lazy_segtree.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy_segtree.test.cpp
    title: test/data-structure/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/lazy_segtree.hpp\"\nunsigned int bit_ceil(unsigned\
    \ int n) {\n   unsigned int x = 1;\n   while(x < (unsigned int)(n)) x *= 2;\n\
    \   return x;\n}\nint countr_zero(unsigned int n) { return __builtin_ctz(n); }\n\
    constexpr int countr_zero_constexpr(unsigned int n) {\n   int x = 0;\n   while(!(n\
    \ & (1 << x))) x++;\n   return x;\n}\ntemplate<class S, S (*op)(S, S), S (*e)(),\
    \ class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct lazy_segtree\
    \ {\n   public:\n   lazy_segtree() : lazy_segtree(0) {}\n   explicit lazy_segtree(int\
    \ n) : lazy_segtree(vector<S>(n, e())) {}\n   explicit lazy_segtree(const vector<S>&\
    \ v) : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned int)(_n));\n\
    \      log = countr_zero((unsigned int)size);\n      d = vector<S>(2 * size, e());\n\
    \      lz = vector<F>(size, id());\n      for(int i = 0; i < _n; i++) d[size +\
    \ i] = v[i];\n      for(int i = size - 1; i >= 1; i--) { update(i); }\n   }\n\
    \   void set(int p, S x) {\n      // assert(0 <= p && p < _n);\n      p += size;\n\
    \      for(int i = log; i >= 1; i--) push(p >> i);\n      d[p] = x;\n      for(int\
    \ i = 1; i <= log; i++) update(p >> i);\n   }\n\n   S get(int p) {\n      // assert(0\
    \ <= p && p < _n);\n      p += size;\n      for(int i = log; i >= 1; i--) push(p\
    \ >> i);\n      return d[p];\n   }\n\n   S prod(int l, int r) {\n      // assert(0\
    \ <= l && l <= r && r <= _n);\n      if(l == r) return e();\n\n      l += size;\n\
    \      r += size;\n\n      for(int i = log; i >= 1; i--) {\n         if(((l >>\
    \ i) << i) != l) push(l >> i);\n         if(((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n      }\n\n      S sml = e(), smr = e();\n      while(l < r) {\n   \
    \      if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr = op(d[--r], smr);\n\
    \         l >>= 1;\n         r >>= 1;\n      }\n\n      return op(sml, smr);\n\
    \   }\n\n   void apply(int l, int r, F f) {\n      assert(0 <= l && l <= r &&\
    \ r <= _n);\n      if(l == r) return;\n\n      l += size;\n      r += size;\n\n\
    \      for(int i = log; i >= 1; i--) {\n         if(((l >> i) << i) != l) push(l\
    \ >> i);\n         if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n\n \
    \     {\n         int l2 = l, r2 = r;\n         while(l < r) {\n            if(l\
    \ & 1) all_apply(l++, f);\n            if(r & 1) all_apply(--r, f);\n        \
    \    l >>= 1;\n            r >>= 1;\n         }\n         l = l2;\n         r\
    \ = r2;\n      }\n\n      for(int i = 1; i <= log; i++) {\n         if(((l >>\
    \ i) << i) != l) update(l >> i);\n         if(((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n      }\n   }\n\n   int _n, size, log;\n   std::vector<S> d;\n\
    \   std::vector<F> lz;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n   void all_apply(int k, F f) {\n      d[k] = mapping(f, d[k]);\n\
    \      if(k < size) lz[k] = composition(f, lz[k]);\n   }\n   void push(int k)\
    \ {\n      all_apply(2 * k, lz[k]);\n      all_apply(2 * k + 1, lz[k]);\n    \
    \  lz[k] = id();\n   }\n};\n"
  code: "unsigned int bit_ceil(unsigned int n) {\n   unsigned int x = 1;\n   while(x\
    \ < (unsigned int)(n)) x *= 2;\n   return x;\n}\nint countr_zero(unsigned int\
    \ n) { return __builtin_ctz(n); }\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n   int x = 0;\n   while(!(n & (1 << x))) x++;\n   return x;\n}\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F), F (*id)()>\nstruct lazy_segtree {\n   public:\n   lazy_segtree() : lazy_segtree(0)\
    \ {}\n   explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}\n \
    \  explicit lazy_segtree(const vector<S>& v) : _n(int(v.size())) {\n      size\
    \ = (int)bit_ceil((unsigned int)(_n));\n      log = countr_zero((unsigned int)size);\n\
    \      d = vector<S>(2 * size, e());\n      lz = vector<F>(size, id());\n    \
    \  for(int i = 0; i < _n; i++) d[size + i] = v[i];\n      for(int i = size - 1;\
    \ i >= 1; i--) { update(i); }\n   }\n   void set(int p, S x) {\n      // assert(0\
    \ <= p && p < _n);\n      p += size;\n      for(int i = log; i >= 1; i--) push(p\
    \ >> i);\n      d[p] = x;\n      for(int i = 1; i <= log; i++) update(p >> i);\n\
    \   }\n\n   S get(int p) {\n      // assert(0 <= p && p < _n);\n      p += size;\n\
    \      for(int i = log; i >= 1; i--) push(p >> i);\n      return d[p];\n   }\n\
    \n   S prod(int l, int r) {\n      // assert(0 <= l && l <= r && r <= _n);\n \
    \     if(l == r) return e();\n\n      l += size;\n      r += size;\n\n      for(int\
    \ i = log; i >= 1; i--) {\n         if(((l >> i) << i) != l) push(l >> i);\n \
    \        if(((r >> i) << i) != r) push((r - 1) >> i);\n      }\n\n      S sml\
    \ = e(), smr = e();\n      while(l < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n\
    \         if(r & 1) smr = op(d[--r], smr);\n         l >>= 1;\n         r >>=\
    \ 1;\n      }\n\n      return op(sml, smr);\n   }\n\n   void apply(int l, int\
    \ r, F f) {\n      assert(0 <= l && l <= r && r <= _n);\n      if(l == r) return;\n\
    \n      l += size;\n      r += size;\n\n      for(int i = log; i >= 1; i--) {\n\
    \         if(((l >> i) << i) != l) push(l >> i);\n         if(((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n      }\n\n      {\n         int l2 = l, r2 = r;\n\
    \         while(l < r) {\n            if(l & 1) all_apply(l++, f);\n         \
    \   if(r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \         }\n         l = l2;\n         r = r2;\n      }\n\n      for(int i =\
    \ 1; i <= log; i++) {\n         if(((l >> i) << i) != l) update(l >> i);\n   \
    \      if(((r >> i) << i) != r) update((r - 1) >> i);\n      }\n   }\n\n   int\
    \ _n, size, log;\n   std::vector<S> d;\n   std::vector<F> lz;\n\n   void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n   void all_apply(int k, F f) {\n\
    \      d[k] = mapping(f, d[k]);\n      if(k < size) lz[k] = composition(f, lz[k]);\n\
    \   }\n   void push(int k) {\n      all_apply(2 * k, lz[k]);\n      all_apply(2\
    \ * k + 1, lz[k]);\n      lz[k] = id();\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2024-12-06 03:31:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/lazy_segtree.test.2.cpp
  - test/data-structure/lazy_segtree.test.cpp
documentation_of: src/data-structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy_segtree.hpp
- /library/src/data-structure/lazy_segtree.hpp.html
title: src/data-structure/lazy_segtree.hpp
---
