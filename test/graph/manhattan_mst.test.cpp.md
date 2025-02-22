---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/manhattan_mst.hpp
    title: src/graph/manhattan_mst.hpp
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
    - https://judge.yosupo.jp/submission/268852
  bundledCode: "#line 1 \"test/graph/manhattan_mst.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\
    \u307F https://judge.yosupo.jp/submission/268852\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define\
    \ all(a) begin(a), end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b,\
    \ 1 : 0; }\nbool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }\n\nstruct\
    \ UnionFind {\n   vector<int> par;\n   UnionFind(int n) :par(n, -1) { }\n   void\
    \ init(int n) { par.assign(n, -1); }\n   int root(int x) {\n      if (par[x] <\
    \ 0) return x;\n      else return par[x] = root(par[x]);\n   }\n   bool connect(int\
    \ x, int y) {\n      x = root(x); y = root(y);\n      if (x == y) return false;\n\
    \      if (par[x] > par[y]) swap(x, y);\n      par[x] += par[y];\n      par[y]\
    \ = x;\n      return true;\n   }\n   int size(int x) {\n      return -par[root(x)];\n\
    \   }\n};\n\n// \u5019\u88DC\u306E\u8FBA\u3092 O(N) \u672C\u306B\u6E1B\u3089\u3059\
    \u3002MST\u6642\u306F\u8FFD\u52A0\u3067sort, UF\u7B49\u306E\u5FC5\u8981\u3042\u308A\
    \u3002\ntemplate<typename T>\nvector<tuple<T, int, int>> manhattan_mst(vector<T>\
    \ xs, vector<T> ys) {\n   assert(xs.size() == ys.size());\n   vector<tuple<T,\
    \ int, int>> ret;\n   int n = (int) xs.size();\n\n   vector<int> ord(n);\n   iota(ord.begin(),\
    \ ord.end(), 0);\n\n   for(int s = 0; s < 2; s++) {\n      for(int t = 0; t <\
    \ 2; t++) {\n         auto cmp = [&](int i, int j) -> bool {\n            return\
    \ xs[i] + ys[i] < xs[j] + ys[j];\n         };\n         sort(ord.begin(), ord.end(),\
    \ cmp);\n\n         map<T, int> idx;\n         for(int i: ord) {\n           \
    \ for(auto it = idx.lower_bound(-ys[i]);\n                  it != idx.end(); it\
    \ = idx.erase(it)) {\n               int j = it->second;\n               if(xs[i]\
    \ - xs[j] < ys[i] - ys[j]) break;\n               ret.emplace_back(abs(xs[i] -\
    \ xs[j]) + abs(ys[i] - ys[j]), i, j);\n            }\n            idx[-ys[i]]\
    \ = i;\n         }\n         swap(xs, ys);\n      }\n      for(int i = 0; i <\
    \ n; i++) xs[i] *= -1;\n   }\n   return ret;\n}\n\nint main() {\n   int n; cin\
    \ >> n;\n   vector<ll> x(n), y(n);\n   for(int i = 0; i < n; i ++) cin >> x[i]\
    \ >> y[i];\n   auto ret = manhattan_mst(x, y);\n   UnionFind uf(n);\n   ll sum\
    \ = 0;\n   vector<pair<int, int>> edges;\n   sort(all(ret));\n   for(auto [a,\
    \ b, c] : ret) {\n      if(uf.root(b) == uf.root(c)) continue;\n      edges.push_back({b,\
    \ c});\n      sum += a;\n      uf.connect(b, c);\n   }\n   cout << sum << '\\\
    n';\n   for(auto [a, b] : edges) {\n      cout << a << \" \" << b << '\\n';\n\
    \   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/graph/manhattan_mst.hpp\"\
    \n// \u5019\u88DC\u306E\u8FBA\u3092 O(N) \u672C\u306B\u6E1B\u3089\u3059\u3002\
    MST\u6642\u306F\u8FFD\u52A0\u3067sort, UF\u7B49\u306E\u5FC5\u8981\u3042\u308A\u3002\
    \ntemplate<typename T> vector<tuple<T, int, int>> manhattan_mst(vector<T> xs,\
    \ vector<T> ys) {\n   assert(xs.size() == ys.size());\n   vector<tuple<T, int,\
    \ int>> ret;\n   int n = (int)xs.size();\n\n   vector<int> ord(n);\n   iota(ord.begin(),\
    \ ord.end(), 0);\n\n   for(int s = 0; s < 2; s++) {\n      for(int t = 0; t <\
    \ 2; t++) {\n         auto cmp = [&](int i, int j) -> bool { return xs[i] + ys[i]\
    \ < xs[j] + ys[j]; };\n         sort(ord.begin(), ord.end(), cmp);\n\n       \
    \  map<T, int> idx;\n         for(int i : ord) {\n            for(auto it = idx.lower_bound(-ys[i]);\
    \ it != idx.end(); it = idx.erase(it)) {\n               int j = it->second;\n\
    \               if(xs[i] - xs[j] < ys[i] - ys[j]) break;\n               ret.emplace_back(abs(xs[i]\
    \ - xs[j]) + abs(ys[i] - ys[j]), i, j);\n            }\n            idx[-ys[i]]\
    \ = i;\n         }\n         swap(xs, ys);\n      }\n      for(int i = 0; i <\
    \ n; i++) xs[i] *= -1;\n   }\n   return ret;\n}\n#line 93 \"test/graph/manhattan_mst.test.cpp\"\
    \n\nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://judge.yosupo.jp/submission/268852\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    const ll INF = LLONG_MAX / 4;\n#define all(a) begin(a), end(a)\nbool chmin(auto&\
    \ a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto& a, auto b) { return\
    \ a < b ? a = b, 1 : 0; }\n\nstruct UnionFind {\n   vector<int> par;\n   UnionFind(int\
    \ n) :par(n, -1) { }\n   void init(int n) { par.assign(n, -1); }\n   int root(int\
    \ x) {\n      if (par[x] < 0) return x;\n      else return par[x] = root(par[x]);\n\
    \   }\n   bool connect(int x, int y) {\n      x = root(x); y = root(y);\n    \
    \  if (x == y) return false;\n      if (par[x] > par[y]) swap(x, y);\n      par[x]\
    \ += par[y];\n      par[y] = x;\n      return true;\n   }\n   int size(int x)\
    \ {\n      return -par[root(x)];\n   }\n};\n\n// \u5019\u88DC\u306E\u8FBA\u3092\
    \ O(N) \u672C\u306B\u6E1B\u3089\u3059\u3002MST\u6642\u306F\u8FFD\u52A0\u3067sort,\
    \ UF\u7B49\u306E\u5FC5\u8981\u3042\u308A\u3002\ntemplate<typename T>\nvector<tuple<T,\
    \ int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {\n   assert(xs.size()\
    \ == ys.size());\n   vector<tuple<T, int, int>> ret;\n   int n = (int) xs.size();\n\
    \n   vector<int> ord(n);\n   iota(ord.begin(), ord.end(), 0);\n\n   for(int s\
    \ = 0; s < 2; s++) {\n      for(int t = 0; t < 2; t++) {\n         auto cmp =\
    \ [&](int i, int j) -> bool {\n            return xs[i] + ys[i] < xs[j] + ys[j];\n\
    \         };\n         sort(ord.begin(), ord.end(), cmp);\n\n         map<T, int>\
    \ idx;\n         for(int i: ord) {\n            for(auto it = idx.lower_bound(-ys[i]);\n\
    \                  it != idx.end(); it = idx.erase(it)) {\n               int\
    \ j = it->second;\n               if(xs[i] - xs[j] < ys[i] - ys[j]) break;\n \
    \              ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);\n\
    \            }\n            idx[-ys[i]] = i;\n         }\n         swap(xs, ys);\n\
    \      }\n      for(int i = 0; i < n; i++) xs[i] *= -1;\n   }\n   return ret;\n\
    }\n\nint main() {\n   int n; cin >> n;\n   vector<ll> x(n), y(n);\n   for(int\
    \ i = 0; i < n; i ++) cin >> x[i] >> y[i];\n   auto ret = manhattan_mst(x, y);\n\
    \   UnionFind uf(n);\n   ll sum = 0;\n   vector<pair<int, int>> edges;\n   sort(all(ret));\n\
    \   for(auto [a, b, c] : ret) {\n      if(uf.root(b) == uf.root(c)) continue;\n\
    \      edges.push_back({b, c});\n      sum += a;\n      uf.connect(b, c);\n  \
    \ }\n   cout << sum << '\\n';\n   for(auto [a, b] : edges) {\n      cout << a\
    \ << \" \" << b << '\\n';\n   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/graph/manhattan_mst.hpp\"\n\n\
    int main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/graph/manhattan_mst.hpp
  isVerificationFile: true
  path: test/graph/manhattan_mst.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/manhattan_mst.test.cpp
layout: document
redirect_from:
- /verify/test/graph/manhattan_mst.test.cpp
- /verify/test/graph/manhattan_mst.test.cpp.html
title: test/graph/manhattan_mst.test.cpp
---
