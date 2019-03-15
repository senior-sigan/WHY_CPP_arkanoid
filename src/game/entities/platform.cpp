#include <game/components/movement_component.h>
#include <game/components/platform_component.h>
#include <game/components/player_control_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <game/entities/entities.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <whycpp/palette.h>

void CreatePlatform(EntityManager *entity_manager, const Vec2 &platform_pos, const Vec2 &platform_size) {
  auto platform_speed = 290;
  auto platform = entity_manager->CreateEntity();
  platform->SetTag("platform");
  platform->Add<PlayerControlComponent>();
  platform->Add<PlatformComponent>();
  platform->Add<MovementComponent>(Vec2(platform_speed, 0));
  platform->Add<TransformComponent>(platform_pos);
  platform->Add<RectColliderComponent>(platform_size);
  platform->Add<RectangleRenderComponent>(platform_size, PALETTE[10], true);
}