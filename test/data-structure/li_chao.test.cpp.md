---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/li_chao.hpp
    title: src/data-structure/li_chao.hpp
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
    - https://qoj.ac/submission/912927
  bundledCode: "#line 1 \"test/data-structure/li_chao.test.cpp\"\n// AC\u6E08\u307F\
    \ https://qoj.ac/submission/912927\n/*\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define all(v) (v).begin(),(v).end()\n#define pb(a) push_back(a)\n#define\
    \ rep(i, n) for(int i=0;i<n;i++)\n#define foa(e, v) for(auto&& e : v)\nusing ll\
    \ = long long;\nconst ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL <<\
    \ 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\nvector<ll>\
    \ di(vector<vector<int>> &v, vector<ll> &h, int s) {\n   int n = v.size();\n \
    \  vector<ll> dis(n, INF);\n   multiset<pair<ll, ll>> ms;\n   dis[s] = 0;\n  \
    \ ms.insert({0, s});\n   while(!ms.empty()) {\n      auto [d, now] = *ms.begin();\n\
    \      ms.erase(ms.begin());\n      if(d > dis[now]) continue;\n      for(int\
    \ e : v[now]) {\n         if(dis[e] > dis[now] + (h[now] - h[e]) * (h[now] - h[e]))\
    \ {\n            dis[e] = dis[now] + (h[now] - h[e]) * (h[now] - h[e]);\n    \
    \        ms.insert({dis[e], e});\n         }\n      }\n   }\n   return dis;\n\
    }\n\nusing Int = __int128;\n\ntemplate <typename T>\nclass LiChaoTree {\n   int\
    \ n, sz, height;\n   vector<T> xs, as, bs;\n\n   void update(T a, T b, int k,\
    \ int h) {\n      int l = (k << h) & (sz - 1);\n      int r = l + (1 << h);\n\
    \      \n      while(1) {\n         int m = (l + r) >> 1;\n         T xl = xs[l],\
    \ xm = xs[m];\n         bool l_update = a*xl + b < as[k]*xl + bs[k];\n       \
    \  bool m_update = a*xm + b < as[k]*xm + bs[k];\n\n         if(m_update) {\n \
    \           swap(as[k], a);\n            swap(bs[k], b);\n         }\n       \
    \  if(h == 0) break;\n         if(l_update != m_update) {\n            k = k*2;\n\
    \            r = m;\n         } else {\n            k = k*2+1;\n            l\
    \ = m;\n         }\n         h--;\n      }\n   }\n\npublic:\n   // \u6700\u5C0F\
    \u5024\u30AF\u30A8\u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\
    \u30A8\u30EA\u306E\u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\
    \u3066\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\n   LiChaoTree(const vector<T>&\
    \ xs) : n(xs.size()), xs(xs) {\n      sz = 1, height = 0;\n      while(sz < (int)xs.size())\
    \ {\n         sz <<= 1;\n         height++;\n      }\n      this->xs.resize(sz,\
    \ xs.back());\n      as.assign(sz*2, 0);\n      bs.assign(sz*2, std::numeric_limits<T>::max());\n\
    \   }\n\n   void add_line(T a, T b) {\n      update(a, b, 1, height);\n   }\n\n\
    \   void add_segment(T a, T b, int l, int r) {\n      if(l == r) return;\n   \
    \   l += sz, r += sz;\n      int h = 0;\n      while(l < r) {\n         if(l &\
    \ 1) update(a, b, l++, h);\n         if(r & 1) update(a, b, --r, h);\n       \
    \  l >>= 1, r >>= 1, h++;\n      }\n   }\n\n   // x = xs[i] \u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n   T get(int i) const {\n  \
    \    T x = xs[i];\n      int k = i + sz;\n      T res = as[k]*x + bs[k];\n   \
    \   while(k > 1) {\n         k >>= 1;\n         T tmp = as[k]*x + bs[k];\n   \
    \      if(tmp < res) res = tmp;\n      }\n      return res;\n   }\n};\n\nint main()\
    \ {\n   ll n, m, s, t;\n   cin >> n >> m >> s >> t;\n   s --; t --;\n   vector<ll>\
    \ h(n);\n   rep(i, n) cin >> h[i];\n   vector<vector<int>> v(n);\n   ll ans =\
    \ INF;\n   rep(i, m) {\n      int a, b; cin >> a >> b;\n      a --; b --;\n  \
    \    v[a].pb(b);\n      v[b].pb(a);\n      if(a == s and b == t) ans = 0;\n  \
    \    if(a == t and b == s) ans = 0;\n   }\n   auto rets = di(v, h, s);\n   auto\
    \ rett = di(v, h, t);\n   \n   rep(now, n) {\n      int sz = v[now].size();\n\
    \      rep(_, 2) {\n         vector<pair<Int, int>> vec;\n         vector<Int>\
    \ xv;\n         rep(i, sz) {\n            vec.push_back({Int(h[v[now][i]]), i});\n\
    \         }\n         sort(all(vec));\n         vector<int> ord(sz);\n       \
    \  rep(i, sz) {\n            xv.pb(vec[i].first);\n            ord[vec[i].second]\
    \ = i;\n         }\n         LiChaoTree cht(xv);\n         rep(i, sz) {\n    \
    \        int e = v[now][i];\n            if(i) {\n               Int val = cht.get(ord[i]);\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add_line(Int(-2LL * h[e]), Int(2LL\
    \ * rets[e] + h[e] * h[e]));\n         }\n         reverse(all(v[now]));\n   \
    \   }\n   }\n\n   for(int e : v[s]) {\n      ans = min(ans, rett[e] * 2);\n  \
    \ }\n   for(int e : v[t]) {\n      ans = min(ans, rets[e] * 2);\n   }\n\n   if(ans\
    \ % 2 == 0) {\n      cout << ans / 2 << endl;\n   } else {\n      cout << ans\
    \ / 2 << \".5\" << endl;\n   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/data-structure/li_chao.hpp\"\
    \ntemplate <typename T>\nclass LiChaoTree {\n   int n, sz, height;\n   vector<T>\
    \ xs, as, bs;\n\n   void update(T a, T b, int k, int h) {\n      int l = (k <<\
    \ h) & (sz - 1);\n      int r = l + (1 << h);\n      \n      while(1) {\n    \
    \     int m = (l + r) >> 1;\n         T xl = xs[l], xm = xs[m];\n         bool\
    \ l_update = a*xl + b < as[k]*xl + bs[k];\n         bool m_update = a*xm + b <\
    \ as[k]*xm + bs[k];\n\n         if(m_update) {\n            swap(as[k], a);\n\
    \            swap(bs[k], b);\n         }\n         if(h == 0) break;\n       \
    \  if(l_update != m_update) {\n            k = k*2;\n            r = m;\n    \
    \     } else {\n            k = k*2+1;\n            l = m;\n         }\n     \
    \    h--;\n      }\n   }\n\npublic:\n   // \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\
    \u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u4E21\
    \u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\u30C8\
    \u3057\u305F\u914D\u5217\n   LiChaoTree(const vector<T>& xs) : n(xs.size()), xs(xs)\
    \ {\n      sz = 1, height = 0;\n      while(sz < (int)xs.size()) {\n         sz\
    \ <<= 1;\n         height++;\n      }\n      this->xs.resize(sz, xs.back());\n\
    \      as.assign(sz*2, 0);\n      bs.assign(sz*2, std::numeric_limits<T>::max());\n\
    \   }\n\n   void add_line(T a, T b) {\n      update(a, b, 1, height);\n   }\n\n\
    \   void add_segment(T a, T b, int l, int r) {\n      if(l == r) return;\n   \
    \   l += sz, r += sz;\n      int h = 0;\n      while(l < r) {\n         if(l &\
    \ 1) update(a, b, l++, h);\n         if(r & 1) update(a, b, --r, h);\n       \
    \  l >>= 1, r >>= 1, h++;\n      }\n   }\n\n   // x = xs[i] \u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n   T get(int i) const {\n  \
    \    T x = xs[i];\n      int k = i + sz;\n      T res = as[k]*x + bs[k];\n   \
    \   while(k > 1) {\n         k >>= 1;\n         T tmp = as[k]*x + bs[k];\n   \
    \      if(tmp < res) res = tmp;\n      }\n      return res;\n   }\n};\n#line 173\
    \ \"test/data-structure/li_chao.test.cpp\"\nint main() { puts(\"Hello World\"\
    ); }\n"
  code: "// AC\u6E08\u307F https://qoj.ac/submission/912927\n/*\n#include <bits/stdc++.h>\n\
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
    }\n\nusing Int = __int128;\n\ntemplate <typename T>\nclass LiChaoTree {\n   int\
    \ n, sz, height;\n   vector<T> xs, as, bs;\n\n   void update(T a, T b, int k,\
    \ int h) {\n      int l = (k << h) & (sz - 1);\n      int r = l + (1 << h);\n\
    \      \n      while(1) {\n         int m = (l + r) >> 1;\n         T xl = xs[l],\
    \ xm = xs[m];\n         bool l_update = a*xl + b < as[k]*xl + bs[k];\n       \
    \  bool m_update = a*xm + b < as[k]*xm + bs[k];\n\n         if(m_update) {\n \
    \           swap(as[k], a);\n            swap(bs[k], b);\n         }\n       \
    \  if(h == 0) break;\n         if(l_update != m_update) {\n            k = k*2;\n\
    \            r = m;\n         } else {\n            k = k*2+1;\n            l\
    \ = m;\n         }\n         h--;\n      }\n   }\n\npublic:\n   // \u6700\u5C0F\
    \u5024\u30AF\u30A8\u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\
    \u30A8\u30EA\u306E\u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\
    \u3066\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\n   LiChaoTree(const vector<T>&\
    \ xs) : n(xs.size()), xs(xs) {\n      sz = 1, height = 0;\n      while(sz < (int)xs.size())\
    \ {\n         sz <<= 1;\n         height++;\n      }\n      this->xs.resize(sz,\
    \ xs.back());\n      as.assign(sz*2, 0);\n      bs.assign(sz*2, std::numeric_limits<T>::max());\n\
    \   }\n\n   void add_line(T a, T b) {\n      update(a, b, 1, height);\n   }\n\n\
    \   void add_segment(T a, T b, int l, int r) {\n      if(l == r) return;\n   \
    \   l += sz, r += sz;\n      int h = 0;\n      while(l < r) {\n         if(l &\
    \ 1) update(a, b, l++, h);\n         if(r & 1) update(a, b, --r, h);\n       \
    \  l >>= 1, r >>= 1, h++;\n      }\n   }\n\n   // x = xs[i] \u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n   T get(int i) const {\n  \
    \    T x = xs[i];\n      int k = i + sz;\n      T res = as[k]*x + bs[k];\n   \
    \   while(k > 1) {\n         k >>= 1;\n         T tmp = as[k]*x + bs[k];\n   \
    \      if(tmp < res) res = tmp;\n      }\n      return res;\n   }\n};\n\nint main()\
    \ {\n   ll n, m, s, t;\n   cin >> n >> m >> s >> t;\n   s --; t --;\n   vector<ll>\
    \ h(n);\n   rep(i, n) cin >> h[i];\n   vector<vector<int>> v(n);\n   ll ans =\
    \ INF;\n   rep(i, m) {\n      int a, b; cin >> a >> b;\n      a --; b --;\n  \
    \    v[a].pb(b);\n      v[b].pb(a);\n      if(a == s and b == t) ans = 0;\n  \
    \    if(a == t and b == s) ans = 0;\n   }\n   auto rets = di(v, h, s);\n   auto\
    \ rett = di(v, h, t);\n   \n   rep(now, n) {\n      int sz = v[now].size();\n\
    \      rep(_, 2) {\n         vector<pair<Int, int>> vec;\n         vector<Int>\
    \ xv;\n         rep(i, sz) {\n            vec.push_back({Int(h[v[now][i]]), i});\n\
    \         }\n         sort(all(vec));\n         vector<int> ord(sz);\n       \
    \  rep(i, sz) {\n            xv.pb(vec[i].first);\n            ord[vec[i].second]\
    \ = i;\n         }\n         LiChaoTree cht(xv);\n         rep(i, sz) {\n    \
    \        int e = v[now][i];\n            if(i) {\n               Int val = cht.get(ord[i]);\n\
    \               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e]\
    \ + ll(val));\n            }\n            cht.add_line(Int(-2LL * h[e]), Int(2LL\
    \ * rets[e] + h[e] * h[e]));\n         }\n         reverse(all(v[now]));\n   \
    \   }\n   }\n\n   for(int e : v[s]) {\n      ans = min(ans, rett[e] * 2);\n  \
    \ }\n   for(int e : v[t]) {\n      ans = min(ans, rets[e] * 2);\n   }\n\n   if(ans\
    \ % 2 == 0) {\n      cout << ans / 2 << endl;\n   } else {\n      cout << ans\
    \ / 2 << \".5\" << endl;\n   }\n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/data-structure/li_chao.hpp\"\n\
    int main() { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/data-structure/li_chao.hpp
  isVerificationFile: true
  path: test/data-structure/li_chao.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 05:53:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/li_chao.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/li_chao.test.cpp
- /verify/test/data-structure/li_chao.test.cpp.html
title: test/data-structure/li_chao.test.cpp
---
