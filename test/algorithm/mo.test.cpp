#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "test/template.hpp"
#include "src/data-structure/BIT.hpp"
#include "src/algorithm/mo.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<int> A(N);
   for(auto& a : A) cin >> a;
   vector<int> inv(N, -1);
   map<int, int> mp1;
   for(int e : A) mp1[e]++;
   {
      int id = 0;
      for(auto [x, y] : mp1) {
         inv[id] = x;
         mp1[x] = id++;
      }
      for(int i = 0; i < N; i++) { A[i] = mp1[A[i]]; }
   }

   Mo mo(N, Q);
   BIT bit(N);
   vector<ll> ans(Q);
   ll cur = 0;
   auto add_left = [&](int idx) {
      bit.add(A[idx], 1);
      cur += bit.sum(0, A[idx]);
   };
   auto add_right = [&](int idx) {
      bit.add(A[idx], 1);
      cur += bit.sum(A[idx] + 1, N);
   };
   auto delete_left = [&](int idx) {
      cur -= bit.sum(0, A[idx]);
      bit.add(A[idx], -1);
   };
   auto delete_right = [&](int idx) {
      cur -= bit.sum(A[idx] + 1, N);
      bit.add(A[idx], -1);
   };
   auto rem = [&](int idx) { ans[idx] = cur; };
   for(int i = 0; i < Q; i++) {
      int l, r;
      cin >> l >> r;
      mo.insert(l, r);
   }
   mo.run(add_left, add_right, delete_left, delete_right, rem);
   for(int i = 0; i < Q; i++) cout << ans[i] << '\n';

   return 0;
}