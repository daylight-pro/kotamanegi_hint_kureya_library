---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/li_chao.test.cpp
    title: test/data-structure/li_chao.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/li_chao.hpp\"\ntemplate <typename T>\n\
    class LiChaoTree {\n   int n, sz, height;\n   vector<T> xs, as, bs;\n\n   void\
    \ update(T a, T b, int k, int h) {\n      int l = (k << h) & (sz - 1);\n     \
    \ int r = l + (1 << h);\n      \n      while(1) {\n         int m = (l + r) >>\
    \ 1;\n         T xl = xs[l], xm = xs[m];\n         bool l_update = a*xl + b <\
    \ as[k]*xl + bs[k];\n         bool m_update = a*xm + b < as[k]*xm + bs[k];\n\n\
    \         if(m_update) {\n            swap(as[k], a);\n            swap(bs[k],\
    \ b);\n         }\n         if(h == 0) break;\n         if(l_update != m_update)\
    \ {\n            k = k*2;\n            r = m;\n         } else {\n           \
    \ k = k*2+1;\n            l = m;\n         }\n         h--;\n      }\n   }\n\n\
    public:\n   // \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\
    \u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\
    \u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\n   LiChaoTree(const\
    \ vector<T>& xs) : n(xs.size()), xs(xs) {\n      sz = 1, height = 0;\n      while(sz\
    \ < (int)xs.size()) {\n         sz <<= 1;\n         height++;\n      }\n     \
    \ this->xs.resize(sz, xs.back());\n      as.assign(sz*2, 0);\n      bs.assign(sz*2,\
    \ std::numeric_limits<T>::max());\n   }\n\n   void add_line(T a, T b) {\n    \
    \  update(a, b, 1, height);\n   }\n\n   void add_segment(T a, T b, int l, int\
    \ r) {\n      if(l == r) return;\n      l += sz, r += sz;\n      int h = 0;\n\
    \      while(l < r) {\n         if(l & 1) update(a, b, l++, h);\n         if(r\
    \ & 1) update(a, b, --r, h);\n         l >>= 1, r >>= 1, h++;\n      }\n   }\n\
    \n   // x = xs[i] \u306B\u304A\u3051\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\
    \u308B\n   T get(int i) const {\n      T x = xs[i];\n      int k = i + sz;\n \
    \     T res = as[k]*x + bs[k];\n      while(k > 1) {\n         k >>= 1;\n    \
    \     T tmp = as[k]*x + bs[k];\n         if(tmp < res) res = tmp;\n      }\n \
    \     return res;\n   }\n};\n"
  code: "template <typename T>\nclass LiChaoTree {\n   int n, sz, height;\n   vector<T>\
    \ xs, as, bs;\n\n   void update(T a, T b, int k, int h) {\n      int l = (k <<\
    \ h) & (sz - 1);\n      int r = l + (1 << h);\n      \n      while(1) {\n    \
    \     int m = (l + r) >> 1;\n         T xl = xs[l], xm = xs[m];\n         bool\
    \ l_update = a*xl + b < as[k]*xl + bs[k];\n         bool m_update = a*xm + b <\
    \ as[k]*xm + bs[k];\n\n         if(m_update) {\n            swap(as[k], a);\n\
    \            swap(bs[k], b);\n         }\n         if(h == 0) break;\n       \
    \  if(l_update != m_update) {\n            k = k*2;\n            r = m;\n    \
    \     } else {\n            k = k*2+1;\n            l = m;\n         }\n     \
    \    h--;\n      }\n   }\n\npublic:\n   // \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\
    \u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u4E21\
    \u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\u30C8\
    \u3057\u305F\u914D\u5217\n   LiChaoTree(const vector<T>& xs) : n(xs.size()), xs(xs)\
    \ {\n      sz = 1, height = 0;\n      while(sz < (int)xs.size()) {\n         sz\
    \ <<= 1;\n         height++;\n      }\n      this->xs.resize(sz, xs.back());\n\
    \      as.assign(sz*2, 0);\n      bs.assign(sz*2, std::numeric_limits<T>::max());\n\
    \   }\n\n   void add_line(T a, T b) {\n      update(a, b, 1, height);\n   }\n\n\
    \   void add_segment(T a, T b, int l, int r) {\n      if(l == r) return;\n   \
    \   l += sz, r += sz;\n      int h = 0;\n      while(l < r) {\n         if(l &\
    \ 1) update(a, b, l++, h);\n         if(r & 1) update(a, b, --r, h);\n       \
    \  l >>= 1, r >>= 1, h++;\n      }\n   }\n\n   // x = xs[i] \u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n   T get(int i) const {\n  \
    \    T x = xs[i];\n      int k = i + sz;\n      T res = as[k]*x + bs[k];\n   \
    \   while(k > 1) {\n         k >>= 1;\n         T tmp = as[k]*x + bs[k];\n   \
    \      if(tmp < res) res = tmp;\n      }\n      return res;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/li_chao.hpp
  requiredBy: []
  timestamp: '2025-02-24 05:53:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/li_chao.test.cpp
documentation_of: src/data-structure/li_chao.hpp
layout: document
redirect_from:
- /library/src/data-structure/li_chao.hpp
- /library/src/data-structure/li_chao.hpp.html
title: src/data-structure/li_chao.hpp
---
