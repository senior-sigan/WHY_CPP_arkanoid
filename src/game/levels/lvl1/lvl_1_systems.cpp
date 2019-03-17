#include <game/levels/lvl_1_creator.h>

#include <lib/ecs/engine.h>
#include <game/scenes/game_scene.h>
#include <game/systems/ball_control_system.h>
#include <game/systems/bricks_system.h>
#include <game/systems/circle_render_system.h>
#include <game/systems/collision_system.h>
#include <game/systems/movement_system.h>
#include <game/systems/physics_system.h>
#include <game/systems/player_control_system.h>
#include <game/systems/rectangle_render_system.h>
#include <game/systems/resize_bonus_system.h>
#include <game/systems/shredder_system.h>
#include <game/systems/texture_render_system.h>
#include <lib/scene.h>

void Lvl1Creator::InitSystems() {
  engine->GetSystemManager()
      ->AddSystem<CollisionSystem>()
      ->AddSystem<PlayerControlSystem>()
      ->AddSystem<BallControlSystem>(scene_manager_)
      ->AddSystem<PhysicsSystem>()
      ->AddSystem<MovementSystem>()
      ->AddSystem<ShredderSystem>()
      ->AddSystem<ResizeBonusSystem>()
      ->AddSystem<BricksSystem>(scene_manager_)
      ->AddSystem<CircleRenderSystem>()
      ->AddSystem<TextureRenderSystem>()
      ->AddSystem<RectangleRenderSystem>();
}