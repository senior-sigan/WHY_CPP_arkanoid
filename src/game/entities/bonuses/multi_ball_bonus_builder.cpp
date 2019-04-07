#include <game/components/audio_component.h>
#include <game/components/bonuses/multi_ball_bonus_component.h>
#include <game/components/movement_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <game/entities/bonuses/multi_ball_bonus_builder.h>
#include <whycpp/palette.h>
#include <iostream>

void MultiBallBonusBuilder::build(EntityManager* entity_manager, const Vec2& pos){
  auto bonus = entity_manager->CreateEntity();
  auto size = Vec2(13, 6);
  auto speed = Vec2(200, 200);
  auto dir = DownVec2;

  auto color = PALETTE[9];

  bonus->Add<AudioComponent>("bonus");
  bonus->Add<TransformComponent>(pos);
  bonus->Add<RectColliderComponent>(size);
  bonus->Add<MovementComponent>(speed, dir);
  bonus->Add<MultiBallBonusComponent>(2);
  bonus->Add<RectangleRenderComponent>(size, color, true);
}
