struct Mo {
   int width;
   vector<int> left, right, order;
   Mo(int N, int Q) : order(Q) {
      width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
      iota(all(order), 0);
   }

   void insert(int l, int r) {
      left.emplace_back(l);
      right.emplace_back(r);
   }

   void run(const auto& add_left,
            const auto& add_right,
            const auto& delete_left,
            const auto& delete_right,
            const auto& rem) {
      sort(begin(order), end(order), [&](int a, int b) {
         int ablock = left[a] / width, bblock = left[b] / width;
         if(ablock != bblock) return ablock < bblock;
         return (ablock & 1) ? right[a] > right[b] : right[a] < right[b];
      });
      int nl = 0, nr = 0;
      for(auto idx : order) {
         while(nl > left[idx]) add_left(--nl);
         while(nr < right[idx]) add_right(nr++);
         while(nl < left[idx]) delete_left(nl++);
         while(nr > right[idx]) delete_right(--nr);
         rem(idx);
      }
   }
};