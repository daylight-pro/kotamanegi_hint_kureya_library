#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int T;
   cin >> T;
   while(T--) {
      int x0, y0, x1, y1, x2, y2, x3, y3;
      cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Point p0(x0, y0), p1(x1, y1), p2(x2, y2), p3(x3, y3);
      if(isinterSS({p0, p1}, {p2, p3})) {
         cout << 1 << "\n";
      } else {
         cout << 0 << "\n";
      }
   }
   return 0;
}