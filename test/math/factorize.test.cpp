#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"
#include "test/template.hpp"
#include "src/math/factorize.hpp"

int main() {
   int N;
   cin >> N;
   cout << N << ":";
   for(auto [k, v] : prime_factor(N)) {
      while(v--) { cout << " " << k; }
   }
   cout << endl;
   return 0;
}