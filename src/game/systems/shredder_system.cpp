#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <game/systems/shredder_system.h>
#include <game/components/transform_component.h>
#include <whycpp/drawing.h>
#include <game/components/rect_collider_component.h>

void ShredderSystem::Update(Context &ctx, Entity *entity) {
  auto tc = entity->Get<TransformComponent>();
  auto cc = entity->Get<RectColliderComponent>();

  if (tc->position.y > (GetDisplayHeight(ctx) - cc->GetSize().y)) {
    to_delete.push_back(entity->GetId());
  }
}

void ShredderSystem::OnPostUpdate(Context &ctx) {
  for (auto id : to_delete) {
    GetEntityManager()->DeleteEntity(id);
  }
  to_delete.clear();
}
bool ShredderSystem::Filter(Entity *entity) const {
  return entity->Contains<TransformComponent>() && entity->Contains<RectColliderComponent>();
}
