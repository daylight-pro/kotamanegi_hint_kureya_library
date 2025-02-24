ll modpow(ll a, ll n, ll MOD) {
   using T = __int128_t;
   // using T = ll;
   T res = 1;
   T mul = a;
   mul %= MOD;
   if(n < 0) {
      n = -n;
      mul = modinv(mul, MOD);
   }
   while(n > 0) {
      if(n & 1) res = (res * mul) % MOD;
      mul = (mul * mul) % MOD;
      n >>= 1;
   }
   return ll(res);
}