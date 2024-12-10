#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"

#include "test/template.hpp"
#include "src/data-structure/range_set.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, M, Q;
   cin >> N >> M >> Q;
   using T = tuple<int, int, int>;
   priority_queue<T, vector<T>, greater<>> update, query;
   rep(i, 0, M) {
      int D, A, B;
      cin >> D >> A >> B;
      update.emplace(D, A, B);
   }
   vector<pair<int, int>> q(Q);
   rep(i, 0, Q) {
      int E, S, T;
      cin >> E >> S >> T;
      query.emplace(E, i, -1);
      q[i] = {S, T};
   }
   range_set<false> rs;
   vector<bool> ansV(Q);
   while(!query.empty()) {
      auto [E, I, _] = query.top();
      query.pop();
      while(!update.empty() && get<0>(update.top()) < E) {
         auto [D, A, B] = update.top();
         update.pop();
         rs.insert(A, B);
      }
      auto [S, T] = q[I];
      auto it = rs.get(S);
      bool ans = false;
      if(it == rs.end()) {
         if(S >= T) ans = true;
      } else {
         auto [l, r] = *it;
         if(r >= T) ans = true;
      }
      ansV[I] = ans;
   }
   for(auto ans : ansV) cout << (ans ? "Yes" : "No") << '\n';
   return 0;
}