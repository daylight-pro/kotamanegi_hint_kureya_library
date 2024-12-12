/*
スペシャルジャッジのためverifyできないがAC確認済み
https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=9994177

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "test/template.hpp"
#include "src/graph/topological_sort.hpp"


int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> g(N);
   for(int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
   }
   auto res = topological_sort(g);
   for(auto x : res) cout << x << '\n';
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/graph/topological_sort.hpp"

int main() { puts("Hello World"); }
