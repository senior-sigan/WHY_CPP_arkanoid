#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>

class MultiBallBonusComponent : public IComponent {
 public:
  int multiplier_;

  MultiBallBonusComponent(int multiplier) : multiplier_(multiplier) {}
};