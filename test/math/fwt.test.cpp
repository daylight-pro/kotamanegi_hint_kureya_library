// AC確認済み https://codeforces.com/contest/1906/submission/306277658

/*
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto&& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

template<int MOD> struct Modint {
   long long val;
   constexpr Modint(long long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
   constexpr int mod() const { return MOD; }
   constexpr long long value() const { return val; }
   constexpr Modint operator - () const noexcept { return val ? MOD - val : 0; }
   constexpr Modint operator + (const Modint& r) const noexcept { return Modint(*this) += r; }
   constexpr Modint operator - (const Modint& r) const noexcept { return Modint(*this) -= r; }
   constexpr Modint operator * (const Modint& r) const noexcept { return Modint(*this) *= r; }
   constexpr Modint operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }
   constexpr Modint& operator += (const Modint& r) noexcept {
      val += r.val;
      if (val >= MOD) val -= MOD;
      return *this;
   }
   constexpr Modint& operator -= (const Modint& r) noexcept {
      val -= r.val;
      if (val < 0) val += MOD;
      return *this;
   }
   constexpr Modint& operator *= (const Modint& r) noexcept {
      val = val * r.val % MOD;
      return *this;
   }
   constexpr Modint& operator /= (const Modint& r) noexcept {
      long long a = r.val, b = MOD, u = 1, v = 0;
      while (b) {
         long long t = a / b;
         a -= t * b, swap(a, b);
         u -= t * v, swap(u, v);
      }
      val = val * u % MOD;
      if (val < 0) val += MOD;
      return *this;
   }
   constexpr bool operator == (const Modint& r) const noexcept { return this->val == r.val; }
   constexpr bool operator != (const Modint& r) const noexcept { return this->val != r.val; }
   friend constexpr istream& operator >> (istream& is, Modint<MOD>& x) noexcept {
      is >> x.val;
      x.val %= MOD;
      if (x.val < 0) x.val += MOD;
      return is;
   }
   friend constexpr ostream& operator << (ostream& os, const Modint<MOD>& x) noexcept {
      return os << x.val;
   }
   constexpr Modint<MOD> pow(long long n) noexcept {
      if (n == 0) return 1;
      if (n < 0) return this->pow(-n).inv();
      Modint<MOD> ret = pow(n >> 1);
      ret *= ret;
      if (n & 1) ret *= *this;
      return ret;
   }
   constexpr Modint<MOD> inv() const noexcept {
      long long a = this->val, b = MOD, u = 1, v = 0;
      while (b) {
         long long t = a / b;
         a -= t * b, swap(a, b);
         u -= t * v, swap(u, v);
      }
      return Modint<MOD>(u);
   }
};

const int MOD = MOD998;
using mint = Modint<MOD>;


template <typename T>
void fwt(vector<T>& f) {
   int n = f.size();
   for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j++) {
         if ((j & i) == 0) {
            T x = f[j], y = f[j | i];
            f[j] = x + y, f[j | i] = x - y;
         }
      }
   }
}
template <typename T>
void ifwt(vector<T>& f) {
   int n = f.size();
   for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j++) {
         if ((j & i) == 0) {
            T x = f[j], y = f[j | i];
            f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
         }
      }
   }
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   int n; cin >> n;
   int N = (1 << 17);
   vector<ll> x(N);
   rep(i, n) {
      int a; cin >> a;
      x[a] ++;
   }
   vector<mint> p(n + 1, 1);
   rep(i, n + 1) p[i] = mint(3).pow(i) * mint((n - i) & 1 ? -1 : 1);
   fwt(x);
   mint ans = 0;
   rep(i, N) ans += p[(x[i] + n) / 2];
   cout << ans / mint(1 << 17) << endl;  
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/math/fwt.hpp"

int main() { puts("Hello World"); }