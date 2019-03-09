#include <game/scenes/win_scene.h>
#include <lib/scene_manager.h>
#include <whycpp/buttons.h>
#include <whycpp/drawing.h>
#include <whycpp/input.h>
#include <whycpp/palette.h>
#include <whycpp/text.h>

void WinScene::OnCreate() {}
void WinScene::OnUpdate() {
  DrawClearScreen(ctx, PALETTE[11]);
  auto x = 1;
  auto y = GetDisplayHeight(ctx) / 2;
  Print(ctx, "!!WIN!!\nSPACE TO RESTART", x, y, PALETTE[0], 2);

  if (IsClicked(ctx, Button::KEY_SPACE)) {
    GetSceneManager()->SetScene(0);
  }
}
void WinScene::OnDispose() {}
