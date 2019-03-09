#pragma once

#include <ecs/entity.h>
#include <ecs/i_system.h>

class TextureRenderSystem : public ISystem {
 protected:
  void Update(Context &ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};
