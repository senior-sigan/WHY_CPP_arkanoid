#pragma once

#include <lib/scene_manager.h>
#include <whycpp/application_listener.h>
#include <memory>
#include "fps_logger.h"

class ArkanoidECS : public ApplicationListener {
  SceneManager scene_manager{};
  FpsLogger fps_;

 public:
  void OnCreate(Context &ctx) override;
  void OnRender(Context &ctx) override;
  void OnDispose(Context &ctx) override;
};