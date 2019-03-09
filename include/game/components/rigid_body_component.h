#pragma once

#include <ecs/i_component.h>
#include <matlib/vec2.h>

class RigidBodyComponent : public IComponent {
 public:
  double mass = 1.0;
  bool is_kinematic = true;
};