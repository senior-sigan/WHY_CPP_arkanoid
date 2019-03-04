#pragma once

#include <ecs/i_system.h>
#include <game/components/transform_component.h>
#include <game/components/rect_collider_component.h>
#include <iostream>

class CollisionSystem : public ISystem {
 protected:
  void Update(Context &ctx, Entity &entity) override {
    auto tc = entity.Get<TransformComponent>();
    auto cc = entity.Get<RectColliderComponent>();

    cc->Clear();
    if (!cc->is_movable) {
      return;
    }

    GetEntityManager()->ForEach([entity](Entity &e) {
      if (!e.Contains<RectColliderComponent>() || e.GetId() == entity.GetId())
        return;
//      auto tc = e.Get<TransformComponent>();
//      auto cc = entity.Get<RectColliderComponent>();
    });
  }
  bool Filter(const Entity &entity) const override {
    return entity.Contains<TransformComponent>() && entity.Contains<RectColliderComponent>();
  }
};