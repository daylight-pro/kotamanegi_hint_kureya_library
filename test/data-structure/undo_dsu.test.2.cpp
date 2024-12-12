#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0723"

#include "test/template.hpp"
#include "src/data-structure/undo_dsu.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M, K;
   cin >> N >> M >> K;
   vector<pair<int, int>> edges(M);
   for(int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges[i] = {u, v};
   }

   vector<int> S(N);
   for(auto&& s : S) cin >> s;
   map<pair<int, int>, vector<pair<int, int>>> E;
   undo_dsu dsu(N);
   for(auto [u, v] : edges) {
      int su = S[u], sv = S[v];
      if(su == sv) {
         dsu.merge(u, v);
      } else {
         if(su > sv) {
            swap(u, v);
            swap(su, sv);
         }
         E[{su, sv}].push_back({u, v});
      }
   }
   int snapshot = dsu.snapshot();
   int Q;
   cin >> Q;
   vector<int> ans(Q);
   map<pair<int, int>, vector<int>> q;
   vector<pair<int, int>> query(Q);

   for(int i = 0; i < Q; i++) {
      int A, B;
      cin >> A >> B;
      A--;
      B--;
      if(S[A] > S[B]) swap(A, B);
      int SA = A;
      int SB = B;
      query[i] = {A, B};
      q[{S[A], S[B]}].push_back(i);
   }

   for(auto [key, value] : q) {
      auto [su, sv] = key;
      for(auto [u, v] : E[{su, sv}]) { dsu.merge(u, v); }
      for(auto i : value) {
         auto [A, B] = query[i];
         ans[i] = dsu.same(A, B);
      }
      dsu.rollback(snapshot);
   }
   for(auto&& a : ans) cout << a << '\n';
   return 0;
}
