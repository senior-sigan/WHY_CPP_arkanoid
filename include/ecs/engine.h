#pragma once

#include <memory>
#include <vector>

class EntityManager;
class SystemManager;
class Context;

class Engine {
 private:
  std::shared_ptr<EntityManager> entityManager;
  std::shared_ptr<SystemManager> systemManager;

 public:
  explicit Engine();
  void Update(Context &ctx);
  std::shared_ptr<EntityManager> GetEntityManager();
  std::shared_ptr<SystemManager> GetSystemManager();
};
