#include <game/arkanoid_ecs.h>
#include <game/levels/lvl_1_creator.h>
#include <game/levels/lvl_2_creator.h>
#include <game/levels/lvl_3_creator.h>
#include <game/levels/lvl_4_creator.h>
#include <game/scenes/fail_scene.h>
#include <game/scenes/game_scene.h>
#include <game/scenes/next_level_scene.h>
#include <game/scenes/title_scene.h>
#include <game/scenes/win_scene.h>
#include <lib/ecs/engine.h>

using namespace std;

void ArkanoidECS::OnCreate(Context &ctx) {
  scene_manager.Add<TitleScene>("title", ctx);
  scene_manager.Add<GameScene<Lvl1Creator>>("lvl1", ctx);
  scene_manager.Add<NextLevelScene>("next_level_2", ctx);
  scene_manager.Add<GameScene<Lvl2Creator>>("lvl2", ctx);
  scene_manager.Add<NextLevelScene>("next_level_3", ctx);
  scene_manager.Add<GameScene<Lvl3Creator>>("lvl3", ctx);
  scene_manager.Add<NextLevelScene>("next_level_4", ctx);
  scene_manager.Add<GameScene<Lvl4Creator>>("lvl4", ctx);
  scene_manager.Add<WinScene>("game_win", ctx);
  scene_manager.Add<FailScene>("game_over", ctx);
  scene_manager.SetScene(0);
}
void ArkanoidECS::OnRender(Context &ctx) {
  scene_manager.OnUpdate();
}
void ArkanoidECS::OnDispose(Context &ctx) {
  scene_manager.OnDispose();
}
