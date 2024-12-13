// \sqrt(n)の素因数分解 a01341
map<ll, int> prime_factor(ll n) {
   map<ll, int> ret;
   for(ll i = 2; i * i <= n; i++) {
      while(n % i == 0) {
         ret[i]++;
         n /= i;
      }
   }
   if(n != 1) ret[n] = 1;
   return ret;
}

// 線形篩 1f4de3
vector<int> preprocess(int n) {
   n++;
   vector<int> res(n);
   std::iota(res.begin(), res.end(), 0);
   for(int i = 2; i * i < n; ++i) {
      if(res[i] < i) continue;
      for(int j = i * i; j < n; j += i)
         if(res[j] == j) res[j] = i;
   }
   return res;
}

map<int, int> prime_factor(int n, const vector<int>& lp) {
   map<int, int> ret;
   while(n > 1) {
      ret[lp[n]]++;
      n /= lp[n];
   }
   return ret;
}