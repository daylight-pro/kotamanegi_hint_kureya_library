ll modinv(ll a, ll MOD) {
   ll b = MOD, u = 1, v = 0;
   while(b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
   }
   u %= MOD;
   if(u < 0) u += MOD;
   return u;
}