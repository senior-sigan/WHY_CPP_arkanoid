#include "ball_control_system.h"
#include "../components/ball_component.h"
#include "../components/transform_component.h"
#include "../components/movement_component.h"
void BallControlSystem::Update(Context &ctx, Entity &entity) {
  auto tc = entity.Get<TransformComponent>();
  auto mc = entity.Get<MovementComponent>();


}
bool BallControlSystem::Filter(const Entity &entity) const {
  return entity.Contains<BallComponent>() && entity.Contains<TransformComponent>() && entity.Contains<MovementComponent>();
}
