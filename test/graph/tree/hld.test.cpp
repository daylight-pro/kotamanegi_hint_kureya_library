#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "test/template.hpp"
#include "test/data-structure/BIT.hpp"
#include "src/graph/tree/hld.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto&& a : A) cin >> a;
   HLDcomposition hld(N);
   for(int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      hld.add_edge(u, v);
   }
   hld.build();
   auto fw = BIT(N);
   for(int i = 0; i < N; i++) fw.add(hld.index(i), A[i]);
   while(Q--) {
      int k;
      cin >> k;
      if(k == 0) {
         int p, x;
         cin >> p >> x;
         fw.add(hld.index(p), x);
      } else {
         int u, v;
         cin >> u >> v;
         ll ans = 0;
         for(auto [l, r, f] : hld.path_query(u, v)) ans += fw.sum(l, r);
         cout << ans << endl;
      }
   }
   return 0;
}
