#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "test/template.hpp"
#include "src/geometry/base.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   Point p(1, 2);
   p *= 3;
   assert(p.X == 3);
   assert(p.Y == 6);
   puts("Hello World");
   return 0;
}