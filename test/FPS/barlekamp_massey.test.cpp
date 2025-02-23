// AC確認済み https://atcoder.jp/contests/abc305/submissions/63090763

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

const ll mod = 998244353;
struct mm {
   ll x;
   mm(ll x_ = 0) : x(x_ % mod) {
      if(x < 0) x += mod;
   }
   friend mm operator-(mm a) { return -a.x; }
   friend mm operator+(mm a, mm b) { return a.x + b.x; }
   friend mm operator-(mm a, mm b) { return a.x - b.x; }
   friend mm operator*(mm a, mm b) { return a.x * b.x; }
   friend mm operator/(mm a, mm b) { return a * b.inv(); }
   // 4 行コピペ  Alt + Shift + クリックで複数カーソル
   friend mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }
   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x; }
   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }
   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }
   mm inv() const { return pow(mod - 2); }
   mm pow(ll b) const {
      mm a = *this, c = 1;
      while(b) {
         if(b & 1) c *= a;
         a *= a;
         b >>= 1;
      }
      return c;
   }
};

// {998244353, 3}, {1811939329, 13}, {2013265921, 31}
mm g = 3;  // 原始根
void fft(vector<mm>& a) {
   ll n = size(a), lg = __lg(n);
   assert((1 << lg) == n);
   vector<mm> b(n);
   for(int l = 1; l <= lg; l++) {
      ll w = n >> l;
      mm s = 1, r = g.pow(mod >> l);
      for(ll u = 0; u < n / 2; u += w) {
         for(int d = 0; d < w; d++) {
            mm x = a[u << 1 | d], y = a[u << 1 | w | d] * s;
            b[u | d] = x + y;
            b[n >> 1 | u | d] = x - y;
         }
         s *= r;
      }
      swap(a, b);
   }
}
vector<mm> conv(vector<mm> a, vector<mm> b) {
   if(a.empty() || b.empty()) return {};
   size_t s = size(a) + size(b) - 1, n = bit_ceil(s);
   // if(min(sz(a), sz(b)) <= 60) 愚直に掛け算
   a.resize(n);
   b.resize(n);
   fft(a);
   fft(b);
   mm inv = mm(n).inv();
   for(int i = 0; i < n; i++) a[i] *= b[i] * inv;
   reverse(1 + all(a));
   fft(a);
   a.resize(s);
   return a;
}
vector<mm> BerlekampMassey(const vector<mm> &s) {
   const int N = (int)s.size();
   vector<mm> b, c;
   b.reserve(N + 1);
   c.reserve(N + 1);
   b.push_back(mm(1));
   c.push_back(mm(1));
   mm y = mm(1);
   for (int ed = 1; ed <= N; ed++) {
      int l = int(c.size()), m = int(b.size());
      mm x = 0;
      for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
      b.emplace_back(mm(0));
      m ++;
      if (x.x == 0) continue;
      mm freq = x / y;
      if (l < m) {
         auto tmp = c;
         c.insert(begin(c), m - l, mm(0));
         for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
         b = tmp;
         y = x;
      } else {
         for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
      }
   }
   reverse(begin(c), end(c));
   return c;
}
mm BostanMori(vector<mm> P, vector<mm> Q, ll N) {
   const int d = Q.size();
   for (; N; N >>= 1) {
      auto Q_neg = Q;
      for (size_t i = 1; i < Q.size(); i += 2) Q_neg[i] *= -1;
      P = conv(P, Q_neg);
      Q = conv(Q, Q_neg);
      for (size_t i = N & 1; i < P.size(); i += 2) P[i >> 1] = P[i];
      for (size_t i = 0; i < Q.size(); i += 2) Q[i >> 1] = Q[i];
      P.resize(d - 1);
      Q.resize(d);
   }
   return P[0];
}

int main() {
   ll n, m;
   cin >> n >> m;
   string s;
   vector<ll> str(64, 7);
   for (ll i = 0; i < m; i++) {
      cin >> s;
      ll l = s.size();
      ll bit = 0;
      for (ll j = 0; j < l; j++) {
         if (s[j] == 'b') {
            bit += (1 << j);
         }
      }
      str[bit] = min(str[bit], l);
   }

   auto is_ok = [&](ll len, ll bit) -> bool {
      for (ll l = 1; l <= len; l++) {
         ll mask = (1 << l) - 1;
         for (ll i = 0; i + l <= len; i++) {
            if (str[(bit >> i) & mask] <= l) return false;
         }
      }
      return true;
   };

   if (n <= 5) {
      ll ans = 0;
      for (ll bit = 0; bit < (1 << n); bit++) {
         if (is_ok(n, bit)) ans++;
      }
      cout << ans << "\n";
      return 0;
   }

   vector<mm> v(240, 0);
   vector<mm> dp(32, 0);
   for (ll i = 0; i < 4; i++) {
      ll num = 1 << i;
      for (ll bit = 0; bit < num; bit++) {
         if (is_ok(i, bit)) v[i] += 1;
      }
   }
   for (ll bit = 0; bit < 32; bit++) {
      if (is_ok(5, bit)) {
         dp[bit] += 1;
         v[4] += 1;
      }
   }
   for (ll i = 5; i < 240; i++) {
      vector<mm> nx(32, 0);
      for (ll bit = 0; bit < 32; bit++) {
         for (ll j = 0; j < 2; j++) {
            if (is_ok(6, (j << 5) | bit)) {
               nx[(bit >> 1) | (j << 4)] += dp[bit];
               v[i] += dp[bit];
            }
         }
      }
      swap(nx, dp);
   }
   vector<mm> a = BerlekampMassey(v);
   vector<mm> b = conv(v, a);
   b.resize(a.size() - 1);

   cout << BostanMori(b, a, n - 1).x << "\n";
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
#include "src/FPS/barlekamp_massey.hpp"
#include "src/FPS/bostan_mori.hpp"
int main() { puts("Hello World"); }