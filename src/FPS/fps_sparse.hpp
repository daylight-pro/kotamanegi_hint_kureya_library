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

vector<mm> fps_exp_sparse(vector<mm>& f) {
   if ((int)f.size() == 0) return {mm(1)};
   // assert(f[0].x == 0);
   int N = f.size();
   vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i ++) if (f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);
   vector<mm> F(N);
   F[0] = 1;
   for(int n = 1; n < N; n ++) {
      mm rhs = 0;
      for (auto&& [k, fk]: dat) {
         if (k > n - 1) break;
         rhs += fk * F[n - 1 - k];
      }
      F[n] = rhs * mm(n).inv();
   }
   return F;
}