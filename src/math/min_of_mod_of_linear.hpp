// depends on floor_sum
ll min_of_mod_of_linear(ll n, ll m, ll a, ll b) {
   ll fsum = floor_sum(n, m, a, b);
   ll le = -1, ri = m - 1;
   while(ri - le > 1) {
      ll mid = (le + ri) / 2;
      if(floor_sum(n, m, a, b + (m - 1 - mid)) < fsum + n) ri = mid;
      else le = mid;
   }
   return ri;
}