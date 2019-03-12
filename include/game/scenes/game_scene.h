#pragma once

#include <game/scenes/ecs_scene.h>
#include <lib/matlib/vec2.h>

class GameScene : public ECSScene {
  void InitSystems();
  void InitEntities();
  void CreateBricks();
  void CreateBorders();
 public:
  explicit GameScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};