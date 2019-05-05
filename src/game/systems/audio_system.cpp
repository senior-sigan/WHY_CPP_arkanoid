#include <game/components/audio_component.h>
#include <game/systems/audio_system.h>
#include <lib/ecs/entity_manager.h>

void AudioSystem::Update(Context& ctx, Entity* entity) {
  auto ac = entity->Get<AudioComponent>();
  if (ac->IsPlaying()) {
    if (ac->is_music_) {
      manager_->PlayMusic(ac->name, ac->loops);
    } else {
      manager_->PlayEffects(ac->name, ac->loops);
    }
    ac->Stop();
  }
}
bool AudioSystem::Filter(Entity* entity) const {
  return entity->Contains<AudioComponent>();
}
AudioSystem::AudioSystem() : manager_(std::make_unique<MusicManager>()) {
  manager_->GetAssets()->RegisterEffect("bonus", "assets/bonus.wav");
  manager_->GetAssets()->RegisterEffect("anti_bonus", "assets/hit.wav");
  manager_->GetAssets()->RegisterEffect("platform", "assets/platform.wav");
  manager_->GetAssets()->RegisterMusic("music1", "assets/music1.WAV");
  manager_->GetAssets()->RegisterMusic("music2", "assets/music2.WAV");
  manager_->GetAssets()->RegisterMusic("music3", "assets/music3.WAV");
}
MusicManager* AudioSystem::GetMusicManager() const{
  return manager_.get();
}
