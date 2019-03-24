#include <game/components/bonuses/multi_ball_bonus_component.h>
#include <game/components/movement_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/transform_component.h>
#include <game/entities/entities.h>
#include <game/systems/multi_ball_bonus_system.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>

void ApplyBonus(MultiBallBonusComponent* bc, EntityManager* entity_manager, Entity* platform) {
  auto ball = entity_manager->FindFirstByTag("ball");
  auto pos = ball->Get<TransformComponent>()->position;
  auto dir = ball->Get<MovementComponent>()->direction;

  for (int i = 1; i < bc->multiplier_; i++) {
    CreateBall(entity_manager, pos, dir * Vec2(-1, 1));
  }
}

void MultiBallBonusSystem::Update(Context& ctx, Entity* entity) {
  auto bc = entity->Get<MultiBallBonusComponent>();
  auto rc = entity->Get<RectColliderComponent>();

  for (auto& collision : rc->GetCollisions()) {
    if (collision.entity->GetTag() != "platform") continue;
    rc->is_sleeping = true;  // TODO: it'd be better to remove this object immediately

    ApplyBonus(bc.get(), GetEntityManager(), collision.entity);
  }
}
bool MultiBallBonusSystem::Filter(Entity* entity) const {
  return entity->Contains<MultiBallBonusComponent>() && entity->Contains<RectColliderComponent>();
}
