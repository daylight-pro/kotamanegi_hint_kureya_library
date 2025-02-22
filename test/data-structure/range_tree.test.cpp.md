---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: BIT (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: src/data-structure/range_tree.hpp
    title: src/data-structure/range_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/data-structure/range_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/range_tree.hpp\"\ntemplate<class\
    \ K, class M> struct range_tree {\n   using S = typename M::S;\n   using D = typename\
    \ M::D;\n\n   private:\n   vector<pair<K, K>> ps;\n   vector<K> xs;\n   vector<vector<K>>\
    \ ys;\n   vector<D> ds;\n   int n;\n   int id(K x) const { return lower_bound(all(xs),\
    \ x) - xs.begin(); }\n\n   int id(int k, K y) const { return lower_bound(all(ys[k]),\
    \ y) - ys[k].begin(); }\n\n   public:\n   void add(K x, K y) { ps.emplace_back(x,\
    \ y); }\n   void build() {\n      sort(ps.begin(), ps.end());\n      ps.erase(unique(all(ps)),\
    \ ps.end());\n      n = size(ps);\n      xs.reserve(n);\n      for(auto& [x, _]\
    \ : ps) xs.push_back(x);\n      ys.resize(2 * n);\n      ds.resize(2 * n, M::init(0));\n\
    \      for(int i = 0; i < n; i++) {\n         ys[i + n] = {ps[i].second};\n  \
    \       ds[i + n] = M::init(1);\n      }\n      for(int i = n - 1; i > 0; i--)\
    \ {\n         ys[i].resize(size(ys[i << 1]) + size(ys[(i << 1) | 1]));\n     \
    \    merge(all(ys[i << 1]), all(ys[(i << 1) | 1]), ys[i].begin());\n         ys[i].erase(unique(all(ys[i])),\
    \ ys[i].end());\n         ds[i] = M::init(size(ys[i]));\n      }\n   }\n\n   void\
    \ apply(K x, K y, S a) {\n      int k = lower_bound(all(ps), make_pair(x, y))\
    \ - ps.begin() + n;\n      while(k > 0) {\n         M::apply(ds[k], id(k, y),\
    \ a);\n         k >>= 1;\n      }\n   }\n\n   S prod(K x1, K y1, K x2, K y2) {\n\
    \      int a = id(x1), b = id(x2);\n      a += n;\n      b += n;\n      S l =\
    \ M::e(), r = M::e();\n      while(a < b) {\n         if(a & 1) {\n          \
    \  l = M::op(l, M::prod(ds[a], id(a, y1), id(a, y2)));\n            ++a;\n   \
    \      }\n         if(b & 1) {\n            --b;\n            r = M::op(M::prod(ds[b],\
    \ id(b, y1), id(b, y2)), r);\n         }\n         a >>= 1;\n         b >>= 1;\n\
    \      }\n      return M::op(l, r);\n   }\n};\n\n/* \u4F7F\u3044\u65B9\n\n// \u30E2\
    \u30CE\u30A4\u30C9\nstruct M {\n   using S = ll;  // \u30C7\u30FC\u30BF(\u30E2\
    \u30CE\u30A4\u30C9)\u306E\u578B\n   using D = BIT;  // \u30CE\u30FC\u30C9\u306B\
    \u6301\u305F\u305B\u308B\u30C7\u30FC\u30BF\u69CB\u9020\u306E\u578B\n   static\
    \ S op(S a, S b) { return a + b; } // S\u306E\u4E8C\u9805\u6F14\u7B97\n   static\
    \ S e() { return 0; }  // S\u306E\u5358\u4F4D\u5143\n   static D init(int n) {\
    \ return BIT(n); }  // D\u3092\u9577\u3055n\u3067\u521D\u671F\u5316\u3059\u308B\
    \u95A2\u6570\n   static void apply(D& bit, int k, const S& v) { bit.add(k, v);\
    \ } // D \u306Ek\u756A\u76EE\u306B v \u3092\u9069\u7528\u3059\u308B\u95A2\u6570\
    \n   static S prod(D& bit, int l, int r) { return bit.sum(l, r); } // D \u306E\
    [l, r) \u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u884C\u3046\u95A2\u6570\
    \n};\n\nrt.add(x, y): \u5EA7\u6A19 (x, y) \u3092\u8FFD\u52A0\nrt.build(): \u30AF\
    \u30A8\u30EA\u3092\u53D7\u3051\u4ED8\u3051\u308B\u6E96\u5099\u3092\u3059\u308B\
    \nrt.apply(x, y, a): \u5EA7\u6A19 (x, y) \u306B a \u3092\u9069\u7528\nrt.prod(x1,\
    \ y1, x2, y2): \u5EA7\u6A19 x \\in [x1, x2), y \\in [y1, y2) \u306E\u9818\u57DF\
    \u306B\u30AF\u30A8\u30EA\u3092\u884C\u3046\n*/\n#line 1 \"src/data-structure/BIT.hpp\"\
    \nstruct BIT {\n   vector<ll> a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll i,\
    \ ll x) {  // A[i] += x\n      i++;\n      while(i < size(a)) {\n         a[i]\
    \ += x;\n         i += i & -i;\n      }\n   }\n   ll sum(ll r) {\n      ll s =\
    \ 0;\n      while(r) {\n         s += a[r];\n         r -= r & -r;\n      }\n\
    \      return s;\n   }\n   ll sum(ll l, ll r) {  // sum of A[l, r)\n      return\
    \ sum(r) - sum(l);\n   }\n};\n#line 6 \"test/data-structure/range_tree.test.cpp\"\
    \n\nstruct M {\n   using S = ll;\n   using D = BIT;\n   static ll op(ll a, ll\
    \ b) { return a + b; }\n   static ll e() { return 0; }\n   static BIT init(int\
    \ n) { return BIT(n); }\n   static void apply(BIT& bit, int k, const ll& v) {\
    \ bit.add(k, v); }\n   static ll prod(BIT& bit, int l, int r) { return bit.sum(l,\
    \ r); }\n};\n\nint main() {\n   cin.tie(0)->sync_with_stdio(false);\n   int N,\
    \ Q;\n   cin >> N >> Q;\n   range_tree<int, M> rt;\n   using T = tuple<int, ll,\
    \ ll, ll, ll>;\n   vector<T> qs;\n   for(int i = 0; i < N; i++) {\n      int x,\
    \ y;\n      ll w;\n      cin >> x >> y >> w;\n      qs.emplace_back(-1, x, y,\
    \ w, -1);\n      rt.add(x, y);\n   }\n   for(int i = 0; i < Q; i++) {\n      int\
    \ t;\n      ll l, d, r, u = -1;\n      cin >> t >> l >> d >> r;\n      if(t ==\
    \ 1) cin >> u;\n      qs.emplace_back(t, l, d, r, u);\n      if(t == 0) rt.add(l,\
    \ d);\n   }\n\n   rt.build();\n\n   for(auto [t, a, b, c, d] : qs) {\n      if(t\
    \ <= 0) rt.apply(a, b, c);\n      else { cout << rt.prod(a, b, c, d) << '\\n';\
    \ }\n   }\n\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"test/template.hpp\"\n#include \"src/data-structure/range_tree.hpp\"\
    \n#include \"src/data-structure/BIT.hpp\"\n\nstruct M {\n   using S = ll;\n  \
    \ using D = BIT;\n   static ll op(ll a, ll b) { return a + b; }\n   static ll\
    \ e() { return 0; }\n   static BIT init(int n) { return BIT(n); }\n   static void\
    \ apply(BIT& bit, int k, const ll& v) { bit.add(k, v); }\n   static ll prod(BIT&\
    \ bit, int l, int r) { return bit.sum(l, r); }\n};\n\nint main() {\n   cin.tie(0)->sync_with_stdio(false);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   range_tree<int, M> rt;\n   using T = tuple<int,\
    \ ll, ll, ll, ll>;\n   vector<T> qs;\n   for(int i = 0; i < N; i++) {\n      int\
    \ x, y;\n      ll w;\n      cin >> x >> y >> w;\n      qs.emplace_back(-1, x,\
    \ y, w, -1);\n      rt.add(x, y);\n   }\n   for(int i = 0; i < Q; i++) {\n   \
    \   int t;\n      ll l, d, r, u = -1;\n      cin >> t >> l >> d >> r;\n      if(t\
    \ == 1) cin >> u;\n      qs.emplace_back(t, l, d, r, u);\n      if(t == 0) rt.add(l,\
    \ d);\n   }\n\n   rt.build();\n\n   for(auto [t, a, b, c, d] : qs) {\n      if(t\
    \ <= 0) rt.apply(a, b, c);\n      else { cout << rt.prod(a, b, c, d) << '\\n';\
    \ }\n   }\n\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/range_tree.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/data-structure/range_tree.test.cpp
  requiredBy: []
  timestamp: '2025-01-03 11:14:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range_tree.test.cpp
- /verify/test/data-structure/range_tree.test.cpp.html
title: test/data-structure/range_tree.test.cpp
---
