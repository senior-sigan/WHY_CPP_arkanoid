#include <game/scenes/ecs_scene.h>

ECSScene::ECSScene(Context& ctx) : engine(std::make_unique<Engine>()), ctx(ctx) {}
