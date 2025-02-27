#pragma once

#include "../Brick/Brick.hpp"

class MagicBrick : public Brick {
private:
  static inline sf::Sprite magicSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(48, 24, 12, 12));

public:
  MagicBrick(int x, int y) : Brick(x, y, magicSprite) { collidable = false; }

  const void Activate() {
    hitBoxSprite->setTexture(Settings::getInstance()->getTexture());
    hitBoxSprite->setTextureRect(sf::IntRect(60, 24, 12, 12));
    collidable = true;
    return;
  }

  ~MagicBrick() = default;
};
