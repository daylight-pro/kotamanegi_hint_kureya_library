template<int L> struct Doubling {
   private:
   vector<vector<int>> V;

   public:
   Doubling(const vector<int>& v) {
      int N = size(v);
      V = vector<vector<int>>(L, vector<int>(N));
      rep(i, 0, N) V[0][i] = v[i];
      rep(i, 0, L - 1) rep(j, 0, N) {
         if(V[i][j] != -1) V[i + 1][j] = V[i][V[i][j]];
      }
   }

   int jump(int from, ll k) {
      for(int cnt = 0; k > 0; k >>= 1, ++cnt) {
         if((k & 1) && from != -1) from = V[cnt][from];
      }
      return from;
   }
};
