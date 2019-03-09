#pragma once

#include <ecs/entity_manager.h>
#include <ecs/system_manager.h>
#include <memory>
#include <vector>

class Context;

class Engine {
 private:
  std::unique_ptr<EntityManager> entityManager;
  std::unique_ptr<SystemManager> systemManager;

 public:
  explicit Engine();
  void Update(Context& ctx);
  EntityManager* GetEntityManager();
  SystemManager* GetSystemManager();
};
