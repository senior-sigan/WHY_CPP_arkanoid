#ifndef GAME_RECTANGLE_H
#define GAME_RECTANGLE_H

struct Rectangle {
  float Left;
  float Right;
  float Top;
  float Bottom;

  Rectangle(float Left, float Right, float Top, float Bottom);
};

bool IsInside(float value, float min, float max);

bool IsIntersect(const Rectangle &r1, const Rectangle &r2);


#endif //GAME_RECTANGLE_H
