template<class K, class M> struct range_tree {
   using S = typename M::S;
   using D = typename M::D;

   private:
   vector<pair<K, K>> ps;
   vector<K> xs;
   vector<vector<K>> ys;
   vector<D> ds;
   int n;
   int id(K x) const { return lower_bound(all(xs), x) - xs.begin(); }

   int id(int k, K y) const { return lower_bound(all(ys[k]), y) - ys[k].begin(); }

   public:
   void add(K x, K y) { ps.emplace_back(x, y); }
   void build() {
      sort(ps.begin(), ps.end());
      ps.erase(unique(all(ps)), ps.end());
      n = size(ps);
      xs.reserve(n);
      for(auto& [x, _] : ps) xs.push_back(x);
      ys.resize(2 * n);
      ds.resize(2 * n, M::init(0));
      for(int i = 0; i < n; i++) {
         ys[i + n] = {ps[i].second};
         ds[i + n] = M::init(1);
      }
      for(int i = n - 1; i > 0; i--) {
         ys[i].resize(size(ys[i << 1]) + size(ys[(i << 1) | 1]));
         merge(all(ys[i << 1]), all(ys[(i << 1) | 1]), ys[i].begin());
         ys[i].erase(unique(all(ys[i])), ys[i].end());
         ds[i] = M::init(size(ys[i]));
      }
   }

   void apply(K x, K y, S a) {
      int k = lower_bound(all(ps), make_pair(x, y)) - ps.begin() + n;
      while(k > 0) {
         M::apply(ds[k], id(k, y), a);
         k >>= 1;
      }
   }

   S prod(K x1, K y1, K x2, K y2) {
      int a = id(x1), b = id(x2);
      a += n;
      b += n;
      S l = M::e(), r = M::e();
      while(a < b) {
         if(a & 1) {
            l = M::op(l, M::prod(ds[a], id(a, y1), id(a, y2)));
            ++a;
         }
         if(b & 1) {
            --b;
            r = M::op(M::prod(ds[b], id(b, y1), id(b, y2)), r);
         }
         a >>= 1;
         b >>= 1;
      }
      return M::op(l, r);
   }
};

/* 使い方
range_tree<K, S, D, op, e, init, inner_apply, prod> rt;
K: 座標の型
S: データ(モノイド)の型
D: ノードに持たせるデータ構造の型
S op(S x, S y): S の二項演算
S e(): S の単位元
D init(int n): Dを長さnで初期化する関数
void inner_apply(D& d, int k, const S& v): D のk番目に v を適用する関数
S prod(D& d, int l, int r): D の[l, r) に対するクエリを行う関数


rt.add(x, y): 座標 (x, y) を追加
rt.build(): クエリを受け付ける準備をする
rt.apply(x, y, a): 座標 (x, y) に a を適用
rt.prod(x1, y1, x2, y2): 座標 x \in [x1, x2), y \in [y1, y2) の領域にクエリを行う
*/