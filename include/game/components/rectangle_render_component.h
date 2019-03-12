#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>
#include <whycpp/color.h>

class RectangleRenderComponent : public IComponent {
 public:
  Vec2 size;
  RGBA color;
  bool filled;

  explicit RectangleRenderComponent(const Vec2& size, const RGBA& color, bool filled = true)
      : size(size), color(color), filled(filled) {}
};
