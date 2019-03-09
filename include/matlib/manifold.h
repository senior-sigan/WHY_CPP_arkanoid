#pragma once

#include <matlib/aabb.h>
#include <matlib/vec2.h>
#include <ostream>

class Manifold {
 public:
  const Vec2 overlap;
  const Vec2 normal;
  const double penetration;
  const bool intersecting;
  const Vec2 vec;

  explicit Manifold(const Vec2 &overlap, const Vec2 &normal, double penetration, bool intersecting, const Vec2 vec);

  friend std::ostream &operator<<(std::ostream &os, const Manifold &manifold);
};