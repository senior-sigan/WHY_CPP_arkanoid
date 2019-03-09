#include <ecs/entity.h>
#include <ecs/entity_manager.h>
#include <algorithm>
#include <memory>

std::shared_ptr<Entity> EntityManager::CreateEntity() {
  auto entity = std::make_shared<Entity>();
  entity->id = ++last_entity_id;
  entities.push_back(entity);
  return entity;
}
void EntityManager::DeleteEntity(size_t id) {
  auto iter = std::remove_if(entities.begin(), entities.end(),
                             [id](const std::shared_ptr<Entity> entity) { return entity->GetId() == id; });
  entities.erase(iter, entities.end());
}
EntityManager::~EntityManager() {
  entities.clear();
}
void EntityManager::RemoveEntities() {
  entities.clear();
}
