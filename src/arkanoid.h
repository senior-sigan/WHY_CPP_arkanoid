#ifndef GAME_ARKANOID_H
#define GAME_ARKANOID_H

#include "platform.h"
#include "brick.h"
#include "ball.h"
#include <whycpp/application_listener.h>

class Arkanoid : public ApplicationListener {
  Platform *platform = nullptr;
  std::vector<Ball *> balls;
  std::vector<Brick *> bricks;

  RGBA* color = nullptr;

  bool paused = true;

  void Win();

  void Lose();

 public:
  void OnCreate(Context &ctx) override;

  void OnRender(Context &ctx) override;

  void HandlePause(Context &ctx);
};

#endif //GAME_ARKANOID_H
