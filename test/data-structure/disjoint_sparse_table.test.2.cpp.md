---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/disjoint_sparse_table.hpp
    title: src/data-structure/disjoint_sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/data-structure/disjoint_sparse_table.test.2.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/disjoint_sparse_table.hpp\"\
    \ntemplate<typename SG> struct disjoint_sparse_table {\n   using S = typename\
    \ SG::S;\n   vector<vector<S>> st;\n   vector<int> lg;\n\n   disjoint_sparse_table(const\
    \ vector<S>& v) {\n      int b = 0;\n      while((1 << b) <= size(v)) b++;\n \
    \     st.assign(b, vector<S>(size(v)));\n      for(int i = 0; i < size(v); i++)\
    \ st[0][i] = v[i];\n      for(int i = 1; i < b; i++) {\n         int shift = 1\
    \ << i;\n         for(int j = 0; j < size(v); j += shift << 1) {\n           \
    \ int t = min(j + shift, (int)size(v));\n            st[i][t - 1] = v[t - 1];\n\
    \            for(int k = t - 2; k >= j; k--) st[i][k] = SG::op(v[k], st[i][k +\
    \ 1]);\n            if(size(v) <= t) break;\n            st[i][t] = v[t];\n  \
    \          for(int k = t + 1; k < min((int)size(v), t + shift); k++) st[i][k]\
    \ = SG::op(st[i][k - 1], v[k]);\n         }\n      }\n      lg.resize(1 << b);\n\
    \      for(int i = 2; i < size(lg); i++) lg[i] = lg[i >> 1] + 1;\n   }\n   S prod(int\
    \ l, int r) {\n      if(l >= --r) return st[0][l];\n      int b = lg[l ^ r];\n\
    \      return SG::op(st[b][l], st[b][r]);\n   }\n};\n#line 5 \"test/data-structure/disjoint_sparse_table.test.2.cpp\"\
    \n\nstruct SG {\n   using S = ll;\n   static S op(S a, S b) { return a + b; }\n\
    };\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   vector<ll> A(N);\n   for(auto&& a : A) cin >> a;\n   disjoint_sparse_table<SG>\
    \ st(A);\n   while(Q--) {\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ st.prod(l, r) << '\\n';\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"test/template.hpp\"\n#include \"src/data-structure/disjoint_sparse_table.hpp\"\
    \n\nstruct SG {\n   using S = ll;\n   static S op(S a, S b) { return a + b; }\n\
    };\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >>\
    \ N >> Q;\n   vector<ll> A(N);\n   for(auto&& a : A) cin >> a;\n   disjoint_sparse_table<SG>\
    \ st(A);\n   while(Q--) {\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ st.prod(l, r) << '\\n';\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/data-structure/disjoint_sparse_table.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-12 20:19:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/disjoint_sparse_table.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/disjoint_sparse_table.test.2.cpp
- /verify/test/data-structure/disjoint_sparse_table.test.2.cpp.html
title: test/data-structure/disjoint_sparse_table.test.2.cpp
---
