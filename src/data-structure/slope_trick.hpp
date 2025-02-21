template <typename T>
class SlopeTrick {
   T min_f;
   priority_queue<T> left;
   priority_queue<T, vector<T>, greater<>> right;
   T l_shift, r_shift;
public:
   SlopeTrick() : min_f(0), l_shift(0), r_shift(0) {}
   T get_min() const { return min_f; }
   void add_all(const T &a) { min_f += a; }
   void add_a_minus_x(const T &a) {
      if(right.empty() || a < right.top() + r_shift) {
         left.push(a - l_shift);
      } else {
         min_f += a - right.top() - r_shift;
         left.push(right.top() + r_shift - l_shift);
         right.pop();
         right.push(a - r_shift);
      }
   }
   void add_x_minus_a(const T &a) {
      if(left.empty() || left.top() + l_shift < a) {
         right.push(a - r_shift);
      } else {
         min_f += left.top() + l_shift - a;
         right.push(left.top() + l_shift - r_shift);
         left.pop();
         left.push(a - l_shift);
      }
   }
   void add_abs(const T &a) {
      add_a_minus_x(a);
      add_x_minus_a(a);
   }
   void clear_right() {
      while(!right.empty()) right.pop();
   }
   void clear_left() {
      while(!left.empty()) left.pop();
   }
   void shift(const T &a) {
      l_shift += a;
      r_shift += a;
   }
   void shift(const T &a, const T &b) {
      l_shift += a;
      r_shift += b;
   }
};
