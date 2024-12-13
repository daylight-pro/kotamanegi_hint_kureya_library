// 2: inside, 1: border, 0: outside
int contains(const vector<Point>& ps, const Point& p) {
   int n = ps.size();
   bool in = false;
   for(int i = 0; i < n; i++) {
      Point a = ps[i] - p, b = ps[(i + 1) % n] - p;
      if(a.Y > b.Y) swap(a, b);
      if(a.Y <= EPS && EPS < b.Y && cross(a, b) < -EPS) in = !in;
      if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
   }
   return in ? 2 : 0;
}