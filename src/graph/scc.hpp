// base: 1e9c3f
struct scc_graph {
   public:
   explicit scc_graph(int _n = 0) : n(_n), G(_n), rG(_n), comp(_n, -1), visited(_n, 0) {}

   void add_edge(int from, int to) {
      // assert(0 <= from && from < n);
      // assert(0 <= to && to < n);
      G[from].push_back(to);
      rG[to].push_back(from);
   }

   vector<vector<int>> scc() {
      fill(all(visited), 0);
      fill(all(comp), -1);
      order.clear();
      rep(i, 0, n) if(!visited[i]) dfs(i);
      comp_size = 0;
      for(int i = sz(order) - 1; i >= 0; i--) {
         if(comp[order[i]] < 0) rdfs(order[i], comp_size++);
      }
      vector<vector<int>> v(comp_size);
      rep(i, 0, n) v[comp[i]].push_back(i);
      return v;
   }

   vector<int> get_comp() { return comp; }  // bdafc0

   vector<vector<int>> dag() {
      vector<vector<int>> res(comp_size);
      rep(i, 0, n) for(auto j : G[i]) {
         if(comp[i] != comp[j]) res[comp[i]].push_back(comp[j]);
      }
      rep(i, 0, comp_size) {
         sort(all(res[i]));
         res[i].erase(unique(all(res[i])), res[i].end());
      }
      return res;
   }  // da3a19

   private:
   vector<vector<int>> G, rG;
   vector<int> order, comp;
   vector<bool> visited;
   int n, comp_size;

   void dfs(int v) {
      visited[v] = true;
      for(auto to : G[v])
         if(!visited[to]) dfs(to);
      order.push_back(v);
   }

   void rdfs(int v, int k) {
      comp[v] = k;
      for(auto to : rG[v]) {
         if(comp[to] < 0) rdfs(to, k);
      }
   }
};