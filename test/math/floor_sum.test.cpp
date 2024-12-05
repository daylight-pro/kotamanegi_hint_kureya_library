#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "test/template.hpp"
#include "src/math/floor_sum.hpp"

int main() {
   int T;
   cin >> T;
   while(T--) {
      ll N, M, A, B;
      cin >> N >> M >> A >> B;
      cout << floor_sum(N, M, A, B) << '\n';
   }
}
