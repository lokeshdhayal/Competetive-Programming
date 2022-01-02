struct point_i { int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {} };

double dist(point p1,point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}

struct point { double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y; }
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };