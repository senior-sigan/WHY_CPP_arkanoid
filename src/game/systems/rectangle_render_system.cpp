#include <ecs/entity.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <game/systems/rectangle_render_system.h>
#include <whycpp/drawing.h>

void RectangleRenderSystem::Update(Context &ctx, Entity* entity) {
  auto rect = entity->Get<RectangleRenderComponent>();
  auto transform = entity->Get<TransformComponent>();

  if (rect->filled) {
    DrawRectFill(ctx, transform->position.x, transform->position.y, rect->size.x, rect->size.y, rect->color);
  } else {
    DrawRect(ctx, transform->position.x, transform->position.y, rect->size.x, rect->size.y, rect->color);
  }
}
bool RectangleRenderSystem::Filter(Entity* entity) const {
  return entity->Contains<RectangleRenderComponent>() && entity->Contains<TransformComponent>();
}
