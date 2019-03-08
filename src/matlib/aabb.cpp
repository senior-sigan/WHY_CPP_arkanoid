#include <matlib/aabb.h>
#include <iostream>

Vec2 AABB::Center() const {
  return Vec2((max.x + min.x) / 2, (max.y + min.y) / 2);
}
std::ostream &operator<<(std::ostream &os, const AABB &aabb) {
  os << "min: " << aabb.min << " max: " << aabb.max;
  return os;
}
