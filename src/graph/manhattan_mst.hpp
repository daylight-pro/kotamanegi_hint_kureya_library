// 候補の辺を O(N) 本に減らす。MST時は追加でsort, UF等の必要あり。
template<typename T> vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
   assert(xs.size() == ys.size());
   vector<tuple<T, int, int>> ret;
   int n = (int)xs.size();

   vector<int> ord(n);
   iota(ord.begin(), ord.end(), 0);

   for(int s = 0; s < 2; s++) {
      for(int t = 0; t < 2; t++) {
         auto cmp = [&](int i, int j) -> bool { return xs[i] + ys[i] < xs[j] + ys[j]; };
         sort(ord.begin(), ord.end(), cmp);

         map<T, int> idx;
         for(int i : ord) {
            for(auto it = idx.lower_bound(-ys[i]); it != idx.end(); it = idx.erase(it)) {
               int j = it->second;
               if(xs[i] - xs[j] < ys[i] - ys[j]) break;
               ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);
            }
            idx[-ys[i]] = i;
         }
         swap(xs, ys);
      }
      for(int i = 0; i < n; i++) xs[i] *= -1;
   }
   return ret;
}