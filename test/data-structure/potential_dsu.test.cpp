#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"

#include "test/template.hpp"
#include "src/data-structure/potential_dsu.hpp"

struct Abel {
   using T = int;
   static T e() { return 0; }
   static T op(T a, T b) { return a + b; }
   static T inv(T a) { return -a; }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M;
   while(cin >> N >> M) {
      if(N == 0 && M == 0) break;
      potential_dsu<Abel> dsu(N);
      while(M--) {
         char c;
         cin >> c;
         if(c == '!') {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            dsu.merge(a, b, c);
         } else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if(dsu.same(a, b)) {
               cout << dsu.diff(a, b) << endl;
            } else {
               cout << "UNKNOWN" << endl;
            }
         }
      }
   }
   return 0;
}