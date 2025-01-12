#pragma once

#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Ladder : public Tile {
private:
  inline static sf::Sprite ladderSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(36, 48, 12, 12));

public:
  Ladder(int x, int y)
      : Tile(x, y, std::make_shared<HitBoxSprite>(ladderSprite, x, y)) {
    climbable = true;
  }
  ~Ladder() = default;

  const void handleCollision() { return; }
};
