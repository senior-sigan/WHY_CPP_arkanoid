#pragma once

#include <whycpp/buttons.h>
#include <ecs/i_component.h>

class PlayerControlComponent : public IComponent {
 public:
  Button left = Button::KEY_LEFT;
  Button right = Button::KEY_RIGHT;
};