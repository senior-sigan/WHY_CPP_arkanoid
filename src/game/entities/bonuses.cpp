#include <game/entities/bonuses.h>
#include <game/components/transform_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/movement_component.h>
#include <game/components/bonuses/resize_bonus_component.h>
#include <game/components/rectangle_render_component.h>
#include <whycpp/palette.h>
#include <ecs/entity_manager.h>
#include <ecs/entity.h>

void CreateBonus(EntityManager *entityManager, const Vec2 &pos, double power) {
  auto bonus = entityManager->CreateEntity();
  auto size = Vec2(10, 10);
  auto speed = Vec2(200, 200);
  auto dir = DownVec2;

  auto color = PALETTE[11];
  if (power < 1) {
    color = PALETTE[8];
  }

  bonus->Add<TransformComponent>(pos);
  bonus->Add<RectColliderComponent>(size);
  bonus->Add<MovementComponent>(speed, dir);
  bonus->Add<ResizeBonusComponent>(power);
  bonus->Add<RectangleRenderComponent>(size, color, true);
}
