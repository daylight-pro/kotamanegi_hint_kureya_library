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
  bundledCode: "#line 1 \"src/data-structure/beats_example.cpp\"\n// \u533A\u9593\
    chmax, chmin, add \u533A\u9593sum\u53D6\u5F97\nnamespace RangeChMinMaxAddSum {\n\
    template<typename Num> inline Num second_lowest(Num a, Num a2, Num c, Num c2)\
    \ noexcept {\n   // a < a2, c < c2 \u306E\u3068\u304D\u5168\u5F15\u6570\u3092\u6607\
    \u9806\u30BD\u30FC\u30C8\u3057\u3066\u4E8C\u756A\u76EE\u306E\u5024\n   return\
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
    \ id>;\n}  // namespace RangeChMinMaxAddSum\n"
  code: "// \u533A\u9593chmax, chmin, add \u533A\u9593sum\u53D6\u5F97\nnamespace RangeChMinMaxAddSum\
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
    \ id>;\n}  // namespace RangeChMinMaxAddSum"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/beats_example.cpp
  requiredBy: []
  timestamp: '2025-02-24 13:12:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/beats.test.cpp
documentation_of: src/data-structure/beats_example.cpp
layout: document
redirect_from:
- /library/src/data-structure/beats_example.cpp
- /library/src/data-structure/beats_example.cpp.html
title: src/data-structure/beats_example.cpp
---
