#pragma once

#include "i_bonus_builder.h"
class UpResizeBonusBuilder : public IBonusBuilder {
 public:
  void build(EntityManager* entity_manager, const Vec2& pos) override;
};