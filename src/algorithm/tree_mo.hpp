template<class T> struct MoTree_edge {
   int n;
   vector<vector<pair<int, T>>> es;
   vector<int> in;
   vector<pair<int, T>> vals;
   Mo mo;
   MoTree_edge(int _n) : n(_n), es(_n), mo(0, 0) {}

   void add_edge(int u, int v, T w) {
      es[u].emplace_back(v, w);
      es[v].emplace_back(u, w);
   }

   void build(int q) {
      int tnow = 0;
      auto dfs = [&](auto dfs, int v, int f) -> void {
         in[v] = tnow++;
         for(auto [u, w] : es[v]) {
            if(u == f) continue;
            vals.emplace_back(u, w);
            dfs(dfs, u, v);
            vals.emplace_back(u, w);
            tnow++;
         }
      };
      in.resize(n);
      dfs(dfs, 0, -1);
      mo = Mo(2 * n - 2, q);
   }

   void insert(int u, int v) {
      u = in[u];
      v = in[v];
      if(u > v) swap(u, v);
      mo.insert(u, v);
   }

   void run(const auto& add, const auto& del, const auto& rem) {
      vector<bool> contain(n, false);
      auto change = [&](int i) {
         int id = vals[i].first;
         if(contain[id]) {
            del(vals[i].second);
            contain[id] = false;
         } else {
            add(vals[i].second);
            contain[id] = true;
         }
      };
      mo.run(change, change, change, change, rem);
   }
};

template<class T> struct MoTree_vertex {
   int n;
   vector<vector<int>> es;
   vector<T> b;
   vector<int> in, lcas;
   vector<pair<int, T>> vals;
   Mo mo;
   MoTree_vertex(int _n, vector<T> _b) : n(_n), b(_b), mo(0, 0) { es.resize(n); }

   void add_edge(int u, int v) {
      es[u].push_back(v);
      es[v].push_back(u);
   }

   void build(int q) {
      vals.reserve(2 * n - 2);
      lcas.reserve(q);
      int tnow = 0;
      auto dfs = [&](auto dfs, int v, int f) -> void {
         in[v] = tnow++;
         for(auto u : es[v]) {
            if(u == f) continue;
            vals.emplace_back(u, b[u]);
            dfs(dfs, u, v);
            vals.emplace_back(u, b[u]);
            tnow++;
         }
      };
      in.resize(n);
      dfs(dfs, 0, -1);
      mo = Mo(2 * n - 2, q);
   }

   void insert(int u, int v, int lca) {
      u = in[u], v = in[v];
      if(u > v) swap(u, v);
      mo.insert(u, v);
      lcas.push_back(lca);
   }

   void run(const auto& add, const auto& del, const auto& rem) {
      vector<bool> contain(n, false);
      auto change = [&](int i) {
         int id = vals[i].first;
         if(contain[id]) {
            del(vals[i].second);
            contain[id] = false;
         } else {
            add(vals[i].second);
            contain[id] = true;
         }
      };
      auto rem_add_lca = [&](int i) {
         add(b[lcas[i]]);
         rem(i);
         del(b[lcas[i]]);
      };
      mo.run(change, change, change, change, rem_add_lca);
   }
};