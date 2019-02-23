#include "platform.h"
void Platform::Draw(Context &ctx) {
  DrawRectFill(ctx, x, y, width, height, color);
}
void Platform::Move(Context &ctx) {
  if (IsPressed(ctx, Button::KEY_LEFT) && x > 0) {
    x -= speed_x * GetDelta(ctx);
  }

  if (IsPressed(ctx, Button::KEY_RIGHT) && x < GetDisplayWidth(ctx) - width) {
    x += speed_x * GetDelta(ctx);
  }
}
