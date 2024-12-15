#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "test/template.hpp"
#include "src/geometry/base.hpp"
#include "src/geometry/etc.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int T;
   cin >> T;
   while(T--) {
      int N;
      cin >> N;
      vector<Point> ps(N);
      for(int i = 0; i < N; i++) {
         int x, y;
         cin >> x >> y;
         ps[i] = Point(x, y);
      }
      auto [d, i, j] = closest_pair(ps);
      cout << i << " " << j << endl;
   }
   return 0;
}