#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "test/template.hpp"
#include "src/string/SuffixArray.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = size(S);
   auto [sa, lcp] = SA(S);
   for(int i = 0; i < N; i++) cout << sa[i] << " \n"[i + 1 == N];
}
