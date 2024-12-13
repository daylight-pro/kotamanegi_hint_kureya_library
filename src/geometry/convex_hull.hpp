vector<Point> convex_hull(vector<Point>& ps, bool collinear = false) {
   int n = ps.size();
   if(n <= 1) return ps;
   sort(ps.begin(), ps.end(),
        [&EPS](const Point& a, const Point& b) { return abs(a.X - b.X) > EPS ? a.X < b.X : a.Y < b.Y; });
   vector<Point> hull(2 * n);
   double th = collinear ? -EPS : EPS;
   int k = 0;
   for(int i = 0; i < n; i++) {
      if(k >= 2) {
         while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k - 2]) < th) {
            k--;
            if(k < 2) break;
         }
      }
      if(k < 1 || abs(hull[k - 1] - ps[i]) > EPS) {
         hull[k] = ps[i];
         k++;
      }
   }
   int t = k + 1;
   for(int i = n - 2; i >= 0; i--) {
      if(k >= t) {
         while(cross(hull[k - 1] - hull[k - 2], ps[i] - hull[k - 2]) < th) {
            k--;
            if(k < t) break;
         }
      }
      if(k < 1 || abs(hull[k - 1] - ps[i]) > EPS) {
         hull[k] = ps[i];
         k++;
      }
   }
   hull.resize(max(1, k - 1));
   return hull;
}