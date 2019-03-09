#pragma once

#include <ecs/i_component.h>
#include <matlib/vec2.h>

class TransformComponent : public IComponent {
 public:
  Vec2 position;
  explicit TransformComponent(const Vec2& position) : position(position) {}
};