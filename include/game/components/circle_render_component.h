#pragma once

#include <lib/ecs/i_component.h>
#include <whycpp/color.h>
class CircleRenderComponent : public IComponent {
 public:
  int radius;
  RGBA color;
  bool filled;

  CircleRenderComponent(int radius, const RGBA &color, bool filled = true)
      : radius(radius), color(color), filled(filled) {}
};