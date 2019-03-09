#pragma once

#include <ecs/i_system.h>
#include <memory>
#include <vector>

class SystemManager {
  std::vector<std::shared_ptr<ISystem>> systems;
  std::shared_ptr<EntityManager> entityManager;

 public:
  explicit SystemManager(std::shared_ptr<EntityManager> entityManager) : entityManager(std::move(entityManager)) {}

  template<typename System, typename... Args>
  SystemManager *AddSystem(Args &&... args) {
    auto system = std::make_shared<System>(std::forward<Args>(args)...);
    system->entityManager = entityManager;
    systems.push_back(system);
    return this;
  }

  void Update(Context &ctx);
  void RemoveSystems();
  virtual ~SystemManager();
};
