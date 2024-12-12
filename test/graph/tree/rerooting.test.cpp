#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/graph/tree/rerooting.hpp"

vector<int> A;
struct M {
   using S = pair<mm, int>;
   using C = pair<mm, mm>;
   static S merge(S a, S b) { return {a.first + b.first, a.second + b.second}; }
   static S apply(S a, int from, int to, C b) {
      return {(a.first + A[from]) * b.first + b.second * (a.second + 1), a.second + 1};
   }
   static S e() { return {0, 0}; }
   static S leaf() { return {0, 0}; }
};

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int N;
   cin >> N;
   A.resize(N);
   for(auto& a : A) cin >> a;
   Rerooting<M> reroot(N);
   for(int i = 0; i < N - 1; i++) {
      int u, v, b, c;
      cin >> u >> v >> b >> c;
      reroot.add_edge(u, v, {b, c});
   }
   auto v = reroot.build();
   auto ans = vector<mm>(N);
   for(int i = 0; i < N; i++) ans[i] = v[i].first + A[i];
   for(int i = 0; i < N; i++) cout << ans[i].x << " \n"[i == N - 1];
   return 0;
}