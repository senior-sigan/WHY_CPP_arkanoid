#include <lib/ecs/entity_manager.h>
#include <lib/ecs/i_system.h>

void ISystem::Update(Context& ctx) {
  OnUpdate(ctx);
  entityManager->ForEach([this, &ctx](Entity* entity) {
    if (Filter(entity)) Update(ctx, entity);
  });
  OnPostUpdate(ctx);
}
bool ISystem::Filter(Entity* entity) const {
  return true;
}
EntityManager* ISystem::GetEntityManager() {
  return entityManager;
}
