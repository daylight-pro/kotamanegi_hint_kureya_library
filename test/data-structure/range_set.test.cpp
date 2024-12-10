#define PROBLEM "https://yukicoder.me/problems/1601"

#include "test/template.hpp"
#include "src/data-structure/range_set.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   ll D, Q;
   cin >> D >> Q;
   ll ans = 0;
   range_set<> rs;
   while(Q--) {
      ll A, B;
      cin >> A >> B;
      rs.insert(A, B);
      auto [l, r] = *rs.get(A);
      chmax(ans, r - l + 1);
      cout << ans << '\n';
   }
   return 0;
}