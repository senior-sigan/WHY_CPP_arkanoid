#pragma once

#include <random>

class TrueRandom {
  std::random_device dev;

 public:
  int NextInt(int min, int max) {
    if (min == max) return min;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max - 1);
    return dist6(rng);
  }
};