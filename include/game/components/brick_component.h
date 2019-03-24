#pragma once

#include <lib/ecs/i_component.h>

class BrickComponent : public IComponent {
 public:
  int hp;

  explicit BrickComponent(int hp = 1) : hp(hp) {}
};