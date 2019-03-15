#pragma once

#include <lib/ecs/entity.h>
#include <lib/ecs/i_system.h>

class TextureRenderSystem : public ISystem {
 protected:
  void Update(Context& ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};
