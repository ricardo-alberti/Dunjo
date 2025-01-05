#pragma once

#include "../Brick.hpp"

class MagicBrick : public Brick {
private:
  static inline sf::Sprite magicSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(48, 24, 12, 12));

public:
  MagicBrick(int x, int y) : Brick(x, y, magicSprite) { collidable = false; }

  ~MagicBrick() = default;
};
