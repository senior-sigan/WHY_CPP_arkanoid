#pragma once

#include <ecs/entity_manager.h>
#include <ecs/i_system.h>
#include <memory>
#include <vector>

class Engine {
 private:
  std::vector<std::shared_ptr<ISystem>> systems;
  std::shared_ptr<EntityManager> entityManager;

 public:
  explicit Engine();

  void Update(Context &ctx);

  template<typename System, typename... Args>
  Engine &AddSystem(Args &&... args) {
    auto system = std::make_shared<System>(std::forward<Args>(args)...);
    system->entityManager = entityManager;
    systems.push_back(system);
    return *this;
  }

  std::shared_ptr<EntityManager> GetEntityManager() {
    return entityManager;
  }

  void RemoveSystems() {
    systems.clear();
  }

  void RemoveEntities() {
    entityManager->RemoveEntities();
  }

  virtual ~Engine();
};
