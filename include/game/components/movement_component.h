#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>

class MovementComponent : public IComponent {
 public:
  Vec2 speed;
  Vec2 direction;

  explicit MovementComponent(const Vec2 &speed, const Vec2 &dir = ZeroVec2) : speed(speed), direction(dir) {}
};
