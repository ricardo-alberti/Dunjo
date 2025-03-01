#pragma once

#include "Player/Player.hpp"
#include "Utils/CollisionMediator.hpp"
#include "Utils/LevelController.hpp"
#include "View/View.hpp"
#include <memory>

class World {
private:
  View &view;
  Player &player;
  LevelController &levelController;
  std::unique_ptr<CollisionMediator> collisionMediator;

  float deltaTime;

public:
  World(View &view, Player &player, LevelController &levelController);
  void display();
};
