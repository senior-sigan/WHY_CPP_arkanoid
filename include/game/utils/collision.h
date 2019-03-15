#pragma once

#include <lib/ecs/entity.h>
#include <lib/matlib/manifold.h>

class Collision {
 public:
  Entity *entity;
  Manifold manifold;

  explicit Collision(Entity *entity, Manifold manifold) : entity(entity), manifold(std::move(manifold)) {}

  bool operator<(const Collision &rhs) const {
    return entity < rhs.entity;
  }
  bool operator>(const Collision &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Collision &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Collision &rhs) const {
    return !(*this < rhs);
  }
};