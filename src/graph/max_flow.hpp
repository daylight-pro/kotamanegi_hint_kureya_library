// base: 89e8d1
template<class Cap> struct mf_graph {
   public:
   mf_graph() : _n(0) {}
   mf_graph(int n) : _n(n), g(n) {}

   int add_edge(int from, int to, Cap cap) {
      // assert(0 <= from && from < _n);
      // assert(0 <= to && to < _n);
      // assert(0 <= cap);
      int m = sz(pos);
      pos.push_back({from, sz(g[from])});
      int from_id = sz(g[from]);
      int to_id = sz(g[to]);
      if(from == to) to_id++;
      g[from].push_back(_edge{to, to_id, cap});
      g[to].push_back(_edge{from, from_id, 0});
      return m;
   }

   Cap flow(int s, int t, Cap flow_limit = numeric_limits<Cap>::max()) {
      // assert(0 <= s && s < _n);
      // assert(0 <= t && t < _n);
      // assert(s != t);

      vector<int> level(_n), iter(_n);
      queue<int> que;
      auto bfs = [&]() {
         fill(all(level), -1);
         level[s] = 0;
         while(!que.empty()) que.pop();
         que.push(s);
         while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(auto e : g[v]) {
               if(e.cap == 0 || level[e.to] >= 0) continue;
               level[e.to] = level[v] + 1;
               if(e.to == t) return;
               que.push(e.to);
            }
         }
      };
      auto dfs = [&](auto self, int v, Cap up) {
         if(v == s) return up;
         Cap res = 0;
         int level_v = level[v];
         for(int& i = iter[v]; i < sz(g[v]); i++) {
            _edge& e = g[v][i];
            if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
            Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
            if(d <= 0) continue;
            g[v][i].cap += d;
            g[e.to][e.rev].cap -= d;
            res += d;
            if(res == up) break;
         }
         return res;
      };

      Cap flow = 0;
      while(flow < flow_limit) {
         bfs();
         if(level[t] == -1) break;
         fill(all(iter), 0);
         while(flow < flow_limit) {
            Cap f = dfs(dfs, t, flow_limit - flow);
            if(!f) break;
            flow += f;
         }
      }
      return flow;
   }

   vector<bool> min_cut(int s) {
      vector<bool> visited(_n);
      queue<int> que;
      que.push(s);
      visited[s] = true;
      while(!que.empty()) {
         int v = que.front();
         que.pop();
         for(auto e : g[v]) {
            if(e.cap && !visited[e.to]) {
               visited[e.to] = true;
               que.push(e.to);
            }
         }
      }
      return visited;
   }  // 8735cf

   struct edge {
      int from, to;
      Cap cap, flow;
   };  // 9fe107

   edge get_edge(int i) {
      int m = sz(pos);
      // assert(0 <= i && i < m);
      auto _e = g[pos[i].first][pos[i].second];
      auto _re = g[_e.to][_e.rev];
      return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
   }  // 8cbb00

   vector<edge> edges() {
      int m = sz(pos);
      vector<edge> result;
      rep(i, 0, m) result.push_back(get_edge(i));
      return result;
   }  // fa2b7d

   void change_edge(int i, Cap new_cap, Cap new_flow) {
      int m = int(pos.size());
      // assert(0 <= i && i < m);
      // assert(0 <= new_flow && new_flow <= new_cap);
      auto& _e = g[pos[i].first][pos[i].second];
      auto& _re = g[_e.to][_e.rev];
      _e.cap = new_cap - new_flow;
      _re.cap = new_flow;
   }  // 025616

   private:
   int _n;
   struct _edge {
      int to, rev;
      Cap cap;
   };
   vector<pair<int, int>> pos;
   vector<vector<_edge>> g;
};