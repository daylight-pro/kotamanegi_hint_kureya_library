---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/cht_slope_monotone.hpp
    title: src/data-structure/cht_slope_monotone.hpp
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
    - https://qoj.ac/submission/912918
  bundledCode: "#line 1 \"test/data-structure/cht_slope_monotone.test.cpp\"\n// AC\u6E08\
    \u307F https://qoj.ac/submission/912918\n\n/*\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define all(v) (v).begin(),(v).end()\n#define pb(a) push_back(a)\n\
    #define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e, v) for(auto&& e : v)\n\
    using ll = long long;\nconst ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL\
    \ << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\nvector<ll>\
    \ di(vector<vector<int>> &v, vector<ll> &h, int s) {\n   int n = v.size();\n \
    \  vector<ll> dis(n, INF);\n   multiset<pair<ll, ll>> ms;\n   dis[s] = 0;\n  \
    \ ms.insert({0, s});\n   while(!ms.empty()) {\n      auto [d, now] = *ms.begin();\n\
    \      ms.erase(ms.begin());\n      if(d > dis[now]) continue;\n      for(int\
    \ e : v[now]) {\n         if(dis[e] > dis[now] + (h[now] - h[e]) * (h[now] - h[e]))\
    \ {\n            dis[e] = dis[now] + (h[now] - h[e]) * (h[now] - h[e]);\n    \
    \        ms.insert({dis[e], e});\n         }\n      }\n   }\n   return dis;\n\
    }\n\nusing Int = __int128;\n\ntemplate<typename T>\nclass CHT {\n   using P =\
    \ pair<T, T>;\nprivate:\n   int head;\n   vector<P> lines;\n   // \u6700\u5C0F\
    \u5024(\u6700\u5927\u5024)\u3092\u6C42\u3081\u308Bx\u304C\u5358\u8ABF\u3067\u3042\
    \u308B\u304B\n   bool isMonotonicX;\n   function<bool(T l, T r)> comp;\n\npublic:\n\
    \   // \u30AF\u30A8\u30EA\u304C\u5358\u8ABF\u3067\u3042\u3063\u305F\u5834\u5408\
    \u306Fflag = true\u3068\u3059\u308B\n   CHT(bool flagX = false, function<bool(T\
    \ l, T r)> compFunc = [](T l, T r) {return l >= r; })\n      :isMonotonicX(flagX),\
    \ comp(compFunc), head(0) {};\n\n   bool check(P l1, P l2, P l3) {\n      if (l1\
    \ < l3) swap(l1, l3);\n      return (l3.second - l2.second) * (l2.first - l1.first)\
    \ >= (l2.second - l1.second) * (l3.first - l2.first);\n   }\n\n   void add(T a,\
    \ T b) {\n      P line(a, b);\n      while (lines.size() >= 2 + head && check(*(lines.end()\
    \ - 2), lines.back(), line))\n         lines.pop_back();\n      lines.emplace_back(line);\n\
    \   }\n\n   T f(int i, T x) {\n      return lines[i].first * x + lines[i].second;\n\
    \   }\n\n   T f(P line, T x) {\n      return line.first * x + line.second;\n \
    \  }\n\n   T get(T x) {\n      if (isMonotonicX) {\n         while (lines.size()\
    \ >= 2 + head && comp(f(head, x), f(head + 1, x)))\n            ++ head;\n   \
    \      return f(head, x);\n      }\n      else {\n         int low = -1, high\
    \ = lines.size() - 1;\n         while (high - low > 1) {\n            int mid\
    \ = (high + low) / 2;\n            (comp(f(mid, x), f(mid + 1, x)) ? low : high)\
    \ = mid;\n         }\n         return f(high, x);\n      }\n   }\n};\n\nint main()\
    \ {\n   ll n, m, s, t;\n   cin >> n >> m >> s >> t;\n   s --; t --;\n   vector<ll>\
    \ h(n);\n   rep(i, n) cin >> h[i];\n   vector<vector<int>> v(n);\n   ll ans =\
    \ INF;\n   rep(i, m) {\n      int a, b; cin >> a >> b;\n      a --; b --;\n  \
    \    v[a].pb(b);\n      v[b].pb(a);\n      if(a == s and b == t) ans = 0;\n  \
    \    if(a == t and b == s) ans = 0;\n   }\n   auto rets = di(v, h, s);\n   auto\
    \ rett = di(v, h, t);\n   \n   rep(now, n) {\n      {\n         int sz = v[now].size();\n\
    \         vector<int> ord(sz);\n         iota(all(ord), 0);\n         sort(all(ord),\
    \ [&](int i, int j) {\n            return h[v[now][i]] < h[v[now][j]];\n     \
    \    });\n         CHT<Int> cht(true);\n         rep(i, sz) {\n            int\
    \ e = v[now][ord[i]];\n            if(i) {\n               Int val = cht.get(Int(h[e]));\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add(Int(-2LL * h[e]), Int(2LL *\
    \ rets[e] + h[e] * h[e]));\n         }\n      }\n      {\n         int sz = v[now].size();\n\
    \         vector<int> ord(sz);\n         iota(all(ord), 0);\n         sort(all(ord),\
    \ [&](int i, int j) {\n            return h[v[now][i]] < h[v[now][j]];\n     \
    \    });\n         CHT<Int> cht(false);\n         rep(i, sz) {\n            int\
    \ e = v[now][ord[i]];\n            if(i) {\n               Int val = cht.get(Int(h[e]));\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rets[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add(Int(-2LL * h[e]), Int(2LL *\
    \ rett[e] + h[e] * h[e]));\n         }\n      }\n      \n   }\n\n   for(int e\
    \ : v[s]) {\n      ans = min(ans, rett[e] * 2);\n   }\n   for(int e : v[t]) {\n\
    \      ans = min(ans, rets[e] * 2);\n   }\n\n   if(ans % 2 == 0) {\n      cout\
    \ << ans / 2 << endl;\n   } else {\n      cout << ans / 2 << \".5\" << endl;\n\
    \   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/cht_slope_monotone.hpp\"\
    \ntemplate<typename T>\nclass CHT {\n   using P = pair<T, T>;\nprivate:\n   int\
    \ head;\n   vector<P> lines;\n   // \u6700\u5C0F\u5024(\u6700\u5927\u5024)\u3092\
    \u6C42\u3081\u308Bx\u304C\u5358\u8ABF\u3067\u3042\u308B\u304B\n   bool isMonotonicX;\n\
    \   function<bool(T l, T r)> comp;\n\npublic:\n   // \u30AF\u30A8\u30EA\u304C\u5358\
    \u8ABF\u3067\u3042\u3063\u305F\u5834\u5408\u306Fflag = true\u3068\u3059\u308B\n\
    \   CHT(bool flagX = false, function<bool(T l, T r)> compFunc = [](T l, T r) {return\
    \ l >= r; })\n      :isMonotonicX(flagX), comp(compFunc), head(0) {};\n\n   bool\
    \ check(P l1, P l2, P l3) {\n      if (l1 < l3) swap(l1, l3);\n      return (l3.second\
    \ - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first\
    \ - l2.first);\n   }\n\n   void add(T a, T b) {\n      P line(a, b);\n      while\
    \ (lines.size() >= 2 + head && check(*(lines.end() - 2), lines.back(), line))\n\
    \         lines.pop_back();\n      lines.emplace_back(line);\n   }\n\n   T f(int\
    \ i, T x) {\n      return lines[i].first * x + lines[i].second;\n   }\n\n   T\
    \ f(P line, T x) {\n      return line.first * x + line.second;\n   }\n\n   T get(T\
    \ x) {\n      if (isMonotonicX) {\n         while (lines.size() >= 2 + head &&\
    \ comp(f(head, x), f(head + 1, x)))\n            ++ head;\n         return f(head,\
    \ x);\n      }\n      else {\n         int low = -1, high = lines.size() - 1;\n\
    \         while (high - low > 1) {\n            int mid = (high + low) / 2;\n\
    \            (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;\n         }\n\
    \         return f(high, x);\n      }\n   }\n};\n#line 164 \"test/data-structure/cht_slope_monotone.test.cpp\"\
    \nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u6E08\u307F https://qoj.ac/submission/912918\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define all(v) (v).begin(),(v).end()\n#define pb(a) push_back(a)\n\
    #define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e, v) for(auto&& e : v)\n\
    using ll = long long;\nconst ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL\
    \ << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\nvector<ll>\
    \ di(vector<vector<int>> &v, vector<ll> &h, int s) {\n   int n = v.size();\n \
    \  vector<ll> dis(n, INF);\n   multiset<pair<ll, ll>> ms;\n   dis[s] = 0;\n  \
    \ ms.insert({0, s});\n   while(!ms.empty()) {\n      auto [d, now] = *ms.begin();\n\
    \      ms.erase(ms.begin());\n      if(d > dis[now]) continue;\n      for(int\
    \ e : v[now]) {\n         if(dis[e] > dis[now] + (h[now] - h[e]) * (h[now] - h[e]))\
    \ {\n            dis[e] = dis[now] + (h[now] - h[e]) * (h[now] - h[e]);\n    \
    \        ms.insert({dis[e], e});\n         }\n      }\n   }\n   return dis;\n\
    }\n\nusing Int = __int128;\n\ntemplate<typename T>\nclass CHT {\n   using P =\
    \ pair<T, T>;\nprivate:\n   int head;\n   vector<P> lines;\n   // \u6700\u5C0F\
    \u5024(\u6700\u5927\u5024)\u3092\u6C42\u3081\u308Bx\u304C\u5358\u8ABF\u3067\u3042\
    \u308B\u304B\n   bool isMonotonicX;\n   function<bool(T l, T r)> comp;\n\npublic:\n\
    \   // \u30AF\u30A8\u30EA\u304C\u5358\u8ABF\u3067\u3042\u3063\u305F\u5834\u5408\
    \u306Fflag = true\u3068\u3059\u308B\n   CHT(bool flagX = false, function<bool(T\
    \ l, T r)> compFunc = [](T l, T r) {return l >= r; })\n      :isMonotonicX(flagX),\
    \ comp(compFunc), head(0) {};\n\n   bool check(P l1, P l2, P l3) {\n      if (l1\
    \ < l3) swap(l1, l3);\n      return (l3.second - l2.second) * (l2.first - l1.first)\
    \ >= (l2.second - l1.second) * (l3.first - l2.first);\n   }\n\n   void add(T a,\
    \ T b) {\n      P line(a, b);\n      while (lines.size() >= 2 + head && check(*(lines.end()\
    \ - 2), lines.back(), line))\n         lines.pop_back();\n      lines.emplace_back(line);\n\
    \   }\n\n   T f(int i, T x) {\n      return lines[i].first * x + lines[i].second;\n\
    \   }\n\n   T f(P line, T x) {\n      return line.first * x + line.second;\n \
    \  }\n\n   T get(T x) {\n      if (isMonotonicX) {\n         while (lines.size()\
    \ >= 2 + head && comp(f(head, x), f(head + 1, x)))\n            ++ head;\n   \
    \      return f(head, x);\n      }\n      else {\n         int low = -1, high\
    \ = lines.size() - 1;\n         while (high - low > 1) {\n            int mid\
    \ = (high + low) / 2;\n            (comp(f(mid, x), f(mid + 1, x)) ? low : high)\
    \ = mid;\n         }\n         return f(high, x);\n      }\n   }\n};\n\nint main()\
    \ {\n   ll n, m, s, t;\n   cin >> n >> m >> s >> t;\n   s --; t --;\n   vector<ll>\
    \ h(n);\n   rep(i, n) cin >> h[i];\n   vector<vector<int>> v(n);\n   ll ans =\
    \ INF;\n   rep(i, m) {\n      int a, b; cin >> a >> b;\n      a --; b --;\n  \
    \    v[a].pb(b);\n      v[b].pb(a);\n      if(a == s and b == t) ans = 0;\n  \
    \    if(a == t and b == s) ans = 0;\n   }\n   auto rets = di(v, h, s);\n   auto\
    \ rett = di(v, h, t);\n   \n   rep(now, n) {\n      {\n         int sz = v[now].size();\n\
    \         vector<int> ord(sz);\n         iota(all(ord), 0);\n         sort(all(ord),\
    \ [&](int i, int j) {\n            return h[v[now][i]] < h[v[now][j]];\n     \
    \    });\n         CHT<Int> cht(true);\n         rep(i, sz) {\n            int\
    \ e = v[now][ord[i]];\n            if(i) {\n               Int val = cht.get(Int(h[e]));\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add(Int(-2LL * h[e]), Int(2LL *\
    \ rets[e] + h[e] * h[e]));\n         }\n      }\n      {\n         int sz = v[now].size();\n\
    \         vector<int> ord(sz);\n         iota(all(ord), 0);\n         sort(all(ord),\
    \ [&](int i, int j) {\n            return h[v[now][i]] < h[v[now][j]];\n     \
    \    });\n         CHT<Int> cht(false);\n         rep(i, sz) {\n            int\
    \ e = v[now][ord[i]];\n            if(i) {\n               Int val = cht.get(Int(h[e]));\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rets[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add(Int(-2LL * h[e]), Int(2LL *\
    \ rett[e] + h[e] * h[e]));\n         }\n      }\n      \n   }\n\n   for(int e\
    \ : v[s]) {\n      ans = min(ans, rett[e] * 2);\n   }\n   for(int e : v[t]) {\n\
    \      ans = min(ans, rets[e] * 2);\n   }\n\n   if(ans % 2 == 0) {\n      cout\
    \ << ans / 2 << endl;\n   } else {\n      cout << ans / 2 << \".5\" << endl;\n\
    \   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/cht_slope_monotone.hpp\"\
    \nint main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/data-structure/cht_slope_monotone.hpp
  isVerificationFile: true
  path: test/data-structure/cht_slope_monotone.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 05:10:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/cht_slope_monotone.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/cht_slope_monotone.test.cpp
- /verify/test/data-structure/cht_slope_monotone.test.cpp.html
title: test/data-structure/cht_slope_monotone.test.cpp
---
