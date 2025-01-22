#pragma once

#include "../Brick/Brick.hpp"

class BrickSlab : public Brick {
private:
  const float COLLISION_MARGIN = 1.0f;

public:
  BrickSlab(int x, int y, sf::Sprite sprite) : Brick(x, y, sprite) {}

  ~BrickSlab() = default;

  const void onPlayerTop() override {
    collidable = true;
    return;
  }

  const void onPlayerBottom() override {
    collidable = false;
    return;
  }

  const void handleCollision(Player &player) override {
    sf::FloatRect playerBounds = player.getHitBoxSprite().getRect();
    sf::FloatRect tileBounds = this->getHitBoxSprite().getRect();

    if (playerBounds.top + playerBounds.height - COLLISION_MARGIN <=
        tileBounds.top) {
      onPlayerTop();
    } else {
      onPlayerBottom();
    }

    if (player.goDownSlab()) {
      onPlayerBottom();
    }
  }
};
