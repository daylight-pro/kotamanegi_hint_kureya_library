---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/doubling.hpp
    title: src/algorithm/doubling.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2320
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2320
  bundledCode: "#line 1 \"test/algorithm/doubling.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2320\"\
    \n\n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/algorithm/doubling.hpp\"\
    \ntemplate<int L> struct Doubling {\n   private:\n   vector<vector<int>> V;\n\n\
    \   public:\n   Doubling(const vector<int>& v) {\n      int N = size(v);\n   \
    \   V = vector<vector<int>>(L, vector<int>(N));\n      for(int i = 0; i < N; i++)\
    \ V[0][i] = v[i];\n      for(int i = 0; i < L - 1; i++)\n         for(int j =\
    \ 0; j < N; j++) {\n            if(V[i][j] != -1) V[i + 1][j] = V[i][V[i][j]];\n\
    \         }\n   }\n\n   int jump(int from, ll k) {\n      for(int cnt = 0; k >\
    \ 0; k >>= 1, ++cnt) {\n         if((k & 1) && from != -1) from = V[cnt][from];\n\
    \      }\n      return from;\n   }\n};\n#line 5 \"test/algorithm/doubling.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int H, W;\n   ll L;\n\
    \   while(cin >> H >> W >> L) {\n      if(H == 0 && W == 0 && L == 0) break;\n\
    \      vector<string> S(H);\n      for(auto&& s : S) cin >> s;\n      vector<int>\
    \ nxt(H * W * 4, -1);\n      int dx[4] = {1, 0, -1, 0};\n      int dy[4] = {0,\
    \ 1, 0, -1};\n      int y, x, dir;\n      for(int i = 0; i < H; i++) {\n     \
    \    for(int j = 0; j < W; j++) {\n            if(S[i][j] == 'E') {\n        \
    \       y = i;\n               x = j;\n               dir = 0;\n             \
    \  break;\n            } else if(S[i][j] == 'S') {\n               y = i;\n  \
    \             x = j;\n               dir = 1;\n               break;\n       \
    \     } else if(S[i][j] == 'W') {\n               y = i;\n               x = j;\n\
    \               dir = 2;\n               break;\n            } else if(S[i][j]\
    \ == 'N') {\n               y = i;\n               x = j;\n               dir\
    \ = 3;\n               break;\n            }\n         }\n      }\n      int sy\
    \ = y, sx = x, sd = dir;\n      while(nxt[y * 4 * W + 4 * x + dir] == -1) {\n\
    \         int ny = y + dy[dir];\n         int nx = x + dx[dir];\n         int\
    \ pd = dir;\n         while(ny < 0 || ny >= H || nx < 0 || nx >= W || S[ny][nx]\
    \ == '#') {\n            dir = (dir + 1) % 4;\n            ny = y + dy[dir];\n\
    \            nx = x + dx[dir];\n         }\n         nxt[y * 4 * W + 4 * x + pd]\
    \ = ny * 4 * W + 4 * nx + dir;\n         y = ny;\n         x = nx;\n      }\n\
    \      Doubling<60> db(nxt);\n      int to = db.jump(sy * W * 4 + 4 * sx + sd,\
    \ L);\n      int Y = to / W / 4;\n      int X = to / 4 % W;\n      int d = to\
    \ % 4;\n      cout << Y + 1 << ' ' << X + 1 << ' ';\n      if(d == 0) cout <<\
    \ 'E';\n      if(d == 1) cout << 'S';\n      if(d == 2) cout << 'W';\n      if(d\
    \ == 3) cout << 'N';\n\n      cout << '\\n';\n   }\n   return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2320\"\n\n#include\
    \ \"test/template.hpp\"\n#include \"src/algorithm/doubling.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   int H, W;\n   ll L;\n   while(cin\
    \ >> H >> W >> L) {\n      if(H == 0 && W == 0 && L == 0) break;\n      vector<string>\
    \ S(H);\n      for(auto&& s : S) cin >> s;\n      vector<int> nxt(H * W * 4, -1);\n\
    \      int dx[4] = {1, 0, -1, 0};\n      int dy[4] = {0, 1, 0, -1};\n      int\
    \ y, x, dir;\n      for(int i = 0; i < H; i++) {\n         for(int j = 0; j <\
    \ W; j++) {\n            if(S[i][j] == 'E') {\n               y = i;\n       \
    \        x = j;\n               dir = 0;\n               break;\n            }\
    \ else if(S[i][j] == 'S') {\n               y = i;\n               x = j;\n  \
    \             dir = 1;\n               break;\n            } else if(S[i][j] ==\
    \ 'W') {\n               y = i;\n               x = j;\n               dir = 2;\n\
    \               break;\n            } else if(S[i][j] == 'N') {\n            \
    \   y = i;\n               x = j;\n               dir = 3;\n               break;\n\
    \            }\n         }\n      }\n      int sy = y, sx = x, sd = dir;\n   \
    \   while(nxt[y * 4 * W + 4 * x + dir] == -1) {\n         int ny = y + dy[dir];\n\
    \         int nx = x + dx[dir];\n         int pd = dir;\n         while(ny < 0\
    \ || ny >= H || nx < 0 || nx >= W || S[ny][nx] == '#') {\n            dir = (dir\
    \ + 1) % 4;\n            ny = y + dy[dir];\n            nx = x + dx[dir];\n  \
    \       }\n         nxt[y * 4 * W + 4 * x + pd] = ny * 4 * W + 4 * nx + dir;\n\
    \         y = ny;\n         x = nx;\n      }\n      Doubling<60> db(nxt);\n  \
    \    int to = db.jump(sy * W * 4 + 4 * sx + sd, L);\n      int Y = to / W / 4;\n\
    \      int X = to / 4 % W;\n      int d = to % 4;\n      cout << Y + 1 << ' '\
    \ << X + 1 << ' ';\n      if(d == 0) cout << 'E';\n      if(d == 1) cout << 'S';\n\
    \      if(d == 2) cout << 'W';\n      if(d == 3) cout << 'N';\n\n      cout <<\
    \ '\\n';\n   }\n   return 0;\n}"
  dependsOn:
  - test/template.hpp
  - src/algorithm/doubling.hpp
  isVerificationFile: true
  path: test/algorithm/doubling.test.cpp
  requiredBy: []
  timestamp: '2024-12-10 19:12:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/doubling.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/doubling.test.cpp
- /verify/test/algorithm/doubling.test.cpp.html
title: test/algorithm/doubling.test.cpp
---
