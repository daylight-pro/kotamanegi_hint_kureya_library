// mが互いに素になるように前処理
// lcm(m) % MODを返す
// crtの解がなければ-1を返す
ll pre_garner(vector<ll>& b, vector<ll>& m, ll MOD) {
   ll res = 1;
   for(int i = 0; i < (int)b.size(); i++) {
      for(int j = 0; j < i; j++) {
         ll g = gcd(m[i], m[j]);
         if((b[i] - b[j]) % g != 0) return -1;
         m[i] /= g;
         m[j] /= g;
         ll gi = gcd(m[i], g);
         ll gj = g / gi;
         do {
            g = gcd(gi, gj);
            gi *= g;
            gj /= g;
         } while(g != 1);
         m[i] *= gi;
         m[j] *= gj;
         b[i] %= m[i];
         b[j] %= m[j];
      }
   }
   for(int i = 0; i < size(b); i++) (res *= m[i]) %= MOD;
   return res;
}

// m が互いに素であることが保証されている場合
// b[i] = x (mod m[i]) となる最小の x \le 0 を求める
ll garner(vector<ll> b, vector<ll> m, ll MOD) {
   m.push_back(MOD);
   vector<ll> coeffs(size(m), 1);
   vector<ll> constants(size(m), 0);
   for(int k = 0; k < size(b); k++) {
      ll t = ((b[k] - constants[k]) * modinv(coeffs[k], m[k])) % m[k];
      if(t < 0) t += m[k];
      for(int i = k + 1; i < size(m); i++) {
         (constants[i] += t * coeffs[i]) %= m[i];
         (coeffs[i] *= m[k]) %= m[i];
      }
   }
   return constants.back();
}