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

    if (IsPressed(ctx, Button::KEY_RIGHT) && x < GetDisplayWidth(ctx)-width) {
      x += speed_x * GetDelta(ctx);
    }
  }
};

class Ball {
 public:
  float x;
  float y;
  float radius;
  float speed_x;
  float speed_y;

  const Platform *platform;

  const RGBA color = PALETTE[4];

  Ball(float x, float y, float radius, float speed, const Platform *platform)
      : x(x), y(y), radius(radius), speed_x(speed), speed_y(speed), platform(platform) {}

  void Draw(Context &ctx) {
    DrawRectFill(ctx, x, y, radius, radius, color);
  }

  void Move(Context &ctx) {
    auto dx = speed_x * GetDelta(ctx);
    auto dy = speed_y * GetDelta(ctx);
    float x_ = x + dx;
    float y_ = y + dy;

    if (x_ < 0 || x_ > GetDisplayWidth(ctx)) {
      speed_x *= -1;
    }

    if (y_ < 0 || y_ > GetDisplayHeight(ctx)) {
      speed_y *= -1;
    }

    Rectangle br = {x_, x_ + radius, y_ + radius, y_};
    Rectangle pr = {platform->x, platform->x + platform->width, platform->y + platform->height, platform->y};

    if (IsIntersect(br, pr)) {
      speed_y *= -1;
    }

    x += speed_x * GetDelta(ctx);
    y += speed_y * GetDelta(ctx);

    // проверить что шарик внутри коробки
    // если качается коробки то должен отразиться под нужным углом
  }
};

class Arkanoid : public ApplicationListener {
  Platform *platform = nullptr;
  Ball *ball;

 public:
  void OnCreate(Context &ctx) override {
    auto pw = 48;
    platform = new Platform((GetDisplayWidth(ctx) - pw) / 2, GetDisplayHeight(ctx) - 10, pw, 6, 300);

    auto br = 4;
    ball = new Ball(platform->x + platform->width / 2 - br / 2, platform->y - br, br, 150, platform);
  }

  void OnRender(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[1]);
    platform->Draw(ctx);
    platform->Move(ctx);

    ball->Draw(ctx);
    ball->Move(ctx);
  }
};

int main(int argc, char *argv[]) {
  RunApp<Arkanoid>({256, 144, "Arkanoid", true});

  return 0;
}