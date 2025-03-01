#pragma once

#include "Tile.hpp"
#include "Utils/SoundManager.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Chest : public Tile {
private:
  bool taken = false;
  int points = 1000;
  inline static sf::Sprite chainSprite =
      Settings::getInstance()->getSprite("Chest");

public:
  Chest(int x, int y)
      : Tile(x, y,
             std::make_shared<HitBoxSprite>(chainSprite, x, y, 12.0f, 12.0f)) {}

  ~Chest() = default;

  const void handleCollision(Player &player) override {
    if (taken != true) {
      SoundManager::getInstance().play("coin");

      player.increaseScore(points);
      hitBoxSprite->setColor(sf::Color::Black);
      taken = true;
    }
  }
};
