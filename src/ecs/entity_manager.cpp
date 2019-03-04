#include <ecs/entity_manager.h>
Entity &EntityManager::CreateEntity() {
  auto& entity = entities.emplace_back();
  entity.id = ++last_entity_id;
  return entity;
}
