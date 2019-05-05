#include <SDL.h>
#include <SDL_error.h>
#if __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#else
#include <SDL_mixer.h>
#endif
#include <lib/music/music_manager.h>
#include <whycpp/log.h>

void MusicManager::PlayMusic(const std::string& name, int loops) {
  // check whether some music already playing or not
  auto music = assets_->GetMusic(name);
  if (music == nullptr) return;
  if (Mix_PlayMusic(music, loops) != 0) {
    LOG_WARN("Cannot play music %s: %s", name.c_str(), SDL_GetError());
  }
}
void MusicManager::PlayEffects(const std::string& name, int loops, int channel) {
  auto sfx = assets_->GetEffect(name);
  if (sfx == nullptr) return;
  if (Mix_PlayChannel(channel, sfx, loops) != 0) {
    LOG_WARN("Cannot play effect %s: %s", name.c_str(), SDL_GetError());
  }
}
MusicAssets* MusicManager::GetAssets() const {
  return assets_.get();
}
MusicManager::MusicManager() : assets_(std::make_unique<MusicAssets>()) {
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
    LOG_ERROR("SDL_MIXER error: %s", SDL_GetError());
  }

  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
    LOG_ERROR("SDL_MIXER error: %s", SDL_GetError());
  }
}
MusicManager::~MusicManager(){
  Mix_CloseAudio();
}
bool MusicManager::IsPlaying() const{
  return Mix_PlayingMusic();
}
