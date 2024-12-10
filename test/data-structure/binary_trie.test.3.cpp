#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "test/template.hpp"
#include "src/data-structure/binary_trie.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   string T;
   cin >> T;

   BinaryTrie<ll> trie;
   for(int i = 0; i < N; i++) {
      if(T[i] == '1') trie.add(i);
   }

   while(Q--) {
      int c;
      cin >> c;
      if(c == 0) {
         int k;
         cin >> k;
         if(trie.count(k) == 0) trie.add(k);
      } else if(c == 1) {
         int k;
         cin >> k;
         if(trie.count(k) > 0) trie.erase(k);
      } else if(c == 2) {
         int k;
         cin >> k;
         cout << (trie.count(k) > 0 ? 1 : 0) << "\n";
      } else if(c == 3) {
         int k;
         cin >> k;
         int cnt = trie.lower_bound_rank(k);
         if(cnt == trie.count()) {
            cout << -1 << "\n";
         } else {
            cout << trie.kth_smallest(cnt) << "\n";
         }
      } else if(c == 4) {
         int k;
         cin >> k;
         int cnt = trie.upper_bound_rank(k);
         if(cnt == 0) {
            cout << -1 << "\n";
         } else {
            cout << trie.kth_smallest(cnt - 1) << "\n";
         }
      }
   }
   return 0;
}