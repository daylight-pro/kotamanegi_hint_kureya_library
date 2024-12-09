#define PROBLEM "https://yukicoder.me/problems/no/1013"

#include "test/template.hpp"
#include "src/algorithm/doubling_monoid.hpp"

ll op(ll a, ll b) { return a + b; };
ll e() { return 0LL; };

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, K;
   cin >> N >> K;
   vector<int> P(N);
   rep(i, 0, N) cin >> P[i];

   vector<ll> data(N);

   rep(i, 0, N) {
      P[i] += i;
      if(P[i] >= N) {
         P[i] -= N;
         data[i]++;
      }
   }

   Doubling<64, ll, op, e> doubling(P, data);

   rep(i, 0, N) {
      auto [pos, cnt] = doubling.jump(i, K);
      cout << pos + 1 + cnt * N << '\n';
   }
   return 0;
}
