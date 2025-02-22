---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/fwt.hpp
    title: src/math/fwt.hpp
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
    - https://codeforces.com/contest/1906/submission/306277658
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/math/fwt.test.cpp\"\n// AC\u78BA\u8A8D\u6E08\u307F\
    \ https://codeforces.com/contest/1906/submission/306277658\n\n/*\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define all(v) (v).begin(),(v).end()\n#define pb(a) push_back(a)\n\
    #define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e, v) for(auto&& e : v)\n\
    using ll = long long;\nconst ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL\
    \ << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\ntemplate<int\
    \ MOD> struct Modint {\n   long long val;\n   constexpr Modint(long long v = 0)\
    \ noexcept : val(v % MOD) { if (val < 0) val += MOD; }\n   constexpr int mod()\
    \ const { return MOD; }\n   constexpr long long value() const { return val; }\n\
    \   constexpr Modint operator - () const noexcept { return val ? MOD - val : 0;\
    \ }\n   constexpr Modint operator + (const Modint& r) const noexcept { return\
    \ Modint(*this) += r; }\n   constexpr Modint operator - (const Modint& r) const\
    \ noexcept { return Modint(*this) -= r; }\n   constexpr Modint operator * (const\
    \ Modint& r) const noexcept { return Modint(*this) *= r; }\n   constexpr Modint\
    \ operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }\n\
    \   constexpr Modint& operator += (const Modint& r) noexcept {\n      val += r.val;\n\
    \      if (val >= MOD) val -= MOD;\n      return *this;\n   }\n   constexpr Modint&\
    \ operator -= (const Modint& r) noexcept {\n      val -= r.val;\n      if (val\
    \ < 0) val += MOD;\n      return *this;\n   }\n   constexpr Modint& operator *=\
    \ (const Modint& r) noexcept {\n      val = val * r.val % MOD;\n      return *this;\n\
    \   }\n   constexpr Modint& operator /= (const Modint& r) noexcept {\n      long\
    \ long a = r.val, b = MOD, u = 1, v = 0;\n      while (b) {\n         long long\
    \ t = a / b;\n         a -= t * b, swap(a, b);\n         u -= t * v, swap(u, v);\n\
    \      }\n      val = val * u % MOD;\n      if (val < 0) val += MOD;\n      return\
    \ *this;\n   }\n   constexpr bool operator == (const Modint& r) const noexcept\
    \ { return this->val == r.val; }\n   constexpr bool operator != (const Modint&\
    \ r) const noexcept { return this->val != r.val; }\n   friend constexpr istream&\
    \ operator >> (istream& is, Modint<MOD>& x) noexcept {\n      is >> x.val;\n \
    \     x.val %= MOD;\n      if (x.val < 0) x.val += MOD;\n      return is;\n  \
    \ }\n   friend constexpr ostream& operator << (ostream& os, const Modint<MOD>&\
    \ x) noexcept {\n      return os << x.val;\n   }\n   constexpr Modint<MOD> pow(long\
    \ long n) noexcept {\n      if (n == 0) return 1;\n      if (n < 0) return this->pow(-n).inv();\n\
    \      Modint<MOD> ret = pow(n >> 1);\n      ret *= ret;\n      if (n & 1) ret\
    \ *= *this;\n      return ret;\n   }\n   constexpr Modint<MOD> inv() const noexcept\
    \ {\n      long long a = this->val, b = MOD, u = 1, v = 0;\n      while (b) {\n\
    \         long long t = a / b;\n         a -= t * b, swap(a, b);\n         u -=\
    \ t * v, swap(u, v);\n      }\n      return Modint<MOD>(u);\n   }\n};\n\nconst\
    \ int MOD = MOD998;\nusing mint = Modint<MOD>;\n\n\ntemplate <typename T>\nvoid\
    \ fwt(vector<T>& f) {\n   int n = f.size();\n   for (int i = 1; i < n; i <<= 1)\
    \ {\n      for (int j = 0; j < n; j++) {\n         if ((j & i) == 0) {\n     \
    \       T x = f[j], y = f[j | i];\n            f[j] = x + y, f[j | i] = x - y;\n\
    \         }\n      }\n   }\n}\ntemplate <typename T>\nvoid ifwt(vector<T>& f)\
    \ {\n   int n = f.size();\n   for (int i = 1; i < n; i <<= 1) {\n      for (int\
    \ j = 0; j < n; j++) {\n         if ((j & i) == 0) {\n            T x = f[j],\
    \ y = f[j | i];\n            f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;\n   \
    \      }\n      }\n   }\n}\n\nint main() {\n   cin.tie(0);\n   ios::sync_with_stdio(false);\n\
    \   int n; cin >> n;\n   int N = (1 << 17);\n   vector<ll> x(N);\n   rep(i, n)\
    \ {\n      int a; cin >> a;\n      x[a] ++;\n   }\n   vector<mint> p(n + 1, 1);\n\
    \   rep(i, n + 1) p[i] = mint(3).pow(i) * mint((n - i) & 1 ? -1 : 1);\n   fwt(x);\n\
    \   mint ans = 0;\n   rep(i, N) ans += p[(x[i] + n) / 2];\n   cout << ans / mint(1\
    \ << 17) << endl;  \n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define all(a) begin(a),\
    \ end(a)\nbool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/fwt.hpp\"\n\
    template<typename T> void fwt(vector<T>& f) {\n   int n = f.size();\n   for(int\
    \ i = 1; i < n; i <<= 1) {\n      for(int j = 0; j < n; j++) {\n         if((j\
    \ & i) == 0) {\n            T x = f[j], y = f[j | i];\n            f[j] = x +\
    \ y, f[j | i] = x - y;\n         }\n      }\n   }\n}\ntemplate<typename T> void\
    \ ifwt(vector<T>& f) {\n   int n = f.size();\n   for(int i = 1; i < n; i <<= 1)\
    \ {\n      for(int j = 0; j < n; j++) {\n         if((j & i) == 0) {\n       \
    \     T x = f[j], y = f[j | i];\n            f[j] = (x + y) / 2, f[j | i] = (x\
    \ - y) / 2;\n         }\n      }\n   }\n}\n#line 131 \"test/math/fwt.test.cpp\"\
    \n\nint main() { puts(\"Hello World\"); }\n"
  code: "// AC\u78BA\u8A8D\u6E08\u307F https://codeforces.com/contest/1906/submission/306277658\n\
    \n/*\n#include <bits/stdc++.h>\nusing namespace std;\n#define all(v) (v).begin(),(v).end()\n\
    #define pb(a) push_back(a)\n#define rep(i, n) for(int i=0;i<n;i++)\n#define foa(e,\
    \ v) for(auto&& e : v)\nusing ll = long long;\nconst ll MOD7 = 1000000007, MOD998\
    \ = 998244353, INF = (1LL << 60);\n#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;\n\
    \ntemplate<int MOD> struct Modint {\n   long long val;\n   constexpr Modint(long\
    \ long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }\n   constexpr\
    \ int mod() const { return MOD; }\n   constexpr long long value() const { return\
    \ val; }\n   constexpr Modint operator - () const noexcept { return val ? MOD\
    \ - val : 0; }\n   constexpr Modint operator + (const Modint& r) const noexcept\
    \ { return Modint(*this) += r; }\n   constexpr Modint operator - (const Modint&\
    \ r) const noexcept { return Modint(*this) -= r; }\n   constexpr Modint operator\
    \ * (const Modint& r) const noexcept { return Modint(*this) *= r; }\n   constexpr\
    \ Modint operator / (const Modint& r) const noexcept { return Modint(*this) /=\
    \ r; }\n   constexpr Modint& operator += (const Modint& r) noexcept {\n      val\
    \ += r.val;\n      if (val >= MOD) val -= MOD;\n      return *this;\n   }\n  \
    \ constexpr Modint& operator -= (const Modint& r) noexcept {\n      val -= r.val;\n\
    \      if (val < 0) val += MOD;\n      return *this;\n   }\n   constexpr Modint&\
    \ operator *= (const Modint& r) noexcept {\n      val = val * r.val % MOD;\n \
    \     return *this;\n   }\n   constexpr Modint& operator /= (const Modint& r)\
    \ noexcept {\n      long long a = r.val, b = MOD, u = 1, v = 0;\n      while (b)\
    \ {\n         long long t = a / b;\n         a -= t * b, swap(a, b);\n       \
    \  u -= t * v, swap(u, v);\n      }\n      val = val * u % MOD;\n      if (val\
    \ < 0) val += MOD;\n      return *this;\n   }\n   constexpr bool operator == (const\
    \ Modint& r) const noexcept { return this->val == r.val; }\n   constexpr bool\
    \ operator != (const Modint& r) const noexcept { return this->val != r.val; }\n\
    \   friend constexpr istream& operator >> (istream& is, Modint<MOD>& x) noexcept\
    \ {\n      is >> x.val;\n      x.val %= MOD;\n      if (x.val < 0) x.val += MOD;\n\
    \      return is;\n   }\n   friend constexpr ostream& operator << (ostream& os,\
    \ const Modint<MOD>& x) noexcept {\n      return os << x.val;\n   }\n   constexpr\
    \ Modint<MOD> pow(long long n) noexcept {\n      if (n == 0) return 1;\n     \
    \ if (n < 0) return this->pow(-n).inv();\n      Modint<MOD> ret = pow(n >> 1);\n\
    \      ret *= ret;\n      if (n & 1) ret *= *this;\n      return ret;\n   }\n\
    \   constexpr Modint<MOD> inv() const noexcept {\n      long long a = this->val,\
    \ b = MOD, u = 1, v = 0;\n      while (b) {\n         long long t = a / b;\n \
    \        a -= t * b, swap(a, b);\n         u -= t * v, swap(u, v);\n      }\n\
    \      return Modint<MOD>(u);\n   }\n};\n\nconst int MOD = MOD998;\nusing mint\
    \ = Modint<MOD>;\n\n\ntemplate <typename T>\nvoid fwt(vector<T>& f) {\n   int\
    \ n = f.size();\n   for (int i = 1; i < n; i <<= 1) {\n      for (int j = 0; j\
    \ < n; j++) {\n         if ((j & i) == 0) {\n            T x = f[j], y = f[j |\
    \ i];\n            f[j] = x + y, f[j | i] = x - y;\n         }\n      }\n   }\n\
    }\ntemplate <typename T>\nvoid ifwt(vector<T>& f) {\n   int n = f.size();\n  \
    \ for (int i = 1; i < n; i <<= 1) {\n      for (int j = 0; j < n; j++) {\n   \
    \      if ((j & i) == 0) {\n            T x = f[j], y = f[j | i];\n          \
    \  f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;\n         }\n      }\n   }\n}\n\
    \nint main() {\n   cin.tie(0);\n   ios::sync_with_stdio(false);\n   int n; cin\
    \ >> n;\n   int N = (1 << 17);\n   vector<ll> x(N);\n   rep(i, n) {\n      int\
    \ a; cin >> a;\n      x[a] ++;\n   }\n   vector<mint> p(n + 1, 1);\n   rep(i,\
    \ n + 1) p[i] = mint(3).pow(i) * mint((n - i) & 1 ? -1 : 1);\n   fwt(x);\n   mint\
    \ ans = 0;\n   rep(i, N) ans += p[(x[i] + n) / 2];\n   cout << ans / mint(1 <<\
    \ 17) << endl;  \n   return 0;\n}\n*/\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/fwt.hpp\"\n\nint main()\
    \ { puts(\"Hello World\"); }"
  dependsOn:
  - test/template.hpp
  - src/math/fwt.hpp
  isVerificationFile: true
  path: test/math/fwt.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 15:22:54+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fwt.test.cpp
layout: document
redirect_from:
- /verify/test/math/fwt.test.cpp
- /verify/test/math/fwt.test.cpp.html
title: test/math/fwt.test.cpp
---
