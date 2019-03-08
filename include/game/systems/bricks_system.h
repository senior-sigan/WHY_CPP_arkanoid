#pragma once

#include <ecs/i_system.h>
#include <vector>

class BricksSystem: public ISystem {
  std::vector<size_t> to_delete{};
 protected:
  bool Filter(std::shared_ptr<Entity> entity) const override;
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  void OnPostUpdate(Context &ctx) override;
};