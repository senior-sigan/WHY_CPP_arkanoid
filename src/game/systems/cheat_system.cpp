#include <game/systems/cheat_system.h>
#include <whycpp/input.h>

CheatSystem::CheatSystem(SceneManager* scene_manager) : scene_manager_(scene_manager) {}
void CheatSystem::OnUpdate(Context& ctx) {
  if (IsPressed(ctx, Button::KEY_ESCAPE)) {
    scene_manager_->NextScene();
  }
}
bool CheatSystem::Filter(Entity* entity) const {
  return true;
}
