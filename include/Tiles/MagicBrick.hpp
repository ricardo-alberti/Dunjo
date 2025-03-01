#pragma once

#include "Brick.hpp"

class MagicBrick : public Brick {
private:
  static inline sf::Sprite magicSprite =
      Settings::getInstance()->getSprite("MagicBrick");

public:
  MagicBrick(int x, int y) : Brick(x, y, magicSprite) { collidable = false; }

  const void Activate() {
    hitBoxSprite->setTextureRect(sf::IntRect(sf::Vector2(60, 24), sf::Vector2(12, 12)));
    collidable = true;
    return;
  }

  ~MagicBrick() = default;
};
