#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "test/template.hpp"
#include "src/string/Zalgorithm.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   auto z = Z(S);
   for(int i = 0; i < size(S); i++) cout << z[i] << " \n"[i + 1 == size(S)];
}
