#include <matlib/manifold.h>

Manifold::Manifold(const Vec2 &overlap,
                   const Vec2 &normal,
                   const double penetration,
                   const bool intersecting)
    : overlap(overlap), normal(normal), penetration(penetration), intersecting(intersecting) {}
std::ostream &operator<<(std::ostream &os, const Manifold &manifold) {
  os << "overlap: " << manifold.overlap << " normal: "
     << manifold.normal << " penetration: " << manifold.penetration << " intersecting: " << manifold.intersecting;
  return os;
}