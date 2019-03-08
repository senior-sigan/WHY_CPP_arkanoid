#include <matlib/numbers.h>

bool Eq(double rhs, double lhs, double eps) {
  return std::abs(rhs - lhs) < eps;
}
bool IsZero(double v) {
  return Eq(v, 0.0);
}
