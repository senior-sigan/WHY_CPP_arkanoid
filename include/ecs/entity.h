#pragma once

#include <ecs/i_component.h>
#include <map>
#include <memory>
#include <typeindex>
#include <utility>

class Entity {
  friend class EntityManager;
  std::map<std::type_index, std::shared_ptr<IComponent>> components;
  size_t id;
 public:
  template<typename Component, typename... Args>
  Entity &Add(Args &&... args) {
    components[typeid(Component)] = std::make_shared<Component>(std::forward<Args>(args)...);
    return *this;
  }

  template<typename Component>
  std::shared_ptr<Component> Get() const {
    auto c = components.at(typeid(Component));
    return std::dynamic_pointer_cast<Component>(c);
  }

  template<typename Component>
  bool Contains() const {
    return components.count(typeid(Component)) != 0;
  }

  size_t GetId() const {
    return id;
  }
};
