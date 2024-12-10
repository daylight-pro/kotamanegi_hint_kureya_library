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
   for(int i = 0; i < N; i++) cin >> P[i];

   vector<ll> data(N);

   for(int i = 0; i < N; i++) {
      P[i] += i;
      if(P[i] >= N) {
         P[i] -= N;
         data[i]++;
      }
   }

   Doubling<64, ll, op, e> doubling(P, data);

   for(int i = 0; i < N; i++) {
      auto [pos, cnt] = doubling.jump(i, K);
      cout << pos + 1 + cnt * N << '\n';
   }
   return 0;
}
