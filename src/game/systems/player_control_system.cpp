#include <game/components/movement_component.h>
#include <game/components/player_control_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/transform_component.h>
#include <game/systems/player_control_system.h>
#include <lib/ecs/entity.h>
#include <whycpp/drawing.h>
#include <whycpp/input.h>
#include <iostream>

void MoveLeft(TransformComponent* tc, MovementComponent* mc, PlayerControlComponent* pcc) {
  if (tc->position.x > pcc->border_size) {
    mc->direction = LeftVec2;
  }
}

void MoveRight(Context& ctx, TransformComponent* tc, MovementComponent* mc, PlayerControlComponent* pcc,
               RectColliderComponent* rcc) {
  if (tc->position.x < GetDisplayWidth(ctx) - rcc->GetSize().x - pcc->border_size) {
    mc->direction = RightVec2;
  }
}

void PlayerControlSystem::Update(Context& ctx, Entity* entity) {
  auto tc = entity->Get<TransformComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  auto mc = entity->Get<MovementComponent>();
  auto rcc = entity->Get<RectColliderComponent>();

  mc->direction = ZeroVec2;

  if (IsPressed(ctx, pcc->left)) {
    MoveLeft(tc.get(), mc.get(), pcc.get());
  }

  if (IsPressed(ctx, pcc->right)) {
    MoveRight(ctx, tc.get(), mc.get(), pcc.get(), rcc.get());
  }

  // Controls for touch screens
  if (IsPressed(ctx, pcc->mouse)) {
    int x, y;
    GetMouse(ctx, x, y);
    if (x < GetDisplayWidth(ctx) / 2) {
      MoveLeft(tc.get(), mc.get(), pcc.get());
    } else {
      MoveRight(ctx, tc.get(), mc.get(), pcc.get(), rcc.get());
    }
  }
}
bool PlayerControlSystem::Filter(Entity* entity) const {
  return entity->Contains<PlayerControlComponent>() && entity->Contains<PlayerControlComponent>() &&
         entity->Contains<MovementComponent>() && entity->Contains<RectColliderComponent>();
}
