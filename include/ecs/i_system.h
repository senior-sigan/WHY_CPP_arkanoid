#pragma once

#include <memory>

class Context;
class EntityManager;
class Entity;

class ISystem {
  friend class SystemManager;
  EntityManager* entityManager{};

 public:
  void Update(Context &ctx);
  virtual ~ISystem() = default;

 protected:
  virtual void OnUpdate(Context &ctx){};
  virtual void Update(Context &ctx, Entity* entity){};
  virtual void OnPostUpdate(Context &ctx){};
  virtual bool Filter(Entity* entity) const;

  EntityManager* GetEntityManager();
};
