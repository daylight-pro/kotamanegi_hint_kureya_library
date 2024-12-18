#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "test/template.hpp"
#include "src/data-structure/wavelet_matrix.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto& a : A) cin >> a;
   WaveletMatrix<ll> wm(A);
   while(Q--) {
      int l, r, k;
      cin >> l >> r >> k;
      cout << wm.kthMin(l, r, k) << '\n';
   }
   return 0;
}
