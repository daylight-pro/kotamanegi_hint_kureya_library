#define PROBLEM "https://yukicoder.me/problems/no/1097"

#include "test/template.hpp"
#include "src/algorithm/doubling_monoid.hpp"

ll op(ll a, ll b) { return a + b; };
ll e() { return 0LL; };

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   vector<int> P(N);
   for(int i = 0; i < N; i++) cin >> P[i];

   vector<ll> data(N);

   for(int i = 0; i < N; i++) {
      P[i] += i;
      data[i] += P[i] / N;
      P[i] %= N;
   }

   Doubling<64, ll, op, e> doubling(P, data);
   int Q;
   cin >> Q;

   while(Q--) {
      ll K;
      cin >> K;
      auto [pos, cnt] = doubling.jump(0, K);
      cout << pos + cnt * N << '\n';
   }
   return 0;
}
