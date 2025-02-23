#pragma once

#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Door : public Tile {
private:
  inline static sf::Sprite doorSprite =
      Settings::getInstance()->getSprite("Door");

public:
  Door(int x, int y)
      : Tile(x, y,
             std::make_shared<HitBoxSprite>(doorSprite, x, y, 12.0f, 12.0f)) {};
  ~Door() = default;

  const void handleCollision(Player &player) override;
};
