#include "brick.h"
void Brick::Draw(Context &ctx) {
  DrawRectFill(ctx, x + 1, y + 1, width - 2, height - 2, color);
}
Rectangle Brick::Rect() const {
  return {x, x + width, y + height, y};
}
void Brick::Damage() {
  hp--;
}
bool Brick::IsDestroyed() const {
  return hp <= 0;
}
