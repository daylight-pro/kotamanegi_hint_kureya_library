vector<mm> BerlekampMassey(const vector<mm>& s) {
   const int N = (int)s.size();
   vector<mm> b, c;
   b.reserve(N + 1);
   c.reserve(N + 1);
   b.push_back(mm(1));
   c.push_back(mm(1));
   mm y = mm(1);
   for(int ed = 1; ed <= N; ed++) {
      int l = int(c.size()), m = int(b.size());
      mm x = 0;
      for(int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
      b.emplace_back(mm(0));
      m++;
      if(x.x == 0) continue;
      mm freq = x / y;
      if(l < m) {
         auto tmp = c;
         c.insert(begin(c), m - l, mm(0));
         for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
         b = tmp;
         y = x;
      } else {
         for(int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
      }
   }
   reverse(begin(c), end(c));
   return c;
}