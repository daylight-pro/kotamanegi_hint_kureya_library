class HLDcomposition {
   private:
   int V;
   vector<vector<int>> G;
   vector<int> stsize, parent, pathtop, in, out;
   int root;
   void build_stsize(int u, int p) {
      stsize[u] = 1, parent[u] = p;
      for(auto&& v : G[u]) {
         if(v == p) {
            if(v == G[u].back()) break;
            else swap(v, G[u].back());
         }
         build_stsize(v, u);
         stsize[u] += stsize[v];
         if(stsize[v] > stsize[G[u][0]]) swap(v, G[u][0]);
      }
   }

   void build_path(int u, int p, int& tm) {
      in[u] = tm++;
      for(auto v : G[u]) {
         if(v == p) continue;
         pathtop[v] = (v == G[u][0] ? pathtop[u] : v);
         build_path(v, u, tm);
      }
      out[u] = tm;
   }

   public:
   void add_edge(int u, int v) {
      G[u].push_back(v);
      G[v].push_back(u);
   }

   void build(int _root = 0) {
      root = _root;
      int tm = 0;
      build_stsize(root, -1);
      pathtop[root] = root;
      build_path(root, -1, tm);
   }

   inline int index(int a) { return in[a]; }

   int lca(int a, int b) {
      int pa = pathtop[a], pb = pathtop[b];
      while(pa != pb) {
         if(in[pa] > in[pb]) {
            a = parent[pa], pa = pathtop[a];
         } else {
            b = parent[pb], pb = pathtop[b];
         }
      }
      if(in[a] > in[b]) swap(a, b);
      return a;
   }

   pair<int, int> subtree_query(int a) { return {in[a], out[a]}; }

   vector<tuple<int, int, bool>> path_query(int from, int to) {
      int pf = pathtop[from], pt = pathtop[to];
      using T = tuple<int, int, bool>;
      deque<T> front, back;
      while(pf != pt) {
         if(in[pf] > in[pt]) {
            front.push_back({in[pf], in[from] + 1, true});
            from = parent[pf], pf = pathtop[from];
         } else {
            back.push_front({in[pt], in[to] + 1, false});
            to = parent[pt], pt = pathtop[to];
         }
      }
      if(in[from] > in[to]) front.push_back({in[to], in[from] + 1, true});
      else front.push_back({in[from], in[to] + 1, false});
      vector<T> ret;
      while(!front.empty()) {
         ret.push_back(front.front());
         front.pop_front();
      }
      while(!back.empty()) {
         ret.push_back(back.front());
         back.pop_front();
      }
      return ret;
   }

   HLDcomposition(int node_size)
       : V(node_size), G(V), stsize(V, 0), parent(V, -1), pathtop(V, -1), in(V, -1), out(V, -1) {}
};