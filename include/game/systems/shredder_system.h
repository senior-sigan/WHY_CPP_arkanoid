#pragma once

#include <ecs/i_system.h>
#include <vector>

class ShredderSystem: public ISystem {
  std::vector<size_t> to_delete{};

 protected:
  void Update(Context &ctx, Entity *entity) override;
  void OnPostUpdate(Context &ctx) override;
  bool Filter(Entity *entity) const override;
};