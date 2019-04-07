#include <game/entities/entities.h>
#include <game/levels/lvl_3_creator.h>
#include <lib/matlib/vec2.h>
#include <whycpp/drawing.h>

void Lvl3Creator::InitEntities() {
  auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
  auto platform_size = Vec2(42, 7);

  CreatePlatform(engine->GetEntityManager(), platform_pos, platform_size);
  CreateBall(engine->GetEntityManager(), platform_pos, platform_size);

  CreateBricks();
  CreateBorders();
  CreateMusic(engine->GetEntityManager(), "music3");
}

void Lvl3Creator::CreateBricks() {
  for (int i = 0; i < 13; i++) {
    for (int j = 1; j < 15; j += 2) {
      auto size = Vec2(15, 8);
      CreateBrick(engine->GetEntityManager(), Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size);
    }
  }
}
void Lvl3Creator::CreateBorders() {
  CreateBorder(engine->GetEntityManager(), Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0));  // top
  //  CreateBorder(engine, Vec2(GetDisplayWidth(ctx), 10), Vec2(0, GetDisplayHeight(ctx))); // bottom
  CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0));                         // left
  CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx) - 6, 0));  // right
}
Lvl3Creator::Lvl3Creator(Engine *engine, Context &ctx, SceneManager *scene_manager)
    : ILevelCreator(engine, ctx, scene_manager) {}
