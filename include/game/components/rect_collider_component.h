#pragma once

#include <ecs/i_component.h>
#include <matlib/vec2.h>
#include <set>
#include <ecs/entity.h>

class RectColliderComponent : public IComponent {
  std::set<std::shared_ptr<Entity>> collisions{};
 public:
  Vec2 size;
  Vec2 offset;
  bool is_trigger;
  bool is_movable;

  explicit RectColliderComponent(const Vec2 &size,
                        const Vec2 &offset = ZeroVec2,
                        bool is_trigger = false,
                        bool is_movable = true)
      : size(size), offset(offset), is_trigger(is_trigger), is_movable(is_movable) {}

  const std::set<std::shared_ptr<Entity>> GetCollisions() const {
    return collisions;
  }

  void Collide(std::shared_ptr<Entity> entity) {
    collisions.emplace(entity);
  }

  void Clear() {
    collisions.clear();
  }
};