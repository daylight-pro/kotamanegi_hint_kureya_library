// AC確認済み https://judge.yosupo.jp/submission/269644

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

template<typename T, typename F> vector<int> monotone_minima(int h, int w, const F& f) {
   vector<pair<int, T>> dp(h, pair(-1, T()));
   auto rec = [&](auto&& rec, int u, int d, int l, int r) {
      if(u > d) return;
      int mid = (u + d) >> 1;
      auto& [idx, mi] = dp[mid];
      idx = l, mi = f(mid, l);
      for(int i = l + 1; i <= r; i ++) if(chmin(mi, f(mid, i))) idx = i;
      rec(rec, u, mid - 1, l, idx);
      rec(rec, mid + 1, d, idx, r);
   };
   rec(rec, 0, h - 1, 0, w - 1);
   vector<int> ret;
   for(auto [idx, val] : dp) ret.push_back(idx);
   return ret;
}

// b is concave
template<typename T> vector<T> minplus_conv_concave(vector<T> &a, vector<T> &b) {
   int n = a.size(), m = b.size();
   if(min(n, m) == 0) return vector<T> ();
   int h = n + m - 1, w = n;
   vector<int> ymin(h, 0), ymax(h, w - 1), xmin(w), xmax(w);
   for(int x = m; x < h; x ++) ymin[x] = x - m + 1;
   for(int x = 0; x <= h - m; x ++) ymax[x] = x;
   iota(all(xmin), 0); iota(all(xmax), m - 1);
   vector<T> c(h, INF); // if long long
   auto rec = [&](auto&& rec, int x1, int x2, int y1, int y2) {
      if(ymax[x1] >= y2 and y1 >= ymin[x2]) {
         auto A = [&](int i, int j) { return a[y2 - j] + b[x1 + i - y2 + j]; };
         auto jmin = monotone_minima<T>(x2 - x1 + 1, y2 - y1 + 1, A);
         for(int i = x1; i <= x2; i ++) chmin(c[i], A(i - x1, jmin[i - x1]));
         return;
      }
      if((ll)(x2 - x1) * (y2 - y1) < 1000) {
         for(int x = x1; x <= x2; x ++) for(int y = max(ymin[x], y1); y <= min(ymax[x], y2); y ++) chmin(c[x], a[y] + b[x - y]);
         return;
      }
      if(x2 - x1 > y2 - y1) {
         int xm = (x1 + x2) / 2;
         int ny2 = min(ymax[xm], y2), ny1 = max(ymin[xm], y1);
         if(y1 <= ny2) rec(rec, x1, xm, y1, ny2);
         if(ny1 <= y2) rec(rec, xm + 1, x2, ny1, y2);
		} else {
         int ym = (y1 + y2) / 2;
         int nx2 = min(xmax[ym], x2), nx1 = max(xmin[ym], x1);
         if(x1 <= nx2) rec(rec, x1, nx2, y1, ym);
         if(nx1 <= x2) rec(rec, nx1, x2, ym + 1, y2);
      }
	};
   rec(rec, 0, h - 1, 0, w - 1);
   return c;
}
int main() {
   int n, m; cin >> n >> m; vector<ll> a(n), b(m);
   for(int i = 0; i < n; i ++) cin >> a[i];
   for(int i = 0; i < m; i ++) cin >> b[i];
   auto c = minplus_conv_concave(b, a);
   for(ll e : c) cout << e << " ";
   cout << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/algorithm/min_plus_conv.hpp"
#include "src/algorithm/min_plus_concave.hpp"
int main() { puts("Hello World"); }