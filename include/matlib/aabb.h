#pragma once

#include <matlib/vec2.h>
#include <ostream>

class AABB {
 public:
  const Vec2 min; // upper left
  const Vec2 max; // bottom right

  AABB(const Vec2 &min, const Vec2 &max) : min(min), max(max) {}

  Vec2 Center() const;

  friend std::ostream &operator<<(std::ostream &os, const AABB &aabb);
};