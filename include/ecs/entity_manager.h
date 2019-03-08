#pragma once

#include <ecs/entity.h>
#include <functional>
#include <vector>
#include <memory>

class EntityManager {
  std::vector<std::shared_ptr<Entity>> entities;
  size_t last_entity_id = 0;
 public:
  template <typename Functor>
  void ForEachMutable(Functor& func) {
    for (auto &entity : entities) {
      func(entity);
    }
  }
  template <typename Functor>
  void ForEach(const Functor& func) {
    for (auto &entity : entities) {
      func(entity);
    }
  }
  std::shared_ptr<Entity> CreateEntity();
  void DeleteEntity(size_t id);
  void RemoveEntities();
  virtual ~EntityManager();
};
