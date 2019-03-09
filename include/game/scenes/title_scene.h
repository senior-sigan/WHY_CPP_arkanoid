#pragma once

#include <ecs/engine.h>
#include <lib/scene.h>

class TitleScene : public IScene {
  Engine engine;
  Context& ctx;

 public:
  explicit TitleScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};