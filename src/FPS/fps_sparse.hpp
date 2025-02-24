using vm = vector<mm>;
vm fps_inv_sparse(vm& f) {
   int n = f.size(); vector<pair<int, mm>> dat;
   for(int i = 0; i < n; i++) if(f[i].x) dat.emplace_back(i, f[i]);
   vm g(n); mm g0 = f[0].inv(); g[0] = g0;
   for(int i = 1; i < n; i++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) { if(k > i) break; rhs -= fk * g[i - k]; }
      g[i] = rhs * g0;
   }
   return g;
}
vm fps_exp_sparse(vm& f) {
   if((int)f.size() == 0) return {mm(1)};
   int N = f.size(); vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i++) if(f[i].x) dat.emplace_back(i - 1, mm(i) * f[i]);
   vm F(N); F[0] = 1;
   for(int n = 1; n < N; n++) {
      mm rhs = 0;
      for(auto&& [k, fk] : dat) { if(k > n - 1) break; rhs += fk * F[n - 1 - k]; }
      F[n] = rhs * mm(n).inv();
   }
   return F;
}
vm fps_log_sparse(vm& f) {
   int N = f.size(); vector<pair<int, mm>> dat;
   for(int i = 1; i < N; i ++) if(f[i].x) dat.emplace_back(i, f[i]);
   vm F(N), g(N - 1);
   for(int n = 0; n < N - 1; n ++) {
      mm rhs = mm(n + 1) * f[n + 1];
      for(auto &&[i, fi] : dat) { if(i > n) break; rhs -= fi * g[n - i]; }
      g[n] = rhs; F[n + 1] = rhs * mm(n + 1).inv();
   }
   return F;
}
vm fps_pow_product(vm& f, vm& g, mm n, mm m) {
   int N = f.size(); using P = pair<int, mm>;
   vector<P> dat_f, dat_g;
   for(int i = 0; i < (int)f.size(); i ++) if(f[i].x) dat_f.emplace_back(i, f[i]);
   for(int i = 0; i < (int)g.size(); i ++) if(g[i].x) dat_g.emplace_back(i, g[i]);
   vm a(N), b(N);
   for (auto&& [i, x]: dat_f) for (auto&& [j, y]: dat_g) {
      if (i + j >= N + 1) continue; 
      mm xy = x * y; if (i + j < N) a[i + j] += xy;
      if (0 < i + j && i + j <= N) b[i + j - 1] -= xy * (n * mm(i) + m * mm(j));
   }
   vector<P> dat_a, dat_b;
   for(int i = 1; i < N; i ++) if(a[i].x) dat_a.emplace_back(i, a[i]);
   for(int i = 0; i < N; i ++) if(b[i].x) dat_b.emplace_back(i, b[i]);
   vm F(N), df(N - 1); F[0] = 1;
   for(int n = 0; n < N - 1; n ++) {
      mm v = 0;
      for(auto&& [i, ai] : dat_a) { if(i > n) break; v += ai * df[n - i]; }
      for(auto&& [i, bi] : dat_b) { if(i > n) break; v += bi * F[n - i]; }
      df[n] = -v; F[n + 1] = df[n] * mm(n + 1).inv();
   }
   return F;
}