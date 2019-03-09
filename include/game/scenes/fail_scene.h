#pragma once

#include <game/scenes/ecs_scene.h>

class FailScene : public ECSScene {
 public:
  explicit FailScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};