#pragma once

#include <memory>

class SceneManager;

class IScene {
  friend class SceneManager;
  SceneManager* sceneManager; // YES, this field should not be initialized

 public:
  SceneManager* GetSceneManager() const;
  virtual void OnCreate() {}
  virtual void OnUpdate() {}
  virtual void OnDispose() {}
  virtual ~IScene() = default;
};