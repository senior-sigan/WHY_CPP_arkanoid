#pragma once

#include <memory>

class SceneManager;

class IScene {
  friend class SceneManager;
  SceneManager* sceneManager = nullptr;

 public:
  SceneManager* GetSceneManager() const;
  virtual void OnCreate() {}
  virtual void OnUpdate() {}
  virtual void OnDispose() {}
  virtual ~IScene() = default;
};