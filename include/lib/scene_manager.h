#pragma once

#include <lib/scene.h>
#include <vector>

class SceneManager {
  std::vector<std::unique_ptr<IScene>> scenes;
  size_t current_scene = 0;
  size_t prev_scene = 0;
  bool first_start = true;

 public:
  template<typename Scene, typename... Args>
  void Add(Args &&... args) {
    auto scene = new Scene(std::forward<Args>(args)...);
    scene->sceneManager = this;
    scenes.push_back(std::unique_ptr<Scene>(scene));
  }
  void OnUpdate();
  void OnDispose();
  void SetScene(size_t id);
  void NextScene();
};