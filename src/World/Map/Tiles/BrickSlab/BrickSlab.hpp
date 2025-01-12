#pragma once

#include "../Brick/Brick.hpp"

class BrickSlab : public Brick {
public:
  BrickSlab(int x, int y, sf::Sprite sprite) : Brick(x, y, sprite) {
    slab = true;
    collidable = false;
  }

  ~BrickSlab() = default;

  const void onPlayerTop() override {
    collidable = true;
    return;
  }
  const void onPlayerBottom() override {
    collidable = false;
    return;
  }
};
