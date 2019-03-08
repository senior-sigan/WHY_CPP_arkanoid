#pragma once

#include <lib/scene.h>
#include <ecs/engine.h>

class GameScene: public IScene {
  Engine engine;
  Context& ctx;

  void InitSystems();
  void InitEntities();
 public:
  explicit GameScene(Context &ctx): ctx(ctx) {};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};