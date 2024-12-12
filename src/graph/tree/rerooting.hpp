// base: b7fc0f
template<class M, bool calc_contribution = false> struct Rerooting {
   using S = typename M::S;
   using C = typename M::C;
   vector<S> dp, memo;
   vector<vector<pair<int, C>>> g;
   map<ll, S> hash;
   int N;

   Rerooting(int n) : N(n), g(n) {}

   void add_edge(int f, int t, const C& c) {
      g[f].emplace_back(t, c);
      g[t].emplace_back(f, c);
   }

   vector<S> build() {
      memo.resize(N, M::e());
      dp.resize(N, M::e());
      dfs(0, -1);
      reroot(0, M::e());
      return dp;
   }

   private:
   void dfs(int cur, int pre = -1) {
      bool is_leaf = true;
      for(auto [to, c] : g[cur]) {
         if(to == pre) continue;
         is_leaf = false;
         dfs(to, cur);
         memo[cur] = M::merge(memo[cur], M::apply(memo[to], to, cur, c));
      }
      if(is_leaf) { memo[cur] = M::leaf(); }
   }

   void reroot(int cur, const S val, int pre = -1) {
      vector<S> ds;
      ds.push_back(val);
      if(calc_contribution) {
         if(pre == -1) hash[cur * N + pre] = val;
      }
      for(auto [to, c] : g[cur]) {
         if(to == pre) continue;
         ds.push_back(M::apply(memo[to], to, cur, c));
         if(calc_contribution) { hash[cur * N + to] = ds.back(); }
      }
      int n = size(ds);
      vector<S> l(n + 1, M::e()), r(n + 1, M::e());
      for(int i = 0; i < n; i++) l[i + 1] = M::merge(l[i], ds[i]);
      for(int i = n - 1; i >= 0; i--) r[i] = M::merge(ds[i], r[i + 1]);
      dp[cur] = r[0];
      int ind = 1;
      for(auto [to, c] : g[cur]) {
         if(to == pre) continue;
         S sub = M::merge(l[ind], r[ind + 1]);
         reroot(to, M::apply(sub, cur, to, c), cur);
         ind++;
      }
   }

   public:
   S get_contribution(int p, int c) {
      if(hash.count(p * N + c)) return hash[p * N + c];
      return M::e();
   }  // e6000f
};

/*

struct M {
   using S = pair<mm, int>; // DPの型
   using C = pair<mm, mm>;  // 辺コストの型
   static S merge(S a, S b) { return {a.first + b.first, a.second + b.second}; } // DPのマージ
   static S apply(S a, int from, int to, C b) {  // DPの親への寄与
      return {(a.first + A[from]) * b.first + b.second * (a.second + 1), a.second + 1};
   }
   static S e() { return {0, 0}; } // 単位元
   static S leaf() { return {0, 0}; } // 葉の値
};

Rerooting<M> reroot;
*/