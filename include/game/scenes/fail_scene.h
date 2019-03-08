#pragma once

#include <lib/scene.h>
#include <ecs/engine.h>

class FailScene: public IScene {
  Engine engine;
  Context& ctx;
 public:
  explicit FailScene(Context &ctx): ctx(ctx) {};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};