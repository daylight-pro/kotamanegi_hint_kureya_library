// AC確認済み https://judge.yosupo.jp/submission/269321

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

vector<mm> fps_inv_sparse(const vector<pair<int, mm>> &dat, int n = -1) {
   // assert(dat[0].first == 0 and dat[0].second.x != 0);
   if(n == -1) n = dat.back().first + 1;
   vector<mm> g(n);
   mm g0 = dat[0].second.inv();
   g[0] = g0;
   for(int i = 1; i < n; i ++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) {
         if(k > i) break;
         rhs -= fk * g[i - k];
      }
      g[i] = rhs * g0;
   }
   return g;
}

int main() {
   int n, k;
   cin >> n >> k;
   vector<pair<int, mm>> vec;
   for(int i = 0; i < k; i ++) {
      ll x, y; cin >> x >> y;
      vec.push_back({x, y});
   }
   auto ret = fps_inv_sparse(vec, n);
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