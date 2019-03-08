#include <game/scenes/game_scene.h>
#include <whycpp/palette.h>
#include <whycpp/drawing.h>
#include <game/arkanoid_ecs.h>
#include <game/systems/texture_render_system.h>
#include <game/components/transform_component.h>
#include <game/systems/rectangle_render_system.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/player_control_component.h>
#include <game/systems/player_control_system.h>
#include <game/components/movement_component.h>
#include <game/components/ball_component.h>
#include <game/systems/ball_control_system.h>
#include <game/systems/collision_system.h>
#include <game/components/rigid_body_component.h>
#include <game/systems/physics_system.h>
#include <game/systems/movement_system.h>
#include <game/components/brick_component.h>
#include <game/systems/bricks_system.h>
#include <game/systems/circle_render_system.h>
#include <game/components/circle_render_component.h>

void CreateBorder(Engine &engine, const Vec2 &size, const Vec2 &pos) {
  auto border = engine.GetEntityManager()->CreateEntity();
  border->Add<TransformComponent>(pos, size);
  border->Add<RectangleRenderComponent>(size, PALETTE[13]);
  border->Add<RectColliderComponent>(size);
}

void CreateBrick(Engine &engine, const Vec2 &pos, const Vec2 &size) {
  auto brick = engine.GetEntityManager()->CreateEntity();
  brick->Add<TransformComponent>(pos, size);
  brick->Add<RectangleRenderComponent>(size, PALETTE[8]);
  brick->Add<RectColliderComponent>(size);
  brick->Add<BrickComponent>();
}

void GameScene::OnCreate() {
  InitSystems();
  InitEntities();
}
void GameScene::OnUpdate() {
  DrawClearScreen(ctx, PALETTE[1]);
  engine.Update(ctx);
}
void GameScene::OnDispose() {
  engine.RemoveSystems();
  engine.RemoveEntities();
}

void GameScene::InitSystems() {
  engine
      .AddSystem<CollisionSystem>()
      .AddSystem<PlayerControlSystem>()
      .AddSystem<BallControlSystem>(GetSceneManager())
      .AddSystem<PhysicsSystem>()
      .AddSystem<MovementSystem>()
      .AddSystem<BricksSystem>(GetSceneManager())
      .AddSystem<CircleRenderSystem>()
      .AddSystem<TextureRenderSystem>()
      .AddSystem<RectangleRenderSystem>();
}
void GameScene::InitEntities() {
  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
  auto platform_size = Vec2(52, 7);
  auto platform_speed = 290;
  auto platform = engine.GetEntityManager()->CreateEntity();
  platform->Add<PlayerControlComponent>();
  platform->Add<MovementComponent>(Vec2(platform_speed, 0));
  platform->Add<TransformComponent>(platform_pos, platform_size);
  platform->Add<RectColliderComponent>(platform_size);
  platform->Add<RectangleRenderComponent>(platform_size, PALETTE[10], true);

  auto br = 3.0;
  auto ball_speed = 180.0;
  auto ball_pos = Vec2(platform_pos.x + platform_size.x / 2 - br / 2, platform_pos.y - br);
  auto ball_size = Vec2(br, br);
  auto ball = engine.GetEntityManager()->CreateEntity();
  ball->Add<TransformComponent>(ball_pos, ball_size);
  ball->Add<RectColliderComponent>(ball_size);
  ball->Add<MovementComponent>(Vec2(ball_speed, ball_speed), Vec2(1, -1).Normalize());
  ball->Add<CircleRenderComponent>(br, PALETTE[5], true);
  ball->Add<BallComponent>();
  ball->Add<RigidBodyComponent>();

  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0)); // top
//  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0, GetDisplayHeight(ctx))); // bottom
  CreateBorder(engine, Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0)); // left
  CreateBorder(engine, Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx)-6, 0)); // right

  for (int i = 1; i < 12; i++) {
    for (int j = 1; j < 4; j++) {
      auto size = Vec2(15, 8);
      CreateBrick(engine, Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size);
    }
  }
}
