template<bool margeAdjacent = true> struct range_set : public map<ll, ll> {
   auto get(ll p) const {
      auto it = upper_bound(p);
      if(it == begin() || (--it)->second < p) return end();
      return it;
   }

   void insert(ll l, ll r) {
      auto itl = upper_bound(l), itr = upper_bound(r + margeAdjacent);
      if(itl != begin()) {
         if((--itl)->second < l - margeAdjacent) ++itl;
      }
      if(itl != itr) {
         l = min(l, itl->first);
         r = max(r, prev(itr)->second);
         erase(itl, itr);
      }
      (*this)[l] = r;
   }

   void remove(ll l, ll r) {
      auto itl = upper_bound(l), itr = upper_bound(r);
      if(itl != begin())
         if((--itl)->second < l) ++itl;
      if(itl == itr) return;
      int tl = min(l, itl->first), tr = max(r, prev(itr)->second);
      erase(itl, itr);
      if(tl < l) (*this)[tl] = l - 1;
      if(r < tr) (*this)[r + 1] = tr;
   }

   bool same(ll p, ll q) {
      auto it = get(p);
      return it != end() && it->first <= q && q <= it->second;
   }
};