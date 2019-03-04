#ifndef GAME_ARKANOID_ECS_H
#define GAME_ARKANOID_ECS_H

#include <whycpp/application_listener.h>
#include <ecs/engine.h>

class ArkanoidECS: public ApplicationListener {
  Engine engine;
 public:
  void OnCreate(Context &ctx) override;
  void OnRender(Context &ctx) override;
};

#endif //GAME_ARKANOID_ECS_H
