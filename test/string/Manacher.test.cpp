#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "test/template.hpp"
#include "src/string/Manacher.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = size(S);
   string T(N * 2 + 1, '$');
   for(int i = 0; i < N; i++) T[i * 2 + 1] = S[i];
   auto r = manacher(T);
   for(int i = 1; i < N * 2; i++) {
      if(i & 1) cout << r[i] - 1 << " \n"[i + 1 == N * 2];
      else cout << r[i] - 1 << ' ';
   }
}
