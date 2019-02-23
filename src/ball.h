#ifndef GAME_BALL_H
#define GAME_BALL_H

#include "rectangle.h"
#include "platform.h"
#include <vector>

class Brick;

class Ball {
  bool shouldDestroy = false;

  void ApplyMovement(Context &ctx);
  void CheckDestroy(Context &ctx);
  void CheckBorderCollisions(Context &ctx, float x_, float y_);
  void CheckPlatformCollision(Context &ctx, float x_, float y_);
  void CheckBrickCollision(Context &ctx, float x_, float y_);

 public:
  float x;
  float y;
  float radius;
  float speed_x;
  float speed_y;

  const Platform *platform;
  const std::vector<Brick *> &bricks;

  const RGBA color = PALETTE[4];

  Ball(float x,
       float y,
       float radius,
       float speed,
       const Platform *platform,
       const std::vector<Brick *> &bricks)
      : x(x), y(y), radius(radius), speed_x(speed), speed_y(speed), platform(platform), bricks(bricks) {}

  void Draw(Context &ctx);

  void Move(Context &ctx);

  bool ShouldDestroy() const {
    return shouldDestroy;
  }
};

#endif //GAME_BALL_H
