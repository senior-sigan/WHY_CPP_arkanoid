#pragma once

#include <lib/scene_manager.h>
#include <whycpp/application_listener.h>
#include <memory>

class ArkanoidECS : public ApplicationListener {
  SceneManager scene_manager{};

 public:
  void OnCreate(Context &ctx) override;
  void OnRender(Context &ctx) override;
  void OnDispose(Context &ctx) override;
};