#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2863"

#include "test/template.hpp"
#include "src/string/trie.hpp"
#include "src/string/aho_corasick.hpp"

const ll mod = 1000000007;
struct mm {
   ll x;
   mm(ll x_ = 0) : x(x_ % mod) {
      if(x < 0) x += mod;
   }
   friend mm operator+(mm a, mm b) { return a.x + b.x; }
   friend mm operator-(mm a, mm b) { return a.x - b.x; }
   friend mm operator*(mm a, mm b) { return a.x * b.x; }
   friend mm operator/(mm a, mm b) { return a * b.inv(); }
   // 4 行コピペ  Alt + Shift + クリックで複数カーソル
   friend mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }
   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x; }
   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }
   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }
   mm inv() const { return pow(mod - 2); }
   mm pow(ll b) const {
      mm a = *this, c = 1;
      while(b) {
         if(b & 1) c *= a;
         a *= a;
         b >>= 1;
      }
      return c;
   }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   AhoCorasick<26, 'a'> aho;
   vector<int> len(N);
   rep(i, 0, N) {
      string s;
      cin >> s;
      aho.add(s);
      len[i] = size(s);
   }
   aho.build();
   string T;
   cin >> T;
   int now = 0;
   int n = size(T);
   vector<mm> dp(n + 1);
   dp[0] = 1;
   rep(i, 0, n) {
      auto [res, nxt] = aho.move(T[i], now);
      auto match = aho.match(T[i], now);
      now = nxt;
      for(auto v : match) { dp[i + 1] += dp[i + 1 - len[v]]; }
   }
   cout << dp[n].x << '\n';
   return 0;
}
