template<typename T> T lagrange_polynomial(const vector<T>& y, ll t, ll mod = 1000000007) {
   int n = y.size() - 1;
   if(t <= n) return y[t];
   T ret(0);
   Combination comb(n + 1, mod);
   vector<T> dp(n + 1, 1), pd(n + 1, 1);
   for(int i = 0; i < n; i++) dp[i + 1] = dp[i] * (t - i);
   for(int i = n; i > 0; i--) pd[i - 1] = pd[i] * (t - i);
   for(int i = 0; i <= n; i++) {
      T tmp = y[i] * dp[i] * pd[i] * comb.finv[i] * comb.finv[n - i];
      ret -= ((n - i) & 1 ? tmp : T(0) - tmp);
   }
   return ret;
}