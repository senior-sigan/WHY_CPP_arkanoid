#pragma once

#include <ecs/i_system.h>
#include <lib/scene_manager.h>
#include <vector>

class BricksSystem : public ISystem {
  std::vector<size_t> to_delete{};
  SceneManager *sceneManager;

 public:
  explicit BricksSystem(SceneManager *sceneManager);

 protected:
  bool Filter(Entity* entity) const override;
  void Update(Context &ctx, Entity* entity) override;
  void OnPostUpdate(Context &ctx) override;
};