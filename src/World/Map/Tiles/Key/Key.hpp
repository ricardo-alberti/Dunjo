#pragma once

#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Key : public Tile {
private:
  inline static sf::Sprite sprite = Settings::getInstance()->getSprite("Key");

public:
  Key(float _x, float _y)
      : Tile(_x, _y, std::make_shared<HitBoxSprite>(sprite, _x, _y)) {}

  const HitBoxSprite &getSprite() const { return *hitBoxSprite; }
  const void handleCollision(Player &player) override {
    hitBoxSprite->setPosition(0, -1000);
    player.getKey();
  }
};
