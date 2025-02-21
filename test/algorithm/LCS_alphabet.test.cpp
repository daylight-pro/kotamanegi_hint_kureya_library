// https://www.acmicpc.net/problem/18440 AC確認済み

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define all(a) begin(a), end(a)
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }

vector<uint64_t> _lcs(const string &s, const string &t) {
   int n = s.size();
   int w = (n + 63) >> 6;
   vector<vector<uint64_t>> m(26, vector<uint64_t>(w));
   for (int i = 0; i < n; ++i) {
      m[s[i] - 'A'][i >> 6] |= 1ULL << (i & 63);
   }
   vector<uint64_t> b(w);
   for (auto &c : t) {
      const auto &mc = m[c - 'A'];
      for (int i = 0, borrow = 0; i < w; ++i) {
         uint64_t x = mc[i] & ~b[i];
         int nx = b[i] < x || (b[i] == x && borrow);
         b[i] = (b[i] - x - borrow) & (mc[i] | b[i]);
         borrow = nx;
      }
   }
   return b;
}

void lcs(string s, string t, string &result) {
   if (s.size() <= 1 || t.size() <= 1) {
      for (auto &i : s) {
         for (auto &j : t) {
            if (i == j) {
               result += i;
               return;
            }
         }
      }
      return;
   }
   int n = s.size();
   int l1 = t.size() / 2;
   int l2 = (int)t.size() - l1;
   auto lef = _lcs(s, t.substr(0, l1));
   reverse(s.begin(), s.end());
   reverse(t.begin(), t.end());
   auto rig = _lcs(s, t.substr(0, l2));
   reverse(s.begin(), s.end());
   reverse(t.begin(), t.end());
   int lc = 0, rc = 0;
   for (auto &i : rig) {
      rc += __builtin_popcountll(i);
   }
   int max_val = lc + rc;
   int max_idx = 0;
   for (int i = 0; i < n; ++i) {
      lc += (lef[i >> 6] >> (i & 63)) & 1;
      rc -= (rig[(n - i - 1) >> 6] >> ((n - i - 1) & 63)) & 1;
      if (max_val < lc + rc) {
         max_val = lc + rc;
         max_idx = i + 1;
      }
   }
   if (max_val == 0) {
      return;
   }
   lcs(s.substr(0, max_idx), t.substr(0, l1), result);
   lcs(s.substr(max_idx), t.substr(l1), result);
}

int main() {
   cin.tie(0);       
   ios::sync_with_stdio(false);
   string s, t;
   cin >> s >> t;
   string ans;
   lcs(s, t, ans);
   cout << ans.size() << endl;
   cout << ans << endl;
   return 0;
}
*/

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/algorithm/LCS_alphabet.hpp"

int main() { puts("Hello World"); }