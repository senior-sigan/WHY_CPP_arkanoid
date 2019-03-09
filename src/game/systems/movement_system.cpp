#include <game/systems/movement_system.h>
#include <game/components/movement_component.h>
#include <game/components/transform_component.h>
#include <ecs/entity.h>
#include <whycpp/time.h>

bool MovementSystem::Filter(std::shared_ptr<Entity> entity) const {
  return entity->Contains<TransformComponent>()
      && entity->Contains<MovementComponent>();
}
void MovementSystem::Update(Context &ctx, std::shared_ptr<Entity> entity) {
  auto tc = entity->Get<TransformComponent>();
  auto mc = entity->Get<MovementComponent>();

  tc->position += mc->direction * mc->speed * GetDelta(ctx);
}
