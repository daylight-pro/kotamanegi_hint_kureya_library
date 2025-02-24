// AC確認済み https://yukicoder.me/submissions/1045895

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

template <typename T> // B is convex. if both A and B are convex, do greedy. 
vector<T> minplus_conv(vector<T>& A, vector<T>& B) {
   int n = A.size(), m = B.size();
   if (n == 0 && m == 0) return {};
   vector<T> C(n + m - 1);

   const ll inf = INF;
   auto select = [&](int i, int j) -> T {
      if(i < j) return inf;
      if(i - j >= m) return inf;
      return A[j] + B[i - j];
   };
   vector<int> J = monotone_minima<T>(n + m - 1, n, select); 
   for(int i = 0; i < n + m - 1; i ++) {
      T x = A[J[i]], y = B[i - J[i]];
      if (x < inf && y < inf) C[i] = x + y;
   }
   return C;
}

template <typename T>
vector<T> monge_shortest_path(int N, const function<T(int, int)>& f) {
   T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;
   vector<T> dp(N + 1, INF);
   vector<int> x(N + 1, 0);
   auto check = [&](int from, int to) {
      if (from >= to) return;
      T cost = f(from, to);
      if (dp[from] + cost < dp[to]) dp[to] = dp[from] + cost, x[to] = from;
   };
   auto dfs = [&](auto rc, int l, int r) -> void {
      if (l + 1 >= r) return;
      int m = (l + r) / 2;
      for (int i = x[l]; i <= x[r]; i++) check(i, m);
      rc(rc, l, m);
      for (int i = l + 1; i <= m; i++) check(i, r);
      rc(rc, m, r);
   };
   dp[0] = 0, check(0, N), dfs(dfs, 0, N);
   return dp;
}

   // [min, max] は閉区間を入力する
template <typename T, bool get_min = true>
pair<ll, T> golden_section_search(const function<T(ll)>& f, ll min,
                                    ll max) {
   assert(min <= max);
   ll a = min - 1, x, b;
   {
      ll s = 1, t = 2;
      while (t < max - min + 2) swap(s += t, t);
      x = a + t - s, b = a + t;
   }
   T fx = f(x), fy;
   while (a + b != 2 * x) {
      ll y = a + b - x;
      if (max < y || (fy = f(y), get_min ? fx < fy : fx > fy)) {
         b = a;
         a = y;
      } else {
         a = x;
         x = y;
         fx = fy;
      }
   }
   return {x, fx};
}

   // upper : max abs(辺数を 1 増減させたときのコストの変化)
ll monge_d_edge_shortest_path(int N, int D, ll upper,
      const function<ll(int, int)>& f) {
   using T = __int128_t;
   upper = abs(upper);
   auto dp = [&](ll x) -> T {
      auto g = [&](int from, int to) -> T { return f(from, to) + x; };
      T cost = monge_shortest_path<T>(N, g)[N];
      return cost - T{1} * D * x;
   };
   auto [_, res] = golden_section_search<T, false>(dp, -upper, upper);
   return res;
}

vector<ll> enumerate_monge_d_edge_shortest_path(
      int N, const function<ll(int, int)>& f,
      ll unreached = (1LL << 62) - 1) {
   using T = __int128_t;
   T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;
   vector<ll> ans(N + 1, unreached);
   vector<T> dp(N + 1, INF);
   dp[0] = 0;
   for (int d = 1; d <= N; d++) {
      vector<int> midx = monotone_minima<T>(N + 1, N + 1, [&](int j, int i) -> T {
         return i < j ? dp[i] + f(i, j) : INF;
      });
      for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] + f(midx[i], i);
      ans[d] = dp[N];
   }
   return ans;
}

int main() {
   cin.tie(0);       
   ios::sync_with_stdio(false);
   int n; cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i ++) cin >> a[i];
   vector<ll> r(n + 1);
   for(int i = 0; i < n; i ++) r[i + 1] = r[i] + a[i];

   auto cost = [&](int i, int j) -> ll {
      assert(i < j);
      if (i + 1 == j) return 0;
      return (r[j - 1] - r[i]) * (r[j - 1] - r[i]);
   };
   auto ans = enumerate_monge_d_edge_shortest_path(n + 1, cost);
   for(int d = 0; d < n; d ++) cout << ans[n - d] << '\n';
 
   // verify 用, 何点か調べる
   {
      vector<int> ds;
      for(int i = 0; i < 10; i ++) {
         int num = (99824433 * i) % (n + 1);
         num ++;
         ds.push_back(num);
      }
      for(int d : ds) {
         ll ans2 = monge_d_edge_shortest_path(n + 1, d, INF, cost);
         assert(ans2 == ans[d]);
      }
   }
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/algorithm/min_plus_conv.hpp"
#include "src/algorithm/larsch.hpp"

int main() { puts("Hello World"); }