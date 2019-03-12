#pragma once

#include <lib/ecs/i_component.h>
#include <string>

class Entity;

class ResizeBonusComponent: public IComponent {
 public:
  double power;

  explicit ResizeBonusComponent(double power) : power(power) {}
};