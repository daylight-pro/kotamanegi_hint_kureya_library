#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "test/template.hpp"
#include "src/data-structure/binary_trie.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   BinaryTrie<ll, 62> bt;
   vector<ll> A(N);
   for(int i = 0; i < N; i++) {
      cin >> A[i];
      bt.add(A[i] * N + i);
   }
   while(Q--) {
      int t;
      cin >> t;
      if(t == 0) {
         int k;
         ll v;
         cin >> k >> v;
         bt.erase(A[k] * N + k);
         A[k] = v;
         bt.add(A[k] * N + k);
      } else {
         int l, r;
         ll x;
         cin >> l >> r >> x;
         cout << bt.lower_bound_rank(x * N + r) - bt.lower_bound_rank(x * N + l) << '\n';
      }
   }
   return 0;
}