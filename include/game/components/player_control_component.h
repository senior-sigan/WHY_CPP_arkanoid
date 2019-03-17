#pragma once

#include <lib/ecs/i_component.h>
#include <whycpp/buttons.h>

class PlayerControlComponent : public IComponent {
 public:
  double border_size = 6;

  Button left = Button::KEY_LEFT;
  Button right = Button::KEY_RIGHT;

  Button mouse = Button::MOUSE_BUTTON_LEFT;
};