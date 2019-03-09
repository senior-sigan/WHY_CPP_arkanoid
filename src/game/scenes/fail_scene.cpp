#include <game/scenes/fail_scene.h>
#include <whycpp/palette.h>
#include <whycpp/drawing.h>
#include <whycpp/text.h>
#include <whycpp/buttons.h>
#include <whycpp/input.h>
#include <lib/scene_manager.h>

void FailScene::OnCreate() {

}
void FailScene::OnUpdate() {
  DrawClearScreen(ctx, PALETTE[8]);
  auto x = 1;
  auto y = GetDisplayHeight(ctx) / 2;
  Print(ctx, "GAME OVER\nSPACE TO RESTART", x, y, PALETTE[7], 2);

  if (IsClicked(ctx, Button::KEY_SPACE)) {
    GetSceneManager()->SetScene(0);
  }
}
void FailScene::OnDispose() {

}