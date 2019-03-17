#pragma once

#include <lib/ecs/i_system.h>
#include <lib/scene_manager.h>

class CheatSystem : public ISystem {
  SceneManager *scene_manager_;
 public:
  explicit CheatSystem(SceneManager *scene_manager);

 protected:
  void OnUpdate(Context &ctx) override;
  bool Filter(Entity *entity) const override;
};
