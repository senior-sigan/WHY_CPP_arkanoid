#pragma once

#include <memory>
#include <lib/music/music_assets.h>
#include <string>

class MusicManager {
  std::unique_ptr<MusicAssets> assets_;
 public:
  MusicManager();
  virtual ~MusicManager();

  MusicAssets* GetAssets() const;

  void PlayMusic(const std::string& name, int loops = -1);
  void PlayEffects(const std::string& name, int loops = 0, int channel = -1);

  bool IsPlaying() const;
};
