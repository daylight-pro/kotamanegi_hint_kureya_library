// AC確認済み https://atcoder.jp/contests/arc033/submissions/62970727

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

const ll mod = 1000000007;
struct mm {
   ll x;
   mm(ll x_ = 0) : x(x_ % mod) {
      if(x < 0) x += mod;
   }
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


struct Combination {
   ll C_MOD;
   vector<ll> fac, finv, inv;
   Combination(ll n, ll mod) : C_MOD(mod) {
      n = max(n, 2LL);
      fac.resize(n, 0);
      finv.resize(n, 0);
      inv.resize(n, 0);
      fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
      for(int i = 2; i < n; i ++) {
         fac[i] = fac[i - 1] * i % mod;
         inv[i] = mod - inv[mod % i] * (mod / i) % mod;
         finv[i] = finv[i - 1] * inv[i] % mod;
      }
   }
   ll com(ll n, ll k) {
      if(n < k || n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % C_MOD) % C_MOD;
   }
};

template<typename T> T lagrange_polynomial(const vector<T>& y, ll t, ll mod = 1000000007) {
   int n = y.size() - 1;
   if(t <= n) return y[t];
   T ret(0);
   Combination comb(n + 1, mod);
   vector<T> dp(n + 1, 1), pd(n + 1, 1);
   for(int i = 0; i < n; i ++) dp[i + 1] = dp[i] * (t - i);
   for(int i = n; i > 0; i --) pd[i - 1] = pd[i] * (t - i);
   for(int i = 0; i <= n; i ++) {
      T tmp = y[i] * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];
      ret -= ((n - i) & 1 ? tmp : T(0) - tmp);
   }
   return ret;
}

int main() {
   int N, T;
   cin >> N;
   vector<mm> A(N + 1);
   for(int i = 0; i <= N; i ++) {
      ll x; cin >> x;
      A[i] = x;
   }
   cin >> T;
   cout << lagrange_polynomial(A, T).x << endl;   
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/math/combination.hpp"
#include "src/graph/lagrange_polynomial.hpp"

int main() { puts("Hello World"); }