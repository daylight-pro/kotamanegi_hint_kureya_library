---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/beats_example.cpp
    title: src/data-structure/beats_example.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/beats.cpp
    title: test/data-structure/beats.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/data-structure/beats.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\n\n#line 1 \"\
    test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"test/data-structure/beats.cpp\"\
    \nunsigned int bit_ceil(unsigned int n) {\n   unsigned int x = 1;\n   while(x\
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
    \ = id();\n   }\n};\n#line 1 \"src/data-structure/beats_example.cpp\"\n// \u533A\
    \u9593chmax, chmin, add \u533A\u9593sum\u53D6\u5F97\nnamespace RangeChMinMaxAddSum\
    \ {\ntemplate<typename Num> inline Num second_lowest(Num a, Num a2, Num c, Num\
    \ c2) noexcept {\n   // a < a2, c < c2 \u306E\u3068\u304D\u5168\u5F15\u6570\u3092\
    \u6607\u9806\u30BD\u30FC\u30C8\u3057\u3066\u4E8C\u756A\u76EE\u306E\u5024\n   return\
    \ a == c ? std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : std::max(a, c);\n\
    }\ntemplate<typename Num> inline Num second_highest(Num a, Num a2, Num b, Num\
    \ b2) noexcept {\n   // a > a2, b > b2 \u306E\u3068\u304D\u5168\u5F15\u6570\u3092\
    \u964D\u9806\u30BD\u30FC\u30C8\u3057\u3066\u4E8C\u756A\u76EE\u306E\u5024\n   return\
    \ a == b ? std::max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : std::min(a, b);\n\
    }\n\nconstexpr ll BINF = 1LL << 61;\n\nstruct S {\n   ll lo, hi, lo2, hi2, sum;\
    \  // \u533A\u9593\u6700\u5C0F\u30FB\u6700\u5927\u5024\uFF0C\u533A\u9593\u6700\
    \u5C0F\u30FB\u6700\u5927\u304B\u3089\u4E8C\u756A\u76EE\u306E\u5024\uFF0C\u533A\
    \u9593\u7DCF\u548C\n   unsigned sz, nlo, nhi;     // \u533A\u9593\u8981\u7D20\u6570\
    \uFF0C\u533A\u9593\u6700\u5C0F\u30FB\u6700\u5927\u5024\u3092\u3068\u308B\u8981\
    \u7D20\u306E\u500B\u6570\n   bool fail;\n   S() : lo(BINF), hi(-BINF), lo2(BINF),\
    \ hi2(-BINF), sum(0), sz(0), nlo(0), nhi(0), fail(0) {}\n   S(ll x, unsigned sz_\
    \ = 1)\n       : lo(x), hi(x), lo2(BINF), hi2(-BINF), sum(x * sz_), sz(sz_), nlo(sz_),\
    \ nhi(sz_), fail(0) {}\n};\n\nS e() { return S(); }\n\nS op(S l, S r) {\n   S\
    \ ret;\n   ret.lo = min(l.lo, r.lo), ret.hi = max(l.hi, r.hi);\n   ret.lo2 = second_lowest(l.lo,\
    \ l.lo2, r.lo, r.lo2);\n   ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);\n\
    \   ret.sum = l.sum + r.sum, ret.sz = l.sz + r.sz;\n   ret.nlo = l.nlo * (l.lo\
    \ <= r.lo) + r.nlo * (r.lo <= l.lo);\n   ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi\
    \ * (r.hi >= l.hi);\n   return ret;\n}\n\nstruct F {\n   ll lb, ub, bias;\n  \
    \ F(ll chmax_ = -BINF, ll chmin_ = BINF, ll add = 0) : lb(chmax_), ub(chmin_),\
    \ bias(add) {}\n   static F chmin(ll x) noexcept { return F(-BINF, x, ll(0));\
    \ }\n   static F chmax(ll x) noexcept { return F(x, BINF, ll(0)); }\n   static\
    \ F add(ll x) noexcept { return F(-BINF, BINF, x); };\n};\n\nF composition(F fnew,\
    \ F fold) {\n   F ret;\n   ret.lb = max(min(fold.lb + fold.bias, fnew.ub), fnew.lb)\
    \ - fold.bias;\n   ret.ub = min(max(fold.ub + fold.bias, fnew.lb), fnew.ub) -\
    \ fold.bias;\n   ret.bias = fold.bias + fnew.bias;\n   return ret;\n}\n\nF id()\
    \ { return F(); }\n\nS mapping(F f, S x) {\n   if(x.sz == 0) return e();\n   else\
    \ if(x.lo == x.hi or f.lb == f.ub or f.lb >= x.hi or f.ub <= x.lo) {\n      return\
    \ S(min(max(x.lo, f.lb), f.ub) + f.bias, x.sz);\n   } else if(x.lo2 == x.hi) {\n\
    \      x.lo = x.hi2 = max(x.lo, f.lb) + f.bias;\n      x.hi = x.lo2 = min(x.hi,\
    \ f.ub) + f.bias;\n      x.sum = x.lo * x.nlo + x.hi * x.nhi;\n      return x;\n\
    \   } else if(f.lb < x.lo2 and f.ub > x.hi2) {\n      ll nxt_lo = max(x.lo, f.lb),\
    \ nxt_hi = min(x.hi, f.ub);\n      x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi -\
    \ nxt_hi) * x.nhi + f.bias * x.sz;\n      x.lo = nxt_lo + f.bias, x.hi = nxt_hi\
    \ + f.bias, x.lo2 += f.bias, x.hi2 += f.bias;\n      return x;\n   }\n   x.fail\
    \ = 1;\n   return x;\n}\nusing segtree = lazy_segtree<S, op, e, F, mapping, composition,\
    \ id>;\n}  // namespace RangeChMinMaxAddSum\n#line 6 \"test/data-structure/beats.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   using namespace RangeChMinMaxAddSum;\n   vector<S> A(N);\n   for(auto&&\
    \ a : A) {\n      ll x;\n      cin >> x;\n      a = S(x);\n   }\n   lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> seg(A);\n   while(Q--) {\n      int k;\n\
    \      cin >> k;\n      if(k == 0) {\n         int l, r;\n         ll b;\n   \
    \      cin >> l >> r >> b;\n         seg.apply(l, r, F::chmin(b));\n      } else\
    \ if(k == 1) {\n         int l, r;\n         ll b;\n         cin >> l >> r >>\
    \ b;\n         seg.apply(l, r, F::chmax(b));\n      } else if(k == 2) {\n    \
    \     int l, r;\n         ll b;\n         cin >> l >> r >> b;\n         seg.apply(l,\
    \ r, F::add(b));\n      } else if(k == 3) {\n         int l, r;\n         cin\
    \ >> l >> r;\n         cout << seg.prod(l, r).sum << endl;\n      }\n   }\n  \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"test/template.hpp\"\n#include \"test/data-structure/beats.cpp\"\
    \n#include \"src/data-structure/beats_example.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   using namespace RangeChMinMaxAddSum;\n  \
    \ vector<S> A(N);\n   for(auto&& a : A) {\n      ll x;\n      cin >> x;\n    \
    \  a = S(x);\n   }\n   lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);\n\
    \   while(Q--) {\n      int k;\n      cin >> k;\n      if(k == 0) {\n        \
    \ int l, r;\n         ll b;\n         cin >> l >> r >> b;\n         seg.apply(l,\
    \ r, F::chmin(b));\n      } else if(k == 1) {\n         int l, r;\n         ll\
    \ b;\n         cin >> l >> r >> b;\n         seg.apply(l, r, F::chmax(b));\n \
    \     } else if(k == 2) {\n         int l, r;\n         ll b;\n         cin >>\
    \ l >> r >> b;\n         seg.apply(l, r, F::add(b));\n      } else if(k == 3)\
    \ {\n         int l, r;\n         cin >> l >> r;\n         cout << seg.prod(l,\
    \ r).sum << endl;\n      }\n   }\n   return 0;\n}\n"
  dependsOn:
  - test/template.hpp
  - test/data-structure/beats.cpp
  - src/data-structure/beats_example.cpp
  isVerificationFile: true
  path: test/data-structure/beats.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 13:12:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/beats.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/beats.test.cpp
- /verify/test/data-structure/beats.test.cpp.html
title: test/data-structure/beats.test.cpp
---
