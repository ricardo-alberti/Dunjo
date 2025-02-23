#pragma once

#include "../../TileAspects/AnimatedTile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Coin : public AnimatedTile {
private:
  int points = 100;
  std::unique_ptr<Animation> animation;

public:
  inline static sf::Sprite coinSprite =
      sf::Sprite(Settings::getInstance()->getTexture(),
                 sf::IntRect(sf::Vector2(0, 60), sf::Vector2(12, 12)));

  Coin(int x, int y, sf::Sprite sprite);
  ~Coin();

  void Update(float deltaTime) override;
  const void handleCollision(Player &player) override;
};
