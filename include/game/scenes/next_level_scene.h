#pragma once

#include <game/scenes/ecs_scene.h>

class NextLevelScene : public ECSScene {
 public:
  explicit NextLevelScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};