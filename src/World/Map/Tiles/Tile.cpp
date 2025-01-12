#include "Tile.hpp"

const sf::Sprite &Tile::getSprite() const { return *hitBoxSprite; }
const HitBoxSprite &Tile::getHitBoxSprite() const { return *hitBoxSprite; }
const void handleCollision() { return; }

const bool Tile::isClimbable() const { return climbable; }
const bool Tile::isAnimated() const { return animated; }
const bool Tile::isDamageable() const { return damageable; }
const bool Tile::isCollectable() const { return collectable; }
const bool Tile::isCollidable() const { return collidable; }
