#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "i_system.h"
#include <vector>
#include <memory>

class Engine {
 private:
  std::vector<std::shared_ptr<ISystem>> systems;
  EntityManager entityManager;

 public:
  void Update(Context &ctx) {
    for (auto &system: systems) {
      system->Update(ctx, entityManager);
    }
  }

  template<typename System, typename ...Args>
  Engine& AddSystem(Args &&...args) {
    systems.push_back(std::make_shared<System>(std::forward<Args>(args)...));
    return *this;
  }

  EntityManager &GetEntityManager() {
    return entityManager;
  }
};

#endif //GAME_ENGINE_H
