#include <ecs/entity.h>
#include <ecs/entity_manager.h>
#include <game/components/ball_component.h>
#include <game/components/movement_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rigid_body_component.h>
#include <game/components/transform_component.h>
#include <game/systems/ball_control_system.h>
#include <game/utils/counter.h>
#include <matlib/numbers.h>
#include <whycpp/drawing.h>
#include <whycpp/lifecycle.h>

#include <game/components/platform_component.h>
#include <iostream>

void BallControlSystem::Update(Context &ctx, Entity* entity) {
  auto tc = entity->Get<TransformComponent>();
  auto mc = entity->Get<MovementComponent>();
  auto rc = entity->Get<RigidBodyComponent>();
  auto cc = entity->Get<RectColliderComponent>();

  if (cc->AnyCollisions()) {
    for (const auto &collision : cc->GetCollisions()) {
      auto v = collision.manifold.normal;
      if (v.x > 0 || v.x < 0) {
        mc->direction.x *= -1;
      }
      if (v.y > 0 || v.y < 0) {
        mc->direction.y *= -1;
      }

      if (collision.entity->Contains<PlatformComponent>()) {
        auto rc_p = collision.entity->Get<RectColliderComponent>();
        auto width = rc_p->GetSize().x / 3.5;
        if (std::abs(collision.manifold.vec.x) > width) {
          mc->direction.x *= -1;
        }
      }
    }
  }

  if (tc->position.y > (GetDisplayHeight(ctx) - tc->size.y)) {
    to_delete.push_back(entity->GetId());
  }
}
bool BallControlSystem::Filter(Entity* entity) const {
  return entity->Contains<BallComponent>() && entity->Contains<TransformComponent>() &&
         entity->Contains<MovementComponent>() && entity->Contains<RectColliderComponent>() &&
         entity->Contains<RigidBodyComponent>();
}
void BallControlSystem::OnPostUpdate(Context &ctx) {
  for (auto id : to_delete) {
    GetEntityManager()->DeleteEntity(id);
    std::cout << "Delete ball " << id << std::endl;
  }
  to_delete.clear();
}
void BallControlSystem::OnUpdate(Context &ctx) {
  Counter<BallComponent> counter;
  GetEntityManager()->ForEachMutable(counter);
  if (counter.get() == 0) {
    std::cout << "Game Over" << std::endl;
    sceneManager->SetScene(2);
  }
}
BallControlSystem::BallControlSystem(SceneManager *sceneManager) : sceneManager(sceneManager) {}
