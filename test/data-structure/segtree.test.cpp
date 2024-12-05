#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "test/template.hpp"
#include "src/data-structure/segtree.hpp"

ll op(ll a, ll b) { return min(a, b); }
ll e() { return 1e9 + 100; }
int main() {
   cin.tie(0)->sync_with_stdio(0);

   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   for(auto&& a : A) cin >> a;
   segtree<ll, op, e> seg(A);
   while(Q--) {
      int L, R;
      cin >> L >> R;
      cout << seg.prod(L, R) << '\n';
   }
}