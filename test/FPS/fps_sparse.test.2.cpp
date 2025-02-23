// AC確認済み https://judge.yosupo.jp/submission/269404

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

vector<mm> fps_exp_sparse(vector<mm>& f) {
   if ((int)f.size() == 0) return {mm(1)};
   // assert(f[0].x == 0);
   int N = f.size();
   vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i ++) if (f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);
   vector<mm> F(N);
   F[0] = 1;
   for(int n = 1; n < N; n ++) {
      mm rhs = 0;
      for (auto&& [k, fk]: dat) {
         if (k > n - 1) break;
         rhs += fk * F[n - 1 - k];
      }
      F[n] = rhs * mm(n).inv();
   }
   return F;
}

int main() {
   int n, k;
   cin >> n >> k;
   vector<mm> f(n, 0);
   for(int i = 0; i < k; i ++) {
      ll x, y; cin >> x >> y;
      f[x] = y;
   }
   auto ret = fps_exp_sparse(f);
   for(int i = 0; i < n; i ++) {
      cout << ret[i].x << " ";
   }
   cout << '\n';
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/fps_sparse.hpp"
int main() { puts("Hello World"); }