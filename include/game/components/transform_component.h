#pragma once

#include <matlib/vec2.h>
#include <ecs/i_component.h>

class TransformComponent : public IComponent {
 public:
  Vec2 position;
  Vec2 size;
  explicit TransformComponent(const Vec2 &position, const Vec2& size) : position(position), size(size) {}
};