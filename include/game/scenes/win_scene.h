#pragma once

#include <lib/scene.h>
#include <ecs/engine.h>

class WinScene: public IScene {
  Engine engine;
  Context& ctx;
 public:
  explicit WinScene(Context &ctx): ctx(ctx) {};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};