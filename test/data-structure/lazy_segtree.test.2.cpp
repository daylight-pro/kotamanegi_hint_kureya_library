#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/data-structure/lazy_segtree.hpp"
#include "src/data-structure/lazy_segtree_bsearch.hpp"

using S = ll;
using F = ll;

const F ID = 2e16;

S op(S a, S b) { return min(a, b); }
S e() { return ID; }
S mapping(F f, S x) { return f == ID ? x : f; }
F composition(F f, F g) { return f == ID ? g : f; }
F id() { return ID; }

int main() {
   cin.tie(0)->sync_with_stdio(0);

   lazy_segtree<S, op, e, F, mapping, composition, id> seg(10);
   seg.set(0, 1);
   seg.set(1, 2);
   assert(seg.prod(0, 2) == 1);
   assert(seg.prod(1, 2) == 2);
   seg.apply(2, 10, 3);
   assert(seg.prod(0, 10) == 1);
   seg.apply(5, 7, 10);
   seg.apply(7, 10, 5);
   assert(min_left(seg, 10, [](ll x) { return x >= 2; }) == 1);
   assert(max_right(seg, 5, [](ll x) { return x > 5; }) == 7);
   cout << "Hello World" << endl;
}