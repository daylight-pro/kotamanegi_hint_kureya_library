// AC確認済み https://judge.yosupo.jp/submission/268935

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

ll floor_sum(const ll& n, const ll& m, ll a, ll b) {
   ll ret = 0;
   if(a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;
   if(b >= m) ret += n * (b / m), b %= m;
   ll y = (a * n + b) / m;
   if(y == 0) return ret;
   ll x = y * m - b;
   ret += (n - (x + a - 1) / a) * y;
   ret += floor_sum(y, a, m, (a - x % a) % a);
   return ret;
}

// depends on floor_sum
// \sum_0^(n-1) floor((a * i + b) / m)
ll min_of_mod_of_linear(ll n, ll m, ll a, ll b) {
   ll fsum = floor_sum(n, m, a, b);
   ll le = -1, ri = m - 1;
   while(ri - le > 1) {
      ll mid = (le + ri) / 2;
      if(floor_sum(n, m, a, b + (m - 1 - mid)) < fsum + n) ri = mid;
      else le = mid;
   }
   return ri;
}

int main() {
   int t; cin >> t;
   while(t --) {
      ll n, m, a, b;
      cin >> n >> m >> a >> b;
      cout << min_of_mod_of_linear(n, m, a, b) << endl;
   }
   
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/math/floor_sum.hpp"
#include "src/math/min_of_mod_of_linear.hpp"
int main() { puts("Hello World"); }