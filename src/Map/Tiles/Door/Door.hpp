#pragma once

#include "../../../Settings/Settings.hpp"
#include "../Tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Door : public Tile {
private:
  inline static sf::Sprite doorSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(84, 12, 12, 12));

public:
  Door(int x, int y)
      : Tile(x, y,
             std::make_shared<HitBoxSprite>(doorSprite, x, y, 12.0f, 12.0f)) {};
  ~Door() = default;
};
