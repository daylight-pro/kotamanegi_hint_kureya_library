#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
      cout << wm.kthMin(l, r, 0) << endl;
   }
   return 0;
}