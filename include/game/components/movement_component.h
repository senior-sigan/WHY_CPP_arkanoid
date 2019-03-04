#pragma once

#include <ecs/i_component.h>

class MovementComponent : public IComponent {
 public:
  Vec2 speed;

  explicit MovementComponent(const Vec2 &speed) : speed(speed) {}
};
