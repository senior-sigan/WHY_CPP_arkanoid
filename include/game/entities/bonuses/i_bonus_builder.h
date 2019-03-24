#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>

class IBonusBuilder {
 public:
  virtual void build(EntityManager* entity_manager, const Vec2& pos) = 0;
  virtual ~IBonusBuilder() = default;
};