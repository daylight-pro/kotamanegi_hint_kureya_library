#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include "test/template.hpp"
#include "src/data-structure/dsu.hpp"
#include "src/graph/eulerian_trail.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int T;
   cin >> T;
   while(T--) {
      int N, M;
      cin >> N >> M;
      EulerianTrail<true> et(N);
      for(int i = 0; i < M; i++) {
         int a, b;
         cin >> a >> b;
         et.add_edge(a, b);
      }
      if(M == 0) {
         cout << "Yes" << "\n";
         cout << "0" << "\n";
         cout << "\n";
         continue;
      }
      auto ans = et.enumerate_semi_et();
      if(size(ans) != 1) {
         cout << "No" << "\n";
      } else {
         cout << "Yes" << "\n";
         cout << et.get_edge(ans[0][0]).first;
         for(auto i : ans[0]) { cout << " " << et.get_edge(i).second; }
         cout << "\n";
         for(int i = 0; i < M; i++) { cout << ans[0][i] << " \n"[i == M - 1]; }
      }
   }
   return 0;
}