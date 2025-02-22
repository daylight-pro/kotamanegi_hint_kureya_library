#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

/*
夏合宿 Day1 A
https://www.acmicpc.net/source/87508962

#include "test/template.hpp"
#include "src/algorithm/rollback_mo.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<int> A(N);
   for(auto& a : A) cin >> a;
   vector<int> inv(N, -1);
   map<int, int> mp1;
   for(int e : A) mp1[e]++;
   {
      int id = 0;
      for(auto [x, y] : mp1) {
         inv[id] = x;
         mp1[x] = id++;
      }
      for(int i = 0; i < N; i++) { A[i] = mp1[A[i]]; }
   }

   int top = -1;
   int count = 0;
   int ptop = -1;
   int pcount = 0;
   vector<int> cnt(N);
   Mo_rollback mo(N, Q);
   vector<ll> ans(Q);
   queue<int> history;
   auto add_left = [&](int idx) {
      cnt[A[idx]]++;
      history.push(A[idx]);
      if(cnt[A[idx]] > count || (cnt[A[idx]] == count && A[idx] > top)) {
         top = A[idx];
         count = cnt[A[idx]];
      }
   };
   auto add_right = [&](int idx) {
      cnt[A[idx]]++;
      history.push(A[idx]);
      if(cnt[A[idx]] > count) {
         top = A[idx];
         count = cnt[A[idx]];
      } else if(cnt[A[idx]] == count && A[idx] > top) top = A[idx];
   };
   auto rem = [&](int idx) { ans[idx] = top; };
   auto reset = [&]() {
      top = -1;
      count = 0;
      fill(all(cnt), 0);
      while(!history.empty()) history.pop();
   };
   auto snapshot = [&]() {
      ptop = top;
      pcount = count;
      while(!history.empty()) history.pop();
   };
   auto rollback = [&]() {
      top = ptop;
      count = pcount;
      while(!history.empty()) {
         cnt[history.front()]--;
         history.pop();
      }
   };
   for(int i = 0; i < Q; i++) {
      int l, r;
      cin >> l >> r;
      l--;
      mo.insert(l, r);
   }
   mo.run(add_left, add_right, rem, reset, snapshot, rollback);
   for(auto& a : ans) cout << inv[a] << '\n';
   return 0;
}
*/

#include "test/template.hpp"
#include "src/algorithm/rollback_mo.hpp"
int main() {
   cin.tie(0)->sync_with_stdio(0);
   puts("Hello World");
   return 0;
}