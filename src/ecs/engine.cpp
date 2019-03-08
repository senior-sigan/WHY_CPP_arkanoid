#include <ecs/engine.h>

void Engine::Update(Context &ctx) {
  for (auto &system : systems) {
    system->Update(ctx);
  }
}
Engine::Engine() : entityManager(std::make_shared<EntityManager>()) {}
Engine::~Engine() {
  RemoveEntities();
  RemoveSystems();
}
