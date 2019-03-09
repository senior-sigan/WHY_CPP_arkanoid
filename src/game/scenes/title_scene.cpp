#include <game/scenes/title_scene.h>
#include <lib/scene_manager.h>
#include <whycpp/drawing.h>
#include <whycpp/input.h>
#include <whycpp/palette.h>
#include <whycpp/text.h>

TitleScene::TitleScene(Context &ctx) : ctx(ctx) {}
void TitleScene::OnCreate() {}
void TitleScene::OnUpdate() {
  DrawClearScreen(ctx, PALETTE[0]);
  Print(ctx, "ARKANOID", 1, 1, PALETTE[7], 3);
  auto x = 1;
  auto y = GetDisplayHeight(ctx) / 2;
  Print(ctx, "PRESS SPACE\nTO START", x, y, PALETTE[6], 2);

  if (IsClicked(ctx, Button::KEY_SPACE)) {
    GetSceneManager()->SetScene(1);
  }
}
void TitleScene::OnDispose() {}
