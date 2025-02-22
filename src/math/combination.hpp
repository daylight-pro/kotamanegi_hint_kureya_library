struct Combination {
   ll C_MOD;
   vector<ll> fac, finv, inv;
   Combination(ll n, ll mod) : C_MOD(mod) {
      n = max(n, 2LL);
      fac.resize(n, 0);
      finv.resize(n, 0);
      inv.resize(n, 0);
      fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
      for(int i = 2; i < n; i++) {
         fac[i] = fac[i - 1] * i % mod;
         inv[i] = mod - inv[mod % i] * (mod / i) % mod;
         finv[i] = finv[i - 1] * inv[i] % mod;
      }
   }
   ll com(ll n, ll k) {
      if(n < k || n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % C_MOD) % C_MOD;
   }
};