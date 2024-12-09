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
   rep(i, 0, M) {
      string s;
      cin >> s;
      aho.add(s);
   }
   aho.build();
   cout << aho.move(S).first << endl;
   return 0;
}
