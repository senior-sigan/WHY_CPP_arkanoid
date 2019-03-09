#include <ecs/engine.h>
#include <ecs/entity_manager.h>
#include <ecs/system_manager.h>

void Engine::Update(Context &ctx) {
  systemManager->Update(ctx);
}
Engine::Engine() : entityManager(std::make_shared<EntityManager>()),
                   systemManager(std::make_shared<SystemManager>(entityManager)) {}
std::shared_ptr<EntityManager> Engine::GetEntityManager() {
  return entityManager;
}
std::shared_ptr<SystemManager> Engine::GetSystemManager() {
  return systemManager;
}
