#pragma once

#include "../../../Settings/Settings.hpp"
#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Ladder : public Tile {
private:
  inline static sf::Sprite ladderSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(36, 48, 12, 12));

public:
  Ladder(int x, int y)
      : Tile(x, y, std::make_shared<HitBoxSprite>(ladderSprite, x, y)) {
    climbable = true;
  }
  ~Ladder() = default;

  void handleCollision(Player &player) {
    if (player.getSprite().getGlobalBounds().top <
        this->getSprite().getGlobalBounds().top)
      player.setForce(-220.0f);

    return;
  }
};
