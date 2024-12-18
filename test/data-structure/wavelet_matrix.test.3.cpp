#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "test/template.hpp"
#include "src/data-structure/wavelet_matrix.hpp"

int main() {
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto& a : A) cin >> a;
   WaveletMatrix wm(A);
   while(Q--) {
      int l, r;
      cin >> l >> r;
      cout << wm.kMinSum(l, r, r - l) << endl;
   }
   return 0;
}