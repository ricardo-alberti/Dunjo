#include "Utils/LevelController.hpp"
#include "Levels/Level_1.hpp"
#include "Levels/Level_2.hpp"
#include "Levels/Level_3.hpp"
#include "Player/Player.hpp"
#include <SFML/System/Vector2.hpp>
#include <memory>

LevelController *LevelController::Instance = nullptr;

LevelController::LevelController() { setLevelOrder(); }

LevelController *LevelController::getInstance() {
  if (Instance == nullptr) {
    Instance = new LevelController();
  }

  return Instance;
}

void LevelController::reset(Player &player) {
  levelOrder[currentLevel]->loadTiles();
  spawnPlayer(player);
}

void LevelController::spawnPlayer(Player &player) {
  player.resetToCheckPoint(
      sf::Vector2f(levelOrder[currentLevel]->getSpawnPoint().x,
                   levelOrder[currentLevel]->getSpawnPoint().y));
}

void LevelController::goNextLevel(Player &player) {
  if (currentLevel == levelOrder.size())
    currentLevel = 0;

  currentLevel++;
  levelOrder[currentLevel]->loadTiles();
  spawnPlayer(player);
};

void LevelController::goPreviousLevel(Player &player) {
  if (currentLevel == 1)
    return;

  currentLevel--;
  levelOrder[currentLevel]->loadTiles();
  spawnPlayer(player);
};

const std::shared_ptr<Map> LevelController::getCurrentLevel() {
  return levelOrder[currentLevel];
};

void LevelController::setLevelOrder() {
  levelOrder[1] = std::make_shared<Level_1>();
  levelOrder[2] = std::make_shared<Level_2>();
  levelOrder[3] = std::make_shared<Level_3>();
}
