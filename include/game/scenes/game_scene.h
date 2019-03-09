#pragma once

#include <ecs/engine.h>
#include <lib/scene.h>

class GameScene : public IScene {
  Engine engine;
  Context& ctx;

  void InitSystems();
  void InitEntities();

 public:
  explicit GameScene(Context& ctx) : ctx(ctx){};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};