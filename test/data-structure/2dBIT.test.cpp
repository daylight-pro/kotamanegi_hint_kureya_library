#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include "test/template.hpp"
#include "src/data-structure/2dBIT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   BinaryIndexedTree2D<ll> bit(1003, 1003);
   while(N--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      bit.imos(x1, y1, x2, y2, 1);
   }
   int ans = 0;
   for(int i = 0; i < 1003; i++) {
      for(int j = 0; j < 1003; j++) { chmax(ans, bit.sum(i, j)); }
   }
   cout << ans << '\n';

   return 0;
}