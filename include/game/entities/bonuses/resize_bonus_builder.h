#pragma once

#include <game/utils/true_random.h>
#include "i_bonus_builder.h"
class ResizeBonusBuilder: public IBonusBuilder {
  TrueRandom random;
 public:
  void build(EntityManager* entity_manager, const Vec2& pos) override;
};


