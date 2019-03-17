#include <lib/scene.h>
#include <lib/scene_manager.h>
#include <iostream>

void SceneManager::OnUpdate() {
  if (scenes.size() > current_scene) {
    if (first_start) {
      first_start = false;
      scenes.at(current_scene)->OnCreate();
      prev_scene = current_scene;
    } else if (prev_scene != current_scene) {
      scenes.at(prev_scene)->OnDispose();
      prev_scene = current_scene;
      scenes.at(current_scene)->OnCreate();
    }
    scenes.at(current_scene)->OnUpdate();
  } else {
    std::cout << "[WARNING] Cannot update scene " << current_scene << ": it doesn't exist. Scenes size is "
              << scenes.size() << std::endl;
  }
}
void SceneManager::OnDispose() {
  for (auto &scene : scenes) {
    scene->OnDispose();
  }
  scenes.clear();
}
void SceneManager::SetScene(size_t id) {
  std::cout << "SetScene(" << id << ")" << std::endl;
  if (id < scenes.size()) {
    prev_scene = current_scene;
    current_scene = id;
  }
}
void SceneManager::SetScene(const std::string& name) {
  std::cout << "SetScene(" << name << ")" << std::endl;
  if (named_scenes.count(name) == 0) {
    std::cout << "There is no scene '" << name << "'. Going to the first scene." << std::endl;
    SetScene(0);
    return;
  }
  auto id = named_scenes.at(name);
  SetScene(id);
}
void SceneManager::NextScene() {
  current_scene++;
  if (current_scene >= scenes.size()) {
    current_scene = 0;
  }
}
