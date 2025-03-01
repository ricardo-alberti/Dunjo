#pragma once

#include "Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Brick : public Tile {
private:
  sf::Sprite sprite;

public:
  Brick(int x, int y, sf::Sprite sprite);
  ~Brick();
};
