#ifndef GAME_RECTANGLE_RENDER_SYSTEM_H
#define GAME_RECTANGLE_RENDER_SYSTEM_H

#include <ecs/i_system.h>

class RectangleRenderSystem: public ISystem {
 protected:
  void Update(Context &ctx, Entity &entity) override;
  bool Filter(const Entity &entity) const override;
};

#endif //GAME_RECTANGLE_RENDER_SYSTEM_H
