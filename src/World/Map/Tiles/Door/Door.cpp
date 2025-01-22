#include "../Door/Door.hpp"
#include "../../../LevelController/LevelController.hpp"

const void Door::handleCollision(Player &player) {
  if (player.useKey()) {
    LevelController::goNextLevel(player);
  }
}
