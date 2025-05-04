#pragma once

#include "Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Grave : public Tile {
private:
  inline static sf::Sprite graveSprite =
      Settings::getInstance()->getSprite("Grave");

public:
  Grave(int x, int y)
      : Tile(x, y, std::make_shared<HitBoxSprite>(graveSprite, x, y)) {}
  ~Grave() = default;
};
