// 1: a-bから見てa-cが反時計回り
// -1: a-bから見てa-cが時計回り
// 0: a-c-bがこの順で直線
// 2: c-a-bの順で直線
// -2: a-b-cの順で直線

int ccw(const Point& a, const Point& b, const Point& c) {
   if(cross(b - a, c - a) > EPS) return 1;
   if(cross(b - a, c - a) < -EPS) return -1;
   if(dot(b - a, c - a) < -EPS) return 2;
   if(norm(b - a) < norm(c - a) - EPS) return -2;
   return 0;
}  // 6f1927

Point projection(const Point& p, const Line& l) {
   double t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
   return l[0] + t * (l[1] - l[0]);
}  // b9dbd7

Point reflection(const Point& p, const Line& l) { return 2.0 * projection(p, l) - p; }
// 65ba76

// point and line intersection
bool isinterPL(const Point& p, const Line& l) { return abs(p - projection(p, l)) < EPS; }
// e9d393

// point and segment intersection
bool isinterPS(const Point& p, const Line& s) { return ccw(s[0], s[1], p) == 0; }
// 79c17b

// two lines intersection
bool isinterLL(const Line& l, const Line& m) {
   return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;
}  // b58dbd

// two segments intersection
bool isinterSS(const Line& s, const Line& t) {
   if(norm(s[1] - s[0]) < EPS) return isinterPS(s[0], t);
   if(norm(t[1] - t[0]) < EPS) return isinterPS(t[0], s);
   return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0) && (ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}  // a499ea

double distancePL(const Point& p, const Line& l) { return abs(p - projection(p, l)); }
// c77772

double distancePS(const Point& p, const Line& s) {
   Point h = projection(p, s);
   if(isinterPS(h, s)) return abs(p - h);
   return min(abs(p - s[0]), abs(p - s[1]));
}  // 3bd780

double distanceLL(const Line& l, const Line& m) {
   if(isinterLL(l, m)) return 0;
   return distancePL(l[0], m);
}  // ab4ace

double distanceSS(const Line& s, const Line& t) {
   if(isinterSS(s, t)) return 0;
   return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0], s), distancePS(t[1], s)));
}  // c284e5

// if(ans){ x = p->X; y = q->Y} else {cout << "not cross"}
optional<Point> crosspoint(const Line& l, const Line& m) {
   double d = cross(m[1] - m[0], l[1] - l[0]);
   if(abs(d) < EPS) return nullopt;
   return l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d;
}  // 687c0c

double area(const vector<Point>& ps) {
   double res = 0;
   for(int i = 0; i < size(ps); i++) res += cross(ps[i], ps[(i + 1) % size(ps)]);
   return res / 2;
}  // 3b832b

bool is_convex(vector<Point>& ps) {
   int n = (int)ps.size();
   for(int i = 0; i < n; ++i) {
      if(ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1) return false;
   }
   return true;
}  // 52fb34

double diameter(const vector<Point> ps) {
   int n = (int)ps.size();
   int si = 0, sj = 0;
   for(int i = 1; i < n; i++) {
      if(ps[i].Y > ps[si].Y) si = i;
      if(ps[i].Y < ps[sj].Y) sj = i;
   }

   double res = 0;
   int i = si, j = sj;
   do {
      res = max(res, abs(ps[i] - ps[j]));
      if(cross(ps[(i + 1) % n] - ps[i], ps[(j + 1) % n] - ps[j]) < 0) i = (i + 1) % n;
      else j = (j + 1) % n;
   } while(i != si || j != sj);
   return res;
}  // ea6b63

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
}  // fd7e87