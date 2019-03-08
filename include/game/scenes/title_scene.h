#pragma once

#include <lib/scene.h>
#include <ecs/engine.h>

class TitleScene: public IScene {
  Engine engine;
  Context& ctx;
 public:
  explicit TitleScene(Context &ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};