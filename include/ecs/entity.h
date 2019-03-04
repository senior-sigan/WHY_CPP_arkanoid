#pragma once

#include <map>
#include <memory>
#include <ecs/i_component.h>
#include <utility>
#include <typeindex>

class Entity {
  std::map<std::type_index, std::shared_ptr<IComponent>> components;

 public:
  template<typename Component, typename ...Args>
  Entity& Add(Args &&...args) {
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
};
