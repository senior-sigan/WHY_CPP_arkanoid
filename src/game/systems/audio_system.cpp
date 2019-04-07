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
  manager_->GetAssets()->RegisterEffect("bonus", "/Users/ilya/Documents/gamedev/ARKANOID/assets/bonus.wav");
  manager_->GetAssets()->RegisterEffect("anti_bonus", "/Users/ilya/Documents/gamedev/ARKANOID/assets/hit.wav");
  manager_->GetAssets()->RegisterEffect("platform", "/Users/ilya/Documents/gamedev/ARKANOID/assets/platform.wav");
  manager_->GetAssets()->RegisterMusic("music1", "/Users/ilya/Documents/gamedev/ARKANOID/assets/music1.WAV");
  manager_->GetAssets()->RegisterMusic("music2", "/Users/ilya/Documents/gamedev/ARKANOID/assets/music2.WAV");
  manager_->GetAssets()->RegisterMusic("music3", "/Users/ilya/Documents/gamedev/ARKANOID/assets/music3.WAV");
}
MusicManager* AudioSystem::GetMusicManager() const{
  return manager_.get();
}
