#include "../LevelController/LevelController.hpp"
#include "../../Entities/Player/Player.hpp"
#include "../Levels/Level_1.hpp"
#include "../Levels/Level_2.hpp"
#include "../Levels/Level_3.hpp"
#include <memory>

std::map<int, std::shared_ptr<Map>> LevelController::levelOrder;

LevelController::LevelController() { setLevelOrder(); }

void LevelController::goNextLevel(Player &player) {
  if (currentLevel == levelOrder.size())
    return;

  currentLevel++;
  levelOrder[currentLevel]->loadTiles();

  player.getHitBoxSprite().setPosition(
      levelOrder[currentLevel]->getSpawnPoint().x,
      levelOrder[currentLevel]->getSpawnPoint().y);
};

void LevelController::goPreviousLevel(Player &player) {
  if (currentLevel == 1)
    return;

  currentLevel--;
  levelOrder[currentLevel]->loadTiles();

  player.getHitBoxSprite().setPosition(
      levelOrder[currentLevel]->getSpawnPoint().x,
      levelOrder[currentLevel]->getSpawnPoint().y);
};

const std::shared_ptr<Map> LevelController::getCurrentLevel() {
  return levelOrder[currentLevel];
};

void LevelController::setLevelOrder() {
  levelOrder[1] = std::make_shared<Level_1>();
  levelOrder[2] = std::make_shared<Level_2>();
  levelOrder[3] = std::make_shared<Level_3>();
}
