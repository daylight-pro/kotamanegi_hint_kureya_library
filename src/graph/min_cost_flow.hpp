// base: 4df545
template<class Cap, class Cost> struct mcf_graph {
   public:
   mcf_graph() {}
   mcf_graph(int n) : _n(n), g(n) {}

   int add_edge(int from, int to, Cap cap, Cost cost) {
      // assert(0 <= from && from < _n);
      // assert(0 <= to && to < _n);
      int m = sz(pos);
      pos.push_back({from, sz(g[from])});
      int from_id = sz(g[from]);
      int to_id = sz(g[to]);
      if(from == to) to_id++;
      g[from].push_back(_edge{to, to_id, cap, cost});
      g[to].push_back(_edge{from, from_id, 0, -cost});
      return m;
   }

   pair<Cap, Cost> flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max()); }
   pair<Cap, Cost> flow(int s, int t, Cap flow_limit) { return slope(s, t, flow_limit).back(); }
   vector<pair<Cap, Cost>> slope(int s, int t) { return slope(s, t, numeric_limits<Cap>::max()); }
   vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
      // assert(0 <= s && s < _n);
      // assert(0 <= t && t < _n);
      // assert(s != t);
      vector<Cost> dual(_n, 0), dist(_n);
      vector<int> pv(_n), pe(_n);
      vector<bool> vis(_n);
      auto dual_ref = [&]() {
         fill(all(dist), numeric_limits<Cost>::max());
         fill(all(pv), -1);
         fill(all(pe), -1);
         fill(all(vis), false);
         struct Q {
            Cost key;
            int to;
            bool operator<(const Q& r) const { return key > r.key; }
         };
         priority_queue<Q> que;
         dist[s] = 0;
         que.push(Q{0, s});
         while(!que.empty()) {
            int v = que.top().to;
            que.pop();
            if(vis[v]) continue;
            vis[v] = true;
            if(v == t) break;
            rep(i, 0, sz(g[v])) {
               auto e = g[v][i];
               if(vis[e.to] || !e.cap) continue;
               Cost cost = e.cost - dual[e.to] + dual[v];
               if(chmin(dist[e.to], dist[v] + cost)) {
                  pv[e.to] = v;
                  pe[e.to] = i;
                  que.push(Q{dist[e.to], e.to});
               }
            }
         }
         if(!vis[t]) return false;
         rep(v, 0, _n) if(vis[v]) dual[v] -= dist[t] - dist[v];
         return true;
      };
      Cap flow = 0;
      Cap cost = 0, prev_cost_per_flow = -1;
      vector<pair<Cap, Cost>> result;
      result.push_back({flow, cost});
      while(flow < flow_limit) {
         if(!dual_ref()) break;
         Cap c = flow_limit - flow;
         for(int v = t; v != s; v = pv[v]) { c = min(c, g[pv[v]][pe[v]].cap); }
         for(int v = t; v != s; v = pv[v]) {
            auto& e = g[pv[v]][pe[v]];
            e.cap -= c;
            g[v][e.rev].cap += c;
         }
         Cost d = -dual[s];
         flow += c;
         cost += c * d;
         if(prev_cost_per_flow == d) { result.pop_back(); }
         result.push_back({flow, cost});
         prev_cost_per_flow = d;
      }
      return result;
   }

   struct edge {
      int from, to;
      Cap cap, flow;
   };  // 9fe107

   edge get_edge(int i) {
      int m = sz(pos);
      // assert(0 <= i && i < m);
      auto _e = g[pos[i].first][pos[i].second];
      auto _re = g[_e.to][_e.rev];
      return edge({pos[i].first, _e.to, _e.cap + _re.cap, _re.cap});
   }  // d8c44b

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
      Cost cost;
   };

   vector<pair<int, int>> pos;
   vector<vector<_edge>> g;
};