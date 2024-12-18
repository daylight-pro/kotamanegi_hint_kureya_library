---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_tree.test.2.cpp
    title: test/data-structure/range_tree.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range_tree.test.cpp
    title: test/data-structure/range_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/range_tree.hpp\"\ntemplate<class K, class\
    \ M> struct range_tree {\n   using S = typename M::S;\n   using D = typename M::D;\n\
    \n   private:\n   vector<pair<K, K>> ps;\n   vector<K> xs;\n   vector<vector<K>>\
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
    \u306B\u30AF\u30A8\u30EA\u3092\u884C\u3046\n*/\n"
  code: "template<class K, class M> struct range_tree {\n   using S = typename M::S;\n\
    \   using D = typename M::D;\n\n   private:\n   vector<pair<K, K>> ps;\n   vector<K>\
    \ xs;\n   vector<vector<K>> ys;\n   vector<D> ds;\n   int n;\n   int id(K x) const\
    \ { return lower_bound(all(xs), x) - xs.begin(); }\n\n   int id(int k, K y) const\
    \ { return lower_bound(all(ys[k]), y) - ys[k].begin(); }\n\n   public:\n   void\
    \ add(K x, K y) { ps.emplace_back(x, y); }\n   void build() {\n      sort(ps.begin(),\
    \ ps.end());\n      ps.erase(unique(all(ps)), ps.end());\n      n = size(ps);\n\
    \      xs.reserve(n);\n      for(auto& [x, _] : ps) xs.push_back(x);\n      ys.resize(2\
    \ * n);\n      ds.resize(2 * n, M::init(0));\n      for(int i = 0; i < n; i++)\
    \ {\n         ys[i + n] = {ps[i].second};\n         ds[i + n] = M::init(1);\n\
    \      }\n      for(int i = n - 1; i > 0; i--) {\n         ys[i].resize(size(ys[i\
    \ << 1]) + size(ys[(i << 1) | 1]));\n         merge(all(ys[i << 1]), all(ys[(i\
    \ << 1) | 1]), ys[i].begin());\n         ys[i].erase(unique(all(ys[i])), ys[i].end());\n\
    \         ds[i] = M::init(size(ys[i]));\n      }\n   }\n\n   void apply(K x, K\
    \ y, S a) {\n      int k = lower_bound(all(ps), make_pair(x, y)) - ps.begin()\
    \ + n;\n      while(k > 0) {\n         M::apply(ds[k], id(k, y), a);\n       \
    \  k >>= 1;\n      }\n   }\n\n   S prod(K x1, K y1, K x2, K y2) {\n      int a\
    \ = id(x1), b = id(x2);\n      a += n;\n      b += n;\n      S l = M::e(), r =\
    \ M::e();\n      while(a < b) {\n         if(a & 1) {\n            l = M::op(l,\
    \ M::prod(ds[a], id(a, y1), id(a, y2)));\n            ++a;\n         }\n     \
    \    if(b & 1) {\n            --b;\n            r = M::op(M::prod(ds[b], id(b,\
    \ y1), id(b, y2)), r);\n         }\n         a >>= 1;\n         b >>= 1;\n   \
    \   }\n      return M::op(l, r);\n   }\n};\n\n/* \u4F7F\u3044\u65B9\n\n// \u30E2\
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
    \u306B\u30AF\u30A8\u30EA\u3092\u884C\u3046\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/range_tree.hpp
  requiredBy: []
  timestamp: '2024-12-11 23:14:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range_tree.test.2.cpp
  - test/data-structure/range_tree.test.cpp
documentation_of: src/data-structure/range_tree.hpp
layout: document
redirect_from:
- /library/src/data-structure/range_tree.hpp
- /library/src/data-structure/range_tree.hpp.html
title: src/data-structure/range_tree.hpp
---
