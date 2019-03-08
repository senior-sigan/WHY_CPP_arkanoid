#include <ecs/entity.h>
#include <game/systems/ball_control_system.h>
#include <game/components/ball_component.h>
#include <game/components/transform_component.h>
#include <game/components/movement_component.h>
#include <game/components/rigid_body_component.h>
#include <game/components/rect_collider_component.h>

#include <iostream>

void BallControlSystem::Update(Context &ctx, std::shared_ptr<Entity> entity) {
  auto tc = entity->Get<TransformComponent>();
  auto mc = entity->Get<MovementComponent>();
  auto rc = entity->Get<RigidBodyComponent>();
  auto cc = entity->Get<RectColliderComponent>();

  if (cc->AnyCollisions()) {
    auto dir = ZeroVec2;
    for (const auto &collision: cc->GetCollisions()) {
      dir += collision.manifold.normal;
    }
    dir.Normalize();
    mc->direction = dir;
  }
}
bool BallControlSystem::Filter(std::shared_ptr<Entity> entity) const {
  return entity->Contains<BallComponent>()
      && entity->Contains<TransformComponent>()
      && entity->Contains<MovementComponent>()
      && entity->Contains<RectColliderComponent>()
      && entity->Contains<RigidBodyComponent>();
}
