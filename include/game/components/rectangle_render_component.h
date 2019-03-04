#pragma once

#include <ecs/i_component.h>
#include <whycpp/color.h>

class RectangleRenderComponent : public IComponent {
 public:
  int width;
  int height;
  RGBA color;
  bool filled;

  explicit RectangleRenderComponent(int width, int height, const RGBA &color, bool filled = true)
      : width(width), height(height), color(color), filled(filled) {}
};
