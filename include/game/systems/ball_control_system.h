#pragma once

#include <ecs/i_system.h>
#include <lib/scene_manager.h>
#include <vector>

class BallControlSystem : public ISystem {
  std::vector<size_t> to_delete;
  SceneManager *sceneManager;

 public:
  BallControlSystem(SceneManager *sceneManager);

 protected:
  void OnUpdate(Context &ctx) override;
  void Update(Context &ctx, std::shared_ptr<Entity> entity) override;
  bool Filter(std::shared_ptr<Entity> entity) const override;
  void OnPostUpdate(Context &ctx) override;
};
