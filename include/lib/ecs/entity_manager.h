#pragma once

#include <lib/ecs/entity.h>
#include <memory>
#include <vector>

class EntityManager {
  std::vector<std::unique_ptr<Entity>> entities; // TODO: it should be map instead
  size_t last_entity_id = 0;

 public:
  template<typename Functor>
  void ForEachMutable(Functor& func) {
    for (auto& entity : entities) {
      func(entity.get());
    }
  }
  template<typename Functor>
  void ForEach(const Functor& func) {
    for (auto& entity : entities) {
      func(entity.get());
    }
  }
  Entity* FindFirstByTag(const std::string& tag);
  Entity* CreateEntity();
  void DeleteEntity(size_t id);
  void RemoveEntities();
  virtual ~EntityManager();
};
