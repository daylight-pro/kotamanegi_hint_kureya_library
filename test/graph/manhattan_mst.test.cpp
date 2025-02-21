// AC確認済み https://judge.yosupo.jp/submission/268852

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

struct UnionFind {
   vector<int> par;
   UnionFind(int n) :par(n, -1) { }
   void init(int n) { par.assign(n, -1); }
   int root(int x) {
      if (par[x] < 0) return x;
      else return par[x] = root(par[x]);
   }
   bool connect(int x, int y) {
      x = root(x); y = root(y);
      if (x == y) return false;
      if (par[x] > par[y]) swap(x, y);
      par[x] += par[y];
      par[y] = x;
      return true;
   }
   int size(int x) {
      return -par[root(x)];
   }
};

// 候補の辺を O(N) 本に減らす。MST時は追加でsort, UF等の必要あり。
template<typename T>
vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
   assert(xs.size() == ys.size());
   vector<tuple<T, int, int>> ret;
   int n = (int) xs.size();

   vector<int> ord(n);
   iota(ord.begin(), ord.end(), 0);

   for(int s = 0; s < 2; s++) {
      for(int t = 0; t < 2; t++) {
         auto cmp = [&](int i, int j) -> bool {
            return xs[i] + ys[i] < xs[j] + ys[j];
         };
         sort(ord.begin(), ord.end(), cmp);

         map<T, int> idx;
         for(int i: ord) {
            for(auto it = idx.lower_bound(-ys[i]);
                  it != idx.end(); it = idx.erase(it)) {
               int j = it->second;
               if(xs[i] - xs[j] < ys[i] - ys[j]) break;
               ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);
            }
            idx[-ys[i]] = i;
         }
         swap(xs, ys);
      }
      for(int i = 0; i < n; i++) xs[i] *= -1;
   }
   return ret;
}

int main() {
   int n; cin >> n;
   vector<ll> x(n), y(n);
   for(int i = 0; i < n; i ++) cin >> x[i] >> y[i];
   auto ret = manhattan_mst(x, y);
   UnionFind uf(n);
   ll sum = 0;
   vector<pair<int, int>> edges;
   sort(all(ret));
   for(auto [a, b, c] : ret) {
      if(uf.root(b) == uf.root(c)) continue;
      edges.push_back({b, c});
      sum += a;
      uf.connect(b, c);
   }
   cout << sum << '\n';
   for(auto [a, b] : edges) {
      cout << a << " " << b << '\n';
   }
   return 0;
}
*/

int main() {return 0;}