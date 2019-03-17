#include <game/scenes/next_level_scene.h>
#include <lib/scene_manager.h>
#include <whycpp/drawing.h>
#include <whycpp/input.h>
#include <whycpp/palette.h>
#include <whycpp/text.h>

void NextLevelScene::OnCreate() {}
void NextLevelScene::OnUpdate() {
  DrawClearScreen(ctx, PALETTE[3]);
  auto x = 1;
  auto y = GetDisplayHeight(ctx) / 2;
  Print(ctx, "NEXT LEVEL\nSPACE TO START", x, y, PALETTE[7], 2);

  if (IsClicked(ctx, Button::KEY_SPACE) || IsClicked(ctx, Button::MOUSE_BUTTON_LEFT)) {
    GetSceneManager()->NextScene();
  }
}
void NextLevelScene::OnDispose() {}
NextLevelScene::NextLevelScene(Context& ctx) : ECSScene(ctx) {}
