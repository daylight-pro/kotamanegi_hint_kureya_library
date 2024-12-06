---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segtree.hpp
    title: src/data-structure/segtree.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/data-structure/segtree.test.3.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/segtree.hpp\"\
    \n// base: bafcf8\nunsigned int bit_ceil(unsigned int n) {\n   unsigned int x\
    \ = 1;\n   while(x < (unsigned int)(n)) x *= 2;\n   return x;\n}\nint countr_zero(unsigned\
    \ int n) { return __builtin_ctz(n); }\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n   int x = 0;\n   while(!(n & (1 << x))) x++;\n   return x;\n}\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n   public:\n   segtree() : segtree(0)\
    \ {}\n   explicit segtree(int n) : segtree(vector<S>(n, e())) {}\n   explicit\
    \ segtree(const vector<S>& v) : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned\
    \ int)(_n));\n      log = countr_zero((unsigned int)size);\n      d = vector<S>(2\
    \ * size, e());\n      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n     \
    \ for(int i = size - 1; i >= 1; i--) { update(i); }\n   }\n\n   void set(int p,\
    \ S x) {\n      // assert(0 <= p && p < _n);\n      p += size;\n      d[p] = x;\n\
    \      for(int i = 1; i <= log; i++) update(p >> i);\n   }\n\n   S get(int p)\
    \ const {\n      // assert(0 <= p && p < _n);\n      return d[p + size];\n   }\n\
    \n   S prod(int l, int r) const {\n      // assert(0 <= l && l <= r && r <= _n);\n\
    \      S sml = e(), smr = e();\n      l += size;\n      r += size;\n\n      while(l\
    \ < r) {\n         if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr =\
    \ op(d[--r], smr);\n         l >>= 1;\n         r >>= 1;\n      }\n      return\
    \ op(sml, smr);\n   }\n\n   S all_prod() const { return d[1]; }\n\n   template<class\
    \ F> int max_right(int l, F f) {\n      // assert(0 <= l && l <= _n);\n      //\
    \ assert(f(e()));\n      if(l == _n) return _n;\n      l += size;\n      S sm\
    \ = e();\n      do {\n         while(l % 2 == 0) l >>= 1;\n         if(!f(op(sm,\
    \ d[l]))) {\n            while(l < size) {\n               l = (2 * l);\n    \
    \           if(f(op(sm, d[l]))) {\n                  sm = op(sm, d[l]);\n    \
    \              l++;\n               }\n            }\n            return l - size;\n\
    \         }\n         sm = op(sm, d[l]);\n         l++;\n      } while((l & -l)\
    \ != l);\n      return _n;\n   }  // faa03f\n\n   template<class F> int min_left(int\
    \ r, F f) {\n      // assert(0 <= r && r <= _n);\n      // assert(f(e()));\n \
    \     if(r == 0) return 0;\n      r += size;\n      S sm = e();\n      do {\n\
    \         r--;\n         while(r > 1 && (r % 2)) r >>= 1;\n         if(!f(op(d[r],\
    \ sm))) {\n            while(r < size) {\n               r = (2 * r + 1);\n  \
    \             if(f(op(d[r], sm))) {\n                  sm = op(d[r], sm);\n  \
    \                r--;\n               }\n            }\n            return r +\
    \ 1 - size;\n         }\n         sm = op(d[r], sm);\n      } while((r & -r) !=\
    \ r);\n      return 0;\n   }  // efa466\n\n   private:\n   int _n, size, log;\n\
    \   vector<S> d;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]);\
    \ }\n};\n#line 5 \"test/data-structure/segtree.test.3.cpp\"\n\nll op(ll a, ll\
    \ b) { return min(a, b); }\nll e() { return 1e9 + 100; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   vector<ll> A{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};\n   segtree<ll, op, e> seg(A);\n\
    \   assert(seg.prod(0, 11) == 1);\n   assert(seg.min_left(11, [](ll x) { return\
    \ x >= 2; }) == 4);\n   assert(seg.max_right(0, [](ll x) { return x > 0; }) ==\
    \ 11);\n   seg.set(3, 0);\n   assert(seg.min_left(11, [](ll x) { return x >= 2;\
    \ }) == 4);\n   assert(seg.max_right(0, [](ll x) { return x >= 0; }) == 11);\n\
    \   assert(seg.max_right(0, [](ll x) { return x > 0; }) == 3);\n   cout << \"\
    Hello World\" << endl;\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/segtree.hpp\"\
    \n\nll op(ll a, ll b) { return min(a, b); }\nll e() { return 1e9 + 100; }\n\n\
    int main() {\n   cin.tie(0)->sync_with_stdio(0);\n   vector<ll> A{3, 1, 4, 1,\
    \ 5, 9, 2, 6, 5, 3, 5};\n   segtree<ll, op, e> seg(A);\n   assert(seg.prod(0,\
    \ 11) == 1);\n   assert(seg.min_left(11, [](ll x) { return x >= 2; }) == 4);\n\
    \   assert(seg.max_right(0, [](ll x) { return x > 0; }) == 11);\n   seg.set(3,\
    \ 0);\n   assert(seg.min_left(11, [](ll x) { return x >= 2; }) == 4);\n   assert(seg.max_right(0,\
    \ [](ll x) { return x >= 0; }) == 11);\n   assert(seg.max_right(0, [](ll x) {\
    \ return x > 0; }) == 3);\n   cout << \"Hello World\" << endl;\n   return 0;\n\
    }"
  dependsOn:
  - test/template.hpp
  - src/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/data-structure/segtree.test.3.cpp
  requiredBy: []
  timestamp: '2024-12-06 14:52:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segtree.test.3.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segtree.test.3.cpp
- /verify/test/data-structure/segtree.test.3.cpp.html
title: test/data-structure/segtree.test.3.cpp
---
