#pragma once

#include <game/scenes/ecs_scene.h>
#include <lib/matlib/vec2.h>

class GameScene : public ECSScene {
  void InitSystems();
  void InitEntities();
  void CreateBrick(const Vec2 &pos, const Vec2 &size);
  void CreateBorder(const Vec2 &size, const Vec2 &pos);
  void CreatePlatform(const Vec2& platform_pos, const Vec2& platform_size);
  void CreateBall(const Vec2& platform_pos, const Vec2& platform_size);
  void CreateBricks();
  void CreateBorders();
 public:
  explicit GameScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};