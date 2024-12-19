---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/eulerian_trail.test.directed.cpp
    title: test/graph/eulerian_trail.test.directed.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/eulerian_trail.test.undirected.cpp
    title: test/graph/eulerian_trail.test.undirected.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/eulerian_trail.hpp\"\n// base: 72bf84\ntemplate<bool\
    \ directed> struct EulerianTrail {\n   vector<vector<pair<int, int>>> G;\n   vector<pair<int,\
    \ int>> es;\n   int M;\n   vector<int> usedV, usedE, deg;\n\n   EulerianTrail(int\
    \ N) : G(N), deg(N), usedV(N), M(0) {}\n\n   void add_edge(int a, int b) {\n \
    \     es.emplace_back(a, b);\n      G[a].emplace_back(b, M);\n      if(directed)\
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
    \ }  // c83977\n};\n"
  code: "// base: 72bf84\ntemplate<bool directed> struct EulerianTrail {\n   vector<vector<pair<int,\
    \ int>>> G;\n   vector<pair<int, int>> es;\n   int M;\n   vector<int> usedV, usedE,\
    \ deg;\n\n   EulerianTrail(int N) : G(N), deg(N), usedV(N), M(0) {}\n\n   void\
    \ add_edge(int a, int b) {\n      es.emplace_back(a, b);\n      G[a].emplace_back(b,\
    \ M);\n      if(directed) {\n         deg[a]++;\n         deg[b]--;\n      } else\
    \ {\n         G[b].emplace_back(a, M);\n         deg[a]++;\n         deg[b]++;\n\
    \      }\n      M++;\n   }\n\n   vector<int> go(int s) {\n      stack<pair<int,\
    \ int>> st;\n      vector<int> ord;\n      st.emplace(s, -1);\n      while(!st.empty())\
    \ {\n         int i = st.top().first;\n         usedV[i] = true;\n         if(G[i].empty())\
    \ {\n            ord.emplace_back(st.top().second);\n            st.pop();\n \
    \        } else {\n            auto e = G[i].back();\n            G[i].pop_back();\n\
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
    \ }  // c83977\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/eulerian_trail.hpp
  requiredBy: []
  timestamp: '2024-12-19 04:39:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/eulerian_trail.test.undirected.cpp
  - test/graph/eulerian_trail.test.directed.cpp
documentation_of: src/graph/eulerian_trail.hpp
layout: document
redirect_from:
- /library/src/graph/eulerian_trail.hpp
- /library/src/graph/eulerian_trail.hpp.html
title: src/graph/eulerian_trail.hpp
---
