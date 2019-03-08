#include <matlib/colliders.h>
#include <matlib/manifold.h>
#include <matlib/vec2.h>
#include <matlib/aabb.h>

bool IsIntersecting(const AABB &a, const AABB &b) {
  if (a.max.x < b.min.x || a.min.x > b.max.x) return false;
  if (a.max.y < b.min.y || a.min.y > b.max.y) return false;

  return true;
}

Manifold Intersection(const AABB &a, const AABB &b) {
  auto n = a.Center() - b.Center();

  auto a_hw = (a.max.x - a.min.x) / 2;
  auto b_hw = (b.max.x - b.min.x) / 2;

  auto a_hy = (a.max.y - a.min.y) / 2;
  auto b_hy = (b.max.y - b.min.y) / 2;

  auto x_overlap = a_hw + b_hw - std::abs(n.x);
  auto y_overlap = a_hy + b_hy - std::abs(n.y);
  auto overlap = Vec2(x_overlap, y_overlap);

  if (x_overlap > 0 && y_overlap > 0) {
    if (x_overlap < y_overlap) {
      if (n.x < 0) {
        return Manifold(overlap, LeftVec2, x_overlap, true);
      } else {
        return Manifold(overlap, RightVec2, x_overlap, true);
      }
    } else {
      if (n.y < 0) {
        return Manifold(overlap, UpVec2, y_overlap, true);
      } else {
        return Manifold(overlap, DownVec2, y_overlap, true);
      }
    }
  }

  return Manifold(ZeroVec2, ZeroVec2, 0, false);
}