#pragma once

#include "../Map/Map.hpp"
#include <map>
#include <memory>

class LevelController {
private:
  static inline int currentLevel = 1;
  static std::map<int, std::shared_ptr<Map>> levelOrder;

public:
  LevelController();
  const std::shared_ptr<Map> getCurrentLevel();

  void setLevelOrder();
  static void goNextLevel();
  static void goPreviousLevel();
};
