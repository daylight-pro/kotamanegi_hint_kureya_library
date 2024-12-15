#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B"
#define ERROR "1e-8"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   vector<Point> ps(N);
   for(int i = 0; i < N; i++) {
      double x, y;
      cin >> x >> y;
      ps[i] = Point(x, y);
   }
   auto [d, i, j] = diameter(ps);
   cout << fixed << setprecision(10) << d << "\n";
   return 0;
}