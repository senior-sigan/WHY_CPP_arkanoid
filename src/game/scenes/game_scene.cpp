#include <game/arkanoid_ecs.h>
#include <game/components/ball_component.h>
#include <game/components/brick_component.h>
#include <game/components/circle_render_component.h>
#include <game/components/movement_component.h>
#include <game/components/platform_component.h>
#include <game/components/player_control_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/rigid_body_component.h>
#include <game/components/transform_component.h>
#include <game/scenes/game_scene.h>
#include <whycpp/drawing.h>
#include <whycpp/palette.h>

void GameScene::CreateBorder(const Vec2 &size, const Vec2 &pos) {
  auto border = engine->GetEntityManager()->CreateEntity();
  border->Add<TransformComponent>(pos);
  border->Add<RectangleRenderComponent>(size, PALETTE[13]);
  border->Add<RectColliderComponent>(size);
}

void GameScene::CreateBrick(const Vec2 &pos, const Vec2 &size) {
  auto brick = engine->GetEntityManager()->CreateEntity();
  brick->SetTag("brick");
  brick->Add<TransformComponent>(pos);
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
  engine->Update(ctx);
}
void GameScene::OnDispose() {
  engine->GetEntityManager()->RemoveEntities();
  engine->GetSystemManager()->RemoveSystems();
}

void GameScene::InitEntities() {
  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
  auto platform_size = Vec2(52, 7);

  CreatePlatform(platform_pos, platform_size);
  CreateBall(platform_pos, platform_size);

  CreateBricks();
  CreateBorders();
}
GameScene::GameScene(Context &ctx) : ECSScene(ctx) {}

void GameScene::CreatePlatform(const Vec2 &platform_pos, const Vec2 &platform_size) {
  auto platform_speed = 290;
  auto platform = engine->GetEntityManager()->CreateEntity();
  platform->SetTag("platform");
  platform->Add<PlayerControlComponent>();
  platform->Add<PlatformComponent>();
  platform->Add<MovementComponent>(Vec2(platform_speed, 0));
  platform->Add<TransformComponent>(platform_pos);
  platform->Add<RectColliderComponent>(platform_size);
  platform->Add<RectangleRenderComponent>(platform_size, PALETTE[10], true);
}
void GameScene::CreateBall(const Vec2 &platform_pos, const Vec2 &platform_size) {
  auto br = 3.0;
  auto ball_speed = 180.0;
  auto ball_pos = Vec2(platform_pos.x + platform_size.x / 2 - br / 2, platform_pos.y - br);
  auto ball_size = Vec2(br, br);
  auto ball = engine->GetEntityManager()->CreateEntity();
  ball->SetTag("ball");
  ball->Add<TransformComponent>(ball_pos);
  ball->Add<RectColliderComponent>(ball_size);
  ball->Add<MovementComponent>(Vec2(ball_speed, ball_speed), Vec2(1, -1).Normalize());
  ball->Add<CircleRenderComponent>(br, PALETTE[5], true);
  ball->Add<BallComponent>();
  ball->Add<RigidBodyComponent>();
}
void GameScene::CreateBricks() {
  for (int i = 1; i < 12; i++) {
    for (int j = 1; j < 4; j++) {
      auto size = Vec2(15, 8);
      CreateBrick(Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size);
    }
  }
}
void GameScene::CreateBorders() {
  CreateBorder(Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0));  // top
  //  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0, GetDisplayHeight(ctx))); // bottom
  CreateBorder(Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0));                         // left
  CreateBorder(Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx) - 6, 0));  // right
}
