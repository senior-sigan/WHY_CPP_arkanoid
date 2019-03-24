#include <game/components/ball_component.h>
#include <game/components/brick_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/transform_component.h>
#include <game/entities/entities.h>
#include <game/systems/bricks_system.h>
#include <game/utils/counter.h>
#include <lib/ecs/entity_manager.h>
#include <cstdlib>
#include <iostream>

bool BricksSystem::Filter(Entity *entity) const {
  return entity->Contains<BrickComponent>() && entity->Contains<RectColliderComponent>() &&
         entity->Contains<TransformComponent>();
}
void BricksSystem::Update(Context &ctx, Entity *entity) {
  auto tc = entity->Get<TransformComponent>();
  auto bc = entity->Get<BrickComponent>();
  auto rc = entity->Get<RectColliderComponent>();

  for (const auto &collision : rc->GetCollisions()) {
    if (collision.entity->Contains<BallComponent>()) {
      to_delete.push_back(entity->GetId());
      bonus_spawner_.spawn(GetEntityManager(), tc->position);
    }
  }
}
void BricksSystem::OnPostUpdate(Context &ctx) {
  for (auto id : to_delete) {
    GetEntityManager()->DeleteEntity(id);
  }
  to_delete.clear();

  Counter<BrickComponent> counter;
  GetEntityManager()->ForEachMutable(counter);
  if (counter.get() == 0) {
    std::cout << "Next level" << std::endl;
    sceneManager->NextScene();
  }
}
BricksSystem::BricksSystem(SceneManager *sceneManager): sceneManager(sceneManager) {}
