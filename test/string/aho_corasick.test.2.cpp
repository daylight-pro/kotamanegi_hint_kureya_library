#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "test/template.hpp"
#include "src/string/trie.hpp"
#include "src/string/aho_corasick.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   int M;
   cin >> M;
   AhoCorasick<26, 'A'> aho;
   for(int i = 0; i < M; i++) {
      string s;
      cin >> s;
      aho.add(s);
   }
   aho.build();
   auto result = aho.match(S);
   ll ans = 0;
   for(auto& [id, cnt] : result) { ans += cnt; }
   cout << ans << endl;
   return 0;
}
