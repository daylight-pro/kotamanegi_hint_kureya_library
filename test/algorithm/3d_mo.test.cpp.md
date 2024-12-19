---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/3d_mo.hpp
    title: src/algorithm/3d_mo.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/algorithm/3d_mo.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/3d_mo.hpp\"\
    \nstruct Mo_3D {\n   int width;\n   vector<int> left, right, index, order;\n \
    \  vector<bool> v;\n   function<void(int)> add, del;\n\n   Mo_3D(int N, int Q)\
    \ : order(Q), v(N) { width = max<int>(1, pow(N, 2.0 / 3.0)); }\n   void insert(int\
    \ idx, int l, int r) {\n      index.push_back(idx);\n      left.emplace_back(l);\n\
    \      right.emplace_back(r);\n   }\n\n   void run(const auto& add, const auto&\
    \ del, const auto& rem, const auto& add_query, const auto& del_query) {\n    \
    \  this->add = add;\n      this->del = del;\n      order.resize(size(left));\n\
    \      iota(all(order), 0);\n      sort(all(order), [&](int a, int b) -> bool\
    \ {\n         if(left[a] / width != left[b] / width) return left[a] < left[b];\n\
    \         if(right[a] / width != right[b] / width) return ((right[a] < right[b])\
    \ ^ (left[a] / width % 2));\n         return bool((index[a] < index[b]) ^ (right[a]\
    \ / width % 2));\n      });\n      int time = 0, nl = 0, nr = 0;\n      for(auto\
    \ idx : order) {\n         while(time < index[idx]) add_query(time++, this);\n\
    \         while(time > index[idx]) del_query(--time, this);\n         while(nl\
    \ > left[idx]) distribute(--nl);\n         while(nr < right[idx]) distribute(nr++);\n\
    \         while(nl < left[idx]) distribute(nl++);\n         while(nr > right[idx])\
    \ distribute(--nr);\n         rem(index[idx]);\n      }\n   }\n\n   void distribute(int\
    \ idx) {\n      if(v[idx]) del(idx);\n      else add(idx);\n      v[idx] = !v[idx];\n\
    \   }\n};\n#line 4 \"test/algorithm/3d_mo.test.cpp\"\n\nint main() {\n   int N,\
    \ Q;\n   cin >> N >> Q;\n   vector<ll> A(N);\n   vector<ll> ans(Q);\n   vector<int>\
    \ type(Q), l(Q), r(Q);\n   Mo_3D mo(N, Q);\n   for(int i = 0; i < Q; i++) {\n\
    \      cin >> type[i] >> l[i] >> r[i];\n      l[i]--;\n      if(type[i] == 1)\
    \ { mo.insert(i, l[i], r[i]); }\n   }\n   ll sum = 0;\n   auto add = [&](int x)\
    \ { sum += A[x]; };\n   auto del = [&](int x) { sum -= A[x]; };\n   auto rem =\
    \ [&](int ind) { ans[ind] = sum; };\n   auto add_query = [&](int x, const auto&\
    \ self) {\n      if(type[x] == 1) return;\n      if(self->v[l[x]]) {\n       \
    \  self->distribute(l[x]);\n         A[l[x]] += r[x];\n         self->distribute(l[x]);\n\
    \      } else {\n         A[l[x]] += r[x];\n      }\n   };\n   auto del_query\
    \ = [&](int x, const auto& self) {\n      if(type[x] == 1) return;\n      if(self->v[l[x]])\
    \ {\n         self->distribute(l[x]);\n         A[l[x]] -= r[x];\n         self->distribute(l[x]);\n\
    \      } else {\n         A[l[x]] -= r[x];\n      }\n   };\n   mo.run(add, del,\
    \ rem, add_query, del_query);\n   for(int i = 0; i < Q; i++) {\n      if(type[i]\
    \ == 1) cout << ans[i] << '\\n';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include \"test/template.hpp\"\n#include \"src/algorithm/3d_mo.hpp\"\n\nint\
    \ main() {\n   int N, Q;\n   cin >> N >> Q;\n   vector<ll> A(N);\n   vector<ll>\
    \ ans(Q);\n   vector<int> type(Q), l(Q), r(Q);\n   Mo_3D mo(N, Q);\n   for(int\
    \ i = 0; i < Q; i++) {\n      cin >> type[i] >> l[i] >> r[i];\n      l[i]--;\n\
    \      if(type[i] == 1) { mo.insert(i, l[i], r[i]); }\n   }\n   ll sum = 0;\n\
    \   auto add = [&](int x) { sum += A[x]; };\n   auto del = [&](int x) { sum -=\
    \ A[x]; };\n   auto rem = [&](int ind) { ans[ind] = sum; };\n   auto add_query\
    \ = [&](int x, const auto& self) {\n      if(type[x] == 1) return;\n      if(self->v[l[x]])\
    \ {\n         self->distribute(l[x]);\n         A[l[x]] += r[x];\n         self->distribute(l[x]);\n\
    \      } else {\n         A[l[x]] += r[x];\n      }\n   };\n   auto del_query\
    \ = [&](int x, const auto& self) {\n      if(type[x] == 1) return;\n      if(self->v[l[x]])\
    \ {\n         self->distribute(l[x]);\n         A[l[x]] -= r[x];\n         self->distribute(l[x]);\n\
    \      } else {\n         A[l[x]] -= r[x];\n      }\n   };\n   mo.run(add, del,\
    \ rem, add_query, del_query);\n   for(int i = 0; i < Q; i++) {\n      if(type[i]\
    \ == 1) cout << ans[i] << '\\n';\n   }\n}"
  dependsOn:
  - test/template.hpp
  - src/algorithm/3d_mo.hpp
  isVerificationFile: true
  path: test/algorithm/3d_mo.test.cpp
  requiredBy: []
  timestamp: '2024-12-19 19:21:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/3d_mo.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/3d_mo.test.cpp
- /verify/test/algorithm/3d_mo.test.cpp.html
title: test/algorithm/3d_mo.test.cpp
---
