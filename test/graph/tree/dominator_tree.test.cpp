// AC確認済み https://www.acmicpc.net/problem/20174
// 少し改変した https://ei1333.github.io/library/graph/others/dominator-tree.hpp.html
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

struct DominatorTree {
public:
   DominatorTree(vector<vector<int>> &g_, int root = 0) : g(g_) {
      const int N = (int)g.size();
      rg = vector<vector<int>>(N);
      par.assign(N, 0);
      idom.assign(N, -1);
      semi.assign(N, -1);
      ord.reserve(N);
      UnionFind uf(semi);
      
      dfs(root);
      for (int i = 0; i < N; i++) {
         for (auto &to : g[i]) {
         if (~semi[i]) rg[to].emplace_back(i);
         }
      }

      vector<vector<int> > bucket(N);
      vector<int> U(N);
      for (int i = (int)ord.size() - 1; i >= 0; i--) {
         int x = ord[i];
         for (int v : rg[x]) {
         v = uf.eval(v);
         if (semi[x] > semi[v]) semi[x] = semi[v];
         }
         bucket[ord[semi[x]]].emplace_back(x);
         for (int v : bucket[par[x]]) U[v] = uf.eval(v);
         bucket[par[x]].clear();
         uf.link(par[x], x);
      }
      for (int i = 1; i < (int)ord.size(); i++) {
         int x = ord[i], u = U[x];
         idom[x] = semi[x] == semi[u] ? semi[x] : idom[u];
      }
      for (int i = 1; i < (int)ord.size(); i++) {
         int x = ord[i];
         idom[x] = ord[idom[x]];
      }
      idom[root] = root;
   }

   int operator[](const int &k) const { return idom[k]; }

private:
   vector<vector<int>> g, rg;

   struct UnionFind {
      const vector<int> &semi;
      vector<int> par, m;

      explicit UnionFind(const vector<int> &semi)
         : semi(semi), par(semi.size()), m(semi.size()) {
         iota(begin(par), end(par), 0);
         iota(begin(m), end(m), 0);
      }

      int find(int v) {
         if (par[v] == v) return v;
         int r = find(par[v]);
         if (semi[m[v]] > semi[m[par[v]]]) m[v] = m[par[v]];
         return par[v] = r;
      }

      int eval(int v) {
         find(v);
         return m[v];
      }

      void link(int p, int c) { par[c] = p; }
   };

   vector<int> ord, par;
   vector<int> idom, semi;

   void dfs(int idx) {
      semi[idx] = (int)ord.size();
      ord.emplace_back(idx);
      for (auto &to : g[idx]) {
         if (~semi[to]) continue;
         dfs(to);
         par[to] = idx;
      }
   }
};

int main() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<int>> v(n + 1);
   for(int i = 1; i <= m; i ++) {
      v[0].push_back(i);
   }
   for(int i = 0; i < k; i ++) {
      int x, y; cin >> x >> y;
      if(x != y) v[x].push_back(y);
   }
   DominatorTree g(v, 0);
   int cnt = 0;
   for(int i = 1; i <= n; i ++) if(g[i] == 0) cnt ++;
   cout << cnt << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/graph/tree/dominator_tree.hpp"
int main() { puts("Hello World"); }