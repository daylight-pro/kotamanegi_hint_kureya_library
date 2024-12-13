#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   cout << fixed << setprecision(10);
   Point a, b;
   {
      int x, y;
      cin >> x >> y;
      a = Point(x, y);
   }
   {
      int x, y;
      cin >> x >> y;
      b = Point(x, y);
   }
   Line l = {a, b};
   int q;
   cin >> q;
   while(q--) {
      int x, y;
      cin >> x >> y;
      Point c(x, y);
      auto p = projection(c, l);
      cout << p.X << " " << p.Y << "\n";
   }
   return 0;
}