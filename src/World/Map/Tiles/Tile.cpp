#include "Tile.hpp"

const sf::Sprite &Tile::getSprite() const { return *hitBoxSprite; }
const HitBoxSprite &Tile::getHitBoxSprite() const { return *hitBoxSprite; }
const void handleCollision() { return; }

const bool Tile::isAnimated() const { return animated; }
const bool Tile::isCollidable() const { return collidable; }
