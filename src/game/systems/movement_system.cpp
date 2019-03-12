#include <lib/ecs/entity.h>
#include <game/components/movement_component.h>
#include <game/components/transform_component.h>
#include <game/systems/movement_system.h>
#include <whycpp/time.h>

bool MovementSystem::Filter(Entity* entity) const {
  return entity->Contains<TransformComponent>() && entity->Contains<MovementComponent>();
}
void MovementSystem::Update(Context &ctx, Entity* entity) {
  auto tc = entity->Get<TransformComponent>();
  auto mc = entity->Get<MovementComponent>();

  tc->position += mc->direction * mc->speed * GetDelta(ctx);
}
