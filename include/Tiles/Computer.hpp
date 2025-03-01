#pragma once

#include "AnimatedTile.hpp"
#include "MagicBrick.hpp"
#include "Utils/SoundManager.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <memory>

class Computer : public AnimatedTile {
private:
  std::unique_ptr<Animation> animation;
  std::vector<std::shared_ptr<MagicBrick>> observers;
  bool activated = false;

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

  const void handleInteraction(Player &player) override {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
      if (activated != true) {
        SoundManager::getInstance().play("computer");
        hitBoxSprite->setColor(sf::Color::Cyan);
        activated = true;
        NotifyObservers();
      }
    }
  }

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
