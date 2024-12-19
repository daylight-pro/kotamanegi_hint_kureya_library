---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    - https://www.acmicpc.net/source/87508962
  bundledCode: "#line 1 \"test/algorithm/rollback_mo.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n/*\n\u590F\
    \u5408\u5BBF Day1 A\nhttps://www.acmicpc.net/source/87508962\n\n#include \"test/template.hpp\"\
    \n#include \"src/algorithm/rollback_mo.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int N, Q;\n   cin >> N >> Q;\n   vector<int> A(N);\n   for(auto& a : A) cin\
    \ >> a;\n   vector<int> inv(N, -1);\n   map<int, int> mp1;\n   for(int e : A)\
    \ mp1[e]++;\n   {\n      int id = 0;\n      for(auto [x, y] : mp1) {\n       \
    \  inv[id] = x;\n         mp1[x] = id++;\n      }\n      for(int i = 0; i < N;\
    \ i++) { A[i] = mp1[A[i]]; }\n   }\n\n   int top = -1;\n   int count = 0;\n  \
    \ int ptop = -1;\n   int pcount = 0;\n   vector<int> cnt(N);\n   Mo_rollback mo(N,\
    \ Q);\n   vector<ll> ans(Q);\n   queue<int> history;\n   auto add_left = [&](int\
    \ idx) {\n      cnt[A[idx]]++;\n      history.push(A[idx]);\n      if(cnt[A[idx]]\
    \ > count || (cnt[A[idx]] == count && A[idx] > top)) {\n         top = A[idx];\n\
    \         count = cnt[A[idx]];\n      }\n   };\n   auto add_right = [&](int idx)\
    \ {\n      cnt[A[idx]]++;\n      history.push(A[idx]);\n      if(cnt[A[idx]] >\
    \ count) {\n         top = A[idx];\n         count = cnt[A[idx]];\n      } else\
    \ if(cnt[A[idx]] == count && A[idx] > top) top = A[idx];\n   };\n   auto rem =\
    \ [&](int idx) { ans[idx] = top; };\n   auto reset = [&]() {\n      top = -1;\n\
    \      count = 0;\n      fill(all(cnt), 0);\n      while(!history.empty()) history.pop();\n\
    \   };\n   auto snapshot = [&]() {\n      ptop = top;\n      pcount = count;\n\
    \      while(!history.empty()) history.pop();\n   };\n   auto rollback = [&]()\
    \ {\n      top = ptop;\n      count = pcount;\n      while(!history.empty()) {\n\
    \         cnt[history.front()]--;\n         history.pop();\n      }\n   };\n \
    \  for(int i = 0; i < Q; i++) {\n      int l, r;\n      cin >> l >> r;\n     \
    \ l--;\n      mo.insert(l, r);\n   }\n   mo.run(add_left, add_right, rem, reset,\
    \ snapshot, rollback);\n   for(auto& a : ans) cout << inv[a] << '\\n';\n   return\
    \ 0;\n}\n*/\n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n#line\
    \ 85 \"test/algorithm/rollback_mo.test.cpp\"\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   puts(\"Hello World\");\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n/*\n\u590F\u5408\u5BBF Day1 A\nhttps://www.acmicpc.net/source/87508962\n\n\
    #include \"test/template.hpp\"\n#include \"src/algorithm/rollback_mo.hpp\"\n\n\
    int main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >> N >>\
    \ Q;\n   vector<int> A(N);\n   for(auto& a : A) cin >> a;\n   vector<int> inv(N,\
    \ -1);\n   map<int, int> mp1;\n   for(int e : A) mp1[e]++;\n   {\n      int id\
    \ = 0;\n      for(auto [x, y] : mp1) {\n         inv[id] = x;\n         mp1[x]\
    \ = id++;\n      }\n      for(int i = 0; i < N; i++) { A[i] = mp1[A[i]]; }\n \
    \  }\n\n   int top = -1;\n   int count = 0;\n   int ptop = -1;\n   int pcount\
    \ = 0;\n   vector<int> cnt(N);\n   Mo_rollback mo(N, Q);\n   vector<ll> ans(Q);\n\
    \   queue<int> history;\n   auto add_left = [&](int idx) {\n      cnt[A[idx]]++;\n\
    \      history.push(A[idx]);\n      if(cnt[A[idx]] > count || (cnt[A[idx]] ==\
    \ count && A[idx] > top)) {\n         top = A[idx];\n         count = cnt[A[idx]];\n\
    \      }\n   };\n   auto add_right = [&](int idx) {\n      cnt[A[idx]]++;\n  \
    \    history.push(A[idx]);\n      if(cnt[A[idx]] > count) {\n         top = A[idx];\n\
    \         count = cnt[A[idx]];\n      } else if(cnt[A[idx]] == count && A[idx]\
    \ > top) top = A[idx];\n   };\n   auto rem = [&](int idx) { ans[idx] = top; };\n\
    \   auto reset = [&]() {\n      top = -1;\n      count = 0;\n      fill(all(cnt),\
    \ 0);\n      while(!history.empty()) history.pop();\n   };\n   auto snapshot =\
    \ [&]() {\n      ptop = top;\n      pcount = count;\n      while(!history.empty())\
    \ history.pop();\n   };\n   auto rollback = [&]() {\n      top = ptop;\n     \
    \ count = pcount;\n      while(!history.empty()) {\n         cnt[history.front()]--;\n\
    \         history.pop();\n      }\n   };\n   for(int i = 0; i < Q; i++) {\n  \
    \    int l, r;\n      cin >> l >> r;\n      l--;\n      mo.insert(l, r);\n   }\n\
    \   mo.run(add_left, add_right, rem, reset, snapshot, rollback);\n   for(auto&\
    \ a : ans) cout << inv[a] << '\\n';\n   return 0;\n}\n*/\n\n#include \"test/template.hpp\"\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   puts(\"Hello World\");\n\
    \   return 0;\n}"
  dependsOn:
  - test/template.hpp
  isVerificationFile: true
  path: test/algorithm/rollback_mo.test.cpp
  requiredBy: []
  timestamp: '2024-12-16 16:28:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/rollback_mo.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/rollback_mo.test.cpp
- /verify/test/algorithm/rollback_mo.test.cpp.html
title: test/algorithm/rollback_mo.test.cpp
---
