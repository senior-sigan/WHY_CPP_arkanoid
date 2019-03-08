#include <whycpp/input.h>
#include <whycpp/drawing.h>
#include <game/systems/player_control_system.h>
#include <game/components/transform_component.h>
#include <game/components/player_control_component.h>
#include <game/components/movement_component.h>
#include <iostream>
#include <ecs/entity.h>

void PlayerControlSystem::Update(Context &ctx, std::shared_ptr<Entity> entity) {
  auto tc = entity->Get<TransformComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  auto mc = entity->Get<MovementComponent>();

  mc->direction = ZeroVec2;

  if (IsPressed(ctx, pcc->left) && tc->position.x > pcc->border_size) {
    mc->direction = LeftVec2;
  }

  if (IsPressed(ctx, pcc->right) && tc->position.x < GetDisplayWidth(ctx) - tc->size.x - pcc->border_size) {
    mc->direction = RightVec2;
  }

  if (IsPressed(ctx, pcc->up) && tc->position.y > pcc->border_size) {
    mc->direction = UpVec2;
  }

  if (IsPressed(ctx, pcc->down) && tc->position.y < GetDisplayHeight(ctx) - tc->size.y) {
    mc->direction = DownVec2;
  }
}
bool PlayerControlSystem::Filter(std::shared_ptr<Entity> entity) const {
  return entity->Contains<PlayerControlComponent>()
      && entity->Contains<PlayerControlComponent>()
      && entity->Contains<MovementComponent>();
}
