ll modpow(ll a, ll n, ll MOD) {
   ll res = 1;
   a %= MOD;
   if(n < 0) {
      n = -n;
      a = modinv(a, MOD);
   }
   while(n > 0) {
      if(n & 1) res = (res * a) % MOD;
      a = (a * a) % MOD;
      n >>= 1;
   }
   return res;
}