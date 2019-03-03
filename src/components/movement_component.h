#ifndef GAME_MOVEMENT_COMPONENT_H
#define GAME_MOVEMENT_COMPONENT_H

#include "../matlib/vec2.h"

class MovementComponent : public IComponent {
 public:
  Vec2 speed;

  explicit MovementComponent(const Vec2 &speed) : speed(speed) {}
};

#endif //GAME_MOVEMENT_COMPONENT_H
