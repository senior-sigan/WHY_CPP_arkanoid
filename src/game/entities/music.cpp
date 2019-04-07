#include <game/components/audio_component.h>
#include <lib/ecs/entity_manager.h>

void CreateMusic(EntityManager *entity_manager, const std::string& name) {
  auto music = entity_manager->CreateEntity();
  music->SetTag("music");
  music->Add<AudioComponent>(name, true, -1);
  music->Get<AudioComponent>()->Play();
}