vector<int> topological_sort(vector<vector<int>>& g) {
   int n = g.size();
   vector<int> indeg(n);
   for(int i = 0; i < n; i++)
      for(int j : g[i]) indeg[j]++;
   vector<int> res;
   queue<int> q;
   for(int i = 0; i < n; i++)
      if(indeg[i] == 0) q.push(i);
   while(!q.empty()) {
      auto v = q.front();
      q.pop();
      res.push_back(v);
      for(auto u : g[v]) {
         indeg[u]--;
         if(indeg[u] == 0) q.push(u);
      }
   }
   return res;
}