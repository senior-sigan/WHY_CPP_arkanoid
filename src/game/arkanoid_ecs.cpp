#include <game/arkanoid_ecs.h>
#include <ecs/engine.h>
#include <game/scenes/fail_scene.h>
#include <game/scenes/game_scene.h>
#include <game/scenes/title_scene.h>
#include <game/scenes/win_scene.h>

using namespace std;

void ArkanoidECS::OnCreate(Context &ctx) {
  scene_manager.Add<TitleScene>(ctx);
  scene_manager.Add<GameScene>(ctx);
  scene_manager.Add<FailScene>(ctx);
  scene_manager.Add<WinScene>(ctx);
  scene_manager.SetScene(0);
}
void ArkanoidECS::OnRender(Context &ctx) {
  scene_manager.OnUpdate();
}
void ArkanoidECS::OnDispose(Context &ctx) {
  scene_manager.OnDispose();
}
