#pragma once

#include <ecs/entity.h>
#include <ecs/i_component.h>
#include <matlib/aabb.h>
#include <matlib/manifold.h>
#include <matlib/vec2.h>
#include <set>
#include <utility>
#include <game/utils/collision.h>

class RectColliderComponent : public IComponent {
  std::set<Collision> collisions{};
  Vec2 size;
  Vec2 offset;

 public:
  bool is_trigger;

  explicit RectColliderComponent(const Vec2 &size, const Vec2 &offset = ZeroVec2, bool is_trigger = false)
      : size(size), offset(offset), is_trigger(is_trigger) {}

  const std::set<Collision> &GetCollisions() const {
    return collisions;
  }

  bool AnyCollisions() const {
    return !collisions.empty();
  }

  void Collide(Entity* entity, const Manifold &manifold) {
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