#pragma once

#include <game/levels/i_level_creator.h>
#include <game/scenes/ecs_scene.h>
#include <game/scenes/game_scene.h>
#include <lib/matlib/vec2.h>
#include <whycpp/drawing.h>
#include <whycpp/palette.h>
#include <memory>

class ILevelCreator;

template<typename LevelCreator>
class GameScene : public ECSScene {
  std::unique_ptr<ILevelCreator> level_creator_;

 public:
  explicit GameScene(Context& ctx) : ECSScene(ctx) {
    level_creator_ = std::make_unique<LevelCreator>(engine.get(), ctx, GetSceneManager());
  }

  void OnCreate() override {
    level_creator_->Init();
  }
  void OnUpdate() override {
    DrawClearScreen(ctx, PALETTE[1]);
    engine->Update(ctx);
  }
  void OnDispose() override {
    level_creator_->Dispose();
  }

  ~GameScene() override = default;
};