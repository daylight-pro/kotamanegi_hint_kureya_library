#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "test/template.hpp"
#include "src/data-structure/dsu.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   dsu d(10);
   d.merge(3, 5);
   d.merge(5, 7);
   d.merge(2, 3);
   d.merge(8, 9);
   d.merge(0, 1);
   d.merge(2, 7);
   assert(d.size(7) == 4);
   assert(size(d.groups()) == 5);
   set<set<int>> s;
   s.insert({0, 1});
   s.insert({2, 3, 5, 7});
   s.insert({4});
   s.insert({6});
   s.insert({8, 9});
   for(auto i : d.groups()) {
      set<int> t(all(i));
      assert(s.count(t));
   }
   cout << "Hello World" << endl;
   return 0;
}