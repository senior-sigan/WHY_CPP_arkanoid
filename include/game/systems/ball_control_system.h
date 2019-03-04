#ifndef GAME_BALL_CONTROL_SYSTEM_H
#define GAME_BALL_CONTROL_SYSTEM_H

#include <ecs/i_system.h>

class BallControlSystem: public ISystem {
 protected:
  void Update(Context &ctx, Entity &entity) override;
  bool Filter(const Entity &entity) const override;
};

#endif //GAME_BALL_CONTROL_SYSTEM_H
