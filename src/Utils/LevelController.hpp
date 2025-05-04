#pragma once

#include "Map/Map.hpp"
#include <map>
#include <memory>

class LevelController {
private:
  static LevelController *Instance;
  std::map<int, std::shared_ptr<Map>> levelOrder;
  int currentLevel = 0;
  void spawnPlayer(Player &player);

public:
  LevelController();

  const std::shared_ptr<Map> getCurrentLevel();

  void setLevelOrder();
  void reset(Player &player);
  void goNextLevel(Player &player);
  void goPreviousLevel(Player &player);
  static LevelController *getInstance();
};
