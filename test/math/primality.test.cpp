#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "test/template.hpp"
#include "src/math/modinv.hpp"
#include "src/math/modpow.hpp"
#include "src/math/primality.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int Q;
   cin >> Q;
   while(Q--) {
      ll N;
      cin >> N;
      if(is_prime(N)) {
         cout << "Yes" << endl;
      } else {
         cout << "No" << endl;
      }
   }
   return 0;
}