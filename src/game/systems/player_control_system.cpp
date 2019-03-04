#include <whycpp/input.h>
#include <whycpp/time.h>
#include <whycpp/drawing.h>
#include <game/systems/player_control_system.h>
#include <game/components/transform_component.h>
#include <game/components/player_control_component.h>
#include <game/components/movement_component.h>
#include <iostream>
#include <ecs/entity.h>

void PlayerControlSystem::Update(Context &ctx, Entity &entity) {
  auto tc = entity.Get<TransformComponent>();
  auto pcc = entity.Get<PlayerControlComponent>();
  auto mc = entity.Get<MovementComponent>();

  auto speed_x = (int) (mc->speed.x * GetDelta(ctx));

  if (IsPressed(ctx, pcc->left) && tc->position.x > 0) {
    tc->position.x -= speed_x;
  }

  if (IsPressed(ctx, pcc->right) && tc->position.x < GetDisplayWidth(ctx) - tc->size.x) {
    tc->position.x += speed_x;
  }
}
bool PlayerControlSystem::Filter(const Entity &entity) const {
  return entity.Contains<TransformComponent>() && entity.Contains<PlayerControlComponent>();
}
