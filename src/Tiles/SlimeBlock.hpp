#pragma once

#include "Tile.hpp"
#include "Utils/SoundManager.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

class SlimeBlock : public Tile {
private:
  float expellForce = 1.5;
  static inline sf::Sprite slimeBlock =
      Settings::getInstance()->getSprite("TopMiddle");

public:
  SlimeBlock(int x, int y)
      : Tile(x, y, std::make_shared<HitBoxSprite>(slimeBlock, x, y)) {
    collidable = true;
    hitBoxSprite->setColor(sf::Color::Green);
  }
  ~SlimeBlock() = default;

  const void handleCollision(Player &player) override {
    float vForce = -player.verticalVelocity / 1.01;
    float hForce = player.horizontalVelocity * 1.3;

    if (vForce > 0)
      vForce *= -1;

    if (vForce > -300)
      vForce = -300;

    SoundManager::getInstance().play("slime");
    player.setForce(hForce, vForce);
  }
};
