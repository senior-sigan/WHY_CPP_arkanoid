#pragma once

#include <ecs/entity_manager.h>
#include <ecs/i_system.h>
#include <memory>
#include <vector>

class Engine {
 private:
  std::vector<std::shared_ptr<ISystem>> systems;
  EntityManager entityManager;

 public:
  void Update(Context &ctx);

  template<typename System, typename... Args>
  Engine &AddSystem(Args &&... args) {
    systems.push_back(std::make_shared<System>(std::forward<Args>(args)...));
    return *this;
  }

  EntityManager &GetEntityManager() {
    return entityManager;
  }
};
