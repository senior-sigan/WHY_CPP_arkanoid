#pragma once

#include <ecs/entity.h>
#include <functional>
#include <vector>

class EntityManager {
  std::vector<Entity> entities;
  size_t last_entity_id = 0;
 public:
  template <typename Functor>
  void ForEach(const Functor& func) {
    for (auto &entity : entities) {
      func(entity);
    }
  }
  Entity &CreateEntity();
};
