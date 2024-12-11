template<typename T> struct BinaryIndexedTree2D {
   int H, W;
   vector<vector<T>> bit;

   BinaryIndexedTree2D(int H, int W) : H(H), W(W), bit(H + 3, vector<T>(W + 3, 0)) {}
   void add(int x, int y, T w) {
      if(x < 0 || x >= H || y < 0 || y >= W) return;
      for(int a = (++y, ++x); a <= H; a += a & -a) {
         for(int b = y; b <= W; b += b & -b) { bit[a][b] += w; }
      }
   }

   void imos(int x1, int y1, int x2, int y2, T w) {
      add(x1, y1, w);
      add(x2, y2, w);
      add(x1, y2, -w);
      add(x2, y1, -w);
   }

   T sum(int x, int y) {
      if(x < 0 || x >= H || y < 0 || y >= W) return 0;
      if(x >= H) x = H - 1;
      if(y >= W) y = W - 1;
      T ret = 0;
      for(int a = (++y, ++x); a > 0; a -= a & -a) {
         for(int b = y; b > 0; b -= b & -b) { ret += bit[a][b]; }
      }
      return ret;
   }

   T sum(int x1, int y1, int x2, int y2) {
      return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
   }
};