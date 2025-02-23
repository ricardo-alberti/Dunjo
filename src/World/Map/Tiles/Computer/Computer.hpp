#pragma once

#include "../../TileAspects/AnimatedTile.hpp"
#include "../../Tiles/MagicBrick/MagicBrick.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <cstdlib>
#include <memory>

class Computer : public AnimatedTile {
private:
  std::unique_ptr<Animation> animation;
  std::vector<std::shared_ptr<MagicBrick>> observers;

public:
  inline static sf::Sprite computerSprite =
      Settings::getInstance()->getSprite("Computer");

  Computer(int x, int y, sf::Sprite sprite)
      : AnimatedTile(
            x, y, std::make_shared<HitBoxSprite>(sprite, x, y, 12.0f, 12.0f)) {

    animation =
        std::make_unique<Animation>(this->hitBoxSprite, 60, 48, 0.2f, 3);
  }

  void Update(float _deltaTime) override { animation->update(_deltaTime); }

  const void handleCollision(Player &player) override { NotifyObservers(); }

  const void AddObserver(std::shared_ptr<MagicBrick> _tile) {
    observers.emplace_back(_tile);
  };

  const void NotifyObservers() {
    for (auto &o : observers) {
      o->Activate();
    }
  };

  ~Computer() = default;
};
