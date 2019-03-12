#include <lib/ecs/entity_manager.h>
#include <game/systems/collision_system.h>
#include <lib/matlib/colliders.h>
#include <lib/matlib/manifold.h>
#include <iostream>

void CollisionSystem::Update(Context &ctx, Entity *entity) {
  auto tc = entity->Get<TransformComponent>();
  auto cc = entity->Get<RectColliderComponent>();
  auto box = cc->GetAABB(tc->position);
  if (cc->is_sleeping) {
    return;
  }

  GetEntityManager()->ForEach([cc, box, entity](Entity *e) {
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
  GetEntityManager()->ForEach([](Entity *e) {
    if (e->Contains<RectColliderComponent>()) {
      e->Get<RectColliderComponent>()->Clear();
    }
  });
}
bool CollisionSystem::Filter(Entity *entity) const {
  return entity->Contains<TransformComponent>()
      && entity->Contains<RectColliderComponent>();
}
