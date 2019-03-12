#pragma once

#include <lib/ecs/i_component.h>
#include <lib/matlib/vec2.h>

class RigidBodyComponent : public IComponent {
 public:
  double mass = 1.0;
  bool is_kinematic = true;
};