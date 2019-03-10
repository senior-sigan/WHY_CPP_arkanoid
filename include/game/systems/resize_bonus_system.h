#pragma once

#include <ecs/i_system.h>

class ResizeBonusSystem: public ISystem {
 protected:
  bool Filter(Entity *entity) const override;
  void Update(Context &ctx, Entity *entity) override;
};