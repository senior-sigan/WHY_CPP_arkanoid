#pragma once

#include <game/scenes/ecs_scene.h>
#include <matlib/vec2.h>

class GameScene : public ECSScene {
  void InitSystems();
  void InitEntities();
  void CreateBrick(const Vec2 &pos, const Vec2 &size);
  void CreateBorder(const Vec2 &size, const Vec2 &pos);
 public:
  explicit GameScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};