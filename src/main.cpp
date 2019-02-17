#include <iostream>
#include <whycpp/application_listener.h>
#include <whycpp/whycpp.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>
#include <cmath>
#include <vector>
#include <whycpp/color.h>
#include <whycpp/buttons.h>
#include <whycpp/input.h>
#include <whycpp/palette.h>
#include <vector>
#include <whycpp/lifecycle.h>
#include <algorithm>

struct Rectangle {
  float Left;
  float Right;
  float Top;
  float Bottom;

  Rectangle(float Left, float Right, float Top, float Bottom) : Left(Left), Right(Right), Top(Top), Bottom(Bottom) {}
};

bool IsInside(float value, float min, float max) {
  return value >= min && value <= max;
}

bool IsIntersect(const Rectangle &r1, const Rectangle &r2) {
  bool x = IsInside(r1.Left, r2.Left, r2.Right) || IsInside(r2.Left, r1.Left, r1.Right);
  bool y = IsInside(r1.Top, r2.Bottom, r2.Top) || IsInside(r2.Top, r1.Bottom, r1.Top);

  return x && y;
}

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

  void Draw(Context &ctx) {
    DrawRectFill(ctx, x, y, width, height, color);
  }

  void Move(Context &ctx) {
    if (IsPressed(ctx, Button::KEY_LEFT) && x > 0) {
      x -= speed_x * GetDelta(ctx);
    }

    if (IsPressed(ctx, Button::KEY_RIGHT) && x < GetDisplayWidth(ctx) - width) {
      x += speed_x * GetDelta(ctx);
    }
  }
};

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

  void Draw(Context &ctx) {
    DrawRectFill(ctx, x + 1, y + 1, width - 2, height - 2, color);
  }

  Rectangle Rect() const {
    return {x, x + width, y + height, y};
  }

  void Damage() {
    hp--;
  }

  bool IsDestroyed() const {
    return hp <= 0;
  }
};

class Ball {
  bool shouldDestroy = false;

  void ApplyMovement(Context &ctx) {
    x += speed_x * GetDelta(ctx);
    y += speed_y * GetDelta(ctx);
  }
  void CheckDestroy(Context &ctx) {
    if (y > GetDisplayHeight(ctx)) {
      shouldDestroy = true;
    }
  }
  void CheckBorderCollisions(Context &ctx, float x_, float y_) {
    if (x_ < 0 || x_ > GetDisplayWidth(ctx)) {
      speed_x *= -1;
    }

    if (y_ < 0) {
      speed_y *= -1;
    }
  }
  void CheckPlatformCollision(Context &ctx, float x_, float y_) {
    Rectangle br = {x_, x_ + radius, y_ + radius, y_};
    Rectangle pr = {platform->x, platform->x + platform->width, platform->y + platform->height, platform->y};

    if (IsIntersect(br, pr)) {
      speed_y *= -1;
    }
  }
  void CheckBrickCollision(Context &ctx, float x_, float y_) {
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

  void Draw(Context &ctx) {
    DrawRectFill(ctx, x, y, radius, radius, color);
  }

  void Move(Context &ctx) {
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

  bool ShouldDestroy() const {
    return shouldDestroy;
  }
};

class Arkanoid : public ApplicationListener {
  Platform *platform = nullptr;
  std::vector<Ball *> balls;
  std::vector<Brick *> bricks;

  RGBA* color = nullptr;

  bool paused = true;

 public:
  void OnCreate(Context &ctx) override {
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
        RGBA color = PALETTE[i * j % PALETTE_LEN];
        bricks.push_back(new Brick(
            brick_width * i, brick_height * j, brick_width, brick_height, color
        ));
      }
    }
  }

  void OnRender(Context &ctx) override {
    if (color != nullptr) {
      DrawClearScreen(ctx, *color);
      return;
    }

    HandlePause(ctx);
    if (paused)
      return;
    DrawClearScreen(ctx, PALETTE[1]);
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

  void HandlePause(Context &ctx) {
    if (IsPressed(ctx, Button::KEY_SPACE) && paused) {
      paused = false;
    }
  }

  void Win() {
    color = new RGBA{0,255,0,0};
  }

  void Lose() {
    color = new RGBA{255,0,0,0};
  }
};

int main(int argc, char *argv[]) {
  RunApp<Arkanoid>({256, 144, "Arkanoid", false});

  return 0;
}