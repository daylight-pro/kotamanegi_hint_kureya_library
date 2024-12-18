#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/data-structure/wavelet_matrix.hpp"

int main() {
   vector<ll> A = {14, 19, 5, 14, 3, 5, 16, 5, 16, 2};
   WaveletMatrix<ll> wm(A);
   assert(wm.kthMin(0, 10, 0) == 2);
   assert(wm.kthMin(0, 10, 2) == 5);
   assert(wm.kMinSum(3, 7, 2) == 8);
   assert(wm.kMinSum(3, 7, 3) == 22);
   assert(wm.kMinSum(2, 6, 4) == 27);
   assert(wm.kMinSum(1, 2, 1) == 19);
   assert(wm.kMinSum(1, 2, 0) == 0);
   assert(wm.lessCount(1, 9, 10) == 4);
   assert(wm.lessCount(0, 1, 14) == 0);
   assert(wm.lessCount(0, 10, 14) == 5);
   assert(wm.lessCount(4, 9, 8) == 3);
   assert(wm.lessCount(0, 10, 20) == 10);
   puts("Hello World");
   return 0;
}
