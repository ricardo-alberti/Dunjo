#pragma once

#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Chain : public Tile {
private:
  inline static sf::Sprite chainSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(84, 24, 12, 12));

public:
  Chain(int x, int y)
      : Tile(x, y,
             std::make_shared<HitBoxSprite>(chainSprite, x, y, 12.0f, 12.0f)) {}

  ~Chain() = default;
};
