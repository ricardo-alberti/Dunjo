#include "Tiles/Brick.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

Brick::Brick(int _x, int _y, sf::Sprite _sprite)
    : sprite(_sprite),
      Tile(_x, _y, std::make_shared<HitBoxSprite>(_sprite, _x, _y)) {
  collidable = true;
}

Brick::~Brick() = default;
