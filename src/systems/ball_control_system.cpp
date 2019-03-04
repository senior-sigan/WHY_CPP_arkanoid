#include <ecs/entity.h>
#include <game/systems/ball_control_system.h>
#include <game/components/ball_component.h>
#include <game/components/transform_component.h>
#include <game/components/movement_component.h>

void BallControlSystem::Update(Context &ctx, Entity &entity) {
  auto tc = entity.Get<TransformComponent>();
  auto mc = entity.Get<MovementComponent>();


}
bool BallControlSystem::Filter(const Entity &entity) const {
  return entity.Contains<BallComponent>() && entity.Contains<TransformComponent>() && entity.Contains<MovementComponent>();
}
