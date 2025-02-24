/* AC確認済み
https://judge.yosupo.jp/submission/269611
https://judge.yosupo.jp/submission/269612
https://judge.yosupo.jp/submission/269613
https://atcoder.jp/contests/abc276/submissions/63131136
*/

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

using vm = vector<mm>;
vm fps_inv_sparse(vm& f) {
   int n = f.size(); vector<pair<int, mm>> dat;
   for(int i = 0; i < n; i++) if(f[i].x) dat.emplace_back(i, f[i]);
   vm g(n); mm g0 = f[0].inv(); g[0] = g0;
   for(int i = 1; i < n; i++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) { if(k > i) break; rhs -= fk * g[i - k]; }
      g[i] = rhs * g0;
   }
   return g;
}
vm fps_exp_sparse(vm& f) {
   if((int)f.size() == 0) return {mm(1)};
   int N = f.size(); vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i++) if(f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);
   vm F(N); F[0] = 1;
   for(int n = 1; n < N; n++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) { if(k > n - 1) break; rhs += fk * F[n - 1 - k]; }
      F[n] = rhs * mm(n).inv();
   }
   return F;
}
vm fps_log_sparse(vm& f) {
   int N = f.size(); vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i ++) if(f[i].x) dat.emplace_back(i, f[i]);
   vm F(N), g(N - 1);
   for(int n = 0; n < N - 1; n ++) {
      mm rhs = mm(n + 1) * f[n + 1];
      for(auto &&[i, fi] : dat) { if(i > n) break; rhs -= fi * g[n - i]; }
      g[n] = rhs; F[n + 1] = rhs * mm(n + 1).inv();
   }
   return F;
}
vm fps_pow_product(vm& f, vm& g, mm n, mm m) {
   int N = f.size(); using P = pair<int, mm>;
   vector<P> dat_f, dat_g;
   for(int i = 0; i < (int)f.size(); i ++) if(f[i].x) dat_f.emplace_back(i, f[i]);
   for(int i = 0; i < (int)g.size(); i ++) if(g[i].x) dat_g.emplace_back(i, g[i]);
   vm a(N), b(N);
   for (auto&& [i, x]: dat_f) for (auto&& [j, y]: dat_g) {
      if (i + j >= N + 1) continue; 
      mm xy = x * y; if (i + j < N) a[i + j] += xy;
      if (0 < i + j && i + j <= N) b[i + j - 1] -= xy * (n * mm(i) + m * mm(j));
   }
   vector<P> dat_a, dat_b;
   for(int i = 1; i < N; i ++) if(a[i].x) dat_a.emplace_back(i, a[i]);
   for(int i = 0; i < N; i ++) if(b[i].x) dat_b.emplace_back(i, b[i]);
   vm F(N), df(N - 1); F[0] = 1;
   for(int n = 0; n < N - 1; n ++) {
      mm v = 0;
      for(auto&& [i, ai] : dat_a) { if(i > n) break; v += ai * df[n - i]; }
      for(auto&& [i, bi] : dat_b) { if(i > n) break; v += bi * F[n - i]; }
      df[n] = -v; F[n + 1] = df[n] * mm(n + 1).inv();
   }
   return F;
}

int main() {
   ll n, m; cin >> n >> m;
   n --;
   m -= n;
   if(m < 0) {
      cout << 0 << endl;
      return 0;
   }
   vm f = {1, 1}, g = {1, 0, 0, -1};
   f.resize(m + 1);
   g.resize(m + 1);
   f = fps_pow_product(f, g, n, -n);
   n = f.size();
   for(int j = 0; j < 2; j ++) for(int i = 1; i < n; i ++) f[i] += f[i - 1];
   cout << f[m].x << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/fps_sparse.hpp"
int main() { puts("Hello World"); }