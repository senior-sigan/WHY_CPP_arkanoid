#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>

class MultiBallBonusComponent: public IComponent {
 public:
  int multiplier_;
  Vec2 pos;

  MultiBallBonusComponent(int multiplier, const Vec2& pos) : multiplier_(multiplier), pos(pos) {}
};