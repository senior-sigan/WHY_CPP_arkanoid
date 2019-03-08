#pragma once

#include <ecs/i_system.h>
#include <game/components/transform_component.h>
#include <game/components/rect_collider_component.h>

class CollisionSystem : public ISystem {
 protected:
  void OnUpdate(Context &ctx) override;
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  bool Filter(std::shared_ptr<Entity> entity) const override {
    return entity->Contains<TransformComponent>() && entity->Contains<RectColliderComponent>();
  }
};