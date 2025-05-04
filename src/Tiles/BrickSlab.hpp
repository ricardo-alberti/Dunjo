#pragma once

#include "Tiles/Brick.hpp"

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

    sf::Vector2f playerPosition = playerBounds.position;
    sf::Vector2f playerSize = playerBounds.size;

    sf::Vector2f tilePosition = tileBounds.position;
    sf::Vector2f tileSize = tileBounds.size;

    if (playerPosition.y + playerSize.y - COLLISION_MARGIN <= tilePosition.y) {
      onPlayerTop();
    } else {
      onPlayerBottom();
    }

    if (player.goDownSlab()) {
      onPlayerBottom();
    }
  }
};
