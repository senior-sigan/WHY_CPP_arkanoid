#pragma once

#include <ecs/i_component.h>
#include <matlib/vec2.h>
#include <matlib/aabb.h>
#include <set>
#include <ecs/entity.h>
#include <utility>
#include <matlib/manifold.h>

class Collision {
 public:
  std::shared_ptr<Entity> entity;
  Manifold manifold;

  Collision(std::shared_ptr<Entity> entity, Manifold manifold)
      : entity(std::move(entity)), manifold(std::move(manifold)) {}

  bool operator<(const Collision &rhs) const {
    return entity < rhs.entity;
  }
  bool operator>(const Collision &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Collision &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Collision &rhs) const {
    return !(*this < rhs);
  }
};

class RectColliderComponent : public IComponent {
  std::set<Collision> collisions{};
  Vec2 size;
  Vec2 offset;
 public:
  bool is_trigger;

  explicit RectColliderComponent(const Vec2 &size,
                                 const Vec2 &offset = ZeroVec2,
                                 bool is_trigger = false)
      : size(size), offset(offset), is_trigger(is_trigger) {}

  const std::set<Collision> &GetCollisions() const {
    return collisions;
  }

  bool AnyCollisions() const {
    return !collisions.empty();
  }

  void Collide(std::shared_ptr<Entity> entity, const Manifold &manifold) {
    collisions.emplace(Collision{std::move(entity), manifold});
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