#pragma once

#include <ecs/entity.h>

class Context;
class EntityManager;

class ISystem {
  friend class Engine;
  std::shared_ptr<EntityManager> entityManager;
 public:
  void Update(Context &ctx);
  virtual ~ISystem() = default;

 protected:
  virtual void Update(Context &ctx, Entity &entity) = 0;
  virtual bool Filter(const Entity &entity) const = 0;
  std::shared_ptr<EntityManager> GetEntityManager() {
    return entityManager;
  }
};
