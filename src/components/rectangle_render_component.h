#ifndef GAME_RECTANGLE_RENDER_COMPONENT_H
#define GAME_RECTANGLE_RENDER_COMPONENT_H

#include "../ECS/i_component.h"
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

#endif //GAME_RECTANGLE_RENDER_COMPONENT_H
