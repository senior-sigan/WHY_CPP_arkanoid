#include <lib/matlib/vec2.h>

double Distance(const Vec2 &lhs, const Vec2 &rhs) {
  double x1 = lhs.x - rhs.x;
  double y1 = lhs.y - rhs.y;
  return std::sqrt(x1 * x1 + y1 * y1);
}
