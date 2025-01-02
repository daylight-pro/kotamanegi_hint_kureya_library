#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "test/template.hpp"
#include "test/data-structure/BIT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   ll N, Q;
   cin >> N >> Q;

   BIT A(N);
   for(int i = 0; i < N; i++) {
      ll a;
      cin >> a;
      A.add(i, a);
   }

   while(Q--) {
      ll a, b, c;
      cin >> a >> b >> c;
      if(a == 0) A.add(b, c);
      else cout << A.sum(b, c) << '\n';
   }
}
