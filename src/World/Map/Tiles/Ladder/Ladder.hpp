#pragma once

#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Ladder : public Tile {
private:
  inline static sf::Sprite ladderSprite =
      Settings::getInstance()->getSprite("Ladder");

public:
  Ladder(int x, int y)
      : Tile(x, y, std::make_shared<HitBoxSprite>(ladderSprite, x, y)) {}
  ~Ladder() = default;

  const void handleCollision(Player &player) override { player.climb(); }
};
