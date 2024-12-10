---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/range_set.hpp
    title: src/data-structure/range_set.hpp
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2880
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2880
  bundledCode: "#line 1 \"test/data-structure/range_set.test.2.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a,\
    \ auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/range_set.hpp\"\ntemplate<bool\
    \ margeAdjacent = true> struct range_set : public map<ll, ll> {\n   auto get(ll\
    \ p) const {\n      auto it = upper_bound(p);\n      if(it == begin() || (--it)->second\
    \ < p) return end();\n      return it;\n   }\n\n   void insert(ll l, ll r) {\n\
    \      auto itl = upper_bound(l), itr = upper_bound(r + margeAdjacent);\n    \
    \  if(itl != begin()) {\n         if((--itl)->second < l - margeAdjacent) ++itl;\n\
    \      }\n      if(itl != itr) {\n         l = min(l, itl->first);\n         r\
    \ = max(r, prev(itr)->second);\n         erase(itl, itr);\n      }\n      (*this)[l]\
    \ = r;\n   }\n\n   void remove(ll l, ll r) {\n      auto itl = upper_bound(l),\
    \ itr = upper_bound(r);\n      if(itl != begin())\n         if((--itl)->second\
    \ < l) ++itl;\n      if(itl == itr) return;\n      int tl = min(l, itl->first),\
    \ tr = max(r, prev(itr)->second);\n      erase(itl, itr);\n      if(tl < l) (*this)[tl]\
    \ = l - 1;\n      if(r < tr) (*this)[r + 1] = tr;\n   }\n\n   bool same(ll p,\
    \ ll q) {\n      auto it = get(p);\n      return it != end() && it->first <= q\
    \ && q <= it->second;\n   }\n};\n#line 5 \"test/data-structure/range_set.test.2.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M, Q;\n   cin\
    \ >> N >> M >> Q;\n   using T = tuple<int, int, int>;\n   priority_queue<T, vector<T>,\
    \ greater<>> update, query;\n   for(int i = 0; i < M; i++) {\n      int D, A,\
    \ B;\n      cin >> D >> A >> B;\n      update.emplace(D, A, B);\n   }\n   vector<pair<int,\
    \ int>> q(Q);\n   for(int i = 0; i < Q; i++) {\n      int E, S, T;\n      cin\
    \ >> E >> S >> T;\n      query.emplace(E, i, -1);\n      q[i] = {S, T};\n   }\n\
    \   range_set<false> rs;\n   vector<bool> ansV(Q);\n   while(!query.empty()) {\n\
    \      auto [E, I, _] = query.top();\n      query.pop();\n      while(!update.empty()\
    \ && get<0>(update.top()) < E) {\n         auto [D, A, B] = update.top();\n  \
    \       update.pop();\n         rs.insert(A, B);\n      }\n      auto [S, T] =\
    \ q[I];\n      auto it = rs.get(S);\n      bool ans = false;\n      if(it == rs.end())\
    \ {\n         if(S >= T) ans = true;\n      } else {\n         auto [l, r] = *it;\n\
    \         if(r >= T) ans = true;\n      }\n      ansV[I] = ans;\n   }\n   for(auto\
    \ ans : ansV) cout << (ans ? \"Yes\" : \"No\") << '\\n';\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/data-structure/range_set.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, M, Q;\n   cin >> N >>\
    \ M >> Q;\n   using T = tuple<int, int, int>;\n   priority_queue<T, vector<T>,\
    \ greater<>> update, query;\n   for(int i = 0; i < M; i++) {\n      int D, A,\
    \ B;\n      cin >> D >> A >> B;\n      update.emplace(D, A, B);\n   }\n   vector<pair<int,\
    \ int>> q(Q);\n   for(int i = 0; i < Q; i++) {\n      int E, S, T;\n      cin\
    \ >> E >> S >> T;\n      query.emplace(E, i, -1);\n      q[i] = {S, T};\n   }\n\
    \   range_set<false> rs;\n   vector<bool> ansV(Q);\n   while(!query.empty()) {\n\
    \      auto [E, I, _] = query.top();\n      query.pop();\n      while(!update.empty()\
    \ && get<0>(update.top()) < E) {\n         auto [D, A, B] = update.top();\n  \
    \       update.pop();\n         rs.insert(A, B);\n      }\n      auto [S, T] =\
    \ q[I];\n      auto it = rs.get(S);\n      bool ans = false;\n      if(it == rs.end())\
    \ {\n         if(S >= T) ans = true;\n      } else {\n         auto [l, r] = *it;\n\
    \         if(r >= T) ans = true;\n      }\n      ansV[I] = ans;\n   }\n   for(auto\
    \ ans : ansV) cout << (ans ? \"Yes\" : \"No\") << '\\n';\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/range_set.hpp
  isVerificationFile: true
  path: test/data-structure/range_set.test.2.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range_set.test.2.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range_set.test.2.cpp
- /verify/test/data-structure/range_set.test.2.cpp.html
title: test/data-structure/range_set.test.2.cpp
---
