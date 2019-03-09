#pragma once

#include <game/scenes/ecs_scene.h>

class WinScene : public ECSScene {
 public:
  explicit WinScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};