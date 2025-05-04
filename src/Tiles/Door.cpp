#include "Tiles/Door.hpp"
#include "Utils/LevelController.hpp"
#include "Utils/SoundManager.hpp"

const void Door::handleInteraction(Player &player) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
    if (open) {
      LevelController::getInstance()->goNextLevel(player);
      return;
    }
  }
}

const void Door::handleCollision(Player &player) {
  if (player.useKey()) {
    SoundManager::getInstance().play("door");
    hitBoxSprite->setTextureRect(sf::IntRect({84, 12}, {12, 12}));
    open = true;
  }
}
