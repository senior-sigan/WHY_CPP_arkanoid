#pragma once

#include <whycpp/application_listener.h>
#include <ecs/engine.h>

class ArkanoidECS: public ApplicationListener {
  Engine engine;
 public:
  void OnCreate(Context &ctx) override;
  void OnRender(Context &ctx) override;
};