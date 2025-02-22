struct rng {
   mt19937 mt;
   rng() : mt(58) {}
   int get(int a, int b) {  // [a, b]
      uniform_int_distribution<int> dist(a, b);
      return dist(mt);
   }
};