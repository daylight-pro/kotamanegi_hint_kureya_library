template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)(), class G>
int max_right(lazy_segtree<S, op, e, F, mapping, composition, id>& seg, int l, G g) {
   auto& _n = seg._n;
   auto& size = seg.size;
   auto& d = seg.d;
   auto& log = seg.log;
   // assert(0 <= l && l <= _n);
   // assert(g(e()));
   if(l == _n) return _n;
   l += size;
   for(int i = log; i >= 1; i--) seg.push(l >> i);
   S sm = e();
   do {
      while(l % 2 == 0) l >>= 1;
      if(!g(op(sm, d[l]))) {
         while(l < size) {
            seg.push(l);
            l = (2 * l);
            if(g(op(sm, d[l]))) {
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

template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)(), class G>
int min_left(lazy_segtree<S, op, e, F, mapping, composition, id>& seg, int r, G g) {
   auto& _n = seg._n;
   auto& size = seg.size;
   auto& d = seg.d;
   auto& log = seg.log;
   // assert(0 <= r && r <= _n);
   // assert(g(e()));
   if(r == 0) return 0;
   r += size;
   for(int i = log; i >= 1; i--) seg.push((r - 1) >> i);
   S sm = e();
   do {
      r--;
      while(r > 1 && (r % 2)) r >>= 1;
      if(!g(op(d[r], sm))) {
         while(r < size) {
            seg.push(r);
            r = (2 * r + 1);
            if(g(op(d[r], sm))) {
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
