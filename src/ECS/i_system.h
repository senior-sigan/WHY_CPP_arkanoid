#ifndef GAME_ISYSTEM_H
#define GAME_ISYSTEM_H

#include "entity_manager.h"
class Context;

class ISystem {
 public:
  void Update(Context &ctx, EntityManager &manager) {
    manager.ForEach([this, &ctx](Entity& entity) {
      if (Filter(entity)) Update(ctx, entity);
    });
  }
  virtual ~ISystem() = default;
 protected:
  virtual void Update(Context &ctx, Entity &entity) = 0;
  virtual bool Filter(const Entity &entity) const = 0;
};

#endif //GAME_ISYSTEM_H
