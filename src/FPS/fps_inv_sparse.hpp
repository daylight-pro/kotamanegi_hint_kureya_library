vector<mm> fps_inv_sparse(const vector<pair<int, mm>> &dat, int n = -1) {
   // assert(dat[0].first == 0 and dat[0].second.x != 0);
   if(n == -1) n = dat.back().first + 1;
   vector<mm> g(n);
   mm g0 = dat[0].second.inv();
   g[0] = g0;
   for(int i = 1; i < n; i ++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) {
         if(k > i) break;
         rhs -= fk * g[i - k];
      }
      g[i] = rhs * g0;
   }
   return g;
}