#pragma once

#include <vector>
#include <lib/scene.h>

class SceneManager {
  std::vector<std::unique_ptr<IScene>> scenes;
  size_t current_scene = 0;
  size_t prev_scene = 0;
  bool first_start = true;
 public:
  template<typename Scene, typename... Args>
  void Add(Args &&... args) {
    scenes.push_back(std::make_unique<Scene>(std::forward<Args>(args)...));
    (*(scenes.end()-1))->sceneManager = this;
  }
  void OnUpdate();
  void OnDispose();
  void SetScene(size_t id);
  void NextScene();
};