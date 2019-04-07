#pragma once

#include <lib/ecs/i_system.h>
#include <lib/music/music_manager.h>
#include <memory>

class AudioSystem : public ISystem {
  std::unique_ptr<MusicManager> manager_;
 public:
  AudioSystem();
  MusicManager* GetMusicManager() const;
 protected:
  void Update(Context& ctx, Entity* entity) override;
  bool Filter(Entity* entity) const override;
};