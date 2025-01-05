#pragma once

#include "../Brick.hpp"

class BrickSlab : public Brick {
public:
  BrickSlab(int x, int y, sf::Sprite sprite) : Brick(x, y, sprite) {
    climbable = true;
  }

  ~BrickSlab() = default;

  void handleCollision(Player &player) override {
    const sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
    const sf::FloatRect tileBounds = this->getHitBoxSprite().getGlobalBounds();

    if (playerBounds.top + playerBounds.height - 7.0f < tileBounds.top) {
      collidable = true;
    } else {
      collidable = false;
    }
  }
};
