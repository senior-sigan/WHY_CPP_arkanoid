#pragma once

#include <ecs/i_system.h>

class PhysicsSystem : public ISystem {
 protected:
  void Update(Context &ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};