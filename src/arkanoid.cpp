#include <whycpp/text.h>
#include "arkanoid.h"

void Arkanoid::OnCreate(Context &ctx) {
  auto pw = 48;
  platform = new Platform((GetDisplayWidth(ctx) - pw) / 2, GetDisplayHeight(ctx) - 10, pw, 6, 300);

  auto br = 4;
  auto ball_speed = 120;
  balls.push_back(new Ball(platform->x + platform->width / 2 - br / 2 - 4,
                           platform->y - br,
                           br,
                           ball_speed,
                           platform,
                           bricks));
  balls.push_back(new Ball(10 + platform->x + platform->width / 2 - br / 2,
                           platform->y - br,
                           br,
                           ball_speed,
                           platform,
                           bricks));
  balls.push_back(new Ball(-10 + platform->x + platform->width / 2 - br / 2,
                           platform->y - br,
                           br,
                           ball_speed,
                           platform,
                           bricks));
  balls.push_back(new Ball(-20 + platform->x + platform->width / 2 - br / 2,
                           platform->y - br,
                           br,
                           ball_speed,
                           platform,
                           bricks));
  balls.push_back(new Ball(20 + platform->x + platform->width / 2 - br / 2,
                           platform->y - br,
                           br,
                           ball_speed,
                           platform,
                           bricks));

  auto brick_width = 16;
  auto brick_height = 8;
  for (int i = 1; i < 15; i++) {
    for (int j = 1; j < 4; j++) {
      RGBA color = PALETTE[i * j % (PALETTE_LEN-1) + 1];
      bricks.push_back(new Brick(
          brick_width * i, brick_height * j, brick_width, brick_height, color
      ));
    }
  }
}
void Arkanoid::OnRender(Context &ctx) {
  if (color != nullptr) {
    DrawClearScreen(ctx, *color);
    return;
  }

  HandlePause(ctx);
  if (paused) {
    Print(ctx, "Press Space", GetDisplayWidth(ctx)/2 - 30, GetDisplayHeight(ctx) / 2 - 4, PALETTE[3]);
    return;
  }
  DrawClearScreen(ctx, PALETTE[0]);
  platform->Draw(ctx);
  platform->Move(ctx);

  auto aliveBalls = 0;
  for (auto &ball: balls) {
    if (ball->ShouldDestroy()) continue; // TODO: remove ball
    ball->Draw(ctx);
    ball->Move(ctx);
    aliveBalls++;
  }

  for (auto &brick: bricks) {
    if (brick->IsDestroyed()) continue;
    brick->Draw(ctx);
  }

  auto not_destroyed = std::count_if(bricks.begin(), bricks.end(), [](const Brick *b) { return !b->IsDestroyed(); });
  if (not_destroyed < 1) {
    Win();
  }

  if (aliveBalls == 0) {
    Lose();
  }
}
void Arkanoid::HandlePause(Context &ctx) {
  if (IsPressed(ctx, Button::KEY_SPACE) && paused) {
    paused = false;
  }
}
void Arkanoid::Win() {
  color = new RGBA{0,255,0,0};
}
void Arkanoid::Lose() {
  color = new RGBA{255,0,0,0};
}
