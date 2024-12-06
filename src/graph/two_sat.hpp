struct two_sat {
   public:
   two_sat() : _n(0), scc(0) {}
   two_sat(int n) : _n(n), scc(2 * n), _answer(n) {}

   void add_clause(int i, bool f, int j, bool g) {
      // assert(0 <= i && i < _n);
      // assert(0 <= j && j < _n);
      scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
      scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
   }

   bool satisfiable() {
      scc.scc();
      auto comp = scc.get_comp();
      rep(i, 0, _n) {
         if(comp[2 * i] == comp[2 * i + 1]) return false;
         _answer[i] = comp[2 * i] < comp[2 * i + 1];
      }
      return true;
   }

   vector<bool> answer() { return _answer; }

   private:
   int _n;
   vector<bool> _answer;
   scc_graph scc;
};