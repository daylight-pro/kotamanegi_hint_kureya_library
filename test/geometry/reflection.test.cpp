#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR "1e-8"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int x0, y0, x1, y1;
   cin >> x0 >> y0 >> x1 >> y1;
   int N;
   cin >> N;
   cout << fixed << setprecision(10);
   for(int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      auto p = reflection(Point(x, y), Line{Point(x0, y0), Point(x1, y1)});
      cout << p.X << " " << p.Y << "\n";
   }
   return 0;
}
