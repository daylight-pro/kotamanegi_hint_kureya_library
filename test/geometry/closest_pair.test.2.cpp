#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n;
   cin >> n;
   vector<Point> ps(n);
   for(int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      ps[i] = Point(x, y);
   }
   auto [d, i, j] = closest_pair(ps);
   cout << fixed << setprecision(10) << d << endl;
   return 0;
}