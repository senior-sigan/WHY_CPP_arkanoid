#pragma once

#include <memory>

class Context;
class EntityManager;
class Entity;

class ISystem {
  friend class SystemManager;
  std::shared_ptr<EntityManager> entityManager;
 public:
  void Update(Context &ctx);
  virtual ~ISystem() = default;

 protected:
  virtual void OnUpdate(Context &ctx) {};
  virtual void Update(Context &ctx, std::shared_ptr<Entity> entity) {};
  virtual void OnPostUpdate(Context &ctx) {};
  virtual bool Filter(std::shared_ptr<Entity> entity) const;;
  std::shared_ptr<EntityManager> GetEntityManager();
};
