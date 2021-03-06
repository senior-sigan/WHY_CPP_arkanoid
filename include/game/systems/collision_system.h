#pragma once

#include <game/components/rect_collider_component.h>
#include <game/components/transform_component.h>
#include <lib/ecs/i_system.h>

class CollisionSystem : public ISystem {
 protected:
  void OnUpdate(Context& ctx) override;
  void Update(Context& ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};