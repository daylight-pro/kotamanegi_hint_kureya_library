// AC済み https://qoj.ac/submission/912927
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

vector<ll> di(vector<vector<int>> &v, vector<ll> &h, int s) {
   int n = v.size();
   vector<ll> dis(n, INF);
   multiset<pair<ll, ll>> ms;
   dis[s] = 0;
   ms.insert({0, s});
   while(!ms.empty()) {
      auto [d, now] = *ms.begin();
      ms.erase(ms.begin());
      if(d > dis[now]) continue;
      for(int e : v[now]) {
         if(dis[e] > dis[now] + (h[now] - h[e]) * (h[now] - h[e])) {
            dis[e] = dis[now] + (h[now] - h[e]) * (h[now] - h[e]);
            ms.insert({dis[e], e});
         }
      }
   }
   return dis;
}

using Int = __int128;

template <typename T>
class LiChaoTree {
   int n, sz, height;
   vector<T> xs, as, bs;

   void update(T a, T b, int k, int h) {
      int l = (k << h) & (sz - 1);
      int r = l + (1 << h);
      
      while(1) {
         int m = (l + r) >> 1;
         T xl = xs[l], xm = xs[m];
         bool l_update = a*xl + b < as[k]*xl + bs[k];
         bool m_update = a*xm + b < as[k]*xm + bs[k];

         if(m_update) {
            swap(as[k], a);
            swap(bs[k], b);
         }
         if(h == 0) break;
         if(l_update != m_update) {
            k = k*2;
            r = m;
         } else {
            k = k*2+1;
            l = m;
         }
         h--;
      }
   }

public:
   // 最小値クエリのx座標や線分追加クエリの両端のx座標を先読みしてソートした配列
   LiChaoTree(const vector<T>& xs) : n(xs.size()), xs(xs) {
      sz = 1, height = 0;
      while(sz < (int)xs.size()) {
         sz <<= 1;
         height++;
      }
      this->xs.resize(sz, xs.back());
      as.assign(sz*2, 0);
      bs.assign(sz*2, std::numeric_limits<T>::max());
   }

   void add_line(T a, T b) {
      update(a, b, 1, height);
   }

   void add_segment(T a, T b, int l, int r) {
      if(l == r) return;
      l += sz, r += sz;
      int h = 0;
      while(l < r) {
         if(l & 1) update(a, b, l++, h);
         if(r & 1) update(a, b, --r, h);
         l >>= 1, r >>= 1, h++;
      }
   }

   // x = xs[i] における最小値を求める
   T get(int i) const {
      T x = xs[i];
      int k = i + sz;
      T res = as[k]*x + bs[k];
      while(k > 1) {
         k >>= 1;
         T tmp = as[k]*x + bs[k];
         if(tmp < res) res = tmp;
      }
      return res;
   }
};

int main() {
   ll n, m, s, t;
   cin >> n >> m >> s >> t;
   s --; t --;
   vector<ll> h(n);
   rep(i, n) cin >> h[i];
   vector<vector<int>> v(n);
   ll ans = INF;
   rep(i, m) {
      int a, b; cin >> a >> b;
      a --; b --;
      v[a].pb(b);
      v[b].pb(a);
      if(a == s and b == t) ans = 0;
      if(a == t and b == s) ans = 0;
   }
   auto rets = di(v, h, s);
   auto rett = di(v, h, t);
   
   rep(now, n) {
      int sz = v[now].size();
      rep(_, 2) {
         vector<pair<Int, int>> vec;
         vector<Int> xv;
         rep(i, sz) {
            vec.push_back({Int(h[v[now][i]]), i});
         }
         sort(all(vec));
         vector<int> ord(sz);
         rep(i, sz) {
            xv.pb(vec[i].first);
            ord[vec[i].second] = i;
         }
         LiChaoTree cht(xv);
         rep(i, sz) {
            int e = v[now][i];
            if(i) {
               Int val = cht.get(ord[i]);
               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e] + ll(val));
            }
            cht.add_line(Int(-2LL * h[e]), Int(2LL * rets[e] + h[e] * h[e]));
         }
         reverse(all(v[now]));
      }
   }

   for(int e : v[s]) {
      ans = min(ans, rett[e] * 2);
   }
   for(int e : v[t]) {
      ans = min(ans, rets[e] * 2);
   }

   if(ans % 2 == 0) {
      cout << ans / 2 << endl;
   } else {
      cout << ans / 2 << ".5" << endl;
   }
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/data-structure/li_chao.hpp"
int main() { puts("Hello World"); }