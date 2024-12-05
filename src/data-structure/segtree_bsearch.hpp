template<class S, S (*op)(S, S), S (*e)(), class F> int max_right(segtree<S, op, e>& seg, int l, F f) {
   auto& _n = seg._n;
   auto& size = seg.size;
   auto& d = seg.d;
   // assert(0 <= l && l <= _n);
   // assert(f(e()));
   if(l == _n) return _n;
   l += size;
   S sm = e();
   do {
      while(l % 2 == 0) l >>= 1;
      if(!f(op(sm, d[l]))) {
         while(l < size) {
            l = (2 * l);
            if(f(op(sm, d[l]))) {
               sm = op(sm, d[l]);
               l++;
            }
         }
         return l - size;
      }
      sm = op(sm, d[l]);
      l++;
   } while((l & -l) != l);
   return _n;
}

template<class S, S (*op)(S, S), S (*e)(), class F> int min_left(segtree<S, op, e>& seg, int r, F f) {
   auto& _n = seg._n;
   auto& size = seg.size;
   auto& d = seg.d;
   // assert(0 <= r && r <= _n);
   // assert(f(e()));
   if(r == 0) return 0;
   r += size;
   S sm = e();
   do {
      r--;
      while(r > 1 && (r % 2)) r >>= 1;
      if(!f(op(d[r], sm))) {
         while(r < size) {
            r = (2 * r + 1);
            if(f(op(d[r], sm))) {
               sm = op(d[r], sm);
               r--;
            }
         }
         return r + 1 - size;
      }
      sm = op(d[r], sm);
   } while((r & -r) != r);
   return 0;
}