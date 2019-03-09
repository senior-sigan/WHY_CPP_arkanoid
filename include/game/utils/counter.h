#pragma once

#include <ecs/entity.h>
#include <memory>

template<typename T>
class Counter {
  int counter = 0;

 public:
  void operator()(Entity* entity) {
    if (entity->Contains<T>()) {
      counter++;
    }
  }

  int get() const {
    return counter;
  }
};