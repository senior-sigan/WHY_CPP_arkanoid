#pragma once

#include <ostream>
class Vec2 {
 public:
  int x;
  int y;

  constexpr Vec2(int x, int y) noexcept: x(x), y(y) {}

  bool operator<(const Vec2 &rhs) const {
    return std::tie(x, y) < std::tie(rhs.x, rhs.y);
  }
  bool operator>(const Vec2 &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Vec2 &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Vec2 &rhs) const {
    return !(*this < rhs);
  }
  friend std::ostream &operator<<(std::ostream &os, const Vec2 &vec2) {
    os << "x: " << vec2.x << " y: " << vec2.y;
    return os;
  }
};

const Vec2 ZeroVec2(0, 0);
const Vec2 UpVec2(0, -1);
const Vec2 DownVec2(0, 1);
const Vec2 RightVec2(1, 0);
const Vec2 LeftVec2(-1, 0);