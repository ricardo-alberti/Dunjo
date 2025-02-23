#pragma once

#include "../../../../Settings/Settings.hpp"
#include "../../TileAspects/AnimatedTile.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Fire : public AnimatedTile {
private:
  float frameTime;
  float timePassed;

public:
  inline static sf::Sprite fireSprite =
      Settings::getInstance()->getSprite("Fire");

  Fire(int x, int y, sf::Sprite sprite);
  ~Fire();
  void Update(float _deltaTime) override;
  const void handleCollision(Player &player) override;
};
