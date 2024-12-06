#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "test/template.hpp"
#include "src/data-structure/segtree.hpp"

ll op(ll a, ll b) { return min(a, b); }
ll e() { return 1e9 + 100; }

int main() {
   cin.tie(0)->sync_with_stdio(0);
   vector<ll> A{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
   segtree<ll, op, e> seg(A);
   assert(seg.prod(0, 11) == 1);
   assert(seg.min_left(11, [](ll x) { return x >= 2; }) == 4);
   assert(seg.max_right(0, [](ll x) { return x > 0; }) == 11);
   seg.set(3, 0);
   assert(seg.min_left(11, [](ll x) { return x >= 2; }) == 4);
   assert(seg.max_right(0, [](ll x) { return x >= 0; }) == 11);
   assert(seg.max_right(0, [](ll x) { return x > 0; }) == 3);
   cout << "Hello World" << endl;
   return 0;
}