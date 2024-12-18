---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/wavelet_matrix.hpp
    title: src/data-structure/wavelet_matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data-structure/wavelet_matrix.test.4.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/wavelet_matrix.hpp\"\n\
    // base: be292e\nstruct BitVector {\n   private:\n   vector<int> vec;\n\n   public:\n\
    \   BitVector(const vector<int>& a) {\n      vec.resize(a.size() + 1);\n     \
    \ for(int j = 0; j < (int)a.size(); j++) { vec[j + 1] = vec[j] + a[j]; }\n   }\n\
    \n   int get(const int i) { return vec[i + 1] - vec[i]; }\n\n   int rank(const\
    \ int b, const int i) {\n      if(b == 0) return i - vec[i];\n      else return\
    \ vec[i];\n   }\n};\n\ntemplate<typename T, int bit_len = 62> struct WaveletMatrix\
    \ {\n   private:\n   vector<BitVector> B;\n   vector<vector<T>> acc;\n   vector<int>\
    \ so;\n   map<T, int> sn;\n   int len;\n\n   public:\n   WaveletMatrix(vector<T>\
    \ vec) {\n      len = vec.size();\n      acc = vector<vector<T>>(bit_len, vector<T>(len\
    \ + 1));\n      so = vector<int>(bit_len);\n      vector<T> v(vec);\n      for(int\
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
    \ right = r;\n         }\n      }\n      return ret;\n   }  // 029c6d\n};\n#line\
    \ 4 \"test/data-structure/wavelet_matrix.test.4.cpp\"\n\nint main() {\n   int\
    \ N, Q;\n   cin >> N >> Q;\n   vector<ll> A(N);\n   for(auto& a : A) cin >> a;\n\
    \   WaveletMatrix wm(A);\n   while(Q--) {\n      int l, r;\n      cin >> l >>\
    \ r;\n      cout << wm.kthMin(l, r, 0) << endl;\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    test/template.hpp\"\n#include \"src/data-structure/wavelet_matrix.hpp\"\n\nint\
    \ main() {\n   int N, Q;\n   cin >> N >> Q;\n   vector<ll> A(N);\n   for(auto&\
    \ a : A) cin >> a;\n   WaveletMatrix wm(A);\n   while(Q--) {\n      int l, r;\n\
    \      cin >> l >> r;\n      cout << wm.kthMin(l, r, 0) << endl;\n   }\n   return\
    \ 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/data-structure/wavelet_matrix.test.4.cpp
  requiredBy: []
  timestamp: '2024-12-18 15:33:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/wavelet_matrix.test.4.cpp
layout: document
redirect_from:
- /verify/test/data-structure/wavelet_matrix.test.4.cpp
- /verify/test/data-structure/wavelet_matrix.test.4.cpp.html
title: test/data-structure/wavelet_matrix.test.4.cpp
---
