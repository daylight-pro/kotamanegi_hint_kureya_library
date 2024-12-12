// base: d569f4
struct dsu {
   private:
   int _n;
   vector<int> p;

   public:
   dsu() : _n(0) {}
   explicit dsu(int n) : _n(n), p(n, -1) {}

   int merge(int a, int b) {
      // assert(0 <= a && a < _n);
      // assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if(x == y) return x;
      if(-p[x] < -p[y]) swap(x, y);
      p[x] += p[y];
      p[y] = x;
      return x;
   }

   bool same(int a, int b) {
      // assert(0 <= a && a < _n);
      // assert(0 <= b && b < _n);
      return leader(a) == leader(b);
   }

   int leader(int a) {
      // assert(0 <= a && a < _n);
      if(p[a] < 0) return a;
      int x = a;
      while(p[x] >= 0) x = p[x];
      while(p[a] >= 0) {
         int t = p[a];
         p[a] = x;
         a = t;
      }
      return x;
   }

   int size(int a) {
      // assert(0 <= a && a < _n);
      return -p[leader(a)];
   }  // 818fe7

   vector<vector<int>> groups() {
      vector<int> leader_buf(_n), group_size(_n);
      for(int i = 0; i < _n; i++) {
         leader_buf[i] = leader(i);
         group_size[leader_buf[i]]++;
      }
      vector<vector<int>> result(_n);
      for(int i = 0; i < _n; i++) result[i].reserve(group_size[i]);
      for(int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);
      result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }),
                   result.end());
      return result;
   }  // bf3a1e
};