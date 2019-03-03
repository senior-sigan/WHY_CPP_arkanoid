#ifndef GAME_PLAYER_CONTROL_COMPONENT_H
#define GAME_PLAYER_CONTROL_COMPONENT_H

#include <whycpp/buttons.h>
#include "../ECS/i_component.h"
class PlayerControlComponent : public IComponent {
 public:
  Button left = Button::KEY_LEFT;
  Button right = Button::KEY_RIGHT;
};

#endif //GAME_PLAYER_CONTROL_COMPONENT_H
