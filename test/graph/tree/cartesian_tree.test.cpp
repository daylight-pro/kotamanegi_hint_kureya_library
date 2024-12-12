#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "test/template.hpp"
#include "src/graph/tree/cartesian_tree.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N;
   cin >> N;
   vector<int> A(N);
   for(auto&& a : A) cin >> a;
   cartesian_tree<int> ct(A);
   for(int i = 0; i < N; i++) {
      if(ct.par[i] != -1) cout << ct.par[i];
      else cout << i;
      cout << " \n"[i == N - 1];
   }
   for(int i = 0; i < N; i++) {
      assert(ct.par[i] != -1 || ct.root == i);
      if(ct.left[i] != -1) assert(ct.left[i] < i && A[ct.left[i]] > A[i] && ct.par[ct.left[i]] == i);
      if(ct.right[i] != -1) assert(ct.right[i] > i && A[ct.right[i]] > A[i] && ct.par[ct.right[i]] == i);
   }
   return 0;
}
