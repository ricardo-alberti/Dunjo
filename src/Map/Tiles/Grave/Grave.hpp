#pragma once

#include "../../../Settings/Settings.hpp"
#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Grave : public Tile {
private:
  inline static sf::Sprite graveSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(48, 12, 12, 12));

public:
  Grave(int x, int y) : Tile(x, y, std::make_shared<HitBoxSprite>(graveSprite, x, y)) {}
  ~Grave() = default;
};
