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
  virtual void OnUpdate(Context &ctx) {};
  virtual void Update(Context &ctx, std::shared_ptr<Entity> entity) {};
  virtual void OnPostUpdate(Context &ctx) {};
  virtual bool Filter(std::shared_ptr<Entity> entity) const {
    return true;
  };
  std::shared_ptr<EntityManager> GetEntityManager() {
    return entityManager;
  }
};
