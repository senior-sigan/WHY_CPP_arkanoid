#include <game/components/brick_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>
#include <whycpp/palette.h>

void CreateBrick(EntityManager *entityManager, const Vec2 &pos, const Vec2 &size) {
  auto brick = entityManager->CreateEntity();
  brick->SetTag("brick");
  brick->Add<TransformComponent>(pos);
  brick->Add<RectangleRenderComponent>(size, PALETTE[15]);
  brick->Add<RectColliderComponent>(size);
  brick->Add<BrickComponent>();
}