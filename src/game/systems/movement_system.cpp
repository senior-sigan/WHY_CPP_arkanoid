#include <game/components/movement_component.h>
#include <game/components/transform_component.h>
#include <game/systems/movement_system.h>
#include <lib/ecs/entity.h>
#include <whycpp/time.h>
#include <iostream>

/**
 * On slow PC i would preffer a slow gameplay instead of lags
 * @param ctx
 * @return
 */
double GetDeltaClip(Context& ctx) {
  auto dt= GetDelta(ctx);
  if (dt >= 0.03) return 0.03;
  return dt;
}

bool MovementSystem::Filter(Entity* entity) const {
  return entity->Contains<TransformComponent>() && entity->Contains<MovementComponent>();
}
void MovementSystem::Update(Context& ctx, Entity* entity) {
  auto tc = entity->Get<TransformComponent>();
  auto mc = entity->Get<MovementComponent>();

  tc->position += mc->direction * mc->speed * GetDeltaClip(ctx);
}
