#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "test/template.hpp"
#include "src/string/sa_is.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = size(S);
   vector<int> str(N);
   for(int i = 0; i < N; i++) str[i] = S[i];
   auto sa = sa_is(str, 255);
   for(int i = 0; i < N; i++) cout << sa[i] << " \n"[i + 1 == N];
   return 0;
}