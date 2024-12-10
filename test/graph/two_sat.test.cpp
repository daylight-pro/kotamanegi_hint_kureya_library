#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "test/template.hpp"

#include "src/graph/scc.hpp"
#include "src/graph/two_sat.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string _;
   cin >> _ >> _;
   int N, M;
   cin >> N >> M;
   two_sat ts(N);
   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b >> _;
      bool f, g;
      if(a < 0) {
         a = -a - 1;
         f = false;
      } else {
         a--;
         f = true;
      }

      if(b < 0) {
         b = -b - 1;
         g = false;
      } else {
         b--;
         g = true;
      }
      ts.add_clause(a, f, b, g);
   }
   if(!ts.satisfiable()) {
      cout << "s UNSATISFIABLE" << endl;
      return 0;
   } else {
      cout << "s SATISFIABLE" << endl;
      auto ans = ts.answer();
      cout << "v ";
      for(int i = 0; i < N; i++) { cout << (ans[i] ? i + 1 : -i - 1) << " "; }
   }
   cout << "0" << endl;
   return 0;
}