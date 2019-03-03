#ifndef GAME_PLAYER_CONTROL_SYSTEM_H
#define GAME_PLAYER_CONTROL_SYSTEM_H

#include "../ECS/i_system.h"
class PlayerControlSystem : public ISystem {
 protected:
  void Update(Context &ctx, Entity &entity) override;
  bool Filter(const Entity &entity) const override;
};

#endif //GAME_PLAYER_CONTROL_SYSTEM_H
