#pragma once

#include <lib/scene.h>
#include <vector>
#include <string>
#include <map>

class SceneManager {
  std::map<std::string, size_t> named_scenes;
  std::vector<std::unique_ptr<IScene>> scenes;
  size_t current_scene = 0;
  size_t prev_scene = 0;
  bool first_start = true;

 public:
  template<typename Scene, typename... Args>
  void Add(const std::string& name, Args &&... args) {
    auto scene_raw = malloc(sizeof(Scene));
    ((Scene*)scene_raw)->sceneManager = this;
    auto scene = new(scene_raw)Scene(std::forward<Args>(args)...);
    scenes.push_back(std::unique_ptr<Scene>(scene));
    named_scenes[name] = scenes.size() - 1;
  }
  void OnUpdate();
  void OnDispose();
  void SetScene(size_t id);
  void SetScene(const std::string& name);
  void NextScene();
};