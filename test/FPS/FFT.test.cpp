#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "test/template.hpp"
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   ll N, M;
   cin >> N >> M;
   vector<mm> A(N), B(M);
   for(mm& a : A) cin >> a.x;
   for(mm& b : B) cin >> b.x;

   auto C = conv(move(A), move(B));
   for(int i = 0; i < size(C); i++) cout << C[i].x << " \n"[i + 1 == size(C)];
}
