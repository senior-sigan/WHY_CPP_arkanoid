#include <ecs/entity_manager.h>
#include <memory>

std::shared_ptr<Entity> EntityManager::CreateEntity() {
  auto entity = std::make_shared<Entity>();
  entity->id = ++last_entity_id;
  entities.push_back(entity);
  return entity;
}
