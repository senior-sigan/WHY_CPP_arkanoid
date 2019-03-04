#include <ecs/engine.h>

void Engine::Update(Context &ctx) {
  for (auto &system : systems) {
    system->Update(ctx, entityManager);
  }
}
