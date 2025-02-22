---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/eulerian_trail.hpp
    title: src/graph/eulerian_trail.hpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu.hpp
    title: test/data-structure/dsu.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_undirected
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_undirected
  bundledCode: "#line 1 \"test/graph/eulerian_trail.test.undirected.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\n\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"test/data-structure/dsu.hpp\"\
    \n// base: d569f4\nstruct dsu {\n   private:\n   int _n;\n   vector<int> p;\n\n\
    \   public:\n   dsu() : _n(0) {}\n   explicit dsu(int n) : _n(n), p(n, -1) {}\n\
    \n   int merge(int a, int b) {\n      // assert(0 <= a && a < _n);\n      // assert(0\
    \ <= b && b < _n);\n      int x = leader(a), y = leader(b);\n      if(x == y)\
    \ return x;\n      if(-p[x] < -p[y]) swap(x, y);\n      p[x] += p[y];\n      p[y]\
    \ = x;\n      return x;\n   }\n\n   bool same(int a, int b) {\n      // assert(0\
    \ <= a && a < _n);\n      // assert(0 <= b && b < _n);\n      return leader(a)\
    \ == leader(b);\n   }\n\n   int leader(int a) {\n      // assert(0 <= a && a <\
    \ _n);\n      if(p[a] < 0) return a;\n      int x = a;\n      while(p[x] >= 0)\
    \ x = p[x];\n      while(p[a] >= 0) {\n         int t = p[a];\n         p[a] =\
    \ x;\n         a = t;\n      }\n      return x;\n   }\n\n   int size(int a) {\n\
    \      // assert(0 <= a && a < _n);\n      return -p[leader(a)];\n   }  // 818fe7\n\
    \n   vector<vector<int>> groups() {\n      vector<int> leader_buf(_n), group_size(_n);\n\
    \      for(int i = 0; i < _n; i++) {\n         leader_buf[i] = leader(i);\n  \
    \       group_size[leader_buf[i]]++;\n      }\n      vector<vector<int>> result(_n);\n\
    \      for(int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n      for(int\
    \ i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n      result.erase(remove_if(result.begin(),\
    \ result.end(), [&](const vector<int>& v) { return v.empty(); }),\n          \
    \         result.end());\n      return result;\n   }  // bf3a1e\n};\n#line 1 \"\
    src/graph/eulerian_trail.hpp\"\n// base: 72bf84\ntemplate<bool directed> struct\
    \ EulerianTrail {\n   vector<vector<pair<int, int>>> G;\n   vector<pair<int, int>>\
    \ es;\n   int M;\n   vector<int> usedV, usedE, deg;\n\n   EulerianTrail(int N)\
    \ : G(N), deg(N), usedV(N), M(0) {}\n\n   void add_edge(int a, int b) {\n    \
    \  es.emplace_back(a, b);\n      G[a].emplace_back(b, M);\n      if(directed)\
    \ {\n         deg[a]++;\n         deg[b]--;\n      } else {\n         G[b].emplace_back(a,\
    \ M);\n         deg[a]++;\n         deg[b]++;\n      }\n      M++;\n   }\n\n \
    \  vector<int> go(int s) {\n      stack<pair<int, int>> st;\n      vector<int>\
    \ ord;\n      st.emplace(s, -1);\n      while(!st.empty()) {\n         int i =\
    \ st.top().first;\n         usedV[i] = true;\n         if(G[i].empty()) {\n  \
    \          ord.emplace_back(st.top().second);\n            st.pop();\n       \
    \  } else {\n            auto e = G[i].back();\n            G[i].pop_back();\n\
    \            if(usedE[e.second]) continue;\n            usedE[e.second] = true;\n\
    \            if(!directed && es[e.second].first != i) swap(es[e.second].first,\
    \ es[e.second].second);\n            st.emplace(e);\n         }\n      }\n   \
    \   ord.pop_back();\n      reverse(all(ord));\n      return ord;\n   }\n\n   vector<vector<int>>\
    \ enumerate_et() {\n      if(directed) {\n         for(auto& p : deg)\n      \
    \      if(p != 0) return {};\n      } else {\n         for(auto& p : deg) {\n\
    \            if(p & 1) return {};\n         }\n      }\n      usedE.assign(M,\
    \ 0);\n      vector<vector<int>> ret;\n      for(int i = 0; i < size(G); i++)\
    \ {\n         if(G[i].empty() || usedV[i]) continue;\n         ret.emplace_back(go(i));\n\
    \      }\n      return ret;\n   }  // a9700f\n\n   vector<vector<int>> enumerate_semi_et()\
    \ {\n      dsu d(size(G));\n      for(auto& p : es) d.merge(p.first, p.second);\n\
    \      vector<vector<int>> group(size(G));\n      for(int i = 0; i < size(G);\
    \ i++) group[d.leader(i)].emplace_back(i);\n      vector<vector<int>> ret;\n \
    \     usedE.assign(M, 0);\n      for(auto& vs : group) {\n         if(vs.empty())\
    \ continue;\n         int latte = -1, malta = -1;\n         if(directed) {\n \
    \           for(auto& p : vs) {\n               if(abs(deg[p]) > 1) return {};\n\
    \               else if(deg[p] == 1) {\n                  if(latte >= 0) return\
    \ {};\n                  latte = p;\n               }\n            }\n       \
    \  } else {\n            for(auto& p : vs) {\n               if(deg[p] & 1) {\n\
    \                  if(latte == -1) latte = p;\n                  else if(malta\
    \ == -1) malta = p;\n                  else return {};\n               }\n   \
    \         }\n         }\n         ret.emplace_back(go(latte == -1 ? vs.front()\
    \ : latte));\n         if(ret.back().empty()) ret.pop_back();\n      }\n     \
    \ return ret;\n   }  // 97a2af\n\n   pair<int, int> get_edge(int i) { return es[i];\
    \ }  // c83977\n};\n#line 6 \"test/graph/eulerian_trail.test.undirected.cpp\"\n\
    \nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int T;\n   cin >> T;\n\
    \   while(T--) {\n      int N, M;\n      cin >> N >> M;\n      EulerianTrail<false>\
    \ et(N);\n      for(int i = 0; i < M; i++) {\n         int a, b;\n         cin\
    \ >> a >> b;\n         et.add_edge(a, b);\n      }\n      if(M == 0) {\n     \
    \    cout << \"Yes\" << \"\\n\";\n         cout << \"0\" << \"\\n\";\n       \
    \  cout << \"\\n\";\n         continue;\n      }\n      auto ans = et.enumerate_semi_et();\n\
    \      if(size(ans) != 1) {\n         cout << \"No\" << \"\\n\";\n      } else\
    \ {\n         cout << \"Yes\" << \"\\n\";\n         cout << et.get_edge(ans[0][0]).first;\n\
    \         for(auto i : ans[0]) { cout << \" \" << et.get_edge(i).second; }\n \
    \        cout << \"\\n\";\n         for(int i = 0; i < M; i++) { cout << ans[0][i]\
    \ << \" \\n\"[i == M - 1]; }\n      }\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\
    \n\n#include \"test/template.hpp\"\n#include \"test/data-structure/dsu.hpp\"\n\
    #include \"src/graph/eulerian_trail.hpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   int T;\n   cin >> T;\n   while(T--) {\n      int N, M;\n      cin >> N >>\
    \ M;\n      EulerianTrail<false> et(N);\n      for(int i = 0; i < M; i++) {\n\
    \         int a, b;\n         cin >> a >> b;\n         et.add_edge(a, b);\n  \
    \    }\n      if(M == 0) {\n         cout << \"Yes\" << \"\\n\";\n         cout\
    \ << \"0\" << \"\\n\";\n         cout << \"\\n\";\n         continue;\n      }\n\
    \      auto ans = et.enumerate_semi_et();\n      if(size(ans) != 1) {\n      \
    \   cout << \"No\" << \"\\n\";\n      } else {\n         cout << \"Yes\" << \"\
    \\n\";\n         cout << et.get_edge(ans[0][0]).first;\n         for(auto i :\
    \ ans[0]) { cout << \" \" << et.get_edge(i).second; }\n         cout << \"\\n\"\
    ;\n         for(int i = 0; i < M; i++) { cout << ans[0][i] << \" \\n\"[i == M\
    \ - 1]; }\n      }\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - test/data-structure/dsu.hpp
  - src/graph/eulerian_trail.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail.test.undirected.cpp
  requiredBy: []
  timestamp: '2025-01-07 15:52:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/eulerian_trail.test.undirected.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail.test.undirected.cpp
- /verify/test/graph/eulerian_trail.test.undirected.cpp.html
title: test/graph/eulerian_trail.test.undirected.cpp
---
