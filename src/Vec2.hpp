#pragma once

class Vec2 {
public:
  double x, y;

  Vec2() : x(0), y(0) {}
  Vec2(double _x, double _y) : x(_x), y(_y) {}
  Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
  Vec2(Vec2 &&o) noexcept : x(0), y(0) { *this = std::move(o); }
  Vec2 &operator=(Vec2 &&o) noexcept {
    if (this != &o) {
      x = std::move(o.x);
      y = std::move(o.y);
      return *this;
    }
    return *this;
  }
  Vec2 operator+(const Vec2 &right) const {
    return Vec2(x + right.x, y + right.y);
  }
  Vec2 operator-(const Vec2 &right) const {
    return Vec2(x - right.x, y - right.y);
  }
  template <typename T> Vec2 operator*(const T &right) const {
    return Vec2(x * right, y * right);
  }
  template <typename T> Vec2 operator/(const T &right) const {
    return Vec2(x / right, y / right);
  }
};