#pragma once

#include <ostream>
#include <cmath>

class Vec2 {
 public:
  double x;
  double y;

  constexpr Vec2() noexcept: x(0.0), y(0.0) {}
  constexpr Vec2(double x, double y) noexcept: x(x), y(y) {}

  bool operator==(const Vec2 &rhs) const {
    return std::tie(x, y) == std::tie(rhs.x, rhs.y);
  }
  bool operator!=(const Vec2 &rhs) const {
    return !(rhs == *this);
  }

  Vec2 operator+(const Vec2 &rhs) const {
    return Vec2(x + rhs.x, y + rhs.y);
  }

  Vec2 operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Vec2 operator-(const Vec2 &rhs) const {
    return Vec2(x - rhs.x, y - rhs.y);
  }

  Vec2 operator*(double c) const {
    return Vec2(x * c, y * c);
  }

  Vec2 operator*=(double c) {
    x *= c;
    y *= c;
    return *this;
  }

  Vec2 operator*(const Vec2 &rhs) const {
    return Vec2(x * rhs.x, y * rhs.y);
  }

  Vec2 operator*=(const Vec2 &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  double DotProd(const Vec2 &rhs) const {
    return x * rhs.x + y * rhs.y;
  }

  double CrossProd(const Vec2 &rhs) const {
    return x * rhs.y - y * rhs.x;
  }

  Vec2 Abs() const {
    return Vec2(std::abs(x), std::abs(y));
  }

  /**
   * Euclidean L2 norm, Length of the vector.
   */
  double Magnitude() const {
    return std::sqrt(x * x + y * y);
  }

  void Normalize() {
    auto m = Magnitude();
    if (m <= 0.000000001)
      return;
    x /= m;
    y /= m;
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

double Distance(const Vec2 &lhs, const Vec2 &rhs);