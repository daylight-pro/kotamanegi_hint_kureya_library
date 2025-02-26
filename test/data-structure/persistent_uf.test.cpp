#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "test/template.hpp"
#include "src/data-structure/persistent-array.hpp"
#include "src/data-structure/persistent-uf.hpp"

int main() {
   int N, Q;
   cin >> N >> Q;
   vector<PersistentUnionFind> uf(Q + 1);
   uf[0] = PersistentUnionFind(N);
   for(int i = 0; i < Q; i++) {
      int t, k, u, v;
      cin >> t >> k >> u >> v;
      ++k;
      if(t == 0) {
         uf[i + 1] = uf[k];
         uf[i + 1].unite(u, v);
      } else {
         cout << (uf[k].find(u) == uf[k].find(v)) << "\n";
      }
   }
   return 0;
}