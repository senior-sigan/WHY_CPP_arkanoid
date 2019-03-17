#pragma once

#include <game/levels/i_level_creator.h>

class Lvl3Creator : public ILevelCreator {
  void InitSystems();
  void InitEntities();
  void CreateBricks();
  void CreateBorders();

 public:
  Lvl3Creator(Engine *engine, Context &ctx, SceneManager *scene_manager);
  void Init() override;
  void Dispose() override;
};