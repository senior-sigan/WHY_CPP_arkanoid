#include <lib/ecs/engine.h>

void Engine::Update(Context& ctx) {
  systemManager->Update(ctx);
}
Engine::Engine()
    : entityManager(std::make_unique<EntityManager>()), systemManager(std::make_unique<SystemManager>(entityManager.get())) {}

EntityManager* Engine::GetEntityManager() {
  return entityManager.get();
}
SystemManager* Engine::GetSystemManager() {
  return systemManager.get();
}
