template<int L, class T, auto op, auto e> struct Doubling {
   private:
   vector<vector<int>> V;
   vector<vector<T>> data;

   public:
   Doubling(const vector<int>& to, const vector<S>& v) {
      int N = size(to);
      rep(0, i, N) {
         V[0][i] = to[i];
         data[0][i] = v[i];
      }

      rep(0, i, L - 1) {
         rep(0, j, N) {
            if(V[i][j] != -1) {
               V[i + 1][j] = V[i][V[i][j]];
               data[i + 1][j] = op(data[i][j], data[i][V[i][j]]);
            } else {
               V[i + 1][j] = V[i][j];
               data[i + 1][j] = data[i][j];
            }
         }
      }
   }

   pair<int, T> jump(int from, ll k) {
      T res = e();
      for(int cnt = 0; k > 0; k >>= 1, ++cnt) {
         if((k & 1) && from != -1) {
            res = op(res, data[cnt][from]);
            from = V[cnt][from];
         }
      }
      return {from, res};
   }
};