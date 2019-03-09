#pragma once

#include <ecs/i_system.h>
#include <ecs/entity.h>

class TextureRenderSystem : public ISystem {
 protected:
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  bool Filter(std::shared_ptr<Entity> entity) const override;
};