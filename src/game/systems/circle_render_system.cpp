#include <game/components/circle_render_component.h>
#include <game/components/transform_component.h>
#include <game/systems/circle_render_system.h>
#include <lib/ecs/entity.h>
#include <whycpp/drawing.h>

void CircleRenderSystem::Update(Context& ctx, Entity* entity) {
  auto obj = entity->Get<CircleRenderComponent>();
  auto transform = entity->Get<TransformComponent>();

  if (obj->filled) {
    DrawCircleFill(ctx, transform->position.x, transform->position.y, obj->radius, obj->color);
  } else {
    DrawCircleFill(ctx, transform->position.x, transform->position.y, obj->radius, obj->color);
  }
}
bool CircleRenderSystem::Filter(Entity* entity) const {
  return entity->Contains<CircleRenderComponent>() && entity->Contains<TransformComponent>();
}
