#ifndef GAME_MOVEMENT_COMPONENT_H
#define GAME_MOVEMENT_COMPONENT_H

#include <ecs/i_component.h>

class MovementComponent : public IComponent {
 public:
  Vec2 speed;

  explicit MovementComponent(const Vec2 &speed) : speed(speed) {}
};

#endif //GAME_MOVEMENT_COMPONENT_H
