#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>

class TransformComponent : public IComponent {
 public:
  Vec2 position;
  explicit TransformComponent(const Vec2& position) : position(position) {}
};