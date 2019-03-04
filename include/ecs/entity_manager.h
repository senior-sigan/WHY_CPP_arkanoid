#pragma once

#include <ecs/entity.h>
#include <functional>
#include <vector>

class EntityManager {
  std::vector<Entity> entities;

 public:
  void ForEach(const std::function<void(Entity &)> &block);
  Entity &CreateEntity();
};
