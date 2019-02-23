#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H

#include <whycpp/color.h>
#include <whycpp/palette.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>
#include <whycpp/buttons.h>
#include <whycpp/input.h>

class Platform {
 public:
  float x;
  float y;
  float width;
  float height;
  float speed_x;
  const RGBA color = PALETTE[10];

  Platform(float x, float y, float width, float height, float speed_x)
      : x(x), y(y), width(width), height(height), speed_x(speed_x) {}

  void Draw(Context &ctx);

  void Move(Context &ctx);
};

#endif //GAME_PLATFORM_H
