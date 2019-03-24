#include <game/components/brick_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/components/transform_component.h>
#include <lib/ecs/entity_manager.h>
#include <lib/matlib/vec2.h>
#include <whycpp/palette.h>

RGBA GetColorForHp(int hp) {
  if (hp == 1) {
    return RGBA{255, 204, 170, 255};
  } else if (hp == 2) {
    return RGBA{200, 160, 110, 255};
  } else {
    return RGBA{131, 118, 156, 255};
  }
}

void CreateBrick(EntityManager *entity_manager, const Vec2 &pos, const Vec2 &size, int hp) {
  auto brick = entity_manager->CreateEntity();
  brick->SetTag("brick");
  brick->Add<TransformComponent>(pos);
  brick->Add<RectangleRenderComponent>(size, GetColorForHp(hp));
  brick->Add<RectColliderComponent>(size);
  brick->Add<BrickComponent>(hp);
}