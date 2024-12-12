#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "test/template.hpp"
#include "src/data-structure/sparse_table.hpp"

int op(int a, int b) { return min(a, b); }

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<int> A(N);
   for(auto&& a : A) cin >> a;
   sparse_table<int, op> st(A);
   while(Q--) {
      int l, r;
      cin >> l >> r;
      cout << st.prod(l, r) << '\n';
   }
   return 0;
}