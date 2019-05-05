#pragma once

#include <map>
#include <string>
#if __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#else
#include <SDL_mixer.h>
#endif

//struct Mix_Music;
//struct Mix_Chunk;

class MusicAssets {
  std::map<std::string, std::string> musics_names_;
  std::map<std::string, std::string> sfx_names_;

  std::map<std::string, Mix_Music*> musics;
  std::map<std::string, Mix_Chunk*> sfx;
 public:
  virtual ~MusicAssets();

  void RegisterMusic(const std::string& name, const std::string& path);
  void RegisterEffect(const std::string& name, const std::string& path);

  Mix_Music* GetMusic(const std::string& name);
  Mix_Chunk* GetEffect(const std::string& name);
};