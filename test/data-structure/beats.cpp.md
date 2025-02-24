---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/beats.test.cpp
    title: test/data-structure/beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/data-structure/beats.cpp\"\nunsigned int bit_ceil(unsigned\
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
    \ - 1) >> i);\n      }\n   }\n\n   template<class G> int max_right(int l, G g)\
    \ {\n      // assert(0 <= l && l <= _n);\n      // assert(g(e()));\n      if(l\
    \ == _n) return _n;\n      l += size;\n      for(int i = log; i >= 1; i--) push(l\
    \ >> i);\n      S sm = e();\n      do {\n         while(l % 2 == 0) l >>= 1;\n\
    \         if(!g(op(sm, d[l]))) {\n            while(l < size) {\n            \
    \   push(l);\n               l = (2 * l);\n               if(g(op(sm, d[l])))\
    \ {\n                  sm = op(sm, d[l]);\n                  l++;\n          \
    \     }\n            }\n            return l - size;\n         }\n         sm\
    \ = op(sm, d[l]);\n         l++;\n      } while((l & -l) != l);\n      return\
    \ _n;\n   }  // d93691\n\n   template<class G> int min_left(int r, G g) {\n  \
    \    // assert(0 <= r && r <= _n);\n      // assert(g(e()));\n      if(r == 0)\
    \ return 0;\n      r += size;\n      for(int i = log; i >= 1; i--) push((r - 1)\
    \ >> i);\n      S sm = e();\n      do {\n         r--;\n         while(r > 1 &&\
    \ (r % 2)) r >>= 1;\n         if(!g(op(d[r], sm))) {\n            while(r < size)\
    \ {\n               push(r);\n               r = (2 * r + 1);\n              \
    \ if(g(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n              \
    \    r--;\n               }\n            }\n            return r + 1 - size;\n\
    \         }\n         sm = op(d[r], sm);\n      } while((r & -r) != r);\n    \
    \  return 0;\n   }  // c9a7eb\n\n   private:\n   int _n, size, log;\n   vector<S>\
    \ d;\n   vector<F> lz;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n   void all_apply(int k, F f) {\n      d[k] = mapping(f, d[k]);\n\
    \      if(k < size) {\n         lz[k] = composition(f, lz[k]);\n         if(d[k].fail)\
    \ push(k), update(k);\n      }\n   }\n   void push(int k) {\n      all_apply(2\
    \ * k, lz[k]);\n      all_apply(2 * k + 1, lz[k]);\n      lz[k] = id();\n   }\n\
    };\n"
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
    \      if(((r >> i) << i) != r) update((r - 1) >> i);\n      }\n   }\n\n   template<class\
    \ G> int max_right(int l, G g) {\n      // assert(0 <= l && l <= _n);\n      //\
    \ assert(g(e()));\n      if(l == _n) return _n;\n      l += size;\n      for(int\
    \ i = log; i >= 1; i--) push(l >> i);\n      S sm = e();\n      do {\n       \
    \  while(l % 2 == 0) l >>= 1;\n         if(!g(op(sm, d[l]))) {\n            while(l\
    \ < size) {\n               push(l);\n               l = (2 * l);\n          \
    \     if(g(op(sm, d[l]))) {\n                  sm = op(sm, d[l]);\n          \
    \        l++;\n               }\n            }\n            return l - size;\n\
    \         }\n         sm = op(sm, d[l]);\n         l++;\n      } while((l & -l)\
    \ != l);\n      return _n;\n   }  // d93691\n\n   template<class G> int min_left(int\
    \ r, G g) {\n      // assert(0 <= r && r <= _n);\n      // assert(g(e()));\n \
    \     if(r == 0) return 0;\n      r += size;\n      for(int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n      S sm = e();\n      do {\n         r--;\n        \
    \ while(r > 1 && (r % 2)) r >>= 1;\n         if(!g(op(d[r], sm))) {\n        \
    \    while(r < size) {\n               push(r);\n               r = (2 * r + 1);\n\
    \               if(g(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n\
    \                  r--;\n               }\n            }\n            return r\
    \ + 1 - size;\n         }\n         sm = op(d[r], sm);\n      } while((r & -r)\
    \ != r);\n      return 0;\n   }  // c9a7eb\n\n   private:\n   int _n, size, log;\n\
    \   vector<S> d;\n   vector<F> lz;\n\n   void update(int k) { d[k] = op(d[2 *\
    \ k], d[2 * k + 1]); }\n   void all_apply(int k, F f) {\n      d[k] = mapping(f,\
    \ d[k]);\n      if(k < size) {\n         lz[k] = composition(f, lz[k]);\n    \
    \     if(d[k].fail) push(k), update(k);\n      }\n   }\n   void push(int k) {\n\
    \      all_apply(2 * k, lz[k]);\n      all_apply(2 * k + 1, lz[k]);\n      lz[k]\
    \ = id();\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: test/data-structure/beats.cpp
  requiredBy: []
  timestamp: '2025-02-24 01:54:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/beats.test.cpp
documentation_of: test/data-structure/beats.cpp
layout: document
redirect_from:
- /library/test/data-structure/beats.cpp
- /library/test/data-structure/beats.cpp.html
title: test/data-structure/beats.cpp
---
