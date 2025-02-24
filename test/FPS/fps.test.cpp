// すべてAC済み https://judge.yosupo.jp/submission/269563

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

using vm = vector<mm>;
vm pre(vm f, int sz) {return vm(f.begin(), f.begin() + min((int)f.size(), sz));}
vm inv(vm f, int deg = -1) {
   if (deg < 0) deg = (int)f.size();
   vm res({mm(1) / f[0]});
   for (int i = 1; i < deg; i <<= 1) {
      vm ff = conv(res, conv(res, pre(f, i << 1)));
      int sz = res.size();
      for(int j = 0; j < sz; j ++) res[j] += res[j];
      sz = max(sz, (int)ff.size());
      res.resize(sz); sz = ff.size();
      for(int j = 0; j < sz; j ++) res[j] -= ff[j];
      res = pre(res, i << 1);
   }
   res.resize(deg); return res;
}
vm diff(vm f) {
   int n = f.size(); vm res(n - 1);
   for(int i = 1; i < n; i ++) res[i - 1] = f[i] * i;
   return res;
}
vm intg(vm f) {
   int n = (int)f.size(); vm res(n+1, 0);
   for (int i = 0; i < n; i ++) res[i + 1] = f[i] / (i+1);
   return res;
}
vm log(vm f, int deg = -1) {
   if(deg == -1) deg = f.size();
   vm res = intg(conv(diff(f), inv(f, deg)));
   res.resize(deg); return res;
}
vm exp(vm f, int deg = -1) {
   vm res(1, 1);
   if(deg == -1) deg = f.size();
   for(int i = 1; i < deg; i <<= 1) {
      vm ff1 = pre(f, i << 1);
      vm ff2 = log(res, i << 1);
      ff1.resize(max(ff1.size(), ff2.size()));
      ff1[0] += mm(1);
      int sz = ff2.size();
      for(int j = 0; j < sz; j ++) ff1[j] -= ff2[j];
      res = conv(res, pre(ff1, i << 1));
   }
   res.resize(deg); return res;
}
vm taylor_shift(vm f, mm a) {
   int n = f.size();
   vm fac(n, 1), inv(n, 1), finv(n, 1);
   for(int i = 2; i < n; i ++) {
      fac[i] = fac[i - 1] * i;
      inv[i] = -inv[mod % i] * (mod / i);
      finv[i] = finv[i - 1] * inv[i];
   }
   for(int i = 0; i < n; i ++) f[i] *= fac[i];
   std::reverse(f.begin(), f.end());
   vm g(n, 1);
   for(int i = 1; i < n; i ++) g[i] = g[i - 1] * a * inv[i];
   f = pre(conv(f, g), n);
   reverse(f.begin(), f.end());
   for(int i = 0; i < n; i ++) f[i] *= finv[i];
   return f;
}

int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   int n, c; cin >> n >> c;
   vm a(n);
   for(int i = 0; i < n; i ++) {
      int x; cin >> x;
      a[i] = x;
   }
   auto ret = taylor_shift(a, mm(c));
   for(int i = 0; i < n; i ++) cout << ret[i].x << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
#include "src/FPS/fps.hpp"
int main() { puts("Hello World"); }