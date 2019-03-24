#include <game/bonus_spawner.h>
#include <game/entities/bonuses/multi_ball_bonus_builder.h>
#include <game/entities/bonuses/resize_bonus_builder.h>
#include <lib/ecs/entity_manager.h>

#include <iostream>

BonusSpawner::BonusSpawner() {
  builders.push_back(std::make_unique<ResizeBonusBuilder>());
  builders.push_back(std::make_unique<MultiBallBonusBuilder>());
}
void BonusSpawner::spawn(EntityManager* em, const Vec2 &pos) {
  auto id = random.NextInt(-2, builders.size());
  std::cout << "Bonus " << id << std::endl;
  if (id < 0) return;

  builders.at(id)->build(em, pos);
}
