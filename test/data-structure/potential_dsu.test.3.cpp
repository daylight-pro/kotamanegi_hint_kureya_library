
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/data-structure/potential_dsu.hpp"

struct Abel {
   using T = mm;
   static T e() { return 0; }
   static T op(T a, T b) { return a + b; }
   static T inv(T a) { return mm(-a.x); }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   potential_dsu<Abel> dsu(N);
   while(Q--) {
      int t;
      cin >> t;
      if(t == 0) {
         int a, b, c;
         cin >> a >> b >> c;
         if(dsu.same(b, a) && dsu.diff(b, a).x != c) {
            cout << 0 << endl;
            continue;
         }
         if(!dsu.same(b, a)) dsu.merge(b, a, c);
         cout << 1 << endl;
      } else {
         int a, b;
         cin >> a >> b;
         if(dsu.same(a, b)) cout << dsu.diff(b, a).x << endl;
         else cout << -1 << endl;
      }
   }
   return 0;
}