#include "ball.h"
#include "brick.h"

void Ball::ApplyMovement(Context &ctx) {
  x += speed_x * GetDelta(ctx);
  y += speed_y * GetDelta(ctx);
}
void Ball::CheckDestroy(Context &ctx) {
  if (y > GetDisplayHeight(ctx)) {
    shouldDestroy = true;
  }
}
void Ball::CheckBorderCollisions(Context &ctx, float x_, float y_) {
  if (x_ < 0 || x_ > GetDisplayWidth(ctx)) {
    speed_x *= -1;
  }

  if (y_ < 0) {
    speed_y *= -1;
  }
}
void Ball::CheckPlatformCollision(Context &ctx, float x_, float y_) {
  Rectangle br = {x_, x_ + radius, y_ + radius, y_};
  Rectangle pr = {platform->x, platform->x + platform->width, platform->y + platform->height, platform->y};

  if (IsIntersect(br, pr)) {
    speed_y *= -1;
  }
}
void Ball::CheckBrickCollision(Context &ctx, float x_, float y_) {
  for (auto &brick: bricks) {
    if (brick->IsDestroyed()) continue;
    Rectangle ball_rect = {x_, x_ + radius, y_ + radius, y_};
    auto brick_rect = brick->Rect();
    if (IsIntersect(ball_rect, brick_rect)) {
      brick->Damage();
      speed_y *= -1; // TODO: smart collisions between rectangles.
    }
  }
}
void Ball::Draw(Context &ctx) {
  DrawRectFill(ctx, x, y, radius, radius, color);
}
void Ball::Move(Context &ctx) {
  auto dx = speed_x * GetDelta(ctx);
  auto dy = speed_y * GetDelta(ctx);
  float x_ = x + dx;
  float y_ = y + dy;

  CheckBorderCollisions(ctx, x_, y_);
  CheckPlatformCollision(ctx, x_, y_);
  CheckBrickCollision(ctx, x_, y_);
  ApplyMovement(ctx);
  CheckDestroy(ctx);
}
