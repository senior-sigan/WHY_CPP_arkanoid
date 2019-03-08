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
#include <game/components/rigid_body_component.h>
#include <game/systems/physics_system.h>
#include <game/systems/movement_system.h>

void CreateBorder(Engine& engine, const Vec2& size, const Vec2& pos) {
  auto border = engine.GetEntityManager()->CreateEntity();
  border->Add<TransformComponent>(pos, size);
//  border->Add<RectangleRenderComponent>(size, PALETTE[1]);
  border->Add<RectColliderComponent>(size);
}

void ArkanoidECS::OnCreate(Context &ctx) {
  engine
      .AddSystem<CollisionSystem>()
      .AddSystem<PlayerControlSystem>()
      .AddSystem<BallControlSystem>()
      .AddSystem<PhysicsSystem>()
      .AddSystem<MovementSystem>()
      .AddSystem<TextureRenderSystem>()
      .AddSystem<RectangleRenderSystem>();

  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 10.0);
  auto platform_size = Vec2(48, 6);
  auto platform = engine.GetEntityManager()->CreateEntity();
  platform->Add<PlayerControlComponent>();
  platform->Add<MovementComponent>(Vec2(100, 100));
  platform->Add<TransformComponent>(platform_pos, platform_size);
  platform->Add<RectColliderComponent>(platform_size);
  platform->Add<RectangleRenderComponent>(platform_size, PALETTE[10], true);

  auto br = 6.0;
  auto ball_speed = 120.0;
  auto ball_pos = Vec2(platform_pos.x + platform_size.x / 2 - br / 2, platform_pos.y - br);
  auto ball_size = Vec2(br, br);
  auto ball = engine.GetEntityManager()->CreateEntity();
  ball->Add<TransformComponent>(ball_pos, ball_size);
  ball->Add<RectColliderComponent>(ball_size);
  ball->Add<MovementComponent>(Vec2(ball_speed, ball_speed), Vec2(1,-1).Normalize());
  ball->Add<RectangleRenderComponent>(ball_size, PALETTE[4], true);
  ball->Add<BallComponent>();
  ball->Add<RigidBodyComponent>();


  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0,-10));
  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0,GetDisplayHeight(ctx)));
  CreateBorder(engine, Vec2(10, GetDisplayHeight(ctx)), Vec2(-10,0));
  CreateBorder(engine, Vec2(10, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx),0));
}
void ArkanoidECS::OnRender(Context &ctx) {
  DrawClearScreen(ctx, PALETTE[0]);
  engine.Update(ctx);
}
