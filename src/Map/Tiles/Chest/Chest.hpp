#pragma once

#include "../../../Settings/Settings.hpp"
#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Chest : public Tile {
private:
  inline static sf::Sprite chainSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(36, 12, 12, 12));

public:
  Chest(int x, int y)
      : Tile(x, y,
             std::make_shared<HitBoxSprite>(chainSprite, x, y, 12.0f, 12.0f)) {}

  ~Chest() = default;
};
