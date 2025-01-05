#pragma once

#include "../../Entities/Player/Player.hpp"
#include "../../Utils/HitBoxSprite/HitBoxSprite.hpp"
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
  bool climbable = false;
  bool collidable = false;
  bool animated = false;
  bool interactable = false;

  Tile(float x, float y, std::shared_ptr<HitBoxSprite> hitBoxSprite)
      : x(x), y(y), hitBoxSprite(hitBoxSprite) {
    hitBoxSprite->setPosition(x, y);
    hitBoxSprite->setOrigin(6, 0);
  }

  virtual ~Tile() = default;
  virtual void handleCollision(Player &player) { return; }
  const sf::Sprite &getSprite() const;
  const HitBoxSprite &getHitBoxSprite() const;
};
