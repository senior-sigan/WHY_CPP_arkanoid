#pragma once

#include <vector>
#include <ecs/entity.h>
#include <functional>

class EntityManager {
  std::vector<Entity> entities;
 public:
  void ForEach(const std::function<void(Entity &)> &block) {
    for (auto &entity: entities) {
      block(entity);
    }
  }

  Entity &CreateEntity() {
    entities.emplace_back();
    return *(entities.end() - 1);
  }
};
