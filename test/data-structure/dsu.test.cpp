#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "test/template.hpp"
#include "src/data-structure/dsu.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int n, q;
   cin >> n >> q;
   dsu uf(n);
   while(q--) {
      int t, u, v;
      cin >> t >> u >> v;
      if(t == 0) uf.merge(u, v);
      else cout << uf.same(u, v) << "\n";
   }
   return 0;
}