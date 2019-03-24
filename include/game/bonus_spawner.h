#pragma once

#include <game/entities/bonuses/i_bonus_builder.h>
#include <game/utils/true_random.h>
#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>
#include <memory>
#include <vector>

class BonusSpawner {
  TrueRandom random;
  std::vector<std::unique_ptr<IBonusBuilder>> builders;
 public:
  BonusSpawner();
  void spawn(EntityManager* em, const Vec2& pos);
};