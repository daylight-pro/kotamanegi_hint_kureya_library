#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "test/template.hpp"
#include "src/math/modinv.hpp"
#include "src/math/modpow.hpp"
#include "src/math/primality.hpp"
#include "src/math/rho.hpp"

int main() {
   int Q;
   cin >> Q;
   while(Q--) {
      ll N;
      cin >> N;
      auto mp = factorize(N);
      vector<ll> ans;
      for(auto [k, v] : mp) {
         while(v--) ans.push_back(k);
      }
      cout << size(ans);
      for(auto x : ans) cout << " " << x;
      cout << "\n";
   }
}