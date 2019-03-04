#pragma once

class Context;
class EntityManager;
class Entity;

class ISystem {
 public:
  void Update(Context &ctx, EntityManager &manager);
  virtual ~ISystem() = default;

 protected:
  virtual void Update(Context &ctx, Entity &entity) = 0;
  virtual bool Filter(const Entity &entity) const = 0;
};
