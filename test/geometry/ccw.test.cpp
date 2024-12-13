#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int x_0, y_0, x_1, y_1;
   cin >> x_0 >> y_0 >> x_1 >> y_1;
   int N;
   cin >> N;
   for(int i = 0; i < N; i++) {
      int x_2, y_2;
      cin >> x_2 >> y_2;
      int result = ccw(Point(x_0, y_0), Point(x_1, y_1), Point(x_2, y_2));
      if(result == 0) {
         cout << "ON_SEGMENT"
              << "\n";
      } else if(result == 1) {
         cout << "COUNTER_CLOCKWISE"
              << "\n";
      } else if(result == 2) {
         cout << "ONLINE_BACK"
              << "\n";
      } else if(result == -1) {
         cout << "CLOCKWISE"
              << "\n";
      } else {
         cout << "ONLINE_FRONT"
              << "\n";
      }
   }
   return 0;
}