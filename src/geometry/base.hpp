using Point = complex<double>;

#define x real()
#define y imag()

inline double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
inline double abs(const Point& a) { return sqrt(dot(a, a)); }
