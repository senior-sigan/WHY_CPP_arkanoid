#include <lib/ecs/system_manager.h>
void SystemManager::Update(Context &ctx) {
  for (auto &system : systems) {
    system->Update(ctx);
  }
}
void SystemManager::RemoveSystems() {
  systems.clear();
}
SystemManager::~SystemManager() {
  systems.clear();
}
