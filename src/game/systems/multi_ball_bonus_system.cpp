#include <game/components/bonuses/multi_ball_bonus_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/transform_component.h>
#include <game/entities/entities.h>
#include <game/systems/multi_ball_bonus_system.h>
#include <lib/ecs/entity.h>

void ApplyBonus(MultiBallBonusComponent* bc, EntityManager* entity_manager, Entity* platform) {
  auto tc = platform->Get<TransformComponent>();
  auto rc = platform->Get<RectColliderComponent>();

  for (int i = 0; i < bc->multiplier_; i++) {
    CreateBall(entity_manager, tc->position, rc->size);
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
