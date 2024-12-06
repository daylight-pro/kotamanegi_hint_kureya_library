---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: src/data-structure/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: Modint
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/data-structure/lazy_segtree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll i = a; i < (b); i++)\n\
    #define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\nbool chmin(auto& a, auto\
    \ b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a\
    \ < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\nconst ll mod = 998244353;\n\
    struct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x +=\
    \ mod;\n   }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend\
    \ mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a,\
    \ mm b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a *\
    \ b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\
    \u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm&\
    \ a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) {\
    \ return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a =\
    \ a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv();\
    \ }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n   \
    \   mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n     \
    \    a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n};\n#line 1 \"\
    src/data-structure/lazy_segtree.hpp\"\n// base: 918715\nunsigned int bit_ceil(unsigned\
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
    \      if(k < size) lz[k] = composition(f, lz[k]);\n   }\n   void push(int k)\
    \ {\n      all_apply(2 * k, lz[k]);\n      all_apply(2 * k + 1, lz[k]);\n    \
    \  lz[k] = id();\n   }\n};\n#line 6 \"test/data-structure/lazy_segtree.test.cpp\"\
    \n\nstruct S {\n   mm val;\n   int sz;\n};\nusing F = pair<mm, mm>;\n\nconst F\
    \ ID = {mm(1), mm(0)};\n\nS op(S a, S b) { return {a.val + b.val, a.sz + b.sz};\
    \ }\nS e() { return {0, 0}; }\nS mapping(F f, S x) { return {f.first * x.val +\
    \ f.second * x.sz, x.sz}; }\nF composition(F f, F g) {\n   auto [fb, fc] = f;\n\
    \   auto [gb, gc] = g;\n   return {fb * gb, fc + fb * gc};\n}\nF id() { return\
    \ ID; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   int N, Q;\n\
    \   cin >> N >> Q;\n   vector<S> A(N);\n   rep(i, 0, N) {\n      int a;\n    \
    \  cin >> a;\n      A[i] = {mm(a), 1};\n   }\n   lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> seg(A);\n   while(Q--) {\n      int k;\n      cin >> k;\n \
    \     if(k == 0) {\n         int l, r, b, c;\n         cin >> l >> r >> b >> c;\n\
    \         seg.apply(l, r, {b, c});\n      } else {\n         int p;\n        \
    \ cin >> p;\n         cout << seg.get(p).val.x << '\\n';\n      }\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/data-structure/lazy_segtree.hpp\"\n\nstruct S {\n   mm val;\n   int sz;\n\
    };\nusing F = pair<mm, mm>;\n\nconst F ID = {mm(1), mm(0)};\n\nS op(S a, S b)\
    \ { return {a.val + b.val, a.sz + b.sz}; }\nS e() { return {0, 0}; }\nS mapping(F\
    \ f, S x) { return {f.first * x.val + f.second * x.sz, x.sz}; }\nF composition(F\
    \ f, F g) {\n   auto [fb, fc] = f;\n   auto [gb, gc] = g;\n   return {fb * gb,\
    \ fc + fb * gc};\n}\nF id() { return ID; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   int N, Q;\n   cin >> N >> Q;\n   vector<S> A(N);\n   rep(i, 0, N) {\n   \
    \   int a;\n      cin >> a;\n      A[i] = {mm(a), 1};\n   }\n   lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> seg(A);\n   while(Q--) {\n      int k;\n\
    \      cin >> k;\n      if(k == 0) {\n         int l, r, b, c;\n         cin >>\
    \ l >> r >> b >> c;\n         seg.apply(l, r, {b, c});\n      } else {\n     \
    \    int p;\n         cin >> p;\n         cout << seg.get(p).val.x << '\\n';\n\
    \      }\n   }\n}"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/data-structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/data-structure/lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '2024-12-06 14:52:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/lazy_segtree.test.cpp
- /verify/test/data-structure/lazy_segtree.test.cpp.html
title: test/data-structure/lazy_segtree.test.cpp
---
