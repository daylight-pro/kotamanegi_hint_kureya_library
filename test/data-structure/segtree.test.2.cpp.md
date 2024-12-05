---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segtree.hpp
    title: src/data-structure/segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data-structure/segtree.test.2.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 1 \"\
    test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll i =\
    \ a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/modint/modint.hpp\"\
    \nconst ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ %\
    \ mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator+(mm a, mm b)\
    \ { return a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return a.x - b.x;\
    \ }\n   friend mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift\
    \ + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend\
    \ mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm&\
    \ a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) {\
    \ return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a =\
    \ a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b)\
    \ const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c\
    \ *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n#line 1 \"src/data-structure/segtree.hpp\"\nunsigned int bit_ceil(unsigned\
    \ int n) {\n   unsigned int x = 1;\n   while(x < (unsigned int)(n)) x *= 2;\n\
    \   return x;\n}\nint countr_zero(unsigned int n) { return __builtin_ctz(n); }\n\
    constexpr int countr_zero_constexpr(unsigned int n) {\n   int x = 0;\n   while(!(n\
    \ & (1 << x))) x++;\n   return x;\n}\ntemplate<class S, S (*op)(S, S), S (*e)()>\
    \ struct segtree {\n   public:\n   segtree() : segtree(0) {}\n   explicit segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n   explicit segtree(const vector<S>& v)\
    \ : _n(int(v.size())) {\n      size = (int)bit_ceil((unsigned int)(_n));\n   \
    \   log = countr_zero((unsigned int)size);\n      d = vector<S>(2 * size, e());\n\
    \      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n      for(int i = size\
    \ - 1; i >= 1; i--) { update(i); }\n   }\n\n   void set(int p, S x) {\n      //\
    \ assert(0 <= p && p < _n);\n      p += size;\n      d[p] = x;\n      for(int\
    \ i = 1; i <= log; i++) update(p >> i);\n   }\n\n   S get(int p) const {\n   \
    \   // assert(0 <= p && p < _n);\n      return d[p + size];\n   }\n\n   S prod(int\
    \ l, int r) const {\n      // assert(0 <= l && l <= r && r <= _n);\n      S sml\
    \ = e(), smr = e();\n      l += size;\n      r += size;\n\n      while(l < r)\
    \ {\n         if(l & 1) sml = op(sml, d[l++]);\n         if(r & 1) smr = op(d[--r],\
    \ smr);\n         l >>= 1;\n         r >>= 1;\n      }\n      return op(sml, smr);\n\
    \   }\n\n   S all_prod() const { return d[1]; }\n\n   int _n, size, log;\n   vector<S>\
    \ d;\n\n   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n#line\
    \ 6 \"test/data-structure/segtree.test.2.cpp\"\n\nstruct Data {\n   mm c, d;\n\
    };\n\nData op(Data a, Data b) { return {a.c * b.c, b.c * a.d + b.d}; }\n\nData\
    \ e() { return {1, 0}; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \n   int N, Q;\n   cin >> N >> Q;\n   vector<Data> V(N);\n   rep(i, 0, N) {\n\
    \      int a, b;\n      cin >> a >> b;\n      V[i] = {mm(a), mm(b)};\n   }\n \
    \  segtree<Data, op, e> seg(V);\n   while(Q--) {\n      int k;\n      cin >> k;\n\
    \      if(k == 0) {\n         int p, c, d;\n         cin >> p >> c >> d;\n   \
    \      seg.set(p, {c, d});\n      } else {\n         int l, r, x;\n         cin\
    \ >> l >> r >> x;\n         auto [c, d] = seg.prod(l, r);\n         cout << (c\
    \ * x + d).x << endl;\n      }\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include\
    \ \"src/data-structure/segtree.hpp\"\n\nstruct Data {\n   mm c, d;\n};\n\nData\
    \ op(Data a, Data b) { return {a.c * b.c, b.c * a.d + b.d}; }\n\nData e() { return\
    \ {1, 0}; }\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   int N, Q;\n\
    \   cin >> N >> Q;\n   vector<Data> V(N);\n   rep(i, 0, N) {\n      int a, b;\n\
    \      cin >> a >> b;\n      V[i] = {mm(a), mm(b)};\n   }\n   segtree<Data, op,\
    \ e> seg(V);\n   while(Q--) {\n      int k;\n      cin >> k;\n      if(k == 0)\
    \ {\n         int p, c, d;\n         cin >> p >> c >> d;\n         seg.set(p,\
    \ {c, d});\n      } else {\n         int l, r, x;\n         cin >> l >> r >> x;\n\
    \         auto [c, d] = seg.prod(l, r);\n         cout << (c * x + d).x << endl;\n\
    \      }\n   }\n}"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/data-structure/segtree.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-06 01:45:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segtree.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segtree.test.2.cpp
- /verify/test/data-structure/segtree.test.2.cpp.html
title: test/data-structure/segtree.test.2.cpp
---
