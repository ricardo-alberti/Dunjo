#pragma once

#include "../../../Utils/HitBoxSprite/HitBoxSprite.hpp"
#include "../../../Entities/Player/Player.hpp"
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
  bool collidable = false;
  bool animated = false;

  Tile(float x, float y, std::shared_ptr<HitBoxSprite> hitBoxSprite)
      : x(x), y(y), hitBoxSprite(hitBoxSprite) {
    hitBoxSprite->setPosition(x, y);
    hitBoxSprite->setOrigin(6, 0);
  }

  virtual ~Tile() = default;

  virtual const void handleCollision(Player &player) { return; };
  virtual const void onPlayerTop() { return; };
  virtual const void onPlayerBottom() { return; };

  const sf::Sprite &getSprite() const;
  const HitBoxSprite &getHitBoxSprite() const;

  const bool isCollidable() const;
  const bool isAnimated() const;
};
