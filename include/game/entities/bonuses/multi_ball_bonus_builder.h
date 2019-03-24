#pragma once

#include "i_bonus_builder.h"
class MultiBallBonusBuilder : public IBonusBuilder {
 public:
  void build(EntityManager* entity_manager, const Vec2& pos) override;
};
