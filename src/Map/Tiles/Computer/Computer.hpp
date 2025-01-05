#pragma once

#include "../../../Settings/Settings.hpp"
#include "../../../Utils/Animation/Animation.hpp"
#include "../TileAspects/AnimatedTile.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Computer : public AnimatedTile {
private:
  std::unique_ptr<Animation> animation;

public:
  inline static sf::Sprite computerSprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(60, 48, 12, 12));

  Computer(int x, int y, sf::Sprite sprite)
      : AnimatedTile(
            x, y, std::make_shared<HitBoxSprite>(sprite, x, y, 12.0f, 12.0f)) {

    animation =
        std::make_unique<Animation>(this->hitBoxSprite, 60, 48, 0.2f, 3);
  }

  void Update(float deltaTime) { animation->update(deltaTime); }

  ~Computer() = default;
};
