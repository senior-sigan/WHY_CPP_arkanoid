#ifndef GAME_BRICK_H
#define GAME_BRICK_H

#include <whycpp/color.h>
#include <whycpp/application_listener.h>
#include <whycpp/drawing.h>
#include "rectangle.h"

class Brick {
  float x;
  float y;
  float width;
  float height;
  const RGBA color;
  int hp = 1;

 public:
  Brick(float x, float y, float width, float height, const RGBA &color)
      : x(x), y(y), width(width), height(height), color(color) {}

  void Draw(Context &ctx);

  Rectangle Rect() const;

  void Damage();

  bool IsDestroyed() const;
};

#endif //GAME_BRICK_H
