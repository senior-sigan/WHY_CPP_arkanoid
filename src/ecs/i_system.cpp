#include <ecs/entity_manager.h>
#include <ecs/i_system.h>

void ISystem::Update(Context &ctx, EntityManager &manager) {
  manager.ForEach([this, &ctx](Entity &entity) {
    if (Filter(entity)) Update(ctx, entity);
  });
}
