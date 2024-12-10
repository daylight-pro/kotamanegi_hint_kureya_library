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
    PROBLEM: https://yukicoder.me/problems/1601
    links:
    - https://yukicoder.me/problems/1601
  bundledCode: "#line 1 \"test/data-structure/range_set.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/1601\"\n\n#line 1 \"test/template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst ll INF =\
    \ LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto& a, auto b)\
    \ { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b\
    \ ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/range_set.hpp\"\ntemplate<bool\
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
    \ && q <= it->second;\n   }\n};\n#line 5 \"test/data-structure/range_set.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll D, Q;\n   cin >> D\
    \ >> Q;\n   ll ans = 0;\n   range_set<> rs;\n   while(Q--) {\n      ll A, B;\n\
    \      cin >> A >> B;\n      rs.insert(A, B);\n      auto [l, r] = *rs.get(A);\n\
    \      chmax(ans, r - l + 1);\n      cout << ans << '\\n';\n   }\n   return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/1601\"\n\n#include \"test/template.hpp\"\
    \n#include \"src/data-structure/range_set.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   ll D, Q;\n   cin >> D >> Q;\n   ll ans = 0;\n   range_set<> rs;\n   while(Q--)\
    \ {\n      ll A, B;\n      cin >> A >> B;\n      rs.insert(A, B);\n      auto\
    \ [l, r] = *rs.get(A);\n      chmax(ans, r - l + 1);\n      cout << ans << '\\\
    n';\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/data-structure/range_set.hpp
  isVerificationFile: true
  path: test/data-structure/range_set.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 18:11:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range_set.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range_set.test.cpp
- /verify/test/data-structure/range_set.test.cpp.html
title: test/data-structure/range_set.test.cpp
---
