#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "test/template.hpp"
#include "src/math/modinv.hpp"
#include "src/math/crt.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   vector<ll> b(N), m(N);
   for(int i = 0; i < N; i++) cin >> b[i] >> m[i];
   bool nonzero = false;
   for(int i = 0; i < N; i++) {
      if(b[i] != 0) {
         nonzero = true;
         break;
      }
   }
   const ll MOD = 1000000007;
   ll lcm = pre_garner(b, m, MOD);

   if(!nonzero) {
      // 最小は0になっちゃうので、次に小さいlcmを返す
      cout << lcm << endl;
   } else if(lcm == -1) {
      cout << -1 << endl;
   } else {
      cout << garner(b, m, MOD) << endl;
   }
   return 0;
}