#include <game/entities/entities.h>
#include <game/levels/lvl_4_creator.h>
#include <lib/matlib/vec2.h>
#include <whycpp/drawing.h>

void Lvl4Creator::InitEntities() {
  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
  auto platform_size = Vec2(42, 7);

  CreatePlatform(engine->GetEntityManager(), platform_pos, platform_size);
  CreateBall(engine->GetEntityManager(), platform_pos, platform_size);

  CreateBricks();
  CreateBorders();
}

void Lvl4Creator::CreateBricks() {
  for (int i = 0; i < 13; i += 2) {
    for (int j = 1; j < 15; j++) {
      auto size = Vec2(15, 8);
      auto hp = 1;
      if (i % 3 == 0) {
        hp = 4;
      }
      CreateBrick(engine->GetEntityManager(), Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size, hp);
    }
  }
}
void Lvl4Creator::CreateBorders() {
  CreateBorder(engine->GetEntityManager(), Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0));  // top
  //  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0, GetDisplayHeight(ctx))); // bottom
  CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0));                         // left
  CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx) - 6, 0));  // right
}
Lvl4Creator::Lvl4Creator(Engine *engine, Context &ctx, SceneManager *scene_manager)
    : ILevelCreator(engine, ctx, scene_manager) {}
