#pragma once

#include <lib/ecs/i_component.h>
#include <string>

/**
 * Actually it's kind of event to notify system to play audio
 */
class AudioComponent: public IComponent {
 public:
  explicit AudioComponent(const std::string& name, bool is_music = false, int loops = 0) : name(name), is_music_(is_music), loops(loops) {}

  std::string name;
  bool is_music_ = false;
  bool play = false;
  int loops = 0;

  bool IsPlaying() {
    return play;
  }

  void Play() {
    play = true;
  }

  void Stop() {
    play = false;
  }
};