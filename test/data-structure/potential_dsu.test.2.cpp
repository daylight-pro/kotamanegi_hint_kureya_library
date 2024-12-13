#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207"

#include "test/template.hpp"
#include "src/data-structure/potential_dsu.hpp"

struct Abel {
   using T = int;
   static T e() { return 0; }
   static T op(T a, T b) { return a + b; }
   static T inv(T a) { return -a; }
};

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   while(cin >> N) {
      if(N == 0) break;
      potential_dsu<Abel> dsu(2 * N);
      map<string, int> id;
      int idx = 0;
      bool flag = true;
      while(N--) {
         string _, s1, s2, diff;
         cin >> _ >> s1 >> _ >> diff >> s2;
         int d = stoi(diff.substr(3, diff.size() - 3));
         if(!id.count(s1)) id[s1] = idx++;
         if(!id.count(s2)) id[s2] = idx++;
         if(dsu.same(id[s1], id[s2])) {
            if(dsu.diff(id[s1], id[s2]) != d) flag = false;
         } else {
            dsu.merge(id[s1], id[s2], d);
         }
      }
      if(flag) {
         cout << "Yes" << "\n";
      } else {
         cout << "No" << "\n";
      }
   }
   return 0;
}