#include <whycpp/palette.h>
#include <whycpp/drawing.h>
#include <game/arkanoid_ecs.h>
#include <game/systems/texture_render_system.h>
#include <game/components/transform_component.h>
#include <game/components/texture_component.h>
#include <game/systems/rectangle_render_system.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/player_control_component.h>
#include <game/systems/player_control_system.h>
#include <game/components/movement_component.h>
#include <game/components/ball_component.h>
#include <game/systems/ball_control_system.h>
#include <matlib/vec2.h>
#include <game/systems/collision_system.h>
#include <game/components/rect_collider_component.h>

void ArkanoidECS::OnCreate(Context &ctx) {
  engine
      .AddSystem<TextureRenderSystem>()
      .AddSystem<RectangleRenderSystem>()
      .AddSystem<CollisionSystem>()
      .AddSystem<PlayerControlSystem>()
      .AddSystem<BallControlSystem>();

  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16) / 2, GetDisplayHeight(ctx) - 10);
  auto platform_size = Vec2(48, 6);
  engine.GetEntityManager()->CreateEntity()
      .Add<PlayerControlComponent>()
      .Add<MovementComponent>(Vec2(300, 0))
      .Add<TransformComponent>(platform_pos, platform_size)
      .Add<RectColliderComponent>(platform_size)
      .Add<RectangleRenderComponent>(48, 6, PALETTE[10], true);

  auto br = 4;
  auto ball_speed = 120;
  engine.GetEntityManager()->CreateEntity()
      .Add<TransformComponent>(Vec2(platform_pos.x + platform_size.x / 2 - br / 2 - 4, platform_pos.y - br),
                               Vec2(br, br))
      .Add<RectColliderComponent>(Vec2(br, br))
      .Add<MovementComponent>(Vec2(ball_speed, ball_speed))
      .Add<RectangleRenderComponent>(br, br, PALETTE[4], true)
      .Add<BallComponent>();
}
void ArkanoidECS::OnRender(Context &ctx) {
  DrawClearScreen(ctx, PALETTE[0]);
  engine.Update(ctx);
}
