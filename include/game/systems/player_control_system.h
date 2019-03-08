#pragma once

#include <ecs/i_system.h>

class PlayerControlSystem : public ISystem {
 protected:
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  bool Filter(std::shared_ptr<Entity> entity) const override;
};