#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include "test/template.hpp"
#include "src/string/KMP.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S, T;
   cin >> S >> T;
   auto s = T + '$' + S;
   auto kmp = KMP(s);

   for(int i = size(s) - size(S); i < size(s); i++) {
      if(kmp[i] == size(T)) cout << i - size(T) * 2 << '\n';
   }
}
