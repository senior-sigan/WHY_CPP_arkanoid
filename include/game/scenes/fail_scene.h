#pragma once

#include <ecs/engine.h>
#include <lib/scene.h>

class FailScene : public IScene {
  Engine engine;
  Context& ctx;

 public:
  explicit FailScene(Context& ctx) : ctx(ctx){};
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};