#pragma once

#include <lib/ecs/i_system.h>

class PlayerControlSystem : public ISystem {
 protected:
  void Update(Context &ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};