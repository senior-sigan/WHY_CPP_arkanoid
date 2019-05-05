#include <lib/music/music_assets.h>

#if __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#else
#include <SDL_mixer.h>
#endif
#include <whycpp/log.h>

MusicAssets::~MusicAssets() {
  for (const auto& effect: sfx) {
    Mix_FreeChunk(effect.second);
  }
  for (const auto& music: musics) {
    Mix_FreeMusic(music.second);
  }
}
void MusicAssets::RegisterMusic(const std::string& name, const std::string& path){
  musics_names_[name] = path;
}
void MusicAssets::RegisterEffect(const std::string& name, const std::string& path){
  sfx_names_[name] = path;
}
Mix_Music* MusicAssets::GetMusic(const std::string& name) {
  if (musics_names_.count(name) == 0) {
    LOG_WARN("There is no music for '%s'", name.c_str());
    return nullptr;
  }
  auto path = musics_names_.at(name);
  if (musics.count(path) == 0) {
    auto music = Mix_LoadMUS(path.c_str());
    if (music == nullptr) {
      LOG_ERROR("Cannot read music from file %s error: %s", path.c_str(), SDL_GetError());
      return nullptr;
    }
    musics[path] = music;
    return music;
  } else {
    return musics.at(path);
  }
}
Mix_Chunk* MusicAssets::GetEffect(const std::string& name) {
  if (sfx_names_.count(name) == 0) {
    LOG_WARN("There is no effect for '%s'", name.c_str());
    return nullptr;
  }
  auto path = sfx_names_.at(name);
  if (sfx.count(path) == 0) {
    auto effect = Mix_LoadWAV(path.c_str());
    if (effect == nullptr) {
      LOG_ERROR("Cannot read effect from file %s error: %s", path.c_str(), SDL_GetError());
      return nullptr;
    }
    sfx[path] = effect;
    return effect;
  } else {
    return sfx.at(path);
  }
}

