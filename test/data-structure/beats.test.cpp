#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "test/template.hpp"
#include "test/data-structure/beats.cpp"
#include "src/data-structure/beats_example.cpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   using namespace RangeChMinMaxAddSum;
   vector<S> A(N);
   for(auto&& a : A) {
      ll x;
      cin >> x;
      a = S(x);
   }
   lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
   while(Q--) {
      int k;
      cin >> k;
      if(k == 0) {
         int l, r;
         ll b;
         cin >> l >> r >> b;
         seg.apply(l, r, F::chmin(b));
      } else if(k == 1) {
         int l, r;
         ll b;
         cin >> l >> r >> b;
         seg.apply(l, r, F::chmax(b));
      } else if(k == 2) {
         int l, r;
         ll b;
         cin >> l >> r >> b;
         seg.apply(l, r, F::add(b));
      } else if(k == 3) {
         int l, r;
         cin >> l >> r;
         cout << seg.prod(l, r).sum << endl;
      }
   }
   return 0;
}
