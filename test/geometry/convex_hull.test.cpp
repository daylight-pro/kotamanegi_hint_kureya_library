#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/convex_hull.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   cout << fixed << setprecision(10);
   int T;
   cin >> T;
   while(T--) {
      int N;
      cin >> N;
      vector<Point> ps(N);
      for(int i = 0; i < N; i++) {
         double x, y;
         cin >> x >> y;
         ps[i] = Point(x, y);
      }
      auto ans = convex_hull(ps);
      cout << size(ans) << "\n";
      for(auto& p : ans) cout << int(round(p.X)) << " " << int(round(p.Y)) << "\n";
   }
   return 0;
}