// AC確認済み https://judge.yosupo.jp/submission/269279

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

// Bostan-Mori
// find [x^N] P(x)/Q(x), O(K log K log N)
// deg(Q(x)) = K, deg(P(x)) < K, Q[0] = 1
template <typename mint> mint BostanMori(const vector<mint> &P, const vector<mint> &Q, long long N) {
   assert(!P.empty() && !Q.empty());
   if (N == 0) return P[0] / Q[0];
   
   int qdeg = (int)Q.size();
   vector<mint> P2{P}, minusQ{Q};
   P2.resize(qdeg - 1);
   for (int i = 1; i < (int)Q.size(); i += 2) minusQ[i] = -minusQ[i];
   P2 = conv(P2, minusQ);
   vector<mint> Q2 = conv(Q, minusQ);
   vector<mint> S(qdeg - 1), T(qdeg);
   for (int i = 0; i < (int)S.size(); ++i) {
      S[i] = (N % 2 == 0 ? P2[i * 2] : P2[i * 2 + 1]);
   }
   for (int i = 0; i < (int)T.size(); ++i) {
      T[i] = Q2[i * 2];
   }
   return BostanMori(S, T, N >> 1);
}

int main() {
   ll d, k; cin >> d >> k;
   vector<mm> a(d), c(d + 1);
   for(int i = 0; i < d; i ++) {
      ll x; cin >> x;
      a[i] = x;
   }
   c[0] = 1;
   for(int i = 1; i <= d; i ++) {
      ll x; cin >> x;
      c[i] = -x;
   }
   a = conv(a, c);
   a.resize(d);
   cout << BostanMori(a, c, k).x << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
#include "src/FPS/bostan_mori.hpp"
int main() { puts("Hello World"); }