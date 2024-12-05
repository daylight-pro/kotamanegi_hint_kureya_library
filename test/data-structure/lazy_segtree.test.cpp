#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/data-structure/lazy_segtree.hpp"

struct S {
   mm val;
   int sz;
};
using F = pair<mm, mm>;

const F ID = {mm(1), mm(0)};

S op(S a, S b) { return {a.val + b.val, a.sz + b.sz}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {f.first * x.val + f.second * x.sz, x.sz}; }
F composition(F f, F g) {
   auto [fb, fc] = f;
   auto [gb, gc] = g;
   return {fb * gb, fc + fb * gc};
}
F id() { return ID; }

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;
   vector<S> A(N);
   rep(i, 0, N) {
      int a;
      cin >> a;
      A[i] = {mm(a), 1};
   }
   lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
   while(Q--) {
      int k;
      cin >> k;
      if(k == 0) {
         int l, r, b, c;
         cin >> l >> r >> b >> c;
         seg.apply(l, r, {b, c});
      } else {
         int p;
         cin >> p;
         cout << seg.get(p).val.x << '\n';
      }
   }
}