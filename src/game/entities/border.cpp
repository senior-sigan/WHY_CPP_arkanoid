#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>
#include <whycpp/palette.h>

void CreateBorder(EntityManager *entity_manager, const Vec2 &size, const Vec2 &pos) {
  auto border = entity_manager->CreateEntity();
  border->Add<TransformComponent>(pos);
  border->Add<RectangleRenderComponent>(size, PALETTE[13]);
  border->Add<RectColliderComponent>(size);
}