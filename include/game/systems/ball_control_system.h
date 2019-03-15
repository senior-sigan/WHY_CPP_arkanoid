#pragma once

#include <lib/ecs/i_system.h>
#include <lib/scene_manager.h>
#include <vector>

class BallControlSystem : public ISystem {
  std::vector<size_t> to_delete;
  SceneManager *sceneManager;

 public:
  explicit BallControlSystem(SceneManager *sceneManager);

 protected:
  void OnUpdate(Context &ctx) override;
  void Update(Context &ctx, Entity *entity) override;
  bool Filter(Entity *entity) const override;
};
