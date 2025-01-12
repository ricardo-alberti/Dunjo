#include "../Door/Door.hpp"
#include "../../../LevelController/LevelController.hpp"

const void Door::handleCollision() { LevelController::goNextLevel(); }
