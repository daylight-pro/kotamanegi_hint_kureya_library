template<typename T, auto op> struct sparse_table {
   vector<vector<T>> st;
   vector<int> lg;

   sparse_table(const vector<T>& v) {
      int b = 0;
      while((1 << b) <= v.size()) b++;
      st.assign(b, vector<T>(1 << b));
      for(int i = 0; i < size(v); i++) { st[0][i] = v[i]; }
      for(int i = 1; i < b; i++) {
         for(int j = 0; j + (1 << i) <= (1 << b); j++) st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
      lg.resize(v.size() + 1);
      for(int i = 2; i < size(lg); i++) lg[i] = lg[i >> 1] + 1;
   }

   inline T prod(int l, int r) {
      int b = lg[r - l];
      return op(st[b][l], st[b][r - (1 << b)]);
   }
};