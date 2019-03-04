#include <ecs/entity_manager.h>
void EntityManager::ForEach(const std::function<void(Entity &)> &block) {
  for (auto &entity : entities) {
    block(entity);
  }
}
Entity &EntityManager::CreateEntity() {
  entities.emplace_back();
  return *(entities.end() - 1);
}
