#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "test/template.hpp"
#include "src/data-structure/ch_segtree.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto& a : A) cin >> a;
   ch_segtree seg(A);

   while(Q--) {
      int t;
      cin >> t;
      if(t == 0) {
         int l, r;
         ll x;
         cin >> l >> r >> x;
         seg.apply_chmin(l, r, x);
      } else if(t == 1) {
         int l, r;
         ll x;
         cin >> l >> r >> x;
         seg.apply_chmax(l, r, x);
      } else if(t == 2) {
         int l, r;
         ll x;
         cin >> l >> r >> x;
         seg.apply_add(l, r, x);
      } else {
         int l, r;
         cin >> l >> r;
         cout << seg.prod_sum(l, r) << '\n';
      }
   }
   return 0;
}