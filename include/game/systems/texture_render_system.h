#pragma once

#include <ecs/entity.h>
#include <ecs/i_system.h>

class TextureRenderSystem : public ISystem {
 protected:
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  bool Filter(std::shared_ptr<Entity> entity) const override;
};
