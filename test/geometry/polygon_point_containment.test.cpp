#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"
#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/polygon_point_containment.hpp"

int main() {
   int N;
   cin >> N;
   vector<Point> ps(N);
   for(int i = 0; i < N; i++) {
      double x, y;
      cin >> x >> y;
      ps[i] = Point(x, y);
   }
   int Q;
   cin >> Q;
   while(Q--) {
      double x, y;
      cin >> x >> y;
      Point p(x, y);
      cout << contains(ps, p) << "\n";
   }
}