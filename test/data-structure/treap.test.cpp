#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "test/template.hpp"
#include "src/data-structure/treap.hpp"

const ll mod = 998244353;
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
   friend bool operator==(const mm& a, const mm& b) { return a.x == b.x; }
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

mm op(mm a, mm b) { return a + b; }
mm e() { return 0; }

using F = pair<mm, mm>;
mm mapping(F f, mm x, int sz) { return f.first * x + sz * f.second; }
F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }
F id() { return {1, 0}; }

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<mm> A(N);
   for(auto& x : A) { cin >> x.x; }
   Treap<mm, op, e, F, mapping, composition, id> treap(A);
   while(Q--) {
      int t;
      cin >> t;
      if(t == 0) {
         int i, x;
         cin >> i >> x;
         treap.insert(i, x);
      } else if(t == 1) {
         int i;
         cin >> i;
         treap.erase(i);
      } else if(t == 2) {
         int l, r;
         cin >> l >> r;
         treap.reverse(l, r);
      } else if(t == 3) {
         int l, r;
         cin >> l >> r;
         mm b, c;
         cin >> b.x >> c.x;
         treap.apply(l, r, {b, c});
      } else if(t == 4) {
         int l, r;
         cin >> l >> r;
         cout << treap.prod(l, r).x << '\n';
      }
   }
   return 0;
}
