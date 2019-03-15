#include <game/components/ball_component.h>
#include <game/components/circle_render_component.h>
#include <game/components/movement_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rigid_body_component.h>
#include <game/components/transform_component.h>
#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>
#include <whycpp/palette.h>

void CreateBall(EntityManager *entity_manager, const Vec2 &platform_pos, const Vec2 &platform_size) {
  auto br = 3.0;
  auto ball_speed = 180.0;
  auto ball_pos = Vec2(platform_pos.x + platform_size.x / 2 - br / 2, platform_pos.y - br);
  auto ball_size = Vec2(br, br);
  auto ball = entity_manager->CreateEntity();
  ball->SetTag("ball");
  ball->Add<TransformComponent>(ball_pos);
  ball->Add<RectColliderComponent>(ball_size);
  ball->Add<MovementComponent>(Vec2(ball_speed, ball_speed), Vec2(1, -1).Normalize());
  ball->Add<CircleRenderComponent>(br, PALETTE[5], true);
  ball->Add<BallComponent>();
  ball->Add<RigidBodyComponent>();
}