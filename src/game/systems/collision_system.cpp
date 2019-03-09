#include <ecs/entity_manager.h>
#include <game/systems/collision_system.h>
#include <matlib/colliders.h>
#include <matlib/manifold.h>
#include <iostream>

void CollisionSystem::Update(Context &ctx, Entity* entity) {
  auto tc = entity->Get<TransformComponent>();
  auto cc = entity->Get<RectColliderComponent>();
  auto box = cc->GetAABB(tc->position);

  GetEntityManager()->ForEach([cc, box, entity](Entity* e) {
    if (!e->Contains<RectColliderComponent>() || e->GetId() == entity->GetId()) {
      return;
    }
    auto tc2 = e->Get<TransformComponent>();
    auto cc2 = e->Get<RectColliderComponent>();
    auto box2 = cc2->GetAABB(tc2->position);

    auto manifold = Intersection(box, box2);
    if (manifold.intersecting) {
      cc->Collide(e, manifold);
    }
  });
}
void CollisionSystem::OnUpdate(Context &ctx) {
  GetEntityManager()->ForEach([](Entity* e) {
    if (e->Contains<RectColliderComponent>()) {
      e->Get<RectColliderComponent>()->Clear();
    }
  });
}
