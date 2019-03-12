#pragma once

#include <lib/ecs/i_system.h>
#include <memory>
#include <vector>

class SystemManager {
  std::vector<std::unique_ptr<ISystem>> systems;
  EntityManager* entityManager;

 public:
  explicit SystemManager(EntityManager* entityManager) : entityManager(entityManager) {}

  template<typename System, typename... Args>
  SystemManager *AddSystem(Args &&... args) {
    auto system = new System(std::forward<Args>(args)...);
    system->entityManager = entityManager;
    systems.push_back(std::unique_ptr<System>(system));
    return this;
  }

  void Update(Context &ctx);
  void RemoveSystems();
  virtual ~SystemManager();
};
