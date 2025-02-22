---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/wavelet_matrix.test.2.cpp
    title: test/data-structure/wavelet_matrix.test.2.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/wavelet_matrix.test.3.cpp
    title: test/data-structure/wavelet_matrix.test.3.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/wavelet_matrix.test.4.cpp
    title: test/data-structure/wavelet_matrix.test.4.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/wavelet_matrix.test.5.cpp
    title: test/data-structure/wavelet_matrix.test.5.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/wavelet_matrix.test.cpp
    title: test/data-structure/wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/wavelet_matrix.hpp\"\n// base: be292e\n\
    struct BitVector {\n   private:\n   vector<int> vec;\n\n   public:\n   BitVector(const\
    \ vector<int>& a) {\n      vec.resize(a.size() + 1);\n      for(int j = 0; j <\
    \ (int)a.size(); j++) { vec[j + 1] = vec[j] + a[j]; }\n   }\n\n   int get(const\
    \ int i) { return vec[i + 1] - vec[i]; }\n\n   int rank(const int b, const int\
    \ i) {\n      if(b == 0) return i - vec[i];\n      else return vec[i];\n   }\n\
    };\n\ntemplate<typename T, int bit_len = 62> struct WaveletMatrix {\n   private:\n\
    \   vector<BitVector> B;\n   vector<vector<T>> acc;\n   vector<int> so;\n   map<T,\
    \ int> sn;\n   int len;\n\n   public:\n   WaveletMatrix(vector<T> vec) {\n   \
    \   len = vec.size();\n      acc = vector<vector<T>>(bit_len, vector<T>(len +\
    \ 1));\n      so = vector<int>(bit_len);\n      vector<T> v(vec);\n      for(int\
    \ b = 0; b < bit_len; b++) {\n         vector<T> cur;\n         cur.reserve(len);\n\
    \         vector<int> bi(len);\n         for(int i = 0; i < len; i++) {\n    \
    \        ll bit = (v[i] >> (bit_len - b - 1)) & 1;\n            if(bit == 0) {\n\
    \               cur.push_back(v[i]);\n               bi[i] = 0;\n            }\n\
    \         }\n         so[b] = cur.size();\n         for(int i = 0; i < len; i++)\
    \ {\n            ll bit = (v[i] >> (bit_len - b - 1)) & 1;\n            if(bit\
    \ == 1) {\n               cur.push_back(v[i]);\n               bi[i] = 1;\n  \
    \          }\n         }\n         B.push_back(BitVector(bi));\n         for(int\
    \ i = 0; i < len; i++) {\n            if(B[b].get(i) == 0) acc[b][i + 1] = v[i];\n\
    \            acc[b][i + 1] += acc[b][i];\n         }\n         v = cur;\n    \
    \  }\n      for(int i = len - 1; i >= 0; i--) { sn[v[i]] = i; }\n   }\n\n   T\
    \ access(int i) {\n      T ret = 0;\n      for(int j = 0; j < bit_len; j++) {\n\
    \         int bit = B[j].get(i);\n         ret = (ret << 1) | bit;\n         i\
    \ = B[j].rank(bit, i) + so[j] * bit;\n      }\n      return ret;\n   }  // 3be264\n\
    \n   int rank(T val, int i) {\n      if(!sn.count(val)) return 0;\n      for(int\
    \ j = 0; j < bit_len; j++) {\n         int bit = (val >> (bit_len - j - 1)) &\
    \ 1;\n         i = B[j].rank(bit, i) + so[j] * bit;\n      }\n      return i -\
    \ sn[val];\n   }  // 88f41a\n\n   T kthMin(int left, int right, int k) {\n   \
    \   T ret = 0;\n      for(int j = 0; j < bit_len; j++) {\n         int l = B[j].rank(0,\
    \ left);\n         int r = B[j].rank(0, right);\n         int cnt = r - l;\n \
    \        if(cnt > k) {\n            left = l;\n            right = r;\n      \
    \   } else {\n            k -= cnt;\n            left += so[j] - l;\n        \
    \    right += so[j] - r;\n            ret |= (1LL << (bit_len - j - 1));\n   \
    \      }\n      }\n      return ret;\n   }  // 941aa0\n\n   T kMinSum(int left,\
    \ int right, int k) {\n      T ret = 0;\n      for(int j = 0; j < bit_len; j++)\
    \ {\n         int l = B[j].rank(0, left);\n         int r = B[j].rank(0, right);\n\
    \         int cnt = r - l;\n         if(cnt > k) {\n            left = l;\n  \
    \          right = r;\n         } else {\n            k -= cnt;\n            ret\
    \ += acc[j][right] - acc[j][left];\n            left += so[j] - l;\n         \
    \   right += so[j] - r;\n         }\n      }\n      return ret;\n   }  // edb4f5\n\
    \n   int lessCount(int left, int right, T upper) {\n      int ret = 0;\n     \
    \ if(upper >= (1LL << bit_len)) return right - left;\n      for(int j = 0; j <\
    \ bit_len; j++) {\n         int l = B[j].rank(0, left);\n         int r = B[j].rank(0,\
    \ right);\n         int cnt = r - l;\n         if((upper >> (bit_len - j - 1))\
    \ & 1) {\n            ret += cnt;\n            left += so[j] - l;\n          \
    \  right += so[j] - r;\n         } else {\n            left = l;\n           \
    \ right = r;\n         }\n      }\n      return ret;\n   }  // 029c6d\n};\n"
  code: "// base: be292e\nstruct BitVector {\n   private:\n   vector<int> vec;\n\n\
    \   public:\n   BitVector(const vector<int>& a) {\n      vec.resize(a.size() +\
    \ 1);\n      for(int j = 0; j < (int)a.size(); j++) { vec[j + 1] = vec[j] + a[j];\
    \ }\n   }\n\n   int get(const int i) { return vec[i + 1] - vec[i]; }\n\n   int\
    \ rank(const int b, const int i) {\n      if(b == 0) return i - vec[i];\n    \
    \  else return vec[i];\n   }\n};\n\ntemplate<typename T, int bit_len = 62> struct\
    \ WaveletMatrix {\n   private:\n   vector<BitVector> B;\n   vector<vector<T>>\
    \ acc;\n   vector<int> so;\n   map<T, int> sn;\n   int len;\n\n   public:\n  \
    \ WaveletMatrix(vector<T> vec) {\n      len = vec.size();\n      acc = vector<vector<T>>(bit_len,\
    \ vector<T>(len + 1));\n      so = vector<int>(bit_len);\n      vector<T> v(vec);\n\
    \      for(int b = 0; b < bit_len; b++) {\n         vector<T> cur;\n         cur.reserve(len);\n\
    \         vector<int> bi(len);\n         for(int i = 0; i < len; i++) {\n    \
    \        ll bit = (v[i] >> (bit_len - b - 1)) & 1;\n            if(bit == 0) {\n\
    \               cur.push_back(v[i]);\n               bi[i] = 0;\n            }\n\
    \         }\n         so[b] = cur.size();\n         for(int i = 0; i < len; i++)\
    \ {\n            ll bit = (v[i] >> (bit_len - b - 1)) & 1;\n            if(bit\
    \ == 1) {\n               cur.push_back(v[i]);\n               bi[i] = 1;\n  \
    \          }\n         }\n         B.push_back(BitVector(bi));\n         for(int\
    \ i = 0; i < len; i++) {\n            if(B[b].get(i) == 0) acc[b][i + 1] = v[i];\n\
    \            acc[b][i + 1] += acc[b][i];\n         }\n         v = cur;\n    \
    \  }\n      for(int i = len - 1; i >= 0; i--) { sn[v[i]] = i; }\n   }\n\n   T\
    \ access(int i) {\n      T ret = 0;\n      for(int j = 0; j < bit_len; j++) {\n\
    \         int bit = B[j].get(i);\n         ret = (ret << 1) | bit;\n         i\
    \ = B[j].rank(bit, i) + so[j] * bit;\n      }\n      return ret;\n   }  // 3be264\n\
    \n   int rank(T val, int i) {\n      if(!sn.count(val)) return 0;\n      for(int\
    \ j = 0; j < bit_len; j++) {\n         int bit = (val >> (bit_len - j - 1)) &\
    \ 1;\n         i = B[j].rank(bit, i) + so[j] * bit;\n      }\n      return i -\
    \ sn[val];\n   }  // 88f41a\n\n   T kthMin(int left, int right, int k) {\n   \
    \   T ret = 0;\n      for(int j = 0; j < bit_len; j++) {\n         int l = B[j].rank(0,\
    \ left);\n         int r = B[j].rank(0, right);\n         int cnt = r - l;\n \
    \        if(cnt > k) {\n            left = l;\n            right = r;\n      \
    \   } else {\n            k -= cnt;\n            left += so[j] - l;\n        \
    \    right += so[j] - r;\n            ret |= (1LL << (bit_len - j - 1));\n   \
    \      }\n      }\n      return ret;\n   }  // 941aa0\n\n   T kMinSum(int left,\
    \ int right, int k) {\n      T ret = 0;\n      for(int j = 0; j < bit_len; j++)\
    \ {\n         int l = B[j].rank(0, left);\n         int r = B[j].rank(0, right);\n\
    \         int cnt = r - l;\n         if(cnt > k) {\n            left = l;\n  \
    \          right = r;\n         } else {\n            k -= cnt;\n            ret\
    \ += acc[j][right] - acc[j][left];\n            left += so[j] - l;\n         \
    \   right += so[j] - r;\n         }\n      }\n      return ret;\n   }  // edb4f5\n\
    \n   int lessCount(int left, int right, T upper) {\n      int ret = 0;\n     \
    \ if(upper >= (1LL << bit_len)) return right - left;\n      for(int j = 0; j <\
    \ bit_len; j++) {\n         int l = B[j].rank(0, left);\n         int r = B[j].rank(0,\
    \ right);\n         int cnt = r - l;\n         if((upper >> (bit_len - j - 1))\
    \ & 1) {\n            ret += cnt;\n            left += so[j] - l;\n          \
    \  right += so[j] - r;\n         } else {\n            left = l;\n           \
    \ right = r;\n         }\n      }\n      return ret;\n   }  // 029c6d\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-12-18 15:33:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/wavelet_matrix.test.2.cpp
  - test/data-structure/wavelet_matrix.test.4.cpp
  - test/data-structure/wavelet_matrix.test.5.cpp
  - test/data-structure/wavelet_matrix.test.cpp
  - test/data-structure/wavelet_matrix.test.3.cpp
documentation_of: src/data-structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/src/data-structure/wavelet_matrix.hpp
- /library/src/data-structure/wavelet_matrix.hpp.html
title: src/data-structure/wavelet_matrix.hpp
---
