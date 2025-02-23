// AC済み https://qoj.ac/submission/912918

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

template<typename T>
class CHT {
   using P = pair<T, T>;
private:
   int head;
   vector<P> lines;
   // 最小値(最大値)を求めるxが単調であるか
   bool isMonotonicX;
   function<bool(T l, T r)> comp;

public:
   // クエリが単調であった場合はflag = trueとする
   CHT(bool flagX = false, function<bool(T l, T r)> compFunc = [](T l, T r) {return l >= r; })
      :isMonotonicX(flagX), comp(compFunc), head(0) {};

   bool check(P l1, P l2, P l3) {
      if (l1 < l3) swap(l1, l3);
      return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
   }

   void add(T a, T b) {
      P line(a, b);
      while (lines.size() >= 2 + head && check(*(lines.end() - 2), lines.back(), line))
         lines.pop_back();
      lines.emplace_back(line);
   }

   T f(int i, T x) {
      return lines[i].first * x + lines[i].second;
   }

   T f(P line, T x) {
      return line.first * x + line.second;
   }

   T get(T x) {
      if (isMonotonicX) {
         while (lines.size() >= 2 + head && comp(f(head, x), f(head + 1, x)))
            ++ head;
         return f(head, x);
      }
      else {
         int low = -1, high = lines.size() - 1;
         while (high - low > 1) {
            int mid = (high + low) / 2;
            (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
         }
         return f(high, x);
      }
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
      {
         int sz = v[now].size();
         vector<int> ord(sz);
         iota(all(ord), 0);
         sort(all(ord), [&](int i, int j) {
            return h[v[now][i]] < h[v[now][j]];
         });
         CHT<Int> cht(true);
         rep(i, sz) {
            int e = v[now][ord[i]];
            if(i) {
               Int val = cht.get(Int(h[e]));
               if(val < Int(INF)) ans = min(ans, 2LL * rett[e] + h[e] * h[e] + ll(val));
            }
            cht.add(Int(-2LL * h[e]), Int(2LL * rets[e] + h[e] * h[e]));
         }
      }
      {
         int sz = v[now].size();
         vector<int> ord(sz);
         iota(all(ord), 0);
         sort(all(ord), [&](int i, int j) {
            return h[v[now][i]] < h[v[now][j]];
         });
         CHT<Int> cht(false);
         rep(i, sz) {
            int e = v[now][ord[i]];
            if(i) {
               Int val = cht.get(Int(h[e]));
               if(val < Int(INF)) ans = min(ans, 2LL * rets[e] + h[e] * h[e] + ll(val));
            }
            cht.add(Int(-2LL * h[e]), Int(2LL * rett[e] + h[e] * h[e]));
         }
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
#include "src/data-structure/cht_slope_monotone.hpp"
int main() { puts("Hello World"); }