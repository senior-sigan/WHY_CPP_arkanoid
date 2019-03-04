#include <utility>

#ifndef GAME_RENDER_COMPONENT_H
#define GAME_RENDER_COMPONENT_H

#include <vector>
#include <whycpp/color.h>
#include <stdexcept>
#include <strstream>
#include <ecs/i_component.h>

class TextureComponent : public IComponent {
 public:
  const int width;
  const int height;

  std::vector<RGBA> sprite;

  TextureComponent(const int width, const int height, const std::vector<RGBA> &sprite)
      : width(width), height(height), sprite(sprite) {
    if (width < 0) throw std::invalid_argument("Width should not be negative");
    if (height < 0) throw std::invalid_argument("Height should not be negative");
    auto w = (unsigned int) width;
    auto h = (unsigned int) height;

    if (sprite.size() != w * h) {
      std::strstream ss;
      ss << "Bad sprite size " << sprite.size() << " but expected " << width * height;
      throw std::invalid_argument(ss.str());
    }
  }

  RGBA Get(int x, int y) const {
    return sprite.at(width * y + x);
  }
};

#endif //GAME_RENDER_COMPONENT_H
