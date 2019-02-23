#include "rectangle.h"

bool IsInside(float value, float min, float max) {
  return value >= min && value <= max;
}

bool IsIntersect(const Rectangle &r1, const Rectangle &r2) {
  bool x = IsInside(r1.Left, r2.Left, r2.Right) || IsInside(r2.Left, r1.Left, r1.Right);
  bool y = IsInside(r1.Top, r2.Bottom, r2.Top) || IsInside(r2.Top, r1.Bottom, r1.Top);

  return x && y;
}

Rectangle::Rectangle(float Left, float Right, float Top, float Bottom) : Left(Left), Right(Right), Top(Top), Bottom(Bottom) {}
