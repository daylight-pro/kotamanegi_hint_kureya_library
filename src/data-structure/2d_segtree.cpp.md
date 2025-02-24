---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/2d_segtree.cpp\"\ntemplate<typename T,\
    \ typename F> struct SegmentTree2D {\n   private:\n   int id(int h, int w) const\
    \ { return h * 2 * W + w; }\n\n   public:\n   int H, W;\n   vector<T> seg;\n \
    \  const F f;\n   const T I;\n\n   SegmentTree2D(int h, int w, F _f, const T&\
    \ i) : f(_f), I(i) { init(h, w); }\n\n   void init(int h, int w) {\n      H =\
    \ W = 1;\n      while(H < h) H <<= 1;\n      while(W < w) W <<= 1;\n      seg.assign(4\
    \ * H * W, I);\n   }\n\n   void set(int h, int w, const T& x) { seg[id(h + H,\
    \ w + W)] = x; }\n\n   void build() {\n      for(int w = W; w < 2 * W; w++) {\n\
    \         for(int h = H - 1; h; h--) { seg[id(h, w)] = f(seg[id(2 * h + 0, w)],\
    \ seg[id(2 * h + 1, w)]); }\n      }\n      for(int h = 0; h < 2 * H; h++) {\n\
    \         for(int w = W - 1; w; w--) { seg[id(h, w)] = f(seg[id(h, 2 * w + 0)],\
    \ seg[id(h, 2 * w + 1)]); }\n      }\n   }\n\n   T get(int h, int w) const { return\
    \ seg[id(h + H, w + W)]; }\n   T operator()(int h, int w) const { return seg[id(h\
    \ + H, w + W)]; }\n\n   void update(int h, int w, const T& x) {\n      h += H,\
    \ w += W;\n      seg[id(h, w)] = x;\n      for(int i = h >> 1; i; i >>= 1) { seg[id(i,\
    \ w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]); }\n      for(; h; h >>=\
    \ 1) {\n         for(int j = w >> 1; j; j >>= 1) { seg[id(h, j)] = f(seg[id(h,\
    \ 2 * j + 0)], seg[id(h, 2 * j + 1)]); }\n      }\n   }\n\n   T _inner_query(int\
    \ h, int w1, int w2) {\n      T res = I;\n      for(; w1 < w2; w1 >>= 1, w2 >>=\
    \ 1) {\n         if(w1 & 1) res = f(res, seg[id(h, w1)]), w1++;\n         if(w2\
    \ & 1) --w2, res = f(res, seg[id(h, w2)]);\n      }\n      return res;\n   }\n\
    \n   T query(int h1, int w1, int h2, int w2) {\n      if(h1 >= h2 || w1 >= w2)\
    \ return I;\n      T res = I;\n      h1 += H, h2 += H, w1 += W, w2 += W;\n   \
    \   for(; h1 < h2; h1 >>= 1, h2 >>= 1) {\n         if(h1 & 1) res = f(res, _inner_query(h1,\
    \ w1, w2)), h1++;\n         if(h2 & 1) --h2, res = f(res, _inner_query(h2, w1,\
    \ w2));\n      }\n      return res;\n   }\n};\n"
  code: "template<typename T, typename F> struct SegmentTree2D {\n   private:\n  \
    \ int id(int h, int w) const { return h * 2 * W + w; }\n\n   public:\n   int H,\
    \ W;\n   vector<T> seg;\n   const F f;\n   const T I;\n\n   SegmentTree2D(int\
    \ h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }\n\n   void init(int\
    \ h, int w) {\n      H = W = 1;\n      while(H < h) H <<= 1;\n      while(W <\
    \ w) W <<= 1;\n      seg.assign(4 * H * W, I);\n   }\n\n   void set(int h, int\
    \ w, const T& x) { seg[id(h + H, w + W)] = x; }\n\n   void build() {\n      for(int\
    \ w = W; w < 2 * W; w++) {\n         for(int h = H - 1; h; h--) { seg[id(h, w)]\
    \ = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]); }\n      }\n      for(int\
    \ h = 0; h < 2 * H; h++) {\n         for(int w = W - 1; w; w--) { seg[id(h, w)]\
    \ = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]); }\n      }\n   }\n\n   T\
    \ get(int h, int w) const { return seg[id(h + H, w + W)]; }\n   T operator()(int\
    \ h, int w) const { return seg[id(h + H, w + W)]; }\n\n   void update(int h, int\
    \ w, const T& x) {\n      h += H, w += W;\n      seg[id(h, w)] = x;\n      for(int\
    \ i = h >> 1; i; i >>= 1) { seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2\
    \ * i + 1, w)]); }\n      for(; h; h >>= 1) {\n         for(int j = w >> 1; j;\
    \ j >>= 1) { seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);\
    \ }\n      }\n   }\n\n   T _inner_query(int h, int w1, int w2) {\n      T res\
    \ = I;\n      for(; w1 < w2; w1 >>= 1, w2 >>= 1) {\n         if(w1 & 1) res =\
    \ f(res, seg[id(h, w1)]), w1++;\n         if(w2 & 1) --w2, res = f(res, seg[id(h,\
    \ w2)]);\n      }\n      return res;\n   }\n\n   T query(int h1, int w1, int h2,\
    \ int w2) {\n      if(h1 >= h2 || w1 >= w2) return I;\n      T res = I;\n    \
    \  h1 += H, h2 += H, w1 += W, w2 += W;\n      for(; h1 < h2; h1 >>= 1, h2 >>=\
    \ 1) {\n         if(h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;\n  \
    \       if(h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));\n      }\n  \
    \    return res;\n   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/2d_segtree.cpp
  requiredBy: []
  timestamp: '2025-02-25 03:16:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/2d_segtree.cpp
layout: document
redirect_from:
- /library/src/data-structure/2d_segtree.cpp
- /library/src/data-structure/2d_segtree.cpp.html
title: src/data-structure/2d_segtree.cpp
---
