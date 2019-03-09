#pragma once

#include <game/scenes/ecs_scene.h>

class TitleScene : public ECSScene {
 public:
  explicit TitleScene(Context& ctx);
  void OnCreate() override;
  void OnUpdate() override;
  void OnDispose() override;
};