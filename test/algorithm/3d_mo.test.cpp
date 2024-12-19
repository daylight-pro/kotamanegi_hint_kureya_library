#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "test/template.hpp"
#include "src/algorithm/3d_mo.hpp"

int main() {
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   vector<ll> ans(Q);
   vector<int> type(Q), l(Q), r(Q);
   Mo_3D mo(N, Q);
   for(int i = 0; i < Q; i++) {
      cin >> type[i] >> l[i] >> r[i];
      l[i]--;
      if(type[i] == 1) { mo.insert(i, l[i], r[i]); }
   }
   ll sum = 0;
   auto add = [&](int x) { sum += A[x]; };
   auto del = [&](int x) { sum -= A[x]; };
   auto rem = [&](int ind) { ans[ind] = sum; };
   auto add_query = [&](int x, const auto& self) {
      if(type[x] == 1) return;
      if(self->v[l[x]]) {
         self->distribute(l[x]);
         A[l[x]] += r[x];
         self->distribute(l[x]);
      } else {
         A[l[x]] += r[x];
      }
   };
   auto del_query = [&](int x, const auto& self) {
      if(type[x] == 1) return;
      if(self->v[l[x]]) {
         self->distribute(l[x]);
         A[l[x]] -= r[x];
         self->distribute(l[x]);
      } else {
         A[l[x]] -= r[x];
      }
   };
   mo.run(add, del, rem, add_query, del_query);
   for(int i = 0; i < Q; i++) {
      if(type[i] == 1) cout << ans[i] << '\n';
   }
}