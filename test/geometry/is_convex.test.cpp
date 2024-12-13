#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   vector<Point> ps(N);
   for(int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      ps[i] = Point(x, y);
   }
   cout << is_convex(ps) << "\n";
   return 0;
}