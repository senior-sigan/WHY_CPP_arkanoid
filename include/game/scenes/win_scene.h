#pragma once

#include <ecs/engine.h>
#include <lib/scene.h>

class WinScene : public IScene {
  Engine engine;
  Context& ctx;

 public:
  explicit WinScene(Context& ctx) : ctx(ctx){};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};