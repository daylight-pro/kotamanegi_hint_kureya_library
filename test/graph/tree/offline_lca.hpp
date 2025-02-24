vector<int> offline_lca(const vector<vector<int>>& g, const vector<pair<int, int>>& qs, int root = 0) {
   int N = size(g);
   int Q = size(qs);
   dsu d(N);
   vector<int> mark(N), ptr(N), ans(Q, -1);
   stack<int> st;
   st.push(root);
   for(auto& [l, r] : qs) {
      mark[l]++;
      mark[r]++;
   }

   vector<vector<pair<int, int>>> q(N);
   for(int i = 0; i < N; i++) {
      q[i].reserve(mark[i]);
      mark[i] = -1;
      ptr[i] = size(g[i]);
   }
   for(int i = 0; i < Q; i++) {
      q[qs[i].first].emplace_back(qs[i].second, i);
      q[qs[i].second].emplace_back(qs[i].first, i);
   }
   auto run = [&](int u) -> bool {
      while(ptr[u]) {
         int v = g[u][--ptr[u]];
         if(mark[v] == -1) {
            st.push(v);
            return true;
         }
      }
      return false;
   };

   while(!st.empty()) {
      int u = st.top();
      if(mark[u] == -1) mark[u] = u;
      else {
         d.merge(u, g[u][ptr[u]]);
         mark[d.leader(u)] = u;
      }
      if(!run(u)) {
         for(auto& [v, i] : q[u]) {
            if(~mark[v] && ans[i] == -1) { ans[i] = mark[d.leader(v)]; }
         }
         st.pop();
      }
   }
   return ans;
};