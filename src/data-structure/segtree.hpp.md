---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segtree.test.2.cpp
    title: test/data-structure/segtree.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segtree.test.3.cpp
    title: test/data-structure/segtree.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segtree.test.cpp
    title: test/data-structure/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.test.2.cpp
    title: test/graph/tree/hld.test.2.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/segtree.hpp\"\n// base: bafcf8\nunsigned\
    \ int bit_ceil(unsigned int n) {\n   unsigned int x = 1;\n   while(x < (unsigned\
    \ int)(n)) x *= 2;\n   return x;\n}\nint countr_zero(unsigned int n) { return\
    \ __builtin_ctz(n); }\nconstexpr int countr_zero_constexpr(unsigned int n) {\n\
    \   int x = 0;\n   while(!(n & (1 << x))) x++;\n   return x;\n}\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n   public:\n   segtree() : segtree(0)\
    \ {}\n   explicit segtree(int n) : segtree(vector<S>(n, e())) {}\n   explicit\
    \ segtree(const vector<S>& v) : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned\
    \ int)(_n));\n      log = countr_zero((unsigned int)size);\n      d = vector<S>(2\
    \ * size, e());\n      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n     \
    \ for(int i = size - 1; i >= 1; i--) { update(i); }\n   }\n\n   void set(int p,\
    \ S x) {\n      p += size;\n      d[p] = x;\n      for(int i = 1; i <= log; i++)\
    \ update(p >> i);\n   }\n\n   S get(int p) const { return d[p + size]; }\n\n \
    \  S prod(int l, int r) const {\n      S sml = e(), smr = e();\n      l += size;\n\
    \      r += size;\n\n      while(l < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n\
    \         if(r & 1) smr = op(d[--r], smr);\n         l >>= 1;\n         r >>=\
    \ 1;\n      }\n      return op(sml, smr);\n   }\n\n   S all_prod() const { return\
    \ d[1]; }\n\n   template<class F> int max_right(int l, F f) {\n      if(l == _n)\
    \ return _n;\n      l += size;\n      S sm = e();\n      do {\n         while(l\
    \ % 2 == 0) l >>= 1;\n         if(!f(op(sm, d[l]))) {\n            while(l < size)\
    \ {\n               l = (2 * l);\n               if(f(op(sm, d[l]))) {\n     \
    \             sm = op(sm, d[l]);\n                  l++;\n               }\n \
    \           }\n            return l - size;\n         }\n         sm = op(sm,\
    \ d[l]);\n         l++;\n      } while((l & -l) != l);\n      return _n;\n   }\
    \  // faa03f\n\n   template<class F> int min_left(int r, F f) {\n      if(r ==\
    \ 0) return 0;\n      r += size;\n      S sm = e();\n      do {\n         r--;\n\
    \         while(r > 1 && (r % 2)) r >>= 1;\n         if(!f(op(d[r], sm))) {\n\
    \            while(r < size) {\n               r = (2 * r + 1);\n            \
    \   if(f(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n            \
    \      r--;\n               }\n            }\n            return r + 1 - size;\n\
    \         }\n         sm = op(d[r], sm);\n      } while((r & -r) != r);\n    \
    \  return 0;\n   }  // efa466\n\n   private:\n   int _n, size, log;\n   vector<S>\
    \ d;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n"
  code: "// base: bafcf8\nunsigned int bit_ceil(unsigned int n) {\n   unsigned int\
    \ x = 1;\n   while(x < (unsigned int)(n)) x *= 2;\n   return x;\n}\nint countr_zero(unsigned\
    \ int n) { return __builtin_ctz(n); }\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n   int x = 0;\n   while(!(n & (1 << x))) x++;\n   return x;\n}\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n   public:\n   segtree() : segtree(0)\
    \ {}\n   explicit segtree(int n) : segtree(vector<S>(n, e())) {}\n   explicit\
    \ segtree(const vector<S>& v) : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned\
    \ int)(_n));\n      log = countr_zero((unsigned int)size);\n      d = vector<S>(2\
    \ * size, e());\n      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n     \
    \ for(int i = size - 1; i >= 1; i--) { update(i); }\n   }\n\n   void set(int p,\
    \ S x) {\n      p += size;\n      d[p] = x;\n      for(int i = 1; i <= log; i++)\
    \ update(p >> i);\n   }\n\n   S get(int p) const { return d[p + size]; }\n\n \
    \  S prod(int l, int r) const {\n      S sml = e(), smr = e();\n      l += size;\n\
    \      r += size;\n\n      while(l < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n\
    \         if(r & 1) smr = op(d[--r], smr);\n         l >>= 1;\n         r >>=\
    \ 1;\n      }\n      return op(sml, smr);\n   }\n\n   S all_prod() const { return\
    \ d[1]; }\n\n   template<class F> int max_right(int l, F f) {\n      if(l == _n)\
    \ return _n;\n      l += size;\n      S sm = e();\n      do {\n         while(l\
    \ % 2 == 0) l >>= 1;\n         if(!f(op(sm, d[l]))) {\n            while(l < size)\
    \ {\n               l = (2 * l);\n               if(f(op(sm, d[l]))) {\n     \
    \             sm = op(sm, d[l]);\n                  l++;\n               }\n \
    \           }\n            return l - size;\n         }\n         sm = op(sm,\
    \ d[l]);\n         l++;\n      } while((l & -l) != l);\n      return _n;\n   }\
    \  // faa03f\n\n   template<class F> int min_left(int r, F f) {\n      if(r ==\
    \ 0) return 0;\n      r += size;\n      S sm = e();\n      do {\n         r--;\n\
    \         while(r > 1 && (r % 2)) r >>= 1;\n         if(!f(op(d[r], sm))) {\n\
    \            while(r < size) {\n               r = (2 * r + 1);\n            \
    \   if(f(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n            \
    \      r--;\n               }\n            }\n            return r + 1 - size;\n\
    \         }\n         sm = op(d[r], sm);\n      } while((r & -r) != r);\n    \
    \  return 0;\n   }  // efa466\n\n   private:\n   int _n, size, log;\n   vector<S>\
    \ d;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2025-02-25 04:14:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segtree.test.3.cpp
  - test/data-structure/segtree.test.2.cpp
  - test/data-structure/segtree.test.cpp
  - test/graph/tree/hld.test.2.cpp
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: src/data-structure/segtree.hpp
---
