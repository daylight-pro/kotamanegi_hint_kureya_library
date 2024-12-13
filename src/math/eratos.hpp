void eratos(int n, vector<bool>& isprime) {
   isprime = vector<bool>(n + 1, true);
   isprime[0] = false;
   isprime[1] = false;
   int last = ((int)sqrt(n)) + 1;
   for(int i = 2; i < last; i++) {
      if(isprime[i]) {
         int j = i + i;
         while(j <= n) {
            isprime[j] = false;
            j += i;
         }
      }
   }
}