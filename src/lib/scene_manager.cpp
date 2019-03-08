#include <lib/scene_manager.h>
#include <lib/scene.h>
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
    std::cout << "[WARNING] Cannot update scene " << current_scene
              << ": it doesn't exist. Scenes size is "
              << scenes.size() << std::endl;
  }
}
void SceneManager::OnDispose() {
  for (auto &scene: scenes) {
    scene->OnDispose();
  }
  scenes.clear();
}
void SceneManager::SetScene(size_t id) {
  if (id < scenes.size()) {
    prev_scene = current_scene;
    current_scene = id;
  }
}
void SceneManager::NextScene() {
  current_scene++;
  if (current_scene >= scenes.size()) {
    current_scene = 0;
  }
}
