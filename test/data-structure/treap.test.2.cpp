#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "test/template.hpp"
#include "src/data-structure/treap.hpp"

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return INT_MAX; }

using F = int;
S mapping(F f, S x, int sz) { return f == INT_MAX ? x : f; }
F composition(F f, F g) { return f == INT_MAX ? g : f; }
F id() { return INT_MAX; }

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   Treap<S, op, e, F, mapping, composition, id> treap;
   string T;
   cin >> T;
   for(int i = 0; i < N; i++) {
      if(T[i] == '1') treap.ordered_insert(i);
   }

   while(Q--) {
      int c, k;
      cin >> c >> k;
      if(c == 0) {
         int count = treap.upper_search(k) - treap.lower_search(k);
         if(count == 0) treap.ordered_insert(k);
      } else if(c == 1) {
         int count = treap.upper_search(k) - treap.lower_search(k);
         if(count == 1) treap.erase_value(k);
      } else if(c == 2) {
         int count = treap.upper_search(k) - treap.lower_search(k);
         cout << count << '\n';
      } else if(c == 3) {
         int cnt = treap.lower_search(k);
         if(cnt == treap.size()) {
            cout << -1 << "\n";
         } else {
            cout << treap[cnt] << "\n";
         }
      } else if(c == 4) {
         int cnt = treap.upper_search(k);
         if(cnt == 0) {
            cout << -1 << "\n";
         } else {
            cout << treap[cnt - 1] << "\n";
         }
      }
   }
   return 0;
}