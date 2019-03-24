#include <game/components/bonuses/resize_bonus_component.h>
#include <game/components/movement_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <game/entities/bonuses/resize_bonus_builder.h>
#include <whycpp/palette.h>

void ResizeBonusBuilder::build(EntityManager* entity_manager, const Vec2& pos) {
  double power;
  if (random.NextInt(0, 2) == 0) {
    power = 0.5;
  } else {
    power = 1.25;
  }


  auto bonus = entity_manager->CreateEntity();
  auto size = Vec2(13, 6);
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
