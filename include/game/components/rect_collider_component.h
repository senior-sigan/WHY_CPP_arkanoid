#pragma once

#include <lib/ecs/entity.h>
#include <lib/ecs/i_component.h>
#include <lib/matlib/aabb.h>
#include <lib/matlib/manifold.h>
#include <lib/matlib/vec2.h>
#include <set>
#include <utility>
#include <game/utils/collision.h>

class RectColliderComponent : public IComponent {
  std::set<Collision> collisions{};
 public:
  Vec2 size;
  Vec2 offset;
  bool is_trigger;
  bool is_sleeping;

  explicit RectColliderComponent(const Vec2 &size,
                                 const Vec2 &offset = ZeroVec2,
                                 bool is_trigger = false,
                                 bool is_sleeping = false)
      : size(size), offset(offset), is_trigger(is_trigger), is_sleeping(is_sleeping) {}

  const std::set<Collision> &GetCollisions() const {
    return collisions;
  }

  bool AnyCollisions() const {
    return !collisions.empty();
  }

  void Collide(Entity *entity, const Manifold &manifold) {
    collisions.emplace(Collision{entity, manifold});
  }

  void Clear() {
    collisions.clear();
  }

  AABB GetAABB(const Vec2 &pos) const {
    return AABB(offset + pos, size + offset + pos);
  }

  Vec2 GetSize() const {
    return size;
  }
};