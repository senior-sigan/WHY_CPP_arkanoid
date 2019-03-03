#include <whycpp/drawing.h>
#include "rectangle_render_system.h"
#include "../components/rectangle_render_component.h"
#include "../components/transform_component.h"

void RectangleRenderSystem::Update(Context &ctx, Entity &entity) {
  auto rect = entity.Get<RectangleRenderComponent>();
  auto transform = entity.Get<TransformComponent>();

  if (rect->filled) {
    DrawRectFill(ctx, transform->position.x, transform->position.y, rect->width, rect->height, rect->color);
  } else {
    DrawRect(ctx, transform->position.x, transform->position.y, rect->width, rect->height, rect->color);
  }
}
bool RectangleRenderSystem::Filter(const Entity &entity) const {
  return entity.Contains<RectangleRenderComponent>() && entity.Contains<TransformComponent>();
}
