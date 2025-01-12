#pragma once

#include "../../../Utils/HitBoxSprite/HitBoxSprite.hpp"
#include "../../../Settings/Settings.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Tile {
protected:
  float x;
  float y;
  std::shared_ptr<HitBoxSprite> hitBoxSprite;

public:
  bool slab = false;
  bool climbable = false;
  bool collidable = false;
  bool animated = false;
  bool collectable = false;
  bool damageable = false;

  Tile(float x, float y, std::shared_ptr<HitBoxSprite> hitBoxSprite)
      : x(x), y(y), hitBoxSprite(hitBoxSprite) {
    hitBoxSprite->setPosition(x, y);
    hitBoxSprite->setOrigin(6, 0);
  }

  virtual ~Tile() = default;
  virtual const void handleCollision() { return; };
  virtual const void onPlayerTop() { return; };
  virtual const void onPlayerBottom() { return; };

  const sf::Sprite &getSprite() const;
  const HitBoxSprite &getHitBoxSprite() const;
  const bool isClimbable() const;
  const bool isCollectable() const;
  const bool isAnimated() const;
  const bool isDamageable() const;
  const bool isCollidable() const;
};
