#pragma once

#include <lib/ecs/engine.h>
#include <lib/scene_manager.h>

class ILevelCreator {
 protected:
  Engine* engine;
  Context& ctx;
  SceneManager* scene_manager_;
 public:
  ILevelCreator(Engine* engine, Context& ctx, SceneManager* scene_manager)
      : engine(engine), ctx(ctx), scene_manager_(scene_manager) {}
  virtual ~ILevelCreator() = default;

  virtual void Init() = 0;
  virtual void Dispose() = 0;
};