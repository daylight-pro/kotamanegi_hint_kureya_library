// AC確認済み https://atcoder.jp/contests/abc315/submissions/63095397

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


template<typename T> class RelaxedConvolution {
   int N, pos;
   vector<T> f, g, buf;
   vector<vector<tuple<int, int, int, int>>> event;
   void dfs1(int le, int ri) {
      if(ri - le == 1) {
         event[le].push_back({le, le + 1, 0, 1});
         return;
      }
      int mid = (le + ri) / 2;
      event[mid].push_back({le, mid, mid - le, ri - le});
      event[ri].push_back({mid, ri, mid - le, ri - le});
      dfs1(le, mid);
      dfs1(mid, ri);
   }
   void dfs2(int le, int ri) {
      if(ri - le == 1) {
         event[le].push_back({0, 1, le, le + 1});
         return;
      }
      int mid = (le + ri) / 2;
      event[mid].push_back({mid - le, ri - le, le, mid});
      event[ri].push_back({mid - le, ri - le, mid, ri});
      dfs2(le, mid);
      dfs2(mid, ri);
   }
   void dfs(int len) {
      if(len == 1) {
         event[0].push_back({0, 1, 0, 1});
         return;
      }
      int mid = len / 2;
      event[len].push_back({mid, len, mid, len});
      dfs(mid);
      dfs1(mid, len);
      dfs2(mid, len);
   }
public:
   RelaxedConvolution(int n) {
      N = 1, pos = 0;
      while(N < n) N *= 2;
      f.resize(N);
      g.resize(N);
      buf.resize(N);
      event.resize(N+1);
      dfs(N);
   }
   T get(T x, T y) {
      f[pos] = x, g[pos] = y;
      for(auto [fl, fr, gl, gr] : event[pos]) {
         vector<T> A({f.begin() + fl, f.begin() + fr});
         vector<T> B({g.begin() + gl, g.begin() + gr});
         auto ret = conv(A, B);
         int sz = ret.size();
         for(int i = 0; i < sz; i ++) {
            if(i + fl + gl >= N) break;
            buf[i + fl + gl] += ret[i];
         }
      }
      return buf[pos++];
   }
};

int main() {
   int n;
   cin >> n;
   RelaxedConvolution<mm> f(n + 1);
   mm sum = 0;
   mm p = 1;

   vector<mm> ans;

   for(int i = 0; i < n; i ++) {
      ll x; cin >> x;
      sum += f.get(p, p);
      p = sum * mm(x);
      ans.push_back(p);
   }
   for(mm x : ans) cout << x.x << " ";
   cout << endl;

   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
#include "src/FPS/relaxed_conv.hpp"
int main() { puts("Hello World"); }