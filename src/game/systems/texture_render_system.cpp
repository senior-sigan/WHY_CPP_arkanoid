#include <ecs/entity.h>
#include <game/components/texture_component.h>
#include <game/components/transform_component.h>
#include <game/systems/texture_render_system.h>
#include <whycpp/drawing.h>

void TextureRenderSystem::Update(Context &ctx, std::shared_ptr<Entity> entity) {
  auto texture = entity->Get<TextureComponent>();
  auto transform = entity->Get<TransformComponent>();

  for (int x = 0; x < texture->width; x++) {
    for (int y = 0; y < texture->height; y++) {
      SetPixel(ctx, transform->position.x + x, transform->position.y + y, texture->Get(x, y));
    }
  }
}
bool TextureRenderSystem::Filter(std::shared_ptr<Entity> entity) const {
  return entity->Contains<TextureComponent>() && entity->Contains<TransformComponent>();
}
