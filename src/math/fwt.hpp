template<typename T> void fwt(vector<T>& f) {
   int n = f.size();
   for(int i = 1; i < n; i <<= 1) {
      for(int j = 0; j < n; j++) {
         if((j & i) == 0) {
            T x = f[j], y = f[j | i];
            f[j] = x + y, f[j | i] = x - y;
         }
      }
   }
}